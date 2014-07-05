#include <stdio.h>
#include <unistd.h>
#include "/usr/zed_macros.h"

#define puts(A) printf(A); printf("\n")
#define len(A) (sizeof(A) / sizeof(A[0]))

int main(void) {
  FILE *in, *out;

  struct pirate {
    char          name[40];  // real name
    unsigned long booty;     // in pounds sterline
    unsigned int  beard_len; // in inches
  } p, blackbeard = { "Edward Teach", 950, 48 },
       demo = { "demo:\0\1\2\3\4\5\6\7", 900, 100 };

  out = fopen("data", "w");
  check(out, "fopen data");

  check(fwrite(&blackbeard, sizeof(struct pirate), 1, out), "fwrite");
  check(fwrite(&demo,       sizeof(struct pirate), 1, out), "fwrite");

  fputs("\ntest all chars under 255:\n", out);
  for (int i = 0; i <= 255; i ++) {
    fputc(i, out);
  }
  check(!fclose(out), "fclose out");

  in = fopen("data", "r");
  check(in, "fopen data in");

  check(fread(&p, sizeof(struct pirate), 1, in), "fread");
  check(!fclose(in), "fclose in");

  printf("name:\"%s\", booty: %lu, beard_len:%u\n", p.name, p.booty, p.beard_len);

  return 0;

error:
  return 1;
}

