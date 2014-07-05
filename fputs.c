#include <stdio.h>
#include <unistd.h>
#include "/usr/zed_macros.h"

#define puts(A) printf(A); printf("\n")
#define len(A) (sizeof(A) / sizeof(A[0]))

int main(void) {
  FILE *in, *out;

  in = fdopen(STDIN_FILENO, "r");
  out = fopen("out.txt", "a");

  check(in, "in");

  char buf[4];
  int c;
  int i = 0;

  while ((c = fgetc(in)) != EOF){
    printf("address of s: %p\n", ( void * )&buf[i]);
    printf("%c\n", c);
    buf[i++] = c;
  }
  buf[i++] = '\0';

  fputs(buf, out);

  fclose(in);
  fclose(out);
  return 0;

error:
  perror("error");
  return 1;
}
