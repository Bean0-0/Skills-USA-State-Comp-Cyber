#include <stdio.h>
#include <string.h>

int upkeep() {
        // IGNORE THIS
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}


int admin = 0;

void set_admin() {
	admin = 1;
	puts("You are now an admin!");
}

void win() {
	if (admin == 1) {
		char flag[64];
		FILE* f = fopen("flag.txt", "r");
		if (!f) {
			perror("Could not read the flag!");
			return;
		}
		fgets(flag, sizeof(flag), f);
		puts(flag);
	}
	else {
		puts("You are not an admin, so no flag for you :(");
	}
}

int main() {
        upkeep();

        char message[16];

        puts("Enter a message:");

        fgets(message, 64, stdin);

        printf("Your message: %s\n", message);

        printf("Exiting...\n");
}

