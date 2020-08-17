#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {

  char c;
  int nDigit = 0, nWhite=0, nOther = 0;

  while ((c=getchar())!=EOF) {
    if (isdigit(c)) {
      nDigit++;
    }
    else if (c == ' ') {
      nWhite++;
    }
    else {
      nOther++;
    }
  }
  
  printf("nDigit=%d, nWhite=%d, nOther=%d \n", nDigit, nWhite, nOther);
}
