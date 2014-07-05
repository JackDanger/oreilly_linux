#include <stdio.h>
#include "/usr/zed_macros.h"

#define puts(A) printf(A); printf("\n")
#define len(A) (sizeof(A) / sizeof(A[0]))

int main(void) {
  FILE *stream;

  int fd = 0;

  stream = fdopen(fd, "r");

  check(stream, "stream");

  char buf[64];
  int c;
  int n = 5;
  int i = 0;

  while (--n > 0 && (c = fgetc(stream)) != EOF){
    printf("address of s: %p\n", ( void * )&buf[i]);
    printf("%c\n", c);
    buf[i++] = c;
  }
  buf[i++] = '\0';

  printf("buffer: %s\n", buf);

  return 0;

error:
  perror("error");
  return 1;
}
