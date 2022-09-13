// author: Liam converted Arturo's code into class
#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>
#include "FindColor.h"
#include <string.h>

using namespace std;
using namespace cv;

class LightBuoyDetector{

 public:
  LightBuoyDetector();
  ~LightBuoyDetector();

  string detectColorSequence(Mat);
  bool show_windows;
  void set_show_windows(bool);

  int max_pause_frames;
  int min_pause_frames;

  void set_blob_size(int);
  void reset();

  FindColor *blue;
  FindColor *green;
  FindColor *red;
  FindColor *red2;


 private:
  int color_counter;
  char auxiliar_color[3];
  char previous_color;
  bool first_found;
  bool found_pause;

  int pause_counter;

};