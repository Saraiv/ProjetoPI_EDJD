//JOGO SETE
char trocarJogador(char jogador) {
    if (jogador == 'X') {
        return '0';
    } else {
        return 'X';
    }
}

void desenharParteDeCima(){
    int columnNumber = 1;
    while(columnNumber != 8)
        printf("| %d | \t", columnNumber++);
}

void quatroEmLinha(){
    char jogadorSelecionado = 'X', tabuleiro[6][7], jogadorVencedor = 'p';
    int rondas = 0, colunaTabela = -1, pontosJogadorX = 0, pontosJogadorY = 0, 
    linhaTabela = 6, flagVezDeJogador = 0, flagLinhas = 0, flagColunas = 0;
    system("cls");

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

        //cada jogada TODO
        while(flagColunas == 0){
            printf("\nJogador %c, em que coluna quer jogar? ", jogadorSelecionado);
            scanf("%d", &colunaTabela);
            if(colunaTabela >= 1 && colunaTabela <= 6){
                flagColunas = 1;
            } else{
                errorMessageGeneral();
                system("PAUSE");
                printf("\n");
            }
        }


        if(colunaTabela != -1){
            flagLinhas = 0;
            linhaTabela = 5;

            desenharParteDeCima();

            if(tabuleiro[0][0] == '\0'){
                tabuleiro[0][0] = ' ';
            }

            printf("\n");

            while(flagLinhas == 0){
                if(tabuleiro[linhaTabela][colunaTabela - 1] == ' '){
                    tabuleiro[linhaTabela][colunaTabela - 1] = jogadorSelecionado;
                    flagLinhas = 1;
                } else if(linhaTabela <= 0){
                    system("cls");
                    errorMessageGeneral();
                    system("PAUSE");
                    break;
                } else if(tabuleiro[linhaTabela][colunaTabela - 1] != ' ') linhaTabela--;
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

            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 7; j++){
                    if(tabuleiro[i][j] == jogadorSelecionado && 
                    tabuleiro[i][j + 1] == jogadorSelecionado && 
                    tabuleiro[i][j + 2] == jogadorSelecionado && 
                    tabuleiro[i][j + 3] == jogadorSelecionado){
                        jogadorVencedor = jogadorSelecionado;
                        if(jogadorVencedor == 'X') pontosJogadorX++;
                        else if(jogadorVencedor == '0') pontosJogadorY++;
                    } else if(tabuleiro[i][j] == jogadorSelecionado && 
                    tabuleiro[i + 1][j] == jogadorSelecionado && 
                    tabuleiro[i + 2][j] == jogadorSelecionado && 
                    tabuleiro[i + 3][j] == jogadorSelecionado){
                        jogadorVencedor = jogadorSelecionado;
                        if(jogadorVencedor == 'X') pontosJogadorX++;
                        else if(jogadorVencedor == '0') pontosJogadorY++;
                    } else if(tabuleiro[i][j] == jogadorSelecionado && 
                    tabuleiro[i + 1][j + 1] == jogadorSelecionado && 
                    tabuleiro[i + 2][j + 2] == jogadorSelecionado && 
                    tabuleiro[i + 3][j + 3] == jogadorSelecionado){
                        jogadorVencedor = jogadorSelecionado;
                        if(jogadorVencedor == 'X') pontosJogadorX++;
                        else if(jogadorVencedor == '0') pontosJogadorY++;
                    } else continue;
                }
            }
        } else{
            system("cls");
            errorMessageGeneral();
            system("PAUSE");
        }
        
        jogadorSelecionado = trocarJogador(jogadorSelecionado);
    }

    system("cls");
    printf("\n\n");
    printf("\nO jogador vencedor é: %c\tPontuacao do Jogador X: %d\tPontuacao do Jogador Y: %d\n", jogadorVencedor, pontosJogadorX, pontosJogadorY);
    system("PAUSE");
}