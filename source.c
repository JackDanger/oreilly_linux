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
  struct iovec iov[3];
  ssize_t nr;
  int fd, i;
  off_t sought;

  char *lines[] = {
    "This is the first line\n",
    "I don't want to copy so much out of the book\n",
    "though the original text was about pirates which was pretty sweet.\n",
  };

  fd = open("text.txt", O_CREAT | O_WRONLY | O_RDONLY | O_APPEND, 0644);
  check(fd != -1, "open text");

  printf("opened fd %d\n", fd);

  for (i = 0; i < 3; i++) {
    iov[i].iov_base = lines[i];
    iov[i].iov_len  = strlen(lines[i]);
  }

  nr = writev(fd, iov, 3);
  check(nr != -1, "writev");

  printf("wrote %ld bytes\n", nr);

  check(!close(fd), "close fd");

  return 0;

error:
  return 1;
}

