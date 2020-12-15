#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char* argv[])
{
	int pid, spid, fd, j=0, stop =0, num_students=0;
	//char* config_filename = argv[1];
	char buff[501], buff1[501];
	char** students = (char**)malloc(sizeof(char*)*1);
	char* dir_path, *dir_in, *dir_exp;
	char student;

	if(argc !=2)
	{
		exit(1);
	}


	if((fd =  open(argv[1],O_RDONLY))<0)
	{

		printf("\nerror opening file %s\n",argv[1]);
		exit(1);
	}

int size = read(fd,&buff,500);
//printf("%d", size);

	for (int i = 0; i < size-2; i++)
//int i=0;
//while(read(fd,&buff,1) == 1)
	{

		if (buff[i] == '\n')
		 {

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
		if(buff[i] == '\0')
			break;

//i++;
	}


	dir_exp = (char*)malloc(sizeof(char) * j);
	strcpy(dir_exp, buff1);



	DIR * dir = opendir(dir_path);
	struct dirent * mydirent = NULL;
	while((mydirent = readdir(dir))!= NULL)
	{
		if((mydirent->d_type == DT_DIR) && (strcmp(".",mydirent->d_name)!=0) && (strcmp("..",mydirent->d_name)!=0))
		{

		students = (char**)realloc(students, sizeof(char*) * (++num_students));
		students[num_students - 1] = (char*)malloc(sizeof(char) * sizeof(mydirent->d_name)+1);
		strcpy(students[num_students - 1], mydirent->d_name);

	  }
	}
	for(int k=0;k<num_students;k++)
		printf("\n%s\n",students[k]);
//	printf("\n%s\n%s\n%s\n%s\n", students[0], students[1], students[2], students[3]);
//	------------------------------------------
	pid_t parent = getpid(); //Storing Daddy ;)
	pid_t children[num_students];
	pid_t child;
	pid_t baby;
	int i;
	for(i=0; i<num_students+1; i++)
	{
		if((child = fork()) == 0)
			{
				children[i] = getpid();
				break;
			}
		if(child < 0)
			{
				perror("Fork Error");
				exit(-1);
			}
			children[i]=child;
	}
	if(getppid() == parent)
		{
		if((baby = fork())<0)
		{
			perror("Fork Error");
			exit(-1);
		}
		else if ( baby == 0)
		{
			if(chdir(dir_path)<0)
			{
				perror("Fuck");
				exit(-1);
			}
			if(chdir(students[i])<0)
			{
				perror("Shit");
				exit(-1);
			}
			char studentName[sizeof(students[i])+3];
			strcpy(studentName,students[i]);
			strcat(studentName,".c");
			char* args[] = {"gcc",studentName,"-o","main.out",NULL};
			execvp("gcc",args);
		}
		}



}
