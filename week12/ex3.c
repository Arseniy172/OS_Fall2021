#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

static const char *const evval[5] = {
	"RELEASED",
	"PRESSED",
	"REPEATED"
};

int main (void){	
	printf ("Enter a shortcut. Available shortcuts: P + E, C + A + P, P + O + R\n");
	const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	struct input_event ev;
	ssize_t n;
	int fd;
	
	fd = open(dev, O_RDONLY);
	if (fd == -1){
		fprintf(stderr, "Cannot open %s: %s, \n", dev, strerror(errno));
		return EXIT_FAILURE;
	}
	
	int P_times = 0, E_times = 0, C_times = 0, A_times = 0, O_times = 0, R_times = 0;
	while (1) {
		n = read(fd, &ev, sizeof ev);
		if ((int )ev.code == 46){ // C
			C_times = (int)ev.time.tv_sec;
		}
		if ((int )ev.code == 30){ // A
			A_times = (int)ev.time.tv_sec;
		}
		if ((int )ev.code == 24){ // O
			O_times = (int)ev.time.tv_sec;
		}
		if ((int )ev.code == 25){ // P
			P_times = (int)ev.time.tv_sec;
			if (C_times == A_times && A_times == P_times){
                P_times=0, E_times = 0, C_times= 0, A_times = 0, O_times = 0, R_times = 0;
				printf("Get some cappuccino!\n");
			}
		}
		if ((int )ev.code == 18 ){ // E
			E_times = (int)ev.time.tv_sec;
			if (P_times == E_times){
                P_times=0, E_times = 0, C_times= 0, A_times = 0, O_times = 0, R_times = 0;
				printf("I passed the Exam!\n");
			}
		}
		if ((int )ev.code == 19){ // R
			R_times = (int)ev.time.tv_sec;
			if (P_times == O_times && O_times == R_times) {
                P_times=0, E_times = 0, C_times= 0, A_times = 0, O_times = 0, R_times = 0;
				printf("Periodical organized round up\n");
			}
		}
	}


	fflush(stdout);
	fprintf(stderr, "%s.\n", strerror(errno));
	return EXIT_FAILURE;
  return 0;
}