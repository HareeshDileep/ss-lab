#include <stdio.h>

int main(void) {
  int p, r;
  
  printf("Enter no. of processes : ");
  scanf("%d", &p);
  printf("Enter no. of resources : ");
  scanf("%d", &r);
  int alloc[p][r], max[p][r], need[p][r], avail[r];
    int process[p], g=0, f[p];
  printf("Alloc Matrix:\n");
  for(int i=0; i<p; i++) {
    for(int j=0; j<r; j++) {
      scanf("%d", &alloc[i][j]);
    }
  }

  printf("Max Matrix:\n");
  for(int i=0; i<p; i++) {
    for(int j=0; j<r; j++) {
      scanf("%d", &max[i][j]);
    }
  }
  
  for(int i=0; i<r; i++) {
      scanf("%d", &avail[i]);
  }
  


  //Need matrix calculation
  for(int i=0; i<p; i++) {
    for(int j=0; j<r; j++) {
      need[i][j] = max[i][j] - alloc[i][j];
    }
  }
  int flag2;
  while(1) {
    flag2 = 1;
    for(int i=0; i<p; i++) {
        if(f[i] == 0) {
            int flag = 0;
            for(int j=0; j<r; j++) {
                if(need[i][j] > avail[j]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                process[g++] = i;
                for(int k=0; k<r; k++) {
                    avail[k] = avail[k] + alloc[i][k];
                }
                f[i] = 1;
            }
        }
    }
    for(int i=0; i<p; i++) {
        if (f[i] == 0) {
            flag2=0;
        }
    }
    
    if(flag2 == 1) {
        break;
    }

  }
  
    for(int i=0; i<=g; i++) {
        printf("P%d ", process[i]);
    }
    printf("\n");

  return 0;
}
