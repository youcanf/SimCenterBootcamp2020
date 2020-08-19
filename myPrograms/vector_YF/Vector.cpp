#include "iostream"
#include "Vector.h"


Vector::Vector(int sz)
{
  size = sz;
  data = new double[size];
}
 
Vector::~Vector()
{
  delete [] data;
}

// some methods
int Vector::Size(void) const
{
  return size;
}

void Vector::zero(void)
{
  for(int i = 0; i<size; i++)
    data[i]=0.;
}

double Vector::norm(void) const
{
  double norm=0;
  for (int i=0; i<size; i++)
    norm += data[i]*data[i];
  return norm;
}


double Vector::dot(const Vector &other) const
{
  double result = 0;
  if (other.size != size) {
    std::cerr << "Vector::dot ERROR vectors not of the same size, returning 0 \n";
    return result;
  }

  for (int i =0; i<size; i++)
    result += data[i]*other.data[i];
  return result;
}

void
Vector::print(void)
{
  for (int i=0; i<size; i++)
    std::cerr << " " << data[i];
  std::cerr << "\n";
}

  // overload some operators to look Matlabish
Vector 
Vector::operator+(const Vector &other) const
{
  Vector c(size);

  if (other.size != size) {
    std::cerr<<"Vector::operator+ ERROR, vectors do not have the same size.\n";
    return c;
  }

  for(int i=0; i< size; i++)
    c.data[i] = data[i] + other.data[i];
  return c;

}

void 
Vector::operator=(const Vector &other)
{
  if (other.size != size) {
    std::cerr<<"Vector::operator= ERROR, vectors do not have the same size.\n";
  }

  for(int i=0; i<size; i++)
    data[i] = other.data[i];
}

void 
Vector::operator+=(double val)
{
  for(int i=0; i<size; i++)
    data[i] += val;

}
  
void 
Vector::operator+=(const Vector &other)
{
  if (other.size != size) {
    std::cerr<<"Vector::operator+= ERROR, vectors do not have the same size.\n";
  }

  for(int i=0; i<size; i++)
    data[i] += other.data[i];

}

double 
Vector::operator()(int x) const
{
  return data[x]; 

}

double &
Vector::operator()(int x)
{
  if(x<0 || x>=size) {
    std::cerr << "error in Vector::operator()\n";
  } 

 return data[x];

}



