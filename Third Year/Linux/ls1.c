#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<stdlib.h>
#include<dirent.h>
#include<pwd.h>
#include <grp.h>
#include<string.h>
#include <fcntl.h>
int main(int argc, char **argv)
{
  struct passwd *pw;
  struct group *gp;
  DIR *mydir;
  char *c;
  int i,file;
  file=open(argv[2], O_WRONLY | O_CREAT | S_IRUSR | S_IWUSR,0777);
  if(file == -1){
		fprintf(stderr,"cannot open source\n");
		return -1;
  }
  struct dirent *myfile;
  struct stat fileStat;
  mydir=opendir(argv[1]);
  stat(argv[1],&fileStat); 
  while((myfile=readdir(mydir))!=NULL)
  {
    stat(myfile->d_name,&fileStat);  
    write(file, (S_ISDIR(fileStat.st_mode)) ? "d" : "-",1);
    write(file, (fileStat.st_mode & S_IRUSR) ? "r" : "-",1);
    write(file, (fileStat.st_mode & S_IWUSR) ? "w" : "-",1);
    write(file, (fileStat.st_mode & S_IXUSR) ? "x" : "-",1);
    write(file, (fileStat.st_mode & S_IRGRP) ? "r" : "-",1);
    write(file, (fileStat.st_mode & S_IWGRP) ? "w" : "-",1);
    write(file, (fileStat.st_mode & S_IXGRP) ? "x" : "-",1);
    write(file, (fileStat.st_mode & S_IROTH) ? "r" : "-",1);
    write(file, (fileStat.st_mode & S_IWOTH) ? "w" : "-",1);
    write(file, (fileStat.st_mode & S_IXOTH) ? "x" : "-",1); 
    write(file," ",1);
    pw=getpwuid(fileStat.st_uid);
    write(file,pw->pw_name,strlen(pw->pw_name));
    write(file," ",1);
    gp=getgrgid(fileStat.st_gid);
    write(file,gp->gr_name,strlen(gp->gr_name));
    write(file," ",1);
    write(file," ",1);
    write(file,myfile->d_name,strlen(myfile->d_name));
    write(file,"\n",1);
  }
  closedir(mydir);  
  return 0;
}
