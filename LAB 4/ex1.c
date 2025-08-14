#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        write(STDERR_FILENO, "Usage: ./mygrep <word> <filename>\n", 34);
        exit(1);
    }

    int fd = open(argv[2], O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char line[BUFFER_SIZE];
    int bytesRead;
    int linePos = 0;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            char c = buffer[i];
            line[linePos++] = c;

            if (c == '\n' || linePos >= BUFFER_SIZE - 1) {
                line[linePos] = '\0';
                if (strstr(line, argv[1]) != NULL) {
                    write(STDOUT_FILENO, line, strlen(line));
                }
                linePos = 0;
            }
        }
    }

    close(fd);
    return 0;
}

