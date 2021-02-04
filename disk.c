#include <stdio.h>
#include <stdlib.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

void fcfs() {
    printf("FCFS\n");
    int init, n, s=0;
    printf("Enter no. of request : ");
    scanf("%d", &n);
    int arr[n+1];
    printf("Enter initial head position : ");
    scanf("%d", &arr[0]);
    printf("Enter request sequence : ");
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Scheduled sequence : ");
    for(int i=1; i<=n; i++) {
        printf("%d ", arr[i]);
        s += abs(arr[i-1]-arr[i]);
    }
    printf("\nTotal seek time : %d", s);
    printf("\nAverage seek time : %d\n", s/n);
}

void scan() {
    printf("SCAN\n");
    int init, final, n, s=0, pos=0, mid;
    printf("Enter no. of request : ");
    scanf("%d", &n);
    int arr[n], arr2[n+2];
    printf("Enter initial head position : ");
    scanf("%d", &init);
    printf("Enter disk end position : ");
    scanf("%d", &final);
    printf("Enter request sequence : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n-1; i++)       
        for (int j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1]) 
                swap(&arr[j], &arr[j+1]);
                
                
    int w = -1;
    while(arr[++w] <= init);
    arr2[pos++] = init;
    printf("Scheduled Sequence : ");
    for(int i=w; i<n; i++) {
        arr2[pos++] = arr[i];
        printf("%d ", arr[i]);
    }
    arr2[pos++] = final;
    for(int i=w-1; i>-1; i--) {
        arr2[pos++] = arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=1; i<pos; i++) {
        s += abs(arr2[i-1]-arr2[i]);
    }
    printf("\nTotal seek time : %d", s);
    printf("\nAverage seek time : %d\n", s/n);
    
}

void cscan() {
    printf("CSCAN\n");
    int init, final, n, s=0, pos=0, mid;
    printf("Enter no. of request : ");
    scanf("%d", &n);
    int arr[n], arr2[n+2];
    printf("Enter initial head position : ");
    scanf("%d", &init);
    printf("Enter disk end position : ");
    scanf("%d", &final);
    printf("Enter request sequence : ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n-1; i++)       
        for (int j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1]) 
                swap(&arr[j], &arr[j+1]);
                
                
    int w = -1;
    while(arr[++w] <= init);
    arr2[pos++] = init;
    printf("Scheduled Sequence : ");
    for(int i=w; i<n; i++) {
        arr2[pos++] = arr[i];
        printf("%d ", arr[i]);
    }
    arr2[pos++] = final;
    arr2[pos++] = 0;
    for(int i=0; i<w; i++) {
        arr2[pos++] = arr[i];
        printf("%d ", arr[i]);
    }
    printf("\n");
    for(int i=1; i<pos; i++) {
        s += abs(arr2[i-1]-arr2[i]);
    }
    printf("\nTotal seek time : %d", s);
    printf("\nAverage seek time : %d\n", s/n);
    
}

int main() {
    int choice;
    while(1) {
        printf("Choice : ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                fcfs();
                break;
            case 2:
                scan();
                break;
            case 3:
                cscan();
                break;
            default:
                return 0;
        }
    }
    return 0;
}
