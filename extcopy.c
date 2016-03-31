//program name: extcopy.c
//purpose: copy bytes from a file to another file
//date: 3/16/16
//input/out: user enters two integers, a source file, and a target file.
// the application copies the contents according to the integers given

//error checking: program will end if user doesn't give all parameters
//program will end if soruce is not found
//program will give warning if file size is smaller than num1+num2

#include <sys/types.h>
#include <sys/stat.h> //stat()
#include <stdio.h> //input
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main (int argc, char* argv[]) {
	int fd;
	//check error for argc
	if (argc == 5) {
		//check if theres a filesource
		fd = open (argv[3], O_RDONLY);
		//set filesource to variable
		char *filesource = argv[3];
		char *filetarget = argv[4];
		int num1 = atoi(argv[1]);
		int num2 = atoi(argv[2]);
		//if theres an error with the filesource
		if (fd == -1) {
			perror("Error");
		}
		else {
			struct stat fileStat;
			stat(filesource, &fileStat);
			//if filesize is smaller than num1+num2
			if (fileStat.st_size < (num1 + num2)) {
				//if starting point is bigger than filesize
				if (num1 > fileStat.st_size) {
					printf("Error: %d is not a valid starting point\n", num1);
					exit(0);
				}
				printf("Warning: file size is smaller than (num1 + num2)\n");
				//set beginning of file to copy
				lseek(fd, num1, SEEK_SET);
				//create buffer
				char buffer[num2];
				//create new file with permissions
				int target = open(filetarget, O_TRUNC | O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				//read into buffer
				//write to end of file
				ssize_t endFile;
				while ((endFile = read(fd, buffer, fileStat.st_size)) > 0) {
					write(target, buffer, endFile);
				}
				//close file
				close(target);
				close(fd);
			}
			//if filesize is equal/biggerthan num1+num2
			else if (fileStat.st_size >= (num1 + num2)) {
				//set beginning of file to copy
				lseek(fd, num1, SEEK_SET);
				//create buffer
				char buffer[num2];
				//create new file with permissions
				int target = open(filetarget, O_TRUNC | O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
				//read into buffer # of bytes
				read(fd, buffer, num2);
				//write to new file with # of bytes
				write(target, buffer, num2);
				//close file
				close(target);
				close(fd);
			}
		}	
	}
	else {
		printf("Usage: num1 num2 filesource filetarget\n");
	}
}