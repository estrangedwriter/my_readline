#define READLINE_READ_SIZE 512

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char* my_readline(int fd);

int main()
{
  char *str = NULL;

  int fd = open("./file.txt", O_RDONLY);

  while ((str = my_readline(fd)) != NULL)
  {
      printf("%s\n", str);
      free(str);
  }
  close(fd);
  //
  //  Yes it's also working with stdin :-)
  //  printf("%s", my_readline(0));
  //

  return 0;
}

char* my_readline (int fd) {

  char buffer[READLINE_READ_SIZE];
  size_t r;
  int counter, i;

  r = read(fd, buffer, READLINE_READ_SIZE);
  while (buffer[counter] != '\n') {
    putchar(buffer[counter]);
    counter++;
  }
  printf("number of bytes read: %ld\nnumber of bytes to newline: %d\n", r, counter);
  
  char* buffer2 = NULL;
  buffer2 = (char*)malloc( (sizeof(char)) * counter + 1);

  for (i = 0; i < counter; i++) {
    buffer2[i] = buffer[i];
    putchar(buffer2[i]);
  }
  
  free(buffer2);
  printf("\n");
  buffer2 = NULL;  
  return buffer2;
}


