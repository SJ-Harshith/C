#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int fd;
  char *myfifo = "/tmp/myfifo";
  char buf[1024];
  fd = open(myfifo, O_RDWR);
    read(fd, buf, 1024);
  printf("Writer: %s\n", buf);
  close(fd);
  return 0;
}