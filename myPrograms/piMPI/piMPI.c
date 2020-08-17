#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

static int long numSteps = 100000;

int main(int argc, char **argv) {

  double pi = 0;
  double stepSize = 1.0/(double) numSteps;
  double *globalData = NULL;

  int procID, numP;
  MPI_Status status;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  clock_t start_t = clock();

  if(procID == 0) {
    globalData = (double *)malloc(numP * sizeof(double));
    for (int i = 0; i<numP; i++) 
      globalData[i] = 0;
   }

  for (int i=0; i<numSteps; i++) {
    double x = (i+0.5)*stepSize;
    pi += 4./(1.+x*x);
  }  


  MPI_Gather(&pi, 1, MPI_DOUBLE, globalData, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  if(procID == 0) {
    for (int i=0; i<numP; i++) 
      pi += globalData[i];
  } 



  //CLOCK_PER_SECONDS
  MPI_Finalize();
  
  pi *= stepSize;
  printf("PI = %16.14f\n",pi);
  return 0;

}
