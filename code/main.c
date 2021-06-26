#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
void word_input();
void hangman_layout();
void words_layout();

int main(char word[256], _Bool verify_word){
    system("clear");
    printf("THE HANGMAN GAME!\n");
    printf("-----------------\n\n");
    if (verify_word){
        word_input();
    }
    else {
        printf("Carregando palavra...\n");
        sleep(2);
        printf("Palavra adicionada!\n");
        sleep(1);
        system("clear");
        hangman_layout(strlen(word), word);
    }
}

void word_input(void){
    char word[256];
    do{
        printf("Jogador 1 - Digite uma palavra: ");
        fgets(word, sizeof(word), stdin);

    }while(strlen(word) < 3);
    
    main(word, false);
}
void hangman_layout(int len, char word[256]){
    printf("THE HANGMAN GAME!\n");
    printf("-----------------");
    printf("\n\n\n|___\n|  O\n| /|\\\n| / \\ ");
    words_layout(len, word);

}
void words_layout(int len, char word_to_lines[256]){
    char palavra[256];
    strcat(palavra, word_to_lines);
    printf(" ");
    for (int i = 0; i < strlen(word_to_lines) - 1; i++){
        if(word_to_lines[i] == ' '){
            word_to_lines[i] = '*';
            printf(" %c ", word_to_lines[i]);
        }
        else {
            word_to_lines[i] = '_';
            printf("%c ", word_to_lines[i]);
        }
        if(i + 1 == strlen(word_to_lines) - 1){
            printf("\n");
        }
    }

}
