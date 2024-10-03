// c program to calculate no of comment in the file and remove the comment from the file
#include<stdio.h>
#include<conio.h>
void main(){
FILE  *fp;
char ch;
char prev_ch = '\0';
char str[200];
int line = 1 , cmt = 0, index = 0  ;
clrscr();
printf("Content of the file \n");
fp = fopen("C:\\TURBOC3\\BIN\\test2.txt","r");
if( fp == NULL){
printf("Error opening in the file ");}
while((ch = getc(fp)) != EOF){
putchar(ch);}
fclose(fp);
fp = fopen("C:\\TURBOC3\\BIN\\test2.txt","r");
while((ch = getc(fp)) != EOF){
if(ch == '\n') line++;
if(ch == '/' && prev_ch == '/'){
cmt++;
printf("\nThere is a comment at line %d \n",line);
while((ch = getc(fp)) != '\n'){
continue;}
}
if(ch != '/'){
str[index++] = ch;
}
prev_ch = ch;
}
printf("Total number of the comment in the file are %d ",cmt);
str[index] = '\0';
fclose(fp);
printf("\n content of the file after removing contents from the file \n");
printf("%s",str);
getch();
}