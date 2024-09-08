//Write a c program to open a file in write and read mode 
#include <stdio.h>
#include<conio.h>

void main() {
    FILE *fp;
    char str[100];
    char ch;
clrscr();

  
    printf("opening the file in write mode \n");
    fp = fopen("output.txt", "w");
    if (fp == NULL) {
	printf("Error opening file for writing\n");
    }

        printf("Enter the data for the file \n");
    fgets(str, sizeof(str), stdin);

    
    fprintf(fp, "%s", str);

   
    fclose(fp);
    printf("opening file in read mode \n");
    fp = fopen("output.txt", "r");
     if (fp == NULL) {
	printf("Error opening file for read mode\n");
    }
    while ((ch = getc(fp)) != EOF) {
	putchar(ch);
    }
    fclose(fp);

    getch();
}
