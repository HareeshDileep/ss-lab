#include <stdio.h>
#include <string.h>

struct Dir {
	char dname[10], filename[10][10];
	int fno;
} file; 

int main() {
	int i, ch;
	char fsearch[20];
  int flag;
	printf("Enter the name of directory : ");
	scanf("%s", file.dname);
  printf("Select Operation: \n 1. INSERT FILE \n 2. DELETE FILE \n 3. DISPLAY FILES \n 4. SEARCH FILE\n 5. EXIT \n");
	while(1) {
	  printf(">> ");
    scanf("%d", &ch);
	  switch(ch) {
		  case 1:   printf("[NEW] File Name : ");
				        scanf("%s", file.filename[file.fno]);
				        file.fno++;
				        break;

		  case 2:   printf("[DELETE] File Name : ");
				        scanf("%s", fsearch);
				        for(i=0;i<10;i++) {
					        if(strcmp(fsearch,file.filename[i])==0) {
						        strcpy(file.filename[i],"NULL");
						        printf("File %s is deleted\n", fsearch);
						        break;
				        	}
				        }
				        break;

		  case 3:   printf("Files in directory %s:\n", file.dname);
				        for(i=0;i<file.fno;i++) {
                  if(strcmp("NULL",file.filename[i])==0) continue;
					        printf("%s  ", file.filename[i]);
				        }
                printf("\n");
				        break;
		  
      case 4:   printf("[SEARCH] File Name : ");
				        scanf("%s",fsearch);
                flag = 1;  
				        for(i=0;i<10;i++) {
					        if(strcmp(fsearch,file.filename[i])==0) {
						        printf("File %s is found\n", file.filename[i]);
                    flag = 0;
                  }
                }
                if(flag) {
                  printf("File not found\n");
                }
                break;
      
      case 5:   return 0;
                break;
    }
	}
	return 0;
}
