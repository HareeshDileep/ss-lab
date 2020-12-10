#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int locations[30],n,n2,end,head_loc,head_index;
int time_taken(int mode)
{
    int sum=0;
    if(mode==1)
    {
        for(int i=0;i<n-1;i++)
         sum=sum+abs(locations[i]-locations[i+1]);
    }
    else if(mode==2)
        sum=abs(head_loc-locations[n-1])+abs(locations[n-1]-locations[0]);
    else 
        sum=abs(head_loc-end)+abs(0-end)+abs(0-locations[head_index-1]);
    return sum;
}
void sort()
{
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(locations[j]>locations[j+1])
            {
                int temp=locations[j];
                locations[j]=locations[j+1];
                locations[j+1]=temp;
            }
 }
void duplicate()
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j&&locations[i]==locations[j])
            {
                int k;
                for(k=j;k<n;k++)
                locations[k]=locations[k+1];
                n--;
            }
    for(int i=0;i<n;i++)
        if(locations[i]==head_loc)
            head_index=i;
}
void prepare(int mode)
{
    if(mode==1)//SCAN
    {
        locations[n]=end;
        n=n+1;
    }
    else// C-SCAN
    {
        locations[n]=0;
        locations[n+1]=end;
        n=n+2;
    }
    sort();
    duplicate();
}
void fcfs()
{
    duplicate();
    printf("THE ORDER IS:\n");
    for(int i=0;i<n;i++)
    printf("%d->",locations[i]);
}
void scan()
{
    prepare(1);
    printf("HEAD IS CURRENTLY MOVING FROM L TO R\nTHE ORDER IS:\n");
    int i=head_index,temp=-1,q=0;
    temp=i;
    while(i!=n)
    {
        printf("%d->",locations[i]);
        i++;
    }
    i=temp;
    if(temp-1>=0)
        i=temp-1;
    while(i>=0)
    {
        printf("%d->",locations[i]);
        i--;
    }
}
void cscan()
{
    prepare(2);
    printf("HEAD IS CURRENTLY MOVING FROM L TO R\nTHE ORDER IS:\n");
    int i=head_index,temp=-1;
    while(i!=n)
    {
        printf("%d->",locations[i]);
        i++;
    }
    i=0;
    while(locations[i]<head_loc)
    {
        printf("%d->",locations[i]);
        i++;
    }
}
void menu()
{
    char loc_string[100];
    int input,i=0,j=1;
    printf("\n\nEnter the end position of the disk: ");
    scanf("%d",&end);
    printf("\nEnter the locations seperated by spaces: ");
    fgets(loc_string,100,stdin);//Extra statement because of strange error
    fgets(loc_string,100,stdin);
    char* token=strtok(loc_string," ");
    while(token!=NULL)
    {
        sscanf(token,"%d",&locations[j]);
        token=strtok(NULL," ");
        j++;
    }
    n=j;
    n2=j;
    printf("Enter the head location: ");
    scanf("%d",&head_loc);
    locations[0]=head_loc;
    printf("\n1.FCFS\n2.SCAN\n3.CSCAN\n0.EXIT\nCHOOSE ALGORITHM: ");
    scanf("%d",&input);
    printf("\n\n");
    switch(input)
    {
        case 1:fcfs();
            break;
        case 2:scan();
            break;
        case 3:cscan();
            break;
        case 0: exit(0);
        default:menu();
    }
    printf("STOP");
    printf("\n\nSEEK TIME: %d",time_taken(input));
    printf("\nAVERAGE SEEK TIME: %d",time_taken(input)/n2);
    menu();
}
int main()
{
    menu();
    return 0;
}
