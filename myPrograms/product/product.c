#include <stdio.h>
float productFloat(float a, float b);

int main() {
  float num1, num2, product;
  printf("Enter first number: ");
  scanf("%f", &num1);
  printf("Enter second number: ");
  scanf("%f", &num2);
  product = productFloat(num1, num2);
  printf("product %f * %f = %f\n", num1, num2, product);
  return(0);
}

float productFloat(float a, float b) {
  
  return (a*b);
}
