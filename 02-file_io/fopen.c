#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
  int input_fd, openFlags;
  mode_t filePerms;

  openFlags = O_CREAT | O_WRONLY;
  filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

  input_fd = open( "test", openFlags, filePerms );
  if( input_fd == -1 )
  {
    perror("error opening file..");
    exit(-1);
  }
  printf("%d",input_fd);
  perror("input_fd");
  

}

