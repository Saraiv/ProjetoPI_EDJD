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
    char* jogador = umJogadorEscolhido();
    char *player;
    player = malloc(sizeof(jogador));
    player = jogador;
    getChar();

    int flag = 0, flagVezDoJogador = 1, pontuacaoJogoPlayer = 0, pontuacaoJogoCPU = 0, naipe = -1, carta = -1, cpuBrain = 0;
    char escolha, escolhaJoga, *naipeString, *cartaString;

    while(flag == 0){
        system("cls");
        printf("\nVINTE E UM\n");
        naipe = generateRandomInt(1, 4);
        naipeString = naipeToString(naipe);
        carta = generateRandomInt(1, 13);
        cartaString = cartaToString(carta);

        if(flagVezDoJogador == 1){
            printf("\nPONTUACAO DO PLAYER: %d\n", pontuacaoJogoPlayer);
            if(carta >= 11 && carta <= 13) printf("\nEscolher ficar com a carta %s de %s ? s/S n/N ", cartaString, naipeString);
            else if(carta == 1) printf("\nEscolher ficar com a carta As de %s ? s/S n/N ", naipeString);
            else printf("\nEscolher ficar com a carta %d de %s ? s/S n/N ", carta, naipeString);
            scanf(" %c", &escolha);

            //a vez do jogador
            if(escolha == 's' || escolha == 'S'){
                if(pontuacaoJogoPlayer > 21){
                    pontuacaoJogoPlayer = -1;
                    printf("\n\n");
                    premirTeclaContinuar();
                    getChar();
                    flagVezDoJogador = 0;
                }else if(pontuacaoJogoPlayer >= 0 && pontuacaoJogoPlayer <= 21){
                    // 1 -> 11 -> 21
                    if(carta > 0 && carta < 11) pontuacaoJogoPlayer += 1;
                    else if(carta > 10 && carta < 14) pontuacaoJogoPlayer += 10;

                    printf("\nNOVA PONTUACAO DO PLAYER: %d\n", pontuacaoJogoPlayer);

                    printf("\nDeseja continuar a jogar? s/S n/N ");
                    scanf(" %c", &escolhaJoga);

                    if(escolhaJoga == 'n' || escolhaJoga == 'N'){
                        printf("\n\n");
                        premirTeclaContinuar();
                        getChar();
                        flagVezDoJogador = 0;
                    }
                }
                
            } else flagVezDoJogador = 0;
        } else if(flagVezDoJogador == 0){
            //Vez do CPU
            printf("\nPONTUACAO DO CPU: %d\n", pontuacaoJogoCPU);
            printf("\nCPU\n");
            if(carta >= 11 && carta <= 13) printf("\nEscolher ficar com a carta %s de %s ? s/S n/N ", cartaString, naipeString);
            else if(carta == 1) printf("\nEscolher ficar com a carta As de %s ? s/S n/N ", naipeString);
            else printf("\nEscolher ficar com a carta %d de %s ? s/S n/N ", carta, naipeString);

            if(carta > 0 && carta < 11) cpuBrain += 1;
            else if(carta > 10 && carta < 14) cpuBrain += 10;

            if(cpuBrain <= 21){
                if(carta > 0 && carta < 11) pontuacaoJogoCPU += 1;
                else if(carta > 10 && carta < 14) pontuacaoJogoCPU += 10;
                printf("\nNOVA PONTUACAO DO CPU: %d\n", pontuacaoJogoCPU);
            } else{
                flag = -1;
            }
            
            premirTeclaContinuar();
            getChar();
            printf("\n\n");
        } else{
            errorMessageGeneral();
            printf("\n\n");
        } 
    }

    if(pontuacaoJogoPlayer > pontuacaoJogoCPU){
        system("cls");
        printf("\nRESULTADO FINAL");
        printf("\nPontos do Jogador: %d\tPontuacao do CPU: %d\nO Jogador ganhou!", pontuacaoJogoPlayer, pontuacaoJogoCPU);
        adicionarPontosAoJogador(player, pontuacaoJogoPlayer, VinteUm);
        printf("\n\n");
    } else if(pontuacaoJogoPlayer < pontuacaoJogoCPU){
        system("cls");
        printf("\nPontos do Jogador: %d\tPontuacao do CPU: %d\nO CPU ganhou!", pontuacaoJogoPlayer, pontuacaoJogoCPU);
        printf("\n\n");
    } else{
        system("cls");
        printf("\nPontos do Jogador: %d\tPontuacao do CPU: %d\nEmpate!", pontuacaoJogoPlayer, pontuacaoJogoCPU);
        printf("\n\n");
    }
}