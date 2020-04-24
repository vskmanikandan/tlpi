#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

int main(int argc, char* argv[])
{
  int outputFd;
  char s_data[BUF_SIZE];
  
  if (argc == 2)
  {
    outputFd = open(argv[1],O_WRONLY);
    if(outputFd == -1)
    {
      perror(argv[2]);
    }

    while ( fgets(s_data, BUF_SIZE, stdin ) != NULL )
      if(write(outputFd, s_data, strlen(s_data)) == -1 )
      {
	perror("write");	
      }

  }
  //printf("%d\n",STDIN_FILENO);
  //printf("%u\n",stdin);
  //printf("%d\n",STDOUT_FILENO);
  //printf("%d\n",STDERR_FILENO);


}
