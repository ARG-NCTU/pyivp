
// author: Combo of Liam and Arturo
// We pass through a sequence of states
// 1. NO DETECTION (never detected any color ever) (returns "NO_DETECTION")
// 2. DETECTION (have detected any color but not found the pause in the sequence to know where to start (returns "WAITING FOR PAUSE IN SEQUENCE")
// 3. FOUND PAUSE (have found the pause in the sequence and ready to start building sequence) (returns a PARTIAL SEQENCE" aka "RG" for red and then green or an empty string if we have found nothing yet)
// 4. SEQUENCE FOUND (as soon as we get 3 transitions we have found the sequence and we are good (returns sequence of length 3 eg "RGB")

// Added Oct. 8 adapt the thresholds to be more admissive in the case that no detection is ever being made. Adapt the thresholds to be less admissive if we are never finding the pause.

#include "LightBuoyDetector.h"

LightBuoyDetector::LightBuoyDetector(){

  color_counter = 0;
  auxiliar_color[0] = 'x';
  auxiliar_color[1] = 'x';
  auxiliar_color[2] = 'x';
  previous_color = 'x';

  first_found = false;
  pause_counter = 0;
  found_pause = false;

  //settable in plug
  max_pause_frames = 10;
  min_pause_frames = 10;

  //These are settable in plug
  green= new FindColor(Scalar(30,80,100),Scalar(60,120,255),"green");
  red=   new FindColor(Scalar(0,120,60),Scalar(5,150,255),"red1");
  red2=  new FindColor(Scalar(170,120,60),Scalar(180,150,255),"red2");
  blue=  new FindColor(Scalar(110,80,100),Scalar(125,150,255),"blue");

  show_windows = false;

}

LightBuoyDetector::~LightBuoyDetector(){
  delete blue;
  delete green;
  delete red;
  delete red2;
}

string LightBuoyDetector::detectColorSequence(Mat frame)
{

  if(frame.empty()) //if there is no frame the program ends
    return "NO FRAME";

  //color segmentation
  Mat imgHSV;

  cvtColor(frame, imgHSV, CV_BGR2HSV);//converts to HSV


  if(blue->isColor(imgHSV)){
    cout << "Got blue detection" << endl;
    cout << "Previous color: "  << previous_color << endl;
     first_found = true;
     pause_counter = 0;
     if(found_pause && previous_color != 'B'){ // we have found the pause and now we have found a transition
       cout << "Added blue to sequence!" << endl;
       auxiliar_color[color_counter]='B';
       previous_color = 'B';
       color_counter++;
     }
  }else if(green->isColor(imgHSV)){
    cout << "Got Green detection" << endl;
    cout << "Previous color: "  << previous_color << endl;
    first_found = true;
    pause_counter = 0;
    if(found_pause && previous_color != 'G'){ // we have found the pause and now we have found a transition
      cout << "Added Green to sequence" << endl;
      auxiliar_color[color_counter]='G';
      previous_color = 'G';
      color_counter++;
    }
  }else if(red->isColor(imgHSV) || red2->isColor(imgHSV)){
    cout << "Got Red Detection" << endl;
    cout << "Previous color: "  << previous_color << endl;
    first_found = true;
    pause_counter = 0;
    if(found_pause && previous_color != 'R'){ // we have found the pause and now we have found a transition
      cout << "Added Red to Sequence" << endl;
      auxiliar_color[color_counter]='R';
      previous_color = 'R';
      color_counter++;
    }
  }
  else{
    // LP: no detection:
    if (first_found){
      pause_counter++;
      if (pause_counter > min_pause_frames){
	int pause_count = pause_counter;
	reset();
	first_found = true; // we still want to maintain that we have found a detection
	pause_counter = pause_count; // need to maintain the pause count
      }
      if (pause_counter > max_pause_frames)
	found_pause = true;
    }
    else
      return "NO DETECTION";
  }
    
  if (!found_pause)
    return "WAITING FOR PAUSE IN SEQUENCE";

  string sequence = "";
  for (int i = 0; i < color_counter; i++)
    sequence += auxiliar_color[i];
  
  return sequence;
}

void LightBuoyDetector::reset(){
  color_counter = 0;
  auxiliar_color[0] = 'x';
  auxiliar_color[1] = 'x';
  auxiliar_color[2] = 'x';
  previous_color = 'x';
  pause_counter = 0;
  found_pause = false;
  blue->reset();
  red->reset();
  red2->reset();
  green->reset();
  //  first_found = false;
}

void LightBuoyDetector::set_show_windows(bool val){
  show_windows = val;
  blue->set_show_windows(val);
  green->set_show_windows(val);
  red->set_show_windows(val);
  red2->set_show_windows(val);
}

void LightBuoyDetector::set_blob_size(int size){
  blue->set_blob_size(size);
  green->set_blob_size(size);
  red->set_blob_size(size);
  red2->set_blob_size(size);
}