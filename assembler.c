#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line
{
     int address;
    char label[10];
    char operator[10];
    char operand[10];
} l[100];
FILE *ptrin, *ptrinter,*ptrsymtab;
int i=0;
int hextodec(char a[10])
{
    int dec=0;
    for(int j=0;j<strlen(a);j++)
    {
        if(a[j]>=48 && a[j]<59)
            dec=dec*16+(a[j]-48);
        else    
            dec=dec*16+(a[j]-97+10);
    }
    return dec;
}
void address_calc()
{
    int locctr;
    if(strcmp(l[0].operator,"START")==0)
        locctr=hextodec(l[0].operand);
    for(int j=0;j<i;j++)
    {
        l[j].address=locctr;
        fprintf(ptrinter,"%x %s %s %s\n",l[j].address,l[j].label,l[j].operator,l[j].operand);
        if(strcmp(l[j].label,"**")!=0 &&j!=0)
            fprintf(ptrsymtab,"%s %x\n",l[j].label,l[j].address);
        printf("%x %s %s %s\n",l[j].address,l[j].label,l[j].operator,l[j].operand);
        if(strcmp(l[j].operator,"RESW")==0)
            locctr+=hextodec(l[j].operand)*3;
        else if(strcmp(l[j].operator,"RESB")==0)
            locctr+=hextodec(l[j].operand);
        else if(strcmp(l[j].operator,"BYTE")==0)
            locctr+=strlen(l[j].operand);
        else if(strcmp(l[j].operator,"START")!=0)
            locctr+=3;
    }
}
void assemble()
{
    while(feof(ptrin)==0)
    {
       fscanf(ptrin,"%s%s%s",l[i].label,l[i].operator,l[i].operand);
       i++; 
    }
    address_calc();
    fclose(ptrin);
    fclose(ptrinter);
    fclose(ptrsymtab);
}
int main()
{
    ptrin=fopen("./input.txt","r");
    ptrinter=fopen("./Intermediate.txt","w");
    ptrsymtab=fopen("./symtab.txt","w");
    if(ptrin==NULL||ptrinter==NULL||ptrsymtab==NULL)
    {
        printf("Unable to find required files\n");
        exit(1);
    }
    assemble();
    return 0;
}
