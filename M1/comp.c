#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc , char * argv[])
{
if(argc!=4)
{
printf("somthing worng with varibles amount\n");
exit(-1);
}
char* filename1=argv[1];
char* filename2=argv[2];
int fd1;
int fd2;
char* buffer1[501];
char* buffer2[501];
int size1,size2,i=0;
if(fd1=open(filename1,O_RDONLY)<0)
{
printf("error opening file %s\n",filename1);
exit(-2);
}
if(fd2=open(filename2,O_RDONLY)<0)
{
printf("error opening file %s\n",filename2);
exit(-2);
}
size1=read(fd1,buffer1,500);
size2=read(fd2,buffer2,500);
if(size1==-1||size2==-1)
{
printf("error reading files\n");
exit(-3);
}
if(size1!=size2)
{
return 1;
}
while(buffer1[i])
{
if(buffer1[i]!=buffer2[i])
return 1;
i++;
}
return 2;
}
