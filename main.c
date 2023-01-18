#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "checker.h"

void cacl(int check_num);

char* Equation;

int main() {
    Equation = (char*) malloc(1 * sizeof(char));
    if (Equation == NULL){
        printf("Mem Err.\n");
        exit(-1);
    }
    char input_str[10000];
    printf("Enter a number to cacl: ");
    scanf("%s", input_str);
    unsigned long input_len;
    input_len = strlen(input_str);
    int flag = 1;
    for (int i=0; i<input_len; i++){
        if (input_str[i] >= '0' && input_str[i] <= '9'){
            continue;
        }
        else if (input_str[i] == '-' || input_str[i] == '.'){
            flag = 0;
        }
        else {
            flag = -1;
        }
    }
    if (flag == 1){
        int search_number;
        search_number = atoi(input_str);
        cacl(search_number);
        unsigned long len;
        len = strlen(Equation);
        char* out;
        out = (char*) malloc(len * sizeof(char));
        if (out == NULL){
            printf("Mem Err.\n");
            exit(-1);
        }
        strncpy(out, Equation, len - 1);
        printf("%s\n", out);
        free(out);
        out = NULL;
    }
    else if (flag == 0){
        printf("Error Number 0: The int number need greater than 0.\n");
    }
    else if (flag == -1){
        printf("Error Number -1: Wrong Input Text.\n");
    }
    free(Equation);
    Equation = NULL;
    return 0;
}

void cacl(int check_num){
    int flag;
    char* the_equation;
    flag = SearchIfExist(check_num);
    if (flag == 1){
        the_equation = GetEquation(check_num);
        unsigned long len;
        len = strlen(the_equation);
        Equation = (char*) realloc(Equation, (len + 1) * sizeof(char));
        if (Equation == NULL){
            printf("Mem Err.\n");
            exit(-1);
        }
        strcat(Equation, the_equation);
        strcat(Equation, "+");
    }
    else {
        int a, b;
        a = check_num / 2;
        b = check_num - a;
        cacl(a);
        cacl(b);
    }
}
