#define READLINE_READ_SIZE 512

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char* my_readline(int fd);

int main(int ac, char **av)
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

  char* buffer = NULL;
  buffer = malloc (READLINE_READ_SIZE * sizeof(char));
  size_t r;
  int index;

  r = read(fd, buffer, READLINE_READ_SIZE);

  for (index = 0; index < r; index++ ) 
    putchar( buffer[index] );
  free(buffer);
  buffer = NULL;  
  return buffer;
}


// char* my_readline(int fd) {
  
//   FILE* file;
//   int c;
//   int index;

//   for (index = 1; index < 5; index++) {
//     c = getc(file); 
//     printf("%c", c);
//   }

//   if (fd == 0) {
//     return "cool";
//   }
//   else if (fd != 0) {
//     return "wow";
//   }
// }
