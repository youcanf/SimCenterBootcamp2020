#ifndef _RECTANGLE
#define _RECTANGLE

#include "Shape.h"

class Square: public Shape {
 public:
  Square(double w, double h);
  ~Square();
  double GetArea(void);
  void PrintArea(std::ostream &s);  

 protected:

 private:
  double width, height;
  static int numRect;
};

#endif // _RECTANGLE

  
