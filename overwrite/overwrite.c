#include <stdio.h>
#include <string.h>

int upkeep() {
        // IGNORE THIS
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}

void win() {
	char flag[64];
	FILE* f = fopen("flag.txt", "r");
	if (!f) {
		perror("Could not read the flag!");
		return;
	}
	fgets(flag, sizeof(flag), f);
	puts(flag);
}

int main() {
	upkeep();

	char username[16] = "user\n";
	char nickname[16];

	puts("Enter a nickname here:");

	fgets(nickname, 32, stdin);

	printf("\nUsername is: %s", username);
	printf("Nickname is: %s\n", nickname);

	// You can't access the flag unless you are an admin :)
	if (strcmp(username, "admin\n") == 0) {
		puts("You are an admin! Here's your flag:");
		win();
	}

	printf("Exiting...\n");
}

