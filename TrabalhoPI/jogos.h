//jogos
//funcoes de ajuda
int generateRandomInt(int min, int max) {
    srand((unsigned)time(NULL));
    return min + rand() % (max - min);
}

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

//error messages
void errorMessageGeneral(){
    printf("\nOpção inserida incorreta!\n");
}

void errorMessageGame(){
    printf("\nErrou!\n");
}

//JOGO UM
void adivinhaONumero(){
    /*variaveis 
    numAAdivinhar ->
    num -> numero random
    flag -> 
    tentativas -> numero total de tentativas
    tentativasFalhadas -> numero total de tentativas falhadas
    pontuacaoPlayer -> pontuacao do player naquela ronda
    */
    int numAAdivinhar = 0, num = 0, flag = 0, tentativas = 0, tentativasFalhadas = 0, pontuacaoPlayer = 0;

    num = generateRandomInt(0, 100);

    while(flag == 0){
        system("cls");

        printf("\nEscreva um número: ");
        scanf("%d", &numAAdivinhar);
        
        //numero de tentativas totais
        tentativas++;

        if(num == numAAdivinhar){
            printf("\nAcertou!\n");
            printf("\nTentativas: %d\n", tentativas);
            
            //sistema de pontos
            if(tentativas <= 0) pontuacaoPlayer = 0; 
            else if(tentativas == 1) pontuacaoPlayer = 10; 
            else if(tentativas >= 10) pontuacaoPlayer = 0;
            else pontuacaoPlayer = 10 - tentativasFalhadas;

            printf("\nPontos: %d\n", pontuacaoPlayer);
            printf("\n\n");
            system("PAUSE");
            flag = -1;
        } else if(numAAdivinhar < num){
            printf("\nNúmero maior\n");
            printf("\n\n");
            //incrementacao para numero de tentativas falhadas
            tentativasFalhadas++;
            system("PAUSE");
        } else if(numAAdivinhar > num){
            printf("\nNúmero menor\n");
            //incrementacao para numero de tentativas falhadas
            tentativasFalhadas++;
            printf("\n\n");
            system("PAUSE");
        } else{
            errorMessageGame();
            printf("\n\n");
            system("PAUSE");
        } 
    }
}

//JOGO DOIS
void adivinhaACarta()
{
    system("cls");
    // N- Naipe aleatorio || carta- carta aleatoria || Tc- Tentativa de acertar a carta || naipes- tentativa de acertar os naipes 
    // nt- numero de tentativas|| P- Pontos
    int N = 0, carta = 0, Tc = 0, flag1 = 0, flag2 = 0, nt = 0, P = 0;
    char naipes[10], NC[10] = "0";
    
    //criar carta aleatoria
    carta = generateRandomInt(1, 13);
    
    //Criar a comparação de strings n=1(Copas) n=2(Espadas) n=3(Paus) n=4(Ouros)
    
    N = generateRandomInt(1, 4);
    
    if (N == 1)
       memcpy(NC, "copas", 10);
    if(N == 2)
        memcpy(NC, "espadas", 10);
    if(N == 3)
        memcpy(NC, "paus", 10);
    if (N == 4)
        memcpy(NC, "ouros", 10);

    //----------------------------------------------
   
    while (flag1 == 0 || flag2 == 0)
    {

        if (flag1 == 0) {
            
            //Input do utilizador
            printf("\tOuros Copas Espadas Paus\n\t    Escolha um naipe:\n");
            scanf("%s", &naipes);
            
            //Converter todos os caracteres para minuscula assim o programa nao e sensivel a maiusculas e minusculas
            for (int i = 0; naipes[i] != '\0'; i++) {
                if (naipes[i] >= 'A' && naipes[i] <= 'Z') {
                    naipes[i] = naipes[i] + 32;
                }
            }

            //Sistema de comparação do input NAIPES

            if (strcmp(naipes, NC) == 0) {
                printf("\nAcertou o naipe!!\n");
                flag1 = 1;
            }
            if (strcmp(naipes, NC) != 0)
                printf("\nFalhou o naipe!!\n");
        }

        if (flag2 == 0) {
            printf("\tCada carta tem um valor correspondente ao seu simbolo\n\t\tAs-1 Valete-11 Dama-12 Rei-13\n\t\t\tEscolha a carta:\n");
            scanf("%d", &Tc);
            //Sistema de comparação do input Cartas
            if (Tc < carta)
                printf("%c O valor da carta e superior %c\n", 30, 30);
            if (Tc > carta)
                printf("%c O valor da carta e inferior %c\n", 31, 31);
            if (Tc == carta)
            {
                printf("Acertou o valor da carta!\n");
                flag2 = 1;
            }
        }
        
        //Contar o numero de tentativas
        nt++;
    }

    //Atribuição dos pontos
    P = 6 - nt;
    if (P < 0)
        P = 0;

    while (flag1 == 1)
    {
        system("cls");
        printf("\nA sua pontuacao foi: %d\nPrecisou de %d tentativas.\n", P, nt);
        printf("Se pretende sair prima (0)\n");
        scanf("%d", &flag1);
        
    }
}

//JOGO TRES
void vinteEUm(){
    /*variaveis 
    flag -> para acabar o jogo
    flagVezDoJogador -> para acabar o turno do jogador e comecar o turno do computador
    pontuacaoJogoCPU -> pontuacao do cpu daquela ronda
    pontuacaoJogoPlayer -> pontuacao do player daquela ronda
    naipe -> Copas ou Espadas ou Ouros ou Paus
    carta -> 1 - 10 numeros das cartas / 11 - 13 Dama Valete e Rei
    cpuBrain -> var temporaria para fazer com que o cpu pare o jogo.
    */
    int flag = 0, flagVezDoJogador = 1, pontuacaoJogoPlayer = 0, pontuacaoJogoCPU = 0, naipe = -1, carta = -1, cpuBrain = 0;
    char escolha, escolhaJoga, naipeString;

    while(flag == 0){
        system("cls");
        naipe = generateRandomInt(1, 4);
        naipeString = naipeToString(naipe);
        carta = generateRandomInt(1, 13);

        if(flagVezDoJogador == 1){
            printf("\nEscolher ficar com a carta %d de %c ? s/S n/N ", carta, naipeString);
            scanf(" %c", &escolha);

            //a vez do jogador
            if(escolha == 's' || escolha == 'S'){
                if(pontuacaoJogoPlayer > 21){
                    pontuacaoJogoPlayer = -1;
                    printf("\n\n");
                    system("PAUSE");
                    flagVezDoJogador = 0;
                }else if(pontuacaoJogoPlayer >= 0 && pontuacaoJogoPlayer <= 21){
                    // 1 -> 11 -> 21
                    if(carta > 0 && carta < 11) pontuacaoJogoPlayer += 1;
                    else if(carta > 10 && carta < 14) pontuacaoJogoPlayer += 10;

                    printf("\nPONTUACAO DO PLAYER: %d\n", pontuacaoJogoPlayer);

                    printf("\nDeseja continuar a jogar? s/S n/N ");
                    scanf(" %c", &escolhaJoga);

                    if(escolhaJoga == 'n' || escolhaJoga == 'N'){
                        printf("\n\n");
                        system("PAUSE");
                        flagVezDoJogador = 0;
                    }
                }
                
            } 
        } else if(flagVezDoJogador == 0){
            //Vez do CPU
            printf("\nCPU\n");
            printf("\nEscolher ficar com a carta %d de %c ?", carta, naipeString);

            if(carta > 0 && carta < 11) cpuBrain += 1;
            else if(carta > 10 && carta < 14) cpuBrain += 10;

            if(cpuBrain <= 21){
                if(carta > 0 && carta < 11) pontuacaoJogoCPU += 1;
                else if(carta > 10 && carta < 14) pontuacaoJogoCPU += 10;
                printf("\nPONTUACAO DO CPU: %d\n", pontuacaoJogoCPU);
            } else{
                flag = -1;
            }

            printf("\n\n");
            system("PAUSE");
        } else{
            errorMessageGeneral();
            printf("\n\n");
            system("PAUSE");
        } 
    }

    if(pontuacaoJogoPlayer > pontuacaoJogoCPU){
        printf("\nPontos do Jogador: %d\tPontuacao do CPU: %d\nO Jogador ganhou!", pontuacaoJogoPlayer, pontuacaoJogoCPU);
        printf("\n\n");
        system("PAUSE");
    } else if(pontuacaoJogoPlayer < pontuacaoJogoCPU){
        printf("\nPontos do Jogador: %d\tPontuacao do CPU: %d\nO CPU ganhou!", pontuacaoJogoPlayer, pontuacaoJogoCPU);
        printf("\n\n");
        system("PAUSE");
    } else{
        printf("\nPontos do Jogador: %d\tPontuacao do CPU: %d\nEmpate!", pontuacaoJogoPlayer, pontuacaoJogoCPU);
        printf("\n\n");
        system("PAUSE");
    }
}

//JOGO QUATRO