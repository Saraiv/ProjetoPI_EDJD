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
    // nt- numero de tentativas|| P- Pontos || np- numero de pontos
    int N = 0, carta = 0, Tc = 0, flag1 = 0, flag2 = 0, nt = 0,np = 0, P = 0;
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
    printf("\n%s", NC);
    printf("\n%d", carta);
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
                printf("\nAcertou o naipe!!\n\n");
                flag1 = 1;
            }
            if (strcmp(naipes, NC) != 0)
                printf("\nFalhou o naipe!!\n\n");
        }

        if (flag2 == 0) {
            printf("\tCada carta tem um valor correspondente ao seu simbolo\n\t\tAs-1 Valete-11 Dama-12 Rei-13\n\t\t\tEscolha a carta:\n");
            scanf("%d", &Tc);
            //Sistema de comparação do input Cartas
            if (Tc < carta)
                printf("%c O valor da carta e superior %c\n\n", 30, 30);
            if (Tc > carta)
                printf("%c O valor da carta e inferior %c\n\n", 31, 31);
            if (Tc == carta)
            {
                printf("Acertou o valor da carta!\n\n");
                flag2 = 1;
            }
        }
        
        //Contar o numero de tentativas
        if(flag1 == 0 || flag2 == 0)
            np++;
        nt++;
    }

    //Atribuição dos pontos
    P = 6 - np;
    if (P < 0)
        P = 0;

    while (flag1 == 1)
    {
        system("cls");
        printf("\nA sua pontuacao foi: %d\nPrecisou de %d tentativa(s).\n", P, nt);
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
//Jogo_do_Galo--------------------------------
void jogoDoGalo()
{
    /*
            |   | 
          1 | 2 | 3
         ___|___|___
            |   |
          4 | 5 | 6
         ___|___|___
            |   |
          7 | 8 | 9
            |   |
    */
    int flags = 0, flag = 0, flagB = 0, temp = 0, J = 1, v1 = 0, v2 = 0, P1 = 0, P2 = 0, jogador1 = 0, jogador2 = 0;
    char tabuleiro[] = {'1','2','3','4','5','6','7','8','9'};
    
    //Ver o jogador que joga primeiro
    jogador1 = generateRandomInt(0, 2);
    if (jogador1 == 0)//jogador1 joga em segundo
        jogador2 = 1;


    while (flags == 0)
    {
        while (flag == 0)
        {
            system("cls");
            //Tabuleiro de jogo
            printf("   |   |   \n %c | %c | %c \n___|___|___\n", tabuleiro[0], tabuleiro[1], tabuleiro[2]);
            printf("   |   |   \n %c | %c | %c \n___|___|___\n", tabuleiro[3], tabuleiro[4], tabuleiro[5]);
            printf("   |   |   \n %c | %c | %c \n   |   |   \n", tabuleiro[6], tabuleiro[7], tabuleiro[8]);

            //Input
            if (jogador1 == 1)
                printf("Jogador(1):\n-Escolha uma coordenada para jogar:\n");
            if (jogador2 == 1)
                printf("Jogador(2):\nEscolha uma coordenada para jogar:\n");
            scanf("%d", &temp);
            

            //Imprimir a jogada no tabuleiro
            switch (temp)
            {
                case 1:
                    if (tabuleiro[0] == 'X' || tabuleiro[0] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[0] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[0] = 'O';
                    break;
                case 2:
                    if (tabuleiro[1] == 'X' || tabuleiro[1] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[1] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[1] = 'O';

                    break;
                case 3:
                    if (tabuleiro[2] == 'X' || tabuleiro[2] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[2] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[2] = 'O';

                    break;
                case 4:
                    if (tabuleiro[3] == 'X' || tabuleiro[3] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[3] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[3] = 'O';

                    break;
                case 5:
                    if (tabuleiro[4] == 'X' || tabuleiro[4] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[4] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[4] = 'O';

                    break;
                case 6:
                    if (tabuleiro[5] == 'X' || tabuleiro[5] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[5] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[5] = 'O';

                    break;
                case 7:
                    if (tabuleiro[6] == 'X' || tabuleiro[6] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[6] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[6] = 'O';

                    break;
                case 8:
                    if (tabuleiro[7] == 'X' || tabuleiro[7] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[7] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[7] = 'O';

                    break;
                case 9:
                    if (tabuleiro[8] == 'X' || tabuleiro[8] == 'O')
                    {
                        printf("Nao tente fazer batota\n");
                        flagB = 1;
                    }
                    else if (jogador1 == 1)
                        tabuleiro[8] = 'X';
                    else if (jogador2 == 1)
                        tabuleiro[8] = 'O';

                    break;
            }

            //Decidir se o jogador pode ou nao jogar
            if (flagB == 0)
            {
                if (jogador1 == 1)
                {
                    jogador1 = 0;
                    jogador2 = 1;
                }
                else
                {
                    jogador1 = 1;
                    jogador2 = 0;
                }
            }
            else
                flagB = 0;

            //Confirmaçao de Vitoria JOGADOR(1)    
            if (tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[2] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria primeira linha horizontal

            if (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[5] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria Segunda linha horizontal

            if (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[8] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria terceira linha horizontal

            if (tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[6] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria primeira linha vertical

            if (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[7] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria segunda linha vertical

            if (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[8] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria terceira linha vertical

            if (tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[8] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria diagonal

            if (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[6] == 'X')
            {
                v1 = 1;
                flag = 1;
            }//Jogador(1) ganha vitoria diagonal

            //------------------------------------------------------------------

            //Confirmaçao de Vitoria JOGADOR(2) 
            if (v1 == 0) {
                if (tabuleiro[0] == tabuleiro[1] && tabuleiro[1] == tabuleiro[2] && tabuleiro[2] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria primeira linha horizontal

                if (tabuleiro[3] == tabuleiro[4] && tabuleiro[4] == tabuleiro[5] && tabuleiro[5] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria Segunda linha horizontal

                if (tabuleiro[6] == tabuleiro[7] && tabuleiro[7] == tabuleiro[8] && tabuleiro[8] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria terceira linha horizontal

                if (tabuleiro[0] == tabuleiro[3] && tabuleiro[3] == tabuleiro[6] && tabuleiro[6] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria primeira linha vertical

                if (tabuleiro[1] == tabuleiro[4] && tabuleiro[4] == tabuleiro[7] && tabuleiro[7] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria segunda linha vertical

                if (tabuleiro[2] == tabuleiro[5] && tabuleiro[5] == tabuleiro[8] && tabuleiro[8] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria terceira linha vertical

                if (tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8] && tabuleiro[8] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria diagonal

                if (tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6] && tabuleiro[6] == 'O')
                {
                    v2 = 1;
                    flag = 1;
                }//Jogador 2 ganha vitoria diagonal
            }
            
        }

        if (v1 == 1)
        {
            printf("Vitoria do jogador(1)!\n");
            P1++;
           
        }
        else 
        {
            printf("Vitoria do jogador(2)!\n");
            P2++;
        }
        
        printf("Pretende continuar?\nSim(0) Nao(1)\n");
        scanf("%d", &flags);
        
        //Se for para jogar novamente reiniciar todas as variaveis do jogo!!
        if(flags == 0)
        {
            for (int i = 0; i < 9; i++)
                tabuleiro[i] = 49 + i;
            flag = 0;
            v1 = 0;
            v2 = 0;
            

            jogador1 = generateRandomInt(0, 2);
            if (jogador1 == 0)//jogador1 joga em segundo
                jogador2 = 1;
        }
    }
 }