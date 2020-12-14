#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int pid, spid, fd, size, j=0, stop =0;
	char* config_filename = argv[1];
	char* buff[501], buff1[501];
	char* dir_path, dir_in, dir_exp;
	

	if(argc !=2)
		exit(1);


//	if(fd =  open(config_filename,O_RDONLY)<0)
//	{
//		printf("\nerror opening file %s\n",config_filename);
//		exit(1);
//	}
	
//	size = read(fd,buff,500);
/*	for (int i = 0; i < size; i++)
	{
		if (buff[i] == '\n') {
			stop++;
		}
		else {
			buff1[j] = buff[i];
			buff1[j + 1] = '\0';
		}
		j++;
		if (stop == 1)
		{
			dir_path = (char*)malloc(sizeof(char) * i);
			strcpy(dir_path, buff1);
			j = 0;
			stop++;
		}
		if (stop == 3)
		{
			dir_in = (char*)malloc(sizeof(char) * j);
			strcpy(dir_in, buff1);
			j = 0;
			stop++;
		}

	}*/
	dir_exp = (char*)malloc(sizeof(char) * j);
	strcpy(dir_exp, buff1);

	DIR * dir = opendir(dir_path);
	struct dirent * mydirent = NULL;
	//while(NULL != (mydirent = readdir(dir)))
	//{
	//spid = fork();
	//if(spid == 0)
	//	break;
	//}
	
	//if(spid == 0)
	//{
        char* std_name = (char*)malloc(sizeof(mydirent->d_name));
	std_name = mydirent->d_name;
	printf("%s", std_name);
	//execl(gcc std_name.c -o main.out);
	//}
return 0;
}
