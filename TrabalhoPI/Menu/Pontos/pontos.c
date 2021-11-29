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

//Função para pontos totais
void pontosGlobais(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);

        Jogadores[i].pontosTotais = Jogadores[i].pontosAdivinhaNumero +
        Jogadores[i].pontosAdivinhaCarta + Jogadores[i].pontosVinteEUm +
        Jogadores[i].pontosJogoDoGaloUmVsUm + Jogadores[i].pontosJogoDoGaloUmVsCPU +
        Jogadores[i].pontosJogoDaForca + Jogadores[i].pontosQuatroEmLinhaUmVsUm +
        Jogadores[i].pontosQuatroEmLinhaUmVsCPU;
    }

    fclose(fJogadores);

    system("cls");

    printf("\nPONTUACAO GLOBAL DOS JOGADORES\n\n");

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosTotais);
    }
    
    getChar();
    printf("\n");
}

//Funções para listar cada jogo
void listarPontosAdivinhaNumero(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosAdivinhaNumero > Jogadores[j].pontosAdivinhaNumero){ 
                auxPontos = Jogadores[i].pontosAdivinhaNumero;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosAdivinhaNumero = Jogadores[j].pontosAdivinhaNumero;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosAdivinhaNumero = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO ADIVINHA O NUMERO DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosAdivinhaNumero);
    }

    printf("\n");
}

void listarPontosAdivinhaACarta(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosAdivinhaCarta > Jogadores[j].pontosAdivinhaCarta){ 
                auxPontos = Jogadores[i].pontosAdivinhaCarta;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosAdivinhaCarta = Jogadores[j].pontosAdivinhaCarta;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosAdivinhaCarta = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO ADIVINHA A CARTA DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosAdivinhaCarta);
    }

    printf("\n");
}

void listarPontosVinteEUm(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosVinteEUm > Jogadores[j].pontosVinteEUm){ 
                auxPontos = Jogadores[i].pontosVinteEUm;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosVinteEUm = Jogadores[j].pontosVinteEUm;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosVinteEUm = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO VINTE E UM DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosVinteEUm);
    }

    printf("\n");
}

void listarPontosJogoDoGaloUmVsUm(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosJogoDoGaloUmVsUm > Jogadores[j].pontosJogoDoGaloUmVsUm){ 
                auxPontos = Jogadores[i].pontosJogoDoGaloUmVsUm;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosJogoDoGaloUmVsUm = Jogadores[j].pontosJogoDoGaloUmVsUm;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosJogoDoGaloUmVsUm = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO JOGO DO GALO DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosJogoDoGaloUmVsUm);
    }

    printf("\n");
}

void listarPontosJogoDoGaloUmVsCPU(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosJogoDoGaloUmVsCPU > Jogadores[j].pontosJogoDoGaloUmVsCPU){ 
                auxPontos = Jogadores[i].pontosJogoDoGaloUmVsCPU;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosJogoDoGaloUmVsCPU = Jogadores[j].pontosJogoDoGaloUmVsCPU;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosJogoDoGaloUmVsCPU = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO JOGO DO GALO VS CPU DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosJogoDoGaloUmVsCPU);
    }

    printf("\n");
}

void listarPontosJogoDaForca(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosJogoDaForca > Jogadores[j].pontosJogoDaForca){ 
                auxPontos = Jogadores[i].pontosJogoDoGaloUmVsCPU;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosJogoDaForca = Jogadores[j].pontosJogoDaForca;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosJogoDaForca = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO JOGO DA FORCA DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosJogoDaForca);
    }

    printf("\n");
}

void listarPontosQuatroEmLinhaUmVsUm(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosQuatroEmLinhaUmVsUm > Jogadores[j].pontosQuatroEmLinhaUmVsUm){ 
                auxPontos = Jogadores[i].pontosQuatroEmLinhaUmVsUm;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosQuatroEmLinhaUmVsUm = Jogadores[j].pontosQuatroEmLinhaUmVsUm;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosQuatroEmLinhaUmVsUm = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO QUATRO EM LINHA DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosQuatroEmLinhaUmVsUm);
    }

    printf("\n");
}

void listarPontosQuatroEmLinhaUmVsCPU(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosQuatroEmLinhaUmVsCPU > Jogadores[j].pontosQuatroEmLinhaUmVsCPU){ 
                auxPontos = Jogadores[i].pontosQuatroEmLinhaUmVsCPU;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosQuatroEmLinhaUmVsCPU = Jogadores[j].pontosQuatroEmLinhaUmVsCPU;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosQuatroEmLinhaUmVsCPU = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    system("cls");

    printf("\nPONTUACAO QUATRO EM LINHA UM VS CPU DOS 10 MELHORES JOGADORES\n\n");
    
    if(count > 10) count = 0;

    for(int i = 0; i < count; i++){
        printf("\n%d: %s %d", i + 1, Jogadores[i].nome, Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    printf("\n");
}

//função para pontos dos 10 melhores jogadores
void pontosPJogadorGlobal(){
    int count = countJogadores() - 1, auxPontos;
    char auxNomes[10];
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    //Ficheiro = Nome pontosAdivinhaNumero pontosAdivinhaCarta pontosVinteEUm, etc..

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);

        Jogadores[i].pontosTotais = Jogadores[i].pontosAdivinhaNumero +
        Jogadores[i].pontosAdivinhaCarta + Jogadores[i].pontosVinteEUm +
        Jogadores[i].pontosJogoDoGaloUmVsUm + Jogadores[i].pontosJogoDoGaloUmVsCPU +
        Jogadores[i].pontosJogoDaForca + Jogadores[i].pontosQuatroEmLinhaUmVsUm +
        Jogadores[i].pontosQuatroEmLinhaUmVsCPU;
    }

    for(int i = 0; i < count; i++){ 
        for(int j = 0; j < count; j++){
            if(Jogadores[i].pontosTotais > Jogadores[j].pontosTotais){ 
                auxPontos = Jogadores[i].pontosTotais;
                strcpy(auxNomes, Jogadores[i].nome);
                Jogadores[i].pontosTotais = Jogadores[j].pontosTotais;
                strcpy(Jogadores[i].nome, Jogadores[j].nome);
                Jogadores[j].pontosTotais = auxPontos;
                strcpy(Jogadores[j].nome, auxNomes);
            } 
        }
    }

    fclose(fJogadores);

    system("cls");

    printf("\nPONTUACAO DOS 10 MELHORES JOGADORES\n\n");

    if(count > 10) count = 10;

    for(int i = 0; i < count; i++){
        printf("\nO total de pontos de %s e: %d", Jogadores[i].nome, Jogadores[i].pontosTotais);
    }

    getChar();

    printf("\n");
}

//função para pontos dos 10 melhores jogadores por cada jogo
void pontosPJogo(){
    //variaveis
    int escolha = -1, flag = 0;
    do{
        system("cls");

        //menu de todos os jogos
        printf("\nIPCA GAMES ARCH\n\n1- Adivinha o numero \n2- Adivinha a carta \n");
        printf("3- Vinte-e-um \n4- Jogo do Galo (1 vs 1) \n5- Jogo do Galo (1 vs CPU) \n");
        printf("6- Jogo da Forca \n7- Quatro-em-Linha (1 vs 1) \n8- Quatro-em-Linha (1 vs CPU) \n0- Sair\n");
        scanf("%d", &escolha);
        
        switch(escolha){
            case 1:
                //Adivinha o número
                listarPontosAdivinhaNumero();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 2:
                //Adivinha a carta
                listarPontosAdivinhaACarta();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 3:
                //Vinte-e-um
                listarPontosVinteEUm();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 4:
                //Jogo do Galo (1 vs 1)
                listarPontosJogoDoGaloUmVsUm();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 5:
                //Jogo do Galo (1 vs CPU)
                listarPontosJogoDoGaloUmVsCPU();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 6:
                //Jogo da Forca
                listarPontosJogoDaForca();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 7:
                //Quatro-em-Linha (1 vs 1)
                listarPontosQuatroEmLinhaUmVsUm();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 8:
                //Quatro-em-Linha (1 vs CPU)
                listarPontosQuatroEmLinhaUmVsCPU();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
            case 0:
                flag = -1;
                break;
            default:
                errorMessageGeneral();
                premirTeclaContinuar();
                getChar();
                getChar();
                break;
        }
    } while(flag == 0);
}

char *umJogadorEscolhido(){
    int count = countJogadores() - 1, flagEscolhido = 0, escolha;
    struct Jogador Jogadores[200];
    char *jogadorSelecionado = " ";
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }

    fclose(fJogadores);

    do{
        printf("Escolha um jogador: \n");

        for(int i = 0; i < count; i++){
            printf("\n%d - %s", i + 1, Jogadores[i].nome);
        }

        printf("\n");

        scanf("%d", &escolha);

        if(escolha > 0 && escolha < count){
            jogadorSelecionado = Jogadores[escolha - 1].nome;
            flagEscolhido = 1;
        }
    } while(flagEscolhido == 0);

    return jogadorSelecionado;
}

void adicionarPontosAoJogador(char jogador[10], int quantidadePontos, const char *jogo){
    int count = countJogadores() - 1;
    struct Jogador Jogadores[200];
    
    FILE *fJogadores = NULL;

    fJogadores = fopen("Ficheiros/Jogadores.txt", "rt");

    if (fJogadores == NULL){
        perror("Error");
    }

    for(int i = 0; i < count; i++){
        fscanf(fJogadores, "%s %d %d %d %d %d %d %d %d", 
        Jogadores[i].nome, &Jogadores[i].pontosAdivinhaNumero,
        &Jogadores[i].pontosAdivinhaCarta, &Jogadores[i].pontosVinteEUm,
        &Jogadores[i].pontosJogoDoGaloUmVsUm, &Jogadores[i].pontosJogoDoGaloUmVsCPU,
        &Jogadores[i].pontosJogoDaForca, &Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        &Jogadores[i].pontosQuatroEmLinhaUmVsCPU);

        if(jogador == Jogadores[i].nome){
            printf("\n2 - AQUI!\n");
            if(jogo == AdivinhaNumero) Jogadores[i].pontosAdivinhaNumero += quantidadePontos;
            else if(jogo == AdivinhaCarta) Jogadores[i].pontosAdivinhaCarta += quantidadePontos;
            else if(jogo == VinteUm) Jogadores[i].pontosVinteEUm += quantidadePontos;
            else if(jogo == JogoGalo1v1) Jogadores[i].pontosJogoDoGaloUmVsUm += quantidadePontos;
            else if(jogo == JogoGalo1vCPU) Jogadores[i].pontosJogoDoGaloUmVsCPU += quantidadePontos;
            else if(jogo == JogoForca) Jogadores[i].pontosJogoDaForca += quantidadePontos;
            else if(jogo == QuatroLinha1v1) Jogadores[i].pontosQuatroEmLinhaUmVsUm += quantidadePontos;
            else if(jogo == QuatroLinha1vCPU) Jogadores[i].pontosQuatroEmLinhaUmVsCPU += quantidadePontos;
        }
    }

    for(int i = 0; i < count; i++){
        fprintf(fJogadores, "%s %d %d %d %d %d %d %d %d\n", Jogadores[i].nome, Jogadores[i].pontosAdivinhaNumero,
        Jogadores[i].pontosAdivinhaCarta, Jogadores[i].pontosVinteEUm,
        Jogadores[i].pontosJogoDoGaloUmVsUm, Jogadores[i].pontosJogoDoGaloUmVsCPU,
        Jogadores[i].pontosJogoDaForca, Jogadores[i].pontosQuatroEmLinhaUmVsUm,
        Jogadores[i].pontosQuatroEmLinhaUmVsCPU);
    }
	
	fclose(fJogadores);
}