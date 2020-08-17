#include <stdio.h>
#include <time.h>
#include <math.h>

static int long numSteps = 100000;

int main() {
  double pi = 0; double time = 0;
  double x = 0; int count = 0;
  double dx = 0;

  printf("Enter N:");
  scanf("%d", &count);
  //clock_t begin = clock();

  dx = 1./count;

  for (int i = 0; ((i<numSteps) && (x<1.0)); i++) {
    double F=0;
    pi += (4.0 / (1 + pow(x,2))) * dx;
    x += dx;
  }

  //clock_t end = clock();
  //time = (double)(end-begin) / CLOCKS_PER_SEC * 1000.;
  //printf("PI = %f, duration: %f ms\n", pi, time);
  printf("PI = %f\n", pi);
  return 0;
}
