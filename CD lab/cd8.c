// c program to insert and dislay entries in the symbol table 
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>
void main(){
char str[100];
char *token;
char symbol[50][50] , type[50][50];
int i,cnt = 0;
char keywords[32][10] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", 
    "int", "long", "register", "return", "short", "signed", "sizeof", "static", 
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", 
    "while", "for", "goto", "if", "else", "enum", "extern", "main"
};
char operators[18][3] = { "=", "-", "*", "/", "%", "+", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "^", "+=", "-=" };
// clrscr();
printf("Enter a string ");
 fgets(str, sizeof(str), stdin);
 str[strcspn(str, "\n")] = '\0';
token = strtok(str, " ");
while(token != NULL ){
     int is_id = 1;
     for (i = 0; i < 32; i++) {
	    if (strcmp(keywords[i], token) == 0) {
		 strcpy(symbol[cnt], token);
                strcpy(type[cnt], "keyword");
                cnt++;
                is_id = 0;
		break;
	    }
	}
      for (i = 0; i < 18; i++) {
	    if (strcmp(operators[i], token) == 0) {
		 strcpy(symbol[cnt], token);
                strcpy(type[cnt], "operator");
                cnt++;
                is_id = 0;
		break;
	    }
	}
     if(is_id){
          strcpy(symbol[cnt], token);
                strcpy(type[cnt], "identifier");
                cnt++;
     }
     token = strtok(NULL, " ");
}
 printf("\n\tSymbol Table\n");
    printf("Symbol\t\tType\n");
    for (i = 0; i < cnt; i++) {
        printf("%s\t\t%s\n", symbol[i], type[i]);
    }

}