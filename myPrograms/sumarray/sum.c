#include <stdio.h>
#include <stdlib.h>
int sumInt(int *array, int n);

int main(int argc, char **argv) {

  int count, n, sum;
  const char *c;
  count = 0, n = 4;

  // array = (int *) malloc (n * (sizeof(int *)));
  //printf("Enter four integers: ");
  /*
  while ( (c=getchar()!=EOF) && (count<n) ) {
    if (c != ' ') {
      array[count] = atoi(c);
      count++;
    }
  }
  */
  
  int array[4] = {1, 2, 3, 4};
  sum = sumInt(array, n);

  printf("sum array = %d\n", sum);


  //free(array);

  return(0);
}

int sumInt(int *array, int n) {
  
  if (n < 1)
    return 1;
  else
    printf("n=%d, array[n-1]=%d\n", n, array[n-1]);
    return (array[n-1] * sumInt(array, n-1));
}
