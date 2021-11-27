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
    while(ch == '\n')
        ch = getchar();
}

//Mensagens de erro
void errorMessageGeneral(){
    printf("\nOpção inserida incorreta!\n");
}

void errorMessageGame(){
    printf("\nErrou!\n");
}

void premirTeclaSair(){
    printf("\nPrima qualquer tecla para sair.\n");
}

void premirTeclaContinuar(){
    printf("\nPrima qualquer tecla para continuar.\n");
}

//Função para introduzir jogadores
void introduzirJogadores(){
    char Jogador[10];
    char writeFile;
    system("cls");
    printf("\n\nNome do jogador: ");
    scanf(" %s", Jogador);

    FILE *fJogadores = NULL;

	fJogadores = fopen("Ficheiros/Jogadores.txt", "a");

	if(fJogadores == NULL){
		perror("Error");
	}

	fprintf(fJogadores, "%s 0\n", Jogador);
	
	fclose(fJogadores);

    printf("\n\nJogador adicionado com sucesso!\n");
}

//Função para saber quantos jogadores tem o programa
int countJogadores(){
    FILE *fJogadores = NULL;
    int count = 1;
    char c, letra = '\n';

    fJogadores = fopen("Ficheiros/Jogadores.txt", "r");

    while (fread(&c, sizeof(char), 1, fJogadores)){
        if (c == letra){
            count++;
        }
    }

    fclose(fJogadores);
    return count;
}

struct Jogador{
    char nome[10];
    int pontos;
};

//Função para receber jogadores do ficheiro
void receberTodosJogadoresEOrdenar(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d", Jogadores[i].nome, &Jogadores[i].pontos);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontos > Jogadores[j].pontos){ 
                auxPontos = Jogadores[i].pontos;
                // auxNomes = Jogadores[i].nome;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontos = Jogadores[j].pontos; 
                // *Jogadores[i].nome = Jogadores[j].nome;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontos = auxPontos;
                // *Jogadores[j].nome = auxNomes;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO GLOBAL DOS JOGADORES\n\n");

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontos);
    }

    printf("\n");
}