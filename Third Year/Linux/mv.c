#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 50

int main(int argc,char **argv){
	int file[2];
	char buffer[BUFFER_SIZE];
	int count=1;
	if(argc!=2){
		fprintf(stderr,"provide source and destination\n");
		return -1;
	}
	file[0]=open(argv[1], O_RDONLY,0777);
	if(file[0] == -1){
		fprintf(stderr,"cannot open source\n");
		return -1;
	}
	file[1]=open(argv[2],O_CREAT,0777);
	if(file[1] == -1){
		close(file[0]);
		fprintf(stderr,"cannot open destination\n");
		return -1;
	}
	while ((count = read(file[0], buffer, BUFFER_SIZE)) > 0)
    		write(file[1], &buffer, count);

	remove(argv[1]);
	close(file[0]);
	close(file[1]);
	return 0;

 }
