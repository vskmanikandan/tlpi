#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char* argv[])
{
  int inputFd, outputFd, openFlags;
  char str[BUF_SIZE];
  ssize_t numRead;
  size_t filePerms;

  if( argc != 3 || strcmp(argv[1], "--help") == 0 )
    printf("%s : old-file new-file\n",argv[0]);

  openFlags = O_CREAT | O_WRONLY | O_TRUNC;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;   /* rw-rw-r-- */

  inputFd = open( argv[1], O_RDONLY );
  if( inputFd < 0 )
  {
    perror(argv[1]);
  }

  outputFd = open( argv[2], openFlags, filePerms  );
  if( outputFd < 0 )
  {
    perror(argv[2]);
  }
  
  numRead = read( inputFd, str, BUF_SIZE );
  numRead = write ( outputFd, str, numRead );
  if(numRead > 0)
  {
    perror("file copied.. ");
  }

  close(inputFd);
  close(outputFd);
}
