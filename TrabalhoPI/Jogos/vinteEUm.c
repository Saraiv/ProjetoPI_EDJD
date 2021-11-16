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