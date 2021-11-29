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
        1 - As
        else = null
    */
    if(carta == 11) return "Dama";
    else if(carta == 12) return "Valete";
    else if(carta == 13) return "Rei";
    else if(carta == 1) return "As";
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

//Função para ajuda no jogo do galo
void tabjogo(char tabuleiro[])
{
    system("cls");
    //Tabuleiro de jogo
    printf("\nJOGO DO GALO\n");
    printf("   |   |   \n %c | %c | %c \n___|___|___\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
    printf("   |   |   \n %c | %c | %c \n___|___|___\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
    printf("   |   |   \n %c | %c | %c \n   |   |   \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);

}

int vganhou(char tabuleiro[])
{
    int v = 0, i = -1, j, x = 0, o = 0, flagv = 0;
    //array vitoria
    int arrayv[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  
        {0,3,6}, {1,4,7}, {2,5,8},  
        {0, 4, 8}, {6, 4, 2}
        };
     
    while(flagv != 1)
    {
        i++;   
        if(i != 8)
        {
            for(j = 0; j < 3; j++)
            {
                //Verifica se é X
                if(tabuleiro[arrayv[i][j]] == 'X')
                x++;
                //Verifica se é O
                if(tabuleiro[arrayv[i][j]] == 'O')
                    o++;
                //Confirma a vitória
                if(x == 3)
                {
                    v = 1;
                    flagv = 1;
                }
                else if(o == 3)
                {
                    v = 2;
                    flagv = 1;
                }
            }
        }
        else
            flagv = 1;
        x = 0;
        o = 0;
        
        if(i == 8)
            flagv = 1;
    }

    //se v = 1 jogador(1) v = 2 jogador(2) v = 0 Empate
    return v;
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