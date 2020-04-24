#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void fun(struct stat *sb)
{
  printf(" file size : %ld",sb->st_size);
}

int main(int argc, char* argv[])
{
  int inputFd,st_ret;
  struct stat sb;
  if(argc == 1)
  {
    printf("Usage : %s file-name\n",argv[0]);
    exit(-10);
  }
  st_ret = stat(argv[1], &sb);
  if(st_ret == -1)
  {
    perror("stat()");
  }

  printf(" file size : %ld",sb.st_size);


  //fun(&sb);

}

