#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct  dir
{
  char dname[60];
  char files[80][80];
};
struct dir d[50];
void sub()
{
  printf("\n 1)Create Directory\n 2)Create File\n 3)Display files\n 4)Delete directory\n 5)Delete file\n 6)Search\n 0)Exit\n\n Select Option: ");
  int option;
  char dname[50],file_name[50];
  scanf("%d",&option);
  switch(option)
  {
    case 0: exit(0);
            break;
case 1: printf("Enter the name of the directory: ");
                 scanf("%s",dname);
              for(int i=0;i<50;i++)
               if(strcmp(d[i].dname,"\0")==0)
              {
                strcpy(d[i].dname,dname);
                sub();
              }
            printf("empty");
            break;
case 2: printf("Select the directory to store file:");
                   scanf("%s",dname);
                  for(int i=0;i<50;i++)
                {  
                 if(strcmp(d[i].dname,dname)==0)
               {
                printf("Enter the filename: ");
                scanf("%s",file_name);
                for(int j=0;j<50;j++)
                  if(strcmp(d[i].files[j],"\0")==0)
                  {
                    strcpy(d[i].files[j],file_name);
                    printf("File is created");
                    sub();
                  }
              }
            }
            printf("Directory is unavailable");
            break;
 case 3: printf("Select the directory to display files: ");
              scanf("%s",dname);
              for(int i=0;i<50;i++)
              {
                if(strcmp(d[i].dname,dname)==0)
                {
                  for(int j=0;j<50;j++)
                      if(strcmp(d[i].files[j],"\0")!=0)
                        printf("%s\n",d[i].files[j]);
                  sub();
                }
              }
              printf("Directory is unavailable");
              break;
case 4: printf("Select directory to delete: ");
                    scanf("%s",dname);
                for(int i=0;i<50;i++)
                  if(strcmp(d[i].dname,dname)==0)
                 {
                   strcpy(d[i].dname,"\0");
                   printf("Directory is deleted");
                   sub();
                }
              break;
case 5: printf("Select directory to delete file: ");
                        scanf("%s",dname);
                        for(int i=0;i<50;i++)
                    {
                        if(strcmp(d[i].dname,dname)==0)
                     {
                          printf("Enter the filename: ");
                          scanf("%s",file_name);
                        for(int j=0;j<50;j++)
                         if(strcmp(d[i].files[j],file_name)==0)
                      {
                        strcpy(d[i].files[j],"\0");
                        printf("The file is deleted");
                        sub();
                     }
                   printf("File is not available");
                  sub();
                }
               }
              printf("Directory is unavailable");
              break;
case 6: printf("Enter file to search for: ");
                    scanf("%s",file_name);
                   for(int i=0;i<50;i++)
                 {
                    for(int j=0;j<50;j++)
                  {
                  if(strcmp(d[i].files[j],file_name)==0)
                {
                printf("File '%s' found in dir '%s'\n",file_name,d[i].dname);
                strcpy(dname,"#FOUND");
              }
             }
            }
                if(strcmp(dname,"#FOUND")!=0)
                  printf("File is unavailable");
                break;
     default: sub();
  }
  sub();
}
int main()
{
  sub();
  return 0;
}
