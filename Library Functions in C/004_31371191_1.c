#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[]){

		
	int lines = atoi(argv[2]); //number of lines specified by command line arg

	char c;
	

	/* opening existing file to be read from */

	FILE *file = fopen(argv[3], "r");

	if (file == NULL){ //error checking for opening file
		printf("file cannot be opened");
		return -1;
	}	
	
	
	/* reading existing file one line at a time */
	
	while(lines > 0){
		while( (c = fgetc(file)) != '\n'){
			printf("%c", c);
			if(feof(file)){
				break;
			}
		}
		if(feof(file)){
			break;
		}
		printf("\n");
		lines--;
	}


	fclose(file);

	return 0;

}

