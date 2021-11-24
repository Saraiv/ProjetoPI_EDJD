//Numero inteiro random
int generateRandomInt(int min, int max) {
    srand((unsigned)time(NULL));
    return min + rand() % (max - min);
}

//Numero inteiro de 1 - 4 para char desde C - E - P - O  
char naipeToString(int naipe){
    /*  1 - Copas
        2 - Espadas
        3 - Paus
        4 - Ouros
        else = null
    */
    if(naipe == 1) return 'C';
    else if(naipe == 2) return 'E';
    else if(naipe == 3) return 'P';
    else if(naipe == 4) return 'O';
    else return 'n';
}

//Desenhar parte de cima da tabela para quatro em linha
void desenharParteDeCima(){
    int columnNumber = 1;
    printf("\nJogo do galo 1v1\n");
    while(columnNumber != 8)
        printf("| %d | \t", columnNumber++);
}

//Trocar de jogador para quatro em linha
char trocarJogador(char jogador) {
    if (jogador == 'X') {
        return '0';
    } else {
        return 'X';
    }
}

//Mensagens de erro
void errorMessageGeneral(){
    printf("\nOpção inserida incorreta!\n");
}

void errorMessageGame(){
    printf("\nErrou!\n");
}