#include <Square.h>

int Square::numRect = 0;

Square::~Square() {
  numRect--;
  std::cout << "Square Destructor\n";
}

Square::Square(double w, double d)
  :Shape(), width(w), height(d)
{
  numRect++;
}

double
Square::GetArea(void) {
  return width*height;
}

void 
Square::PrintArea(std::ostream &s) {
  s << "Square: " << width * height << " numRect: " << numRect << "\n";
}

