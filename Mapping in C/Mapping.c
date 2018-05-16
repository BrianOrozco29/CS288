#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>

#define NUMINTS (1000)
#define FILESIZE (NUMINTS * sizeof(int))

int main (int argc, char *argv[]){


        int lines = atoi(argv[2]); //number of lines specified by command line arg
	int file;
	int i;

	char *p;
	char *map;
	/* opening existing file to be read from */

	file = open(argv[3], O_RDONLY);
	
	if (file == -1){ //error checking for opening file
		printf("file cannot be opened");
		return -1;
	}

	map = mmap(0, FILESIZE, PROT_READ, MAP_SHARED, file, 0);
	if (map == MAP_FAILED){
		close(file);
		perror("Error mapping file");
		exit(EXIT_FAILURE);
	}


	/* reading existing file one line at a time */

	
	for(i = 0; i <= NUMINTS; i++ ){
			if(map[i] != '\n'){
				printf("%c", map[i]);
			}	
			else{	
				if(lines > 0){
					printf("\n");
					lines--;
					continue;
				}
				else{
					break;
				}
			}
		
	

	}
		
	

	if(munmap(map, FILESIZE) == -1){
		perror("Error unmapping file");
	}

	close(file);
	return 0;
}
