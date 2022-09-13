
#include <algorithm>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "Detector.h"
#include "transformations.h"



Detector::Detector()
{
  showWindows = true;
  frame_count = 0;
  for(int i =0; i<6; i++)
    trans[i] = 0.0;

  //defaults:
  green_min.h = 50;
  green_min.s = 85;
  green_min.v = 0;

  green_max.h = 97;
  green_max.s = 255;
  green_max.v = 255;
 
  red_min.h  = 110;
  red_min.s  = 130;
  red_min.v  = 0;
  
  red_max.h  = 137;
  red_max.s  = 255;
  red_max.v  = 255;

  white_min.r = 180;
  white_min.g = 180;
  white_min.b = 180;
  
  white_max.r = 255;
  white_max.g = 255;
  white_max.b = 255;

  sub_window_width = 50;
  sub_window_height = 50;

}  

Detector::~Detector(){
  
}

ColorFeature Detector::DetectColor(Feature feature, Pose3 nav, Mat frame){


  ColorFeature colorFeature(feature,UNKNOWN); // intiialize the ColorFeature to be unknown color

  if (frame.empty()){
    cout << "No frame" << endl;
    return colorFeature;
  }

  imwrite("current_frame.jpg", frame);


  Mat framer,frameg,segmented_red, segmented_green, morpho_red, morpho_green,segmented_white, morpho_white, HSVG,HSVR,HSVW;
  Mat open_element_red, open_element_green, element_c;
  Mat small_morpho;

  frameg = frame;

  //MORPHOLOGICAL FILTERS
  //create the elements for opening and closing
  open_element_green = getStructuringElement(MORPH_RECT, Size(2,3),cv::Point(1,1));
  open_element_red = getStructuringElement(MORPH_RECT, Size(5,5),cv::Point(1,1));
  element_c = getStructuringElement(MORPH_RECT, Size(10,14),cv::Point(1,1));
  small_morpho = getStructuringElement(MORPH_RECT, Size(2,2));

    
  //COUNTER FOR STATISTICS
  int counter_red =0;
  vector<int> v_red;
  //CAMERA
    
    
    
  //VECTORS TO SPLIT IMAGE
  vector<Mat> RGB_channels;
    
  
  //step 1: transform feature location to camera coords
  //step 2: transform feature location to pixel coords
  robotx::Transformations t;
  // t.setB2C(trans);
  Pixel pix = t.global2pixel(robotx::Point3(feature.x,feature.y,0),nav); // this does step 1 and 2 together

  cout << "Pixel of feature: u=" << pix.u << " v=" << pix.v <<endl;


  if (pix.u  > width || 
      pix.v > height  || 
      pix.u < 0 || 
      pix.v < 0){
    cout << "Pixel outside of camera field of view" << endl;
    return colorFeature;
  }

  //step 3: decide how big of a window to select based on image size? range?
  int window_height = sub_window_height;// for now the window size is the square root of the number of points. Thinking here is that the number points should about equal the number of pixels? Needs more work / thought. 
  int window_width = sub_window_width;
  
  int window_top_left_u = max(pix.u-window_width/2,0);
  int window_top_left_v = max(pix.v-window_height/2,0);

  if (window_top_left_u + window_width > width)
    window_width = width - window_top_left_u;
  if (window_top_left_v + window_height > height)
    window_height = height - window_top_left_v;

  cout << "subwindow: " << window_top_left_u << ", " << window_top_left_v << ", " << window_top_left_u + window_width << ", " << window_top_left_v + window_height << endl;

  //step 4: Use this information to select only small window in image.
  Rect roi = Rect(window_top_left_u,window_top_left_v,window_width,window_height);
  Mat sub_image = Mat(frameg,roi);
 

  //step 5: Decide if windowed image passes any of the color filters.
      

  cvtColor(sub_image,HSVG,COLOR_BGR2HSV);
  cvtColor(sub_image, framer, COLOR_RGB2BGR);
  cvtColor(framer,HSVR,COLOR_BGR2HSV);
       
        
    
        
  //GREEN
  inRange(HSVG, Scalar(green_min.h, green_min.s, green_min.v), 
	  Scalar(green_max.h,green_max.s,green_max.v), segmented_green);
        
        
  //RED
  inRange(HSVR,Scalar(red_min.h,red_min.s,red_min.v), 
	  Scalar(red_max.h,red_max.s,red_max.v), segmented_red);
  //H:100-130 S:85-255 V:200-255
   
     
  //WHITE
  //inRange(HSVG,Scalar(0,0,180),Scalar(255,30,255),segmented_white);
  inRange(sub_image,Scalar(white_min.r,white_min.g,white_min.b),
	  Scalar(white_max.r,white_max.g,white_max.b),segmented_white);
        
    
  //STATISTICS
  //RED 
  counter_red=0;
  //counter for white pixels
  for (int row=0; row<segmented_red.rows; row++) {
    uchar *p_count = segmented_red.ptr(row);
    for(int col=0; col<segmented_red.cols; col++)
      {
	if(*p_count == 255)
	  counter_red++;
	p_count++;
      }
  }


   //GREEN
    int counter_green = 0 ;
    for (int row = 0; row < segmented_green.rows; row++)
      {
	uchar *p_count = segmented_green.ptr(row);
	for(int col = 0; col<segmented_green.cols; col++)
	  {
	    if(*p_count == 255)
	      counter_green++;
	    p_count++;
	  }
      }

    //WHITE
        
    int counter_white=0;
    vector<int> v_white;
    //counter for white pixels
    for (int row=0; row<segmented_white.rows; row++) {
      uchar *p_count = segmented_white.ptr(row);
      for(int col=0; col<segmented_white.cols; col++)
	{
	  if(*p_count == 255)
	    counter_white++;
	  p_count++;
	}
    }
    v_white.push_back(counter_white);

    if(counter_red >= 70 && counter_red <= 240)//min 80 // TODO should this be a function of the size of the feature? test later...
      {
	cout << "FEATURE DETECTED as RED!!!" << endl;
	colorFeature.color=RED;
      }
    else if(counter_green >= 80 && counter_green <= 240)
      {
	cout << "FEATURE DETECTED as GREEN !!!" << endl;
	colorFeature.color = GREEN;
      }


    else if(counter_white >= 80 && counter_white <= 6400)//min 80 // TODO should this be a function of the size of the feature? test later...
      {
	cout << "FEATURE DETECTED as WHITE!!!" << endl;
	colorFeature.color=WHITE;

      }
    else 
      cout << "FEATURE COLOR not DETECTED" << endl;


  if(showWindows){
    imshow(o, frameg);
    imshow("SUB_WINDOW",sub_image);
    imshow(gw1, segmented_green);
    imshow(rw1, segmented_red);
    imshow(ww1, segmented_white);
  }
  else{
    std::string file_name = "data/images/sub_image" + intToString(frame_count) + ".jpg";
    imwrite(file_name, sub_image);
    file_name = "data/images/segmented_green" + intToString(frame_count) + ".jpg";
    imwrite(file_name, segmented_green);
    file_name = "data/images/segmented_red" + intToString(frame_count) + ".jpg";
    imwrite(file_name, segmented_red);
    file_name = "data/images/segmented_white" + intToString(frame_count) + ".jpg";
    imwrite(file_name, segmented_white);
  }

  frame_count++;
  return colorFeature;
}