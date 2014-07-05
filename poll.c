#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include "/usr/zed_macros.h"

#define TIMEOUT 5

#define len(A) (sizeof(A) / sizeof(A[0]))

int main(void) {
  struct pollfd fds[2];
  int ret;

  fds[0].fd = STDIN_FILENO;
  fds[0].events = POLLIN;
  fds[1].fd = STDOUT_FILENO;
  fds[1].events = POLLOUT;

  debug("I have %d fds", (int)len(fds));

  ret = poll(fds, 2,  TIMEOUT * 1000);

  check(ret != -1, "poll");
  check(ret, "Timed out after %d seconds", TIMEOUT);

  if (fds[0].revents & POLLIN) {
    printf("stdin is readable\n");
  }

  if (fds[1].revents & POLLOUT) {
    printf("stdout is writable\n");
  }

  return 0;

error:
  return 1;
}
