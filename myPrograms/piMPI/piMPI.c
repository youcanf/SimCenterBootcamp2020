#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

static int long numSteps = 100000;

int main(int argc, char **argv) {


  int procID, numP;
  

  MPI_Status status;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  clock_t start_t = clock();

  double pi = 0;
  double stepSize = 1.0/(double) numSteps;
  double *globalData = 0;
  

  /*
  if(procID == 0) {
    globalData = (double *)malloc(numP * sizeof(double));
    for (int i = 0; i<numP; i++) 
      globalData[i] = 0;
   }
  */

  for (int i=procID; i<numSteps; i+=numP) {
    double x = (i+0.5)*stepSize;
    pi += 4./(1.+x*x);
  }  

  if (procID == 0) {
    globalData = (double *)malloc(numP * sizeof(double));
  }


  MPI_Gather(&pi, 1, MPI_DOUBLE, globalData, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  if(procID == 0) {
    for (int i=1; i<numP; i++) // 1 as pi already has p0 contribution 
      pi += globalData[i];
  } 

  
  pi *= stepSize;

  clock_t end_t = clock();
  double time = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  
  if (procID == 0)
    printf("PI = %16.14f, duration: %f s\n",pi, time);


  MPI_Finalize();
  return 0;

}
