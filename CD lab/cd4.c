// count total no of keyword in a file [Taking file from the user ]
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(){
FILE *fp;
int count = 0,i;
char ch[100];
char str[100];
char keyword[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "int", "long", "register", "return", "short", "signed", "sizeof", "static", 
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", 
    "while", "for", "goto", "if", "else", "enum", "extern", "main"
};
clrscr();
fp = fopen("C:\\TURBOC3\\BIN\\test.txt" , "w");
printf("Enter the data for the file \n");
fgets(str, sizeof(str), stdin);

    fprintf(fp, "%s", str);

    fclose(fp);
fp = fopen("C:\\TURBOC3\\BIN\\test.txt" , "r");
while((fscanf(fp,"%s",ch))!=EOF){
for(i = 0; i<5; i++){
if(strcmp(keyword[i],ch)==0){
count++;
}
}}
fclose(fp);
printf("total no of keywords in the file are %d" , count);
getch();
}