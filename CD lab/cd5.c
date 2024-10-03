//aim : To write a c program to calculate no of operators in a file taking the input from the user
#include<stdio.h>
#include<conio.h>
#include<string.h>
void main(){
FILE *fp;
int count = 0,i;
char ch[100];
char str[100];
char operators[18][10] = { "=" , "-" ,"*" , "/" , "%" , "+", "==" , "!=" , ">" , "<" ,">=" , "<=" , "&&" , "||" ,"!" ,"^" , "+=" , "-="

};
clrscr();
fp = fopen("C:\\TURBOC3\\BIN\\test3.txt" , "w");
printf("Enter the data for the file \n");
fgets(str, sizeof(str), stdin);

    fprintf(fp, "%s", str);

    fclose(fp);
fp = fopen("C:\\TURBOC3\\BIN\\test3.txt" , "r");
while((fscanf(fp,"%s",ch))!=EOF){
for(i = 0; i<17; i++){
if(strcmp(operators[i],ch)==0){
count++;
}
}}
fclose(fp);
printf("total no of operators in the file are %d" , count);
getch();
}