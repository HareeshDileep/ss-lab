#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char path[200];
char command[50];
int current_dir_id;
void console();
struct Dir
{
    char dirname[200];
    char files[20][200] ;
    int parent_id;
    int file_count;
    int subdir_count;
    int dir_id;
};
struct Dir d[30];

void back()
{
  current_dir_id=d[current_dir_id].parent_id;
  int k=strlen(path)-1;
  while(path[k]!='/')
    k--;
  path[k]='\0';
  console();
}

void help()
{
  printf("HELP MENU\n");
  printf("cd                         :Change directory\n");
  printf("cd ..                      :Go to parent directory\n");
  printf("ls                         :Directory listing\n");
  printf("mkdir 'directory_name'     :Make directory\n");
  printf("touch 'file_name'          :Make file\n");
  printf("rmdir 'directory_name'     :Remove directory\n");
  printf("rm 'file_name'             :Remove file\n");
  console();
}

void remove_file(int i)
{
  char filename1[200];
  int j=0;
  while(command[i]!='\0')
  {
    filename1[j]=command[i];
    j++;
    i++;
  }

  for(int k=0;k<20;k++)
  {
    if(strcmp(filename1,d[current_dir_id].files[k])==0)
    {
      d[current_dir_id].files[k][0]='\0';
      d[current_dir_id].file_count--;
      printf("File %s deleted\n",filename1);
      console();
    }
    printf("File not found\n");
    console();
  }

}

void remove_directory(int i)
{
  char dirname1[200];
  int j=0;
  while(command[i]!='\0')
  {
    dirname1[j]=command[i];
    j++;
    i++;
  }
  for(int j=0;j<30;j++)
  {
    if(strcmp(dirname1,d[j].dirname)==0 && d[j].parent_id==current_dir_id)
    {
      d[j].dirname[0]='\0';
      d[current_dir_id].subdir_count--;
      printf("Deleted directory %s\n",dirname1);
      console();
    }
  }
  printf("Diretory not found\n");
  console();
}
void listing()
{
  printf("Displaying %d directories and %d file/s\n",d[current_dir_id].subdir_count,d[current_dir_id].file_count);
  for(int j=0;j<20;j++)
  {
    if(strcmp(d[current_dir_id].files[j],"\0")!=0)
      printf("%s   [FILE]\n",d[current_dir_id].files[j]);
  }
  for (int j=0;j<30;j++)
  {
    if(d[j].parent_id==current_dir_id &&strcmp(d[j].dirname,"\0")!=0)
      printf("%s   [DIR]\n",d[j].dirname);
  }
  console();
}
void make_file(int i)
{
  char filename1[200];
  int j=0;
  while(command[i]!='\0')
  {
    filename1[j]=command[i];
    j++;
    i++;
  }
  if(d[current_dir_id].file_count==20)
    printf("No more available space for files\n");
  for(int k=0;k<20;k++)
  {
    if(strcmp(filename1,d[current_dir_id].files[k])==0)
    {
      printf("This file already exists\n");
      console();
    }
  }
  for(int k=0;k<20;k++)
  {
    if(strcmp(d[current_dir_id].files[k],"\0")==0)
    {
      d[current_dir_id].file_count++;
      strcpy(d[current_dir_id].files[k],filename1);
      printf("File '%s' created\n",d[current_dir_id].files[k]);
      console();
    }
  }
  console();
}
void make_directory(int i)
{
  char dirname1[200];
  int j=0;
  while(command[i]!='\0')
  {
    dirname1[j]=command[i];
    j++;
    i++;
  }
  for(int k=0;k<30;k++)
  {
    if(strcmp(d[k].dirname,dirname1)==0)
    {
      printf("Directory already exists\n");
      console();
    }
  }
  for(int k=0;k<30;k++)
  {
    if(strcmp(d[k].dirname,"\0")==0)
    {
      strcpy(d[k].dirname,dirname1);
      d[k].dir_id=k;
      d[k].file_count=0;
      d[k].subdir_count=0;
      d[k].parent_id=current_dir_id;
      d[current_dir_id].subdir_count++;
      printf("New directory '%s' created.\n",d[k].dirname);
      console();
    }
  }
  printf("NO SPACE FOR NEW DIRECTORY\n");
  console();

}
void change_directory(int i)
{
  char dirname1[200];
  int j=0;
  while(command[i]!='\0')
  {
    dirname1[j]=command[i];
    j++;
    i++;
  }
  for(int m=0;m<30;m++)
  {
    if(strcmp(dirname1,d[m].dirname)==0)
    {
      current_dir_id=m;
      path[strlen(path)]='/';
      int k=strlen(path),l=0;
      while(dirname1[l]!='\0')
      {
        path[k]=dirname1[l];
        k++;
        l++;
      }
      console();
    }
  }
  printf("No such directory exists\n");
  console();
}
void console()
{
  printf("%s> ",path);
  gets(command);
  if(strcmp(command,"cd ..")==0)
    back();
  char cmdword[20];
  int i=0;
  strcpy(cmdword, "");
  while(command[i]!=' ' && command[i]!='\0')
  {
    cmdword[i]=command[i];
    i++;

  }
  cmdword[i] = '\0';
  i++;
  if(strcmp(cmdword,"cd")==0)
    change_directory(i);
  else if(strcmp(cmdword,"mkdir")==0)
    make_directory(i);
  else if(strcmp(cmdword,"touch")==0)
    make_file(i);
  else if(strcmp(cmdword,"exit")==0)
  {
    printf("Program Exited\n");
    exit(0);
  }
  else if(strcmp(cmdword,"ll")==0||strcmp(cmdword,"ls")==0)
    listing();
  else if(strcmp(cmdword,"rmdir")==0)
    remove_directory(i);
  else if(strcmp(cmdword,"rm")==0)
    remove_file(i);
  else if(strcmp(cmdword,"help")==0)
    help();

  else
  {
    printf("UNRECOGNISED COMMAND\nType 'help' to see list of commands or type the command again.\n");
    console();
  }
}
int main()
{
  strcpy(d[0].dirname,"Console/root");
  d[0].file_count=0;
  d[0].subdir_count=0;
  d[0].parent_id=-1;
  d[0].dir_id=0;
  strcpy(path,d[0].dirname);
  current_dir_id=0;
  console();
  return 0;
}
