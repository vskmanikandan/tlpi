#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef BUF_SIZE
#define BUF_SIZE 4096
#endif

int main(int argc, char* argv[])
{
  int inputFd,i=0,l=1,fp=0, sfp=0, efp=0,lineNo=0;
  ssize_t numRead;
  char str[BUF_SIZE], data[1024];

  lineNo = atoi(argv[2]);
  inputFd = open( argv[1], O_RDONLY );
  if( inputFd < 0 )
  {
    perror(argv[1]);
  }
  lseek(inputFd,0,SEEK_SET);

//  lseek(inputFd, 9, SEEK_CUR);
  perror("lseek");

  numRead = read(inputFd, str, BUF_SIZE);

 // if(str[0] ==  '\n')
 //   printf("%c\n",str[0]);

  for(i=0; i<numRead; i++)
  {
    //printf("%c",str[i]);
    fp++;
    if(str[i] == '\n')
    {
      l++;
      if( lineNo == l )
      {
	sfp = fp;
	printf(" sfp : %d\n",sfp);
      }
      else if( (lineNo+1) == l )
      {
	efp = fp;
	printf(" efp : %d\n",efp);
      }
    }
  }
  lseek(inputFd, 0, SEEK_SET);
  lseek(inputFd, sfp, SEEK_CUR);
  read(inputFd, data, (efp-sfp) );

  printf(" %s ",data);
  printf("no of lines : %d",l);
}
