#ifndef DETECTORH
#define DETECTORH


#include <algorithm>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "feature.h"
#include "types.h"

using namespace std;
using namespace cv;
using namespace robotx;

const string o   = "ORIGINAL";

const string gw1 = "SEGMENTED GREEN";
const string gw2 = "MORPHO GREEN";

const string rw1 = "SEGMENTED RED";
const string rw2 = "MORPHO RED";

const string ww1 = "SEGMENTED WHITE";
const string ww2 = "MORPHO WHITE";

struct HSV{
  int h;
  int s;
  int v;
};

struct RGB{
  int r;
  int g;
  int b;
};

class Detector{

 public:
  Detector();
  ~Detector();
  //  bool OpenCapture(string);
  // bool OpenCapture();
  ColorFeature DetectColor(Feature, Pose3, Mat);

  bool showWindows;
  int width;
  int height;
  int frame_count;
  double trans[6];
  HSV green_min;
  HSV green_max;
  HSV red_min;
  HSV red_max;
  RGB white_min;
  RGB white_max;

  int sub_window_width;
  int sub_window_height;
 private:

};

#endif