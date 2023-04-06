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
		fprintf(stderr,"provide source and destination\n");
		return -1;
	}
	file=open(argv[1], O_CREAT|O_WRONLY,0777);
	if(file == -1){
		fprintf(stderr,"cannot open source\n");
		return -1;
	}
	write(file, &buffer, count);

	close(file);
	return 0;

 }
