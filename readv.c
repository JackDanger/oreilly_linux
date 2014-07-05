#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>
#include "/usr/zed_macros.h"

#define len(A) (sizeof(A) / sizeof(A[0]))

int main(void) {
  char first[38], second[73], third[45];
  struct iovec iov[3];
  ssize_t nr;
  int fd, i;

  fd = open("text.txt", O_RDONLY);
  check(fd != -1, "open");

  iov[0].iov_base = first;
  iov[0].iov_len = sizeof(first) + 1;
  iov[1].iov_base = second;
  iov[1].iov_len = sizeof(second) + 1;
  iov[2].iov_base = third;
  iov[2].iov_len = sizeof(third) + 1;

  nr = readv(fd, iov, 3);
  check(nr != -1, "readv");

  for (i = 0; i < 3; i++) {
    printf("%d: %s", i, (char *) iov[i].iov_base);
  }

  check(!close(fd), "close fd");

  return 0;

error:
  return 1;
}

