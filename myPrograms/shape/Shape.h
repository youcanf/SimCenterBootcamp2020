#ifndef _SHAPE
#define _SHAPE

#include "iostream.h"

class Shape {
 public:
  Shape();
  virtual ~Shape();
  virtual double GetArea(void) =0;
  virtual void PrintArea(std::ostream &s);
};

#endif // _SHAPE

  
