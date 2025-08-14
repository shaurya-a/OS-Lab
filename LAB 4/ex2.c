#include <unistd.h>   // for read(), write(), close()
#include <fcntl.h>    // for open()
#include <stdlib.h>   // for exit()

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    int bytesRead, lineCount, pos;

    for (int fileIndex = 1; fileIndex < argc; fileIndex++) {
        int fd = open(argv[fileIndex], O_RDONLY);

        lineCount = 0;
        pos = 0;

        while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
            for (int i = 0; i < bytesRead; i++) {
                temp[pos++] = buffer[i];

                if (buffer[i] == '\n' || pos >= BUFFER_SIZE - 1) {
                    write(STDOUT_FILENO, temp, pos);
                    pos = 0;
                    lineCount++;

                    if (lineCount == 20) {
                        char ch;
                        read(STDIN_FILENO, &ch, 1); // wait for key
                        lineCount = 0;
                    }
                }
            }
        }

        close(fd);
    }
    return 0;
}

