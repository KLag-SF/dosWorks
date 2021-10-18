#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd;
    ssize_t cc;
    char buf[BUFSIZ];
    
    if (argc < 2)
    {
        fprintf(stderr, "%s filename\n", argv[0]);
        exit(1);
    }

    fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);
    
    while ((cc = read(STDIN_FILENO, buf, sizeof(buf))) > 0)
    {
        write(STDOUT_FILENO, buf, cc);
        if (write(fd, buf, cc) < cc)
        {
            perror("Writing error");
            exit(1);
        }
    }

    close(fd);

    return 0;
}

