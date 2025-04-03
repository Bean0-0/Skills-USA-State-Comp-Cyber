#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int upkeep() {
        // IGNORE THIS
        setvbuf(stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        setvbuf(stderr, NULL, _IONBF, 0);
}

void win() {
	asm(
            "andq $-16, %rsp"
    	);

	char flag[64];
	FILE* f = fopen("flag.txt", "r");
	if (!f) {
		perror("Couldn't read the flag");
		return;
	}
	fgets(flag, sizeof(flag), f);
	puts(flag);
}

int main() {
        upkeep();

	char sel[16];
	char dir[8];
	char file[40];

        puts("Welcome to FTPwn!");
	puts("Note that uploading files requires Administrator!\n");

	while (true) {
		printf("ftpwn> ");
		fgets(sel, 15, stdin);

		// Command selection
		// upload
		if (strcmp(sel, "upload\n") == 0) {
			puts("You are not an Administrator! This incident will be reported. ");

			// TODO: IMPLEMENT REPORTING

		}
		// ls
		else if (strcmp(sel, "ls\n") == 0) {
			puts("In what directory do you want to list files?");

			printf("\n> ");
			fgets(dir, 7, stdin);
			dir[strlen(dir)-1] = 0;

			printf("Listing directory: ");
			printf(dir);
			puts("\nListing Files: ");

			// TODO: IMPLEMENT FILESYSTEM

		}
		// download
		else if (strcmp(sel, "download\n") == 0) {
			puts("Which file do you want to download:");

			printf("\n> ");
			fgets(file, 400, stdin);
			file[strlen(file)-1] = 0; //remove null terminator

			printf("Downloading file %s:\n", file);

			// TODO: IMPLEMENT FILE DOWNLOAD

		}
		// exit / quit
		else if ((strcmp(sel, "exit\n") == 0) || (strcmp(sel, "quit\n") == 0)) {
			break;
		}
		// help / ?
		else if ((strcmp(sel, "help\n") == 0) || (strcmp(sel, "?\n") == 0)) {
			puts("Commands:");
			puts("download	exit	help	ls	quit	upload	?\n");
		}
		else {
			puts("Invalid command. ");
		}
	}
        printf("Exiting...\n");
}
