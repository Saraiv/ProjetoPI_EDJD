//JOGO SETE
void quatroEmLinha(){
    char* jogador = umJogadorEscolhido();
    char* player;
    player = malloc(sizeof(jogador));
    player = jogador;
    char* jogadorDois = umJogadorEscolhido();
    char *playerDois;
    playerDois = malloc(sizeof(jogadorDois));
    playerDois = jogadorDois;
    getChar();
    char jogadorSelecionado = 'X', tabuleiro[6][7], jogadorVencedor = 'p';
    int rondas = 0, colunaTabela = -1, pontosJogadorX = 0, pontosJogadorY = 0, 
    linhaTabela = 6, flagVezDeJogador = 0, flagLinhas = 0, flagColunas = 0;
    system("cls");
    printf("\nQUATRO EM LINHA\n");

    desenharParteDeCima();

    printf("\n");

    for(int i = 0; i < 6; i++) {
        for(int j = 1; j <= 7; j++) {
            tabuleiro[i][j] = ' ';
            printf("| %c |\t", tabuleiro[i][j]); 
        }
        printf("\n");
    }

    while (jogadorVencedor == 'p' || rondas > 42) {
        rondas++;
        flagColunas = 0;

        //cada jogada
        while(flagColunas == 0){
            if(jogadorSelecionado == 'X') printf("\n%s, em que coluna quer jogar? ", player);
            else if(jogadorSelecionado == '0') printf("\n%s, em que coluna quer jogar? ", playerDois);
            scanf("%d", &colunaTabela);
            if(colunaTabela >= 1 && colunaTabela <= 7){
                flagColunas = 1;
            } else{
                system("cls");
                errorMessageGeneral();
                premirTeclaContinuar();
                getChar();
                printf("\n");
            }
        }

        //imprimir tabela
        if(colunaTabela != -1){
            flagLinhas = 0;
            linhaTabela = 5;

            desenharParteDeCima();

            if(tabuleiro[0][0] == '\0'){
                tabuleiro[0][0] = ' ';
            }

            printf("\n");

            //Vez do player
            while(flagLinhas == 0){
                if(tabuleiro[linhaTabela][colunaTabela - 1] == ' '){
                    tabuleiro[linhaTabela][colunaTabela - 1] = jogadorSelecionado;
                    flagLinhas = 1;
                } else if(linhaTabela <= 0){
                    system("cls");
                    errorMessageGeneral();
                    premirTeclaContinuar();
                    getChar();
                    break;
                } else if(tabuleiro[linhaTabela][colunaTabela - 1] != ' ') linhaTabela--;
            }

            //Confirmação se há vencedor ou não
            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 4; j++){
                    if(tabuleiro[i][j] == jogadorSelecionado &&
                    tabuleiro[i][j + 1] == jogadorSelecionado &&
                    tabuleiro[i][j + 2] == jogadorSelecionado &&
                    tabuleiro[i][j + 3] == jogadorSelecionado &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = jogadorSelecionado;
                        break;
                    } else if(tabuleiro[i][j] == jogadorSelecionado && 
                    tabuleiro[i + 1][j] == jogadorSelecionado &&
                    tabuleiro[i + 2][j] == jogadorSelecionado &&
                    tabuleiro[i + 3][j] == jogadorSelecionado &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = jogadorSelecionado;
                        break;
                    } else if(tabuleiro[i][j] == jogadorSelecionado &&
                    tabuleiro[i - 1][j + 1] == jogadorSelecionado &&
                    tabuleiro[i - 2][j + 2] == jogadorSelecionado &&
                    tabuleiro[i - 3][j + 3] == jogadorSelecionado &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = jogadorSelecionado;
                        break;
                    } else if(tabuleiro[i][j] == jogadorSelecionado &&
                    tabuleiro[i - 3][j - 3] == jogadorSelecionado &&
                    tabuleiro[i - 2][j - 2] == jogadorSelecionado &&
                    tabuleiro[i - 1][j - 1] == jogadorSelecionado &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = jogadorSelecionado;
                        break;
                    } else continue;
                }
            }
        } else{
            system("cls");
            errorMessageGeneral();
            premirTeclaContinuar();
            getChar();
        }

        system("cls");

        desenharParteDeCima();
        
        printf("\n");

        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 7; j++){
                printf("| %c |\t", tabuleiro[i][j]);
            }
            printf("\n");
        }
        
        //trocar de jogador
        jogadorSelecionado = trocarJogador(jogadorSelecionado);
    }

    //Verificação para adicionar pontos ao jogador vencedor
    if(jogadorVencedor == 'X') pontosJogadorX++;
    else if(jogadorVencedor == '0') pontosJogadorY++;

    system("cls");
    desenharParteDeCima();
            
    printf("\n");

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 7; j++){
            printf("| %c |\t", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");
    if(rondas != 42){
        if(jogadorVencedor == 'X') printf("\nO jogador vencedor e: %s\tPontuacao de %s: %d\tPontuacao de %s: %d\n", player, player, pontosJogadorX, playerDois, pontosJogadorY);
        else if(jogadorVencedor == '0') printf("\nO jogador vencedor e: %s\tPontuacao de %s: %d\tPontuacao de %s: %d\n", playerDois, player, pontosJogadorX, playerDois, pontosJogadorY);
        
        adicionarPontosAoJogador(player, pontosJogadorX, QuatroLinha1v1);
        adicionarPontosAoJogador(playerDois, pontosJogadorY, QuatroLinha1v1);
    } else printf("\nEmpate!\tPontuacao do Jogador X: %d\tPontuacao do Jogador Y: %d\n", jogadorVencedor, pontosJogadorX, pontosJogadorY);

    getChar();
}