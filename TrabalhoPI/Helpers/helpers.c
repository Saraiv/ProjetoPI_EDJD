//Numero inteiro random
int generateRandomInt(int min, int max) {
    srand((unsigned)time(NULL));
    return min + rand() % (max - min);
}

//Numero inteiro de 1 - 4 para char desde C - E - P - O  
char *naipeToString(int naipe){
    /*  1 - Copas
        2 - Espadas
        3 - Paus
        4 - Ouros
        else = null
    */
    if(naipe == 1) return "Copas";
    else if(naipe == 2) return "Espadas";
    else if(naipe == 3) return "Paus";
    else if(naipe == 4) return "Ouros";
    else return "Nada";
}

char *cartaToString(int carta){
    /*  11 - Dama
        12 - Valete
        13 - Rei
        else = null
    */
    if(carta == 11) return "Dama";
    else if(carta == 12) return "Valete";
    else if(carta == 13) return "Rei";
    else return "Nada";
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

void getChar(){
    char ch;
    ch = getchar();
    while(ch != '\n')
        ch = getchar();
}

//Função para validar char jogo da forca
char getValidChar() {
	char c;

	do {
		scanf("%c", &c);
	} while (c == '\n');

	return c;
}

//Mensagens de erro
void errorMessageGeneral(){
    printf("\nOpcao inserida incorreta!\n");
}

void errorMessageGame(){
    printf("\nErrou!\n");
}

void premirTeclaSair(){
    printf("\nPrima qualquer tecla para sair.\n");
}

void premirTeclaContinuar(){
    printf("\nPrima enter para continuar.\n");
}