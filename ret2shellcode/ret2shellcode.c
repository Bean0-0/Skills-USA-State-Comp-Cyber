#include <stdio.h>

int upkeep() {
        // IGNORE THIS
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}

int main() {
        upkeep();

	char message[80];

	printf("This is a valuable piece of information: 0x%lx\n", &message);
	puts("Enter your message:\n");

	fgets(message, 100, stdin);

        printf("Here is your message: %s\n", message);
}
