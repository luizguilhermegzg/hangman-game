/*************************************************************************
 *  Name: hangman.c                                                      *
 *  Purpose: Play hangman in terminal.                                   *
 *  Author: L. G. Costa                                                  *
 *************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
void word_input();
int build_hangman();
void check_letter();
int check_word();

int main(char *word, _Bool not_valid){
    if (not_valid == true){
        word_input();
    }
    else if(not_valid == false){
        build_hangman(word, 0, 0);
    }
}

void word_input(void){
    char word_inputed[256];
    do{
        system("clear");
        printf("The Hangman Game!!!\n");
        printf("--------------------\n");
        printf("\n\nJogador 1 - Digite a palavra: ");
        scanf(" %[^\n]%*c", word_inputed);
    }while(strlen(word_inputed) < 2);
    
    main(word_inputed, false);    
}

int build_hangman(char *word, int choice, int parts_loose){
    char lines[strlen(word)];
    char *hanged_man[6];
    hanged_man[0] = "\n\n|___\n|  O\n| /|\\\n| / \\   ";
    hanged_man[1] = "\n\n|___\n|  O\n| /|\\\n| /    ";
    hanged_man[2] = "\n\n|___\n|  O\n| /|\\\n|   ";
    hanged_man[3] = "\n\n|___\n|  O\n| /|\n|   ";
    hanged_man[4] = "\n\n|___\n|  O\n|  |\n|   ";
    hanged_man[5] = "\n\n|___\n|  O\n|   \n|   ";
    if (parts_loose < 6) {
    do {
        system("clear");
        printf("THE HANGMAN GAME!\n");
        printf("-----------------");
        printf("%s", hanged_man[parts_loose]);
        for(int i = 0; i < strlen(word); i++){
            if (word[i] == ' '){
                lines[i] = '*';
            }
            else {
                lines[i] = '_';
            }
            printf("%c ", lines[i]);
        }
        printf("\n\n[1] Digtar palavra\n[2] Digitar letra\n\nEscolha: ");
        scanf(" %d", &choice);
    }while(choice != 1 && choice != 2);

    switch(choice){
        case 1:
            check_word(word, parts_loose);
            break;
        case 2:
            check_letter(word, parts_loose);
            break;
    }
}
    else {
        printf("\nMe desculpe jogador 2 - Você perdeu!\n");
        return 0;
    }
}

int check_word(char *word, int parts_resting){
    char check[256];
    printf("Jogador 2 - Digite a palavra: ");
    scanf(" %[^\n]%*c", check);
    if (strcmp(check, word) == 0){
        printf("\nParabéns jogador 2 - Você ganhou!!!\n");
        return 0;
    }
    else {
        build_hangman(word, 0, parts_resting + 1);
    }
}

void check_letter(char *word, int parts_resting){
    printf("Estamos aqui em check_letter()\n");
}