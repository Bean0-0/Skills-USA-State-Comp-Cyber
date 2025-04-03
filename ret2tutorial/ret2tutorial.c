#include <stdio.h>
#include <string.h>
#include <ctype.h>

int upkeep() {
    // IGNORE THIS
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    return 0;
}

void win() {
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
    fclose(f);
}

void ask_question(const char* question, const char* options[], const char correct_answer) {
    char user_answer;
    do {
        printf("%s\n", question);
        for (int i = 0; i < 4; i++) {
            printf("%c) %s\n", 'A' + i, options[i]);
        }
        printf("Your answer (A/B/C/D): ");
        scanf(" %c", &user_answer);
        user_answer = toupper(user_answer);
        
        if (user_answer != correct_answer) {
            printf("Wrong, try again\n\n");
        }
    } while (user_answer != correct_answer);
    printf("Correct!\n\n");
}

int main() {
    upkeep();

    char message[32];
    char choice;
    printf("Howdy! Welcome to ret2tutorial! Is this your first time doing a pwn challenge? Y/N:\n");
    scanf(" %c", &choice);
    getchar();

    if (choice == 'Y' || choice == 'y') {
        printf("Cool, let's start from the very beginning then!\n");
        printf("Here's a great site to learn how to do pwn: https://ir0nstone.gitbook.io/notes\n\n");

        const char* q1_options[] = {"Stack and Heap", "RAM and ROM", "CPU and GPU", "Cache and Register"};
        ask_question("Which two sections of program memory are stored in RAM?", q1_options, 'A');

        const char* q2_options[] = {"Heap", "Stack", "Register", "Cache"};
        ask_question("In a typical C program, where are local variables stored if they are not dynamically allocated?", q2_options, 'B');

        const char* q3_options[] = {"Pushed", "Pulled", "Copied", "Linked"};
        ask_question("Every time a function is called, the variables and parameters are ____ onto the stack.", q3_options, 'A');

        const char* q4_options[] = {"Popped", "Deleted", "Removed", "Cleared"};
        ask_question("When the function is done, those values are then _____ off the stack.", q4_options, 'A');

        const char* q5_options[] = {"rax, rbx, rcx, rdx, rsi, rdi", "rdi, rsi, rdx, rcx, r8, r9", "r1, r2, r3, r4, r5, r6", "eax, ebx, ecx, edx, esi, edi"};
        ask_question("What is the calling convention for function arguments in x86-64?", q5_options, 'B');

        const char* q6_options[] = {"4 bytes", "8 bytes", "16 bytes", "32 bytes"};
        ask_question("How many bytes in size is a register in 64-bit architecture?", q6_options, 'B');

        const char* q7_options[] = {"Segfault", "Coconut Mall", "Undefined Behavior", "Kernel Panic"};
        ask_question("What happens when software attempts to access a restricted area of memory?", q7_options, 'A');

        const char* q8_options[] = {"Buffer Overflow", "Integer Overflow", "Stack Overflow", "Heap Corruption"};
        ask_question("What's it called when you write data into a buffer beyond its allocated memory size?", q8_options, 'A');

        const char* q9_options[] = {"checksec", "file", "objdump", "readelf"};
        ask_question("What bash script would you use to check the security properties of executables?", q9_options, 'A');

        const char* q10_options[] = {"Big endian", "Little endian", "Mixed endian", "Middle endian"};
        ask_question("In computing, endianness is the order in which bytes are transmitted. For example, 0x412324 is in which endianness?", q10_options, 'B');

	const char* q12_options[] = {"rax", "rbx", "rsp", "rip"};
        ask_question("Which register would you need to write to so that you could change the next machine instruction in x86-64 architecture?", q12_options, 'D');

        const char* q11_options[] = {"32 bytes", "36 bytes", "40 bytes", "44 bytes"};
        ask_question("Say you have a buffer array buf[32]. How many bytes of buffer would you need to write to overflow into the rip register?", q11_options, 'C');

        const char* q13_options[] = {"info functions", "list functions", "show functions", "print functions"};
        ask_question("Using gdb (GNU Debugger), what command would you use to dump the names and types of known defined functions?", q13_options, 'A');

        const char* q14_options[] = {"scanf", "fgets", "gets", "read"};
        ask_question("What C function reads in a line from stdin of unlimited size until it receives a terminating newline or EOF?", q14_options, 'C');

        printf("Congratulations! You've completed all the questions.\n");
        printf("Now let's see if you can solve the challenge.\n");
        printf("Uh-oh spaghetti-o's! I'm trying to fit an unlimited number of input characters into a 32 byte array, how could this ever go wrong?\n");
        getchar(); 
        gets(message);
        printf("Your message: %s\n", message);

    } else if (choice == 'N' || choice == 'n') {
        printf("Cool! Let's just skip to the challenge part then.\n");
        printf("Uh-oh spaghetti-o's! I'm trying to fit an unlimited number of input characters into a 32 byte array, how could this ever go wrong?\n");
        gets(message);
        printf("Your message: %s\n", message);
    } else {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    printf("Exiting...\n");
    return 0;
}
