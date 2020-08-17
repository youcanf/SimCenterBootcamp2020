
#include <omp.h>
#include <stdio.h>
#include <time.h>

static int long numSteps = 1000000000;

int main() {

  // perform calculation
  double pi   = 0;
  double dx = 1./numSteps;
  double x = 0.5*x;

  //
  // compute Serially
  //

  double start = omp_get_wtime();  
  {
    pi = 0;
    double sum = 0;
    double x  = dx*0.50;
    for (int i=0; i<numSteps; i++) {
     pi += 4./(1.+x*x);
      x += dx;
    }
    pi*=dx;
  }

  printf("Serially: PI = %16.8f in %.4g sec\n",pi, omp_get_wtime()-start);

  //  
  // compute in parallel
  //

  start = omp_get_wtime();  
  int nThreads;
  double pSum[32];
  for (int i=0; i<32; i++) 
    pSum[i] = 0;

#pragma omp parallel 
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    if (tid == 0)
      nThreads = numT;
    
    for (int i=tid; i<numSteps; i+=numT) {
      double x = (i+0.5)*dx;  
      pSum[tid] += 4./(1.+x*x);
    }
  }  

  pi = 0;
  for (int i=0; i<nThreads; i++) {
    pi += pSum[i];
  }
  pi *= dx;

  printf("\nParallel Results: %d Threads\n",nThreads);
  printf("Basic no padding: PI = %16.8f in %.4g sec\n",pi, omp_get_wtime()-start);  


  start = omp_get_wtime();

  double padSum[32][64];
  for (int i=0; i<nThreads; i++) 
    padSum[i][0] = 0;

#pragma omp parallel 
  {
    int tid = omp_get_thread_num();
    int numT = omp_get_num_threads();
    if (tid == 0)
      nThreads = numT;
    
    for (int i=tid; i<numSteps; i+=numT) {
      double x = (i+0.5)*dx;  
      padSum[tid][0] += 4./(1.+x*x);
    }
  }  

  pi = 0;
  for (int i=0; i<nThreads; i++) {
    pi += padSum[i][0];
  }
  pi *= dx;

  printf("Basic with padding: PI = %16.8f in %.4g sec\n",pi, omp_get_wtime()-start);  

  
  // compute using #omp parallel for reduction
  start = omp_get_wtime();

#pragma omp parallel for reduction(+:pi) private(x)
  for (int i=0; i<numSteps; i++) {
    double x = (i+0.5)*dx;  
    pi += 4./(1.+x*x);
  }
  
  pi *= dx;
  
  printf("Reduction: PI = %16.8f in %.4g sec\n", pi,omp_get_wtime()-start);
  
  // compute using Synchronization: critical
  start = omp_get_wtime();  
#pragma omp parallel 
  {
    double sum = 0;
    double x = 0;
#pragma omp for
    for (int i=0; i<numSteps; i++) {
      x = (i+0.5)*dx;
      sum += 4./(1.+x*x);
    }
#pragma omp critical
    {
      pi += sum;
      // OTHER STUFF .. NOT TOO MUCH
    }
  }
  
  pi *= dx;
  
  printf("Synchronization: PI = %16.8f in %.4g sec\n",pi, omp_get_wtime()-start);

  return 0;
}
