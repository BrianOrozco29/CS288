#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

	int file; //existing file	
	int lines = atoi(argv[2]); //number of lines specified by command line arg

	char c;
	char word;	//buffer for read call
	

	/* opening existing file to be read from */

	file = open(argv[3], O_RDONLY);

	if (file == -1){ //error checking for opening file
		printf("file cannot be opened");
		return -1;
	}	
	
	
	/* reading existing file one line at a time */
	
	while(lines > 0){
		while( (c = read(file, &word, 1)) != '\n'){
			printf("%c", c);
		}
		lines--;
	}
	

	close(file);

	return 0;

}
