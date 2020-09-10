#include <stdio.h>
#include <string.h>
struct Dir {
	    char dirname[10], listname[10][10];
	    int lnum;
           } list; 
int main() {
        int j, ch;
	char lscan[20];
  int flag;
	printf("Enter the name of directory : ");
	scanf("%s", list.dirname);
  printf("Select Operation: \n 1. Insert file \n 2. Delete file \n 3. Display file \n 4. Search file \n 5. Exit \n");
	while(1) {
	  printf(">> ");
    scanf("%d", &ch);
	  switch(ch) 
 {
       case 1:   printf(" File Name : ");
				        scanf("%s", list.listname[list.lnum]);
				        list.lnum++;
				        break;
       case 2:   printf(" File Name : ");
				        scanf("%s", lscan);
				        for(j=0;j<10;j++) {
		 			        if(strcmp(lscan,list.listname[j])==0) 
					  {
				           strcpy(list.listname[j],"NULL");
				           printf("File %s is deleted\n", lscan);
				           break;
				          }
				        }
				        break;

       case 3:   printf("Files in directory %s:\n", list.dirname);
				        for(j=0;j<list.lnum;j++)
					{
                  if(strcmp("NULL",list.listname[j])==0) continue;
					     printf("%s  ", list.listname[j]);
				        }
                printf("\n");
				        break;
		  
       case 4:   printf("[SEARCH] File Name : ");
		        scanf("%s",lscan);
                        flag = 1;  
			   for(j=0;j<10;j++) 
			    {
		              if(strcmp(lscan,list.listname[j])==0) {
	                      printf("File %s is found\n", list.listname[j]);
                      flag = 0;
                  }
                }
                if(flag)
		{
                  printf("FILE UNAVAILABLE\n");
                }
                break;
      
      case 5:   return 0;
                break;
   }
 }
return 0;
}
