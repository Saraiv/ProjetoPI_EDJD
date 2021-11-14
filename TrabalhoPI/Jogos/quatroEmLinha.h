//Normal includes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//helpers functions
char naipeToString(int naipe);
int generateRandomInt(int min, int max);
void errorMessageGeneral();
void errorMessageGame();


char tabuleiro[6][7], jogadorSelecionado = 'X';
int rondas = 0, jogadorVencedor = -1;

void desenharTabela() {
    printf("\n");

    system("cls");

    int columnNumber = 1;
    while(columnNumber != 8)
        printf(" | %d | \t", columnNumber++);

    printf("\n");

    for(int i = 0; i < 6; i++) {
        for(int j = 1; j <= 7; j++) {
            tabuleiro[i][j] = ' ';
            printf(" | %c | \t", tabuleiro[i][j]); 
        }
        printf("\n");
    }
}

void desenharTabelaComSimbolos(int colunaTabela, int linhaTabela, char jogador) {
    system("cls");

    if(colunaTabela != -1){
        int columnNumber = 1;
        while(columnNumber != 8)
            printf(" | %d | \t", columnNumber++);

        printf("\n");

        tabuleiro[colunaTabela][linhaTabela] = jogador;

        for(int i = 0; i < 6; i++) {
            for(int j = 1; j <= 7; j++) {
                printf(" | %c | \t", tabuleiro[i][j]); 
            }
            printf("\n");
        }
    } else desenharTabela();
}

void jogada(int rondas, char jogadorSelecionado) {
    int colunaTabela = -1, linhaTabela = 0;

    do{
        printf("\nJogador %c, em que coluna quer jogar? ", jogadorSelecionado);
        scanf("%d", &colunaTabela);
    } while(colunaTabela <= 1 && colunaTabela >= 6);

    while(tabuleiro[colunaTabela][linhaTabela] != ' ') {
        if(linhaTabela >= 0) {
            linhaTabela--;
        }
    }
    
    desenharTabelaComSimbolos(colunaTabela, linhaTabela, jogadorSelecionado);
}

char trocarJogador(char jogador) {
    if (jogador == 'X') {
        return '0';
    } else {
        return 'X';
    }
    
}

//JOGO SETE
void quatroEmLinha(){
    while (jogadorVencedor != 1) {
        rondas++;
        desenharTabela();
        //cada jogada TODO
        jogada(rondas, jogadorSelecionado);
        //jogadorVencedor TODO
        jogadorSelecionado = trocarJogador(jogadorSelecionado);
    }
    system("PAUSE");
}