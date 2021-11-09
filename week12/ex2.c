#include <stdio.h>
#include <errno.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static const char *const evval[5] = {
  "RELEASED",
  "PRESSED",
  "REPEATED"
};

int main (void){
  const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
  struct input_event ev;
  ssize_t n;
  int fd;
  
  fd = open(dev, O_RDONLY);
  if (fd == -1){
    fprintf(stderr, "Cannot open %s: %s, \n", dev, strerror(errno));
    return EXIT_FAILURE;
  }
  while (1) {
    n = read(fd, &ev, sizeof ev);
    if ((int )ev.type != 4 && (int)ev.code != 0){
      printf(" Type: %s  Value: %d Code: 0x%04x (%d) \n", evval[(int )ev.value], (int )ev.value, (int )ev.code, (int )ev.code);
    }
  }
  
  fflush(stdout);
  fprintf(stderr, "%s.\n", strerror(errno));
  return EXIT_FAILURE;
  return 0;
}