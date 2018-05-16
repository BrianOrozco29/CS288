#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	int file; //existing file
	int newfile; //created file to be copied to
	int bytecount = 0; //variable for file loop
	int bytes = atoi(argv[2]); //number of bytes specified by command line arg
	char buf[1000];	//buffer for read call

	/* opening existing file to be read from */

	file = open(argv[4], O_RDONLY);

	if (file == -1){ //error checking for opening file
		printf("file cannot be opened");
		return -1;
	}	
	
	/* assigning the created file to be written to */

	newfile = creat(argv[6], O_CREAT | 0666); //0666 refers to permissions to read and write

	if (file == -1){ //error checking for creating a new file
		printf("file cannot be created");
		return -1;
	}	

	/* reading existing file one byte at a time */
	
	bytecount = read(file, buf, bytes);
	ssize_t newf;
	while(bytecount > 0){
		if(bytecount < bytes){
			bytes = bytecount;
		}	
		
		newf = write(newfile, buf, bytes); //copying to new file
		if (newf == -1){ //error checking for writing
			printf("Copy Error");
			return -1;
		}
		bytecount = read(file, buf, bytes);

	}

	close(file);
	close(newfile);
	return 0;

}
