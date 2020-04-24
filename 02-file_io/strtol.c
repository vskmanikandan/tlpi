#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char* argv[])
{
  char *enptr, data[20];
  int base;
  long long_no, val;


  printf("Enter some text\n");
  fgets(data,20,stdin);

  printf("Enter base val:" );
  scanf("%d",&base);
  
  long_no = strtol(data,&enptr,base);
  if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
                       || (errno != 0 && val == 0)) 
                 perror("strtol");
  //if(*enptr)
   // printf("failed to convert base : %d enptr : %c  data: %s", base, *enptr, data);
  //perror(errno);
//  else
    //printf("\nLong No : %ld",long_no);

}
