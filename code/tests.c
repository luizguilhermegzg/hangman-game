#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

int main(void){
    char str1[50] = "Olá mundo";
    char str2[50] = "Olá mundso";
    if (strcmp (str1, str2) == 0){
        printf("As frases são iguais!\n");
    }
    else {
        printf("As frases não são iguais!");
    }
    
}