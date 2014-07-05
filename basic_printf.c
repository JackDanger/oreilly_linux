#include <stdio.h>

void print();

int main() {
  print();
}

void print() {
  const char *string1 = "hi there";
  const char *string2 = "what's up?";
  const char *string3 = "not much";
  ssize_t size;

  printf("%d: %s\n", *string1, string1);
  printf("%d: %s\n", *string2, string2);
  printf("%d: %s\n", *string3, string3);
}
