#include <vector>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <unistd.h>
#include <string.h>

using namespace cv;
using namespace std;



class FindColor{
 private:
  Scalar colorBoxMin, colorBoxMax;
  bool show_windows;
  string name;
  int blob_size;

 public:

  //static int posicion;
  Mat binaryOutput;
  Mat before;
  Mat currentImg;
  Mat addImg;
  Mat beforeAdd;
  Mat total;
  FindColor(Scalar colorBoxMin, Scalar colorBoxMax, string name);
  ~FindColor(){};

  void set_show_windows(bool val){show_windows = val;};
  void set_blob_size(int);
  void reset();

  bool isColor(Mat);
  void set_min(double, double, double);
  void set_max(double, double, double);

  void increment(string, const char);
  void decrement(string, const char);

};