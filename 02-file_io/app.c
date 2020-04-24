#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char* argv[])
{
  int inputFd, outputFd, openFlags;
  char * data[BUF_SIZE];

  mode_t filePerms;
  ssize_t numRead; 

  openFlags = O_CREAT | O_WRONLY;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH; /* rw-rw-r-- */


  if(argc != 3 || (strcmp(argv[1], "--help") == 0))
  {
    printf("%s : file1 file2",argv[0]);
    exit(-1);
  }

  inputFd = open(argv[1], O_RDONLY);
  if( inputFd == -1 )
  {
    perror(argv[1]);
  }

  outputFd = open(argv[2], openFlags, filePerms);
  if(outputFd == -1)
  {
    perror(argv[2]);
  }

  if( lseek(outputFd,0,SEEK_END) == -1 )
    perror("Error appending a data ");

  while ( (numRead = read(inputFd, data, BUF_SIZE)) > 0 )
  {
    if ( (write (outputFd, data, numRead)) != numRead )
      perror("Coudn`t append entire data ");
  }

  if(close(inputFd) == -1)
    perror(argv[1]);

  if(close(outputFd) == -1)
    perror(argv[2]);

}
