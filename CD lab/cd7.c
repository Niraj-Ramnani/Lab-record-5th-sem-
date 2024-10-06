// write a c program to implement lexical analyzer to recognize keyword , datatype , number , parenthesis , operator
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    FILE *fp;
    char ch[100];
    char str[100];
    int kcount = 0, dcount = 0, opcount = 0, pcount = 0, ncount = 0;
    int i;

    char keyword[32][10] = {
	"auto", "break", "case", "char", "const", "continue", "default", "do",
	"int", "long", "register", "return", "short", "signed", "sizeof", "static",
	"struct", "switch", "typedef", "union", "unsigned", "void", "volatile",
	"while", "for", "goto", "if", "else", "enum", "extern", "main"
    };

    char operators[18][3] = { "=", "-", "*", "/", "%", "+", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!", "^", "+=", "-=" };
    char datatype[5][10] = { "int", "char", "float", "double", "void" };
    char parenthesis[6][3] = { "(", ")", "[", "]", "{", "}" };
	clrscr();
    fp = fopen("C:\\TURBOC3\\BIN\\test4.txt", "w");
    if (fp == NULL) {
	printf("Error opening file for writing");
	
    }

    printf("Enter the data for the file:\n");
    fgets(str, sizeof(str), stdin);
    fprintf(fp, "%s", str);
    fclose(fp);

    fp = fopen("C:\\TURBOC3\\BIN\\test4.txt", "r");
    if (fp == NULL) {
	printf("Error opening file for reading");
	
    }

    while (fscanf(fp, "%s", ch) != EOF) {
	
	for (i = 0; i < 18; i++) {
	    if (strcmp(operators[i], ch) == 0) {
		opcount++;
		break;
	    }
	}

	for (i = 0; i < 32; i++) {
	    if (strcmp(keyword[i], ch) == 0) {
		kcount++;
		break;
	    }
	}

	for (i = 0; i < 5; i++) {
	    if (strcmp(datatype[i], ch) == 0) {
		dcount++;
		break;
	    }
	}

	for (i = 0; i < 6; i++) {
	    if (strcmp(parenthesis[i], ch) == 0) {
		pcount++;
		break;
	    }
	}

	if (isdigit(ch[0])) {
	    ncount++;
	}
    }

    fclose(fp);

    printf("Total number of operators in the file: %d\n", opcount);
    printf("Total number of keywords in the file: %d\n", kcount);
    printf("Total number of parentheses in the file: %d\n", pcount);
    printf("Total number of data types in the file: %d\n", dcount);
    printf("Total number of numeric values in the file: %d\n", ncount);
getch();
}
