#include <stdio.h>
#include <string.h>

int upkeep() {
        // IGNORE THIS
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}


int admin = 0;

void useful_gadgets() {
	asm(
		"pop %rdi\n"
		"ret\n"
		"pop %rsi\n"
		"ret\n"
		"pop %rdx\n"
		"ret\n"
	);
}

void set_admin(int a, int b, int c) {
	if (a == 1 && b == 2 && c == 3) {
		admin = 1;
		puts("You are now an admin!");
	}
	else {
		puts("You are not permitted to become an admin!");
		puts("Did you try using ROP gadgets?");
	}
}

void win() {
	if (admin == 1) {
		asm(
      "andq $-16, %rsp"
    );

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

        fgets(message, 128, stdin);

        printf("Your message: %s\n", message);

        printf("Exiting...\n");
}

