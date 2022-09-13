
#include "FindColor.h"

FindColor::FindColor(cv::Scalar _colorBoxMin, cv::Scalar _colorBoxMax, string _name){
  colorBoxMin=_colorBoxMin;
  colorBoxMax=_colorBoxMax;
  show_windows = false;
  name = _name;
  blob_size = 150; // nominal - can be overwritten in mission file
}

void FindColor::set_min(double h, double s, double v){
  // cout << "Setting min values for " << name << " to " << h << " " << s << " " << v << endl;
  colorBoxMin = cv::Scalar(h,s,v);
}

void FindColor::set_max(double h, double s, double v){
  // cout << "Setting max values for " << name << " to " << h << " " << s << " " << v << endl;
  colorBoxMax = cv::Scalar(h,s,v);
}

void FindColor::increment(string minmax, const char c){
  cv::Scalar inc;
  if (c == 'h') inc = cv::Scalar(1,0,0);
  else if (c == 's') inc = cv::Scalar(0,1,0);
  else if (c == 'v') inc = cv::Scalar(0,0,1);
  else{
    cout << "invalid char input to increment" << endl;
    return;
  }
  if (minmax == "max"){
    colorBoxMax += inc;
    cout << "increment max value for " << name << " and char " << c << "new values " << colorBoxMax <<endl;
  }
  else if (minmax == "min"){
    colorBoxMin += inc;
    cout << "increment min value for " << name << " and char " << c << "new values " << colorBoxMin <<endl;
  }
  else{
    cout << "valid strings for minmax are min and max" << endl;
    return;
  }
}

void FindColor::decrement(string minmax, const char c){
  cv::Scalar inc;
  if (c == 'h') inc = cv::Scalar(1,0,0);
  else if (c == 's') inc = cv::Scalar(0,1,0);
  else if (c == 'v') inc = cv::Scalar(0,0,1);
  else{
    cout << "invalid char input to increment" << endl;
    return;
  }
  if (minmax == "max"){
    colorBoxMax -= inc;
    cout << "decrement max value for " << name << " and char " << c << "new values " << colorBoxMax <<endl;
  }
  else if (minmax == "min"){
    colorBoxMin -= inc;
    cout << "decrement min value for " << name << " and char " << c << "new values " << colorBoxMin <<endl;
  }
  else{
    cout << "valid strings for minmax are min and max" << endl;
    return;
  }
}

void FindColor::set_blob_size(int _size){
  blob_size = _size;
}

//function isColor returns a true or false if it can find the color(thresholds) that calls the function
bool FindColor::isColor(Mat img2test){
  currentImg=img2test;
  inRange(img2test,colorBoxMin,colorBoxMax,binaryOutput);

  if (show_windows)
    imshow("BINARY_OUTPUT",binaryOutput);

  if(!before.data){ //first time it wont get a frame so that why we return false
    before=binaryOutput;
    return false;
  }
  else{
    
    //    bitwise_or(binaryOutput,before,addImg);//adds images because the rate can be slow causing only to see lines

    int stadistics=countNonZero(binaryOutput);//counts pixels segmented
    if(stadistics>blob_size){//checks that it was a successful segmentation //1400
      cout << "blob_size = " << stadistics << endl;
      if(show_windows)
	imshow("OUTPUT_DETECT" + name,binaryOutput);//ONLY WHEN IT PERFORMS A SUCCESSFUL THRESHOLDING IT SHOWS AN OUTPUT
      else
	imwrite("data/images/output_detect" + name + ".jpg",binaryOutput);
      addImg.setTo(cv::Scalar::all(0));
      return true;//if it found the color returns true
    }
    before=addImg;
  }
  return false;

}

void FindColor::reset(){
  addImg.setTo(cv::Scalar::all(0));
}