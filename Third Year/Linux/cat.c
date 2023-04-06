#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 50

int main(int argc,char **argv){
	int file;
	char buffer[BUFFER_SIZE];
	int count=1;
	if(argc!=2){
		fprintf(stderr,"provide command and file name\n");
		return -1;
	}
	file=open(argv[1], O_RDONLY);
	if(file == -1){
		fprintf(stderr,"cannot open file\n");
		return -1;
	}
	while ((count = read(file, buffer, BUFFER_SIZE)) > 0)
    	write(1, &buffer, count);

	close(file);
	return 0;

 }
