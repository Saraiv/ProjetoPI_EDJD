//JOGO OITO
void quatroEmLinhaVsCPU(){
    char jogadorSelecionado = 'X', tabuleiro[6][7], jogadorVencedor = 'p';
    int rondas = 0, 
    //Variaveis do jogador
    pontosJogadorX = 0, linhaTabela = 6, flagVezDeJogador = 0, flagLinhas = 0, flagColunas = 0, colunaTabela = -1, 
    //Variaveis do CPU
    pontosCPU = 0, linhaTabelaCPU = 6, flagVezDoCPU = 0, flagLinhasCPU = 0, flagColunasCPU = 0, colunaTabelaCPU = -1;
    system("cls");

    //Desenho da tabela
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
        flagColunasCPU = 0;

        //cada jogada
        while(flagColunas == 0){
            printf("\nJogador %c, em que coluna quer jogar? ", jogadorSelecionado);
            scanf("%d", &colunaTabela);
            if(colunaTabela >= 1 && colunaTabela <= 7){
                flagColunas = 1;
            } else{
                system("cls");
                errorMessageGeneral();
                system("PAUSE");
                printf("\n");
            }
        }

        //Vez do Jogador
        if(colunaTabela != -1){
            flagLinhas = 0;
            linhaTabela = 5;
            flagLinhasCPU = 0;

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
                    system("PAUSE");
                    break;
                } else if(tabuleiro[linhaTabela][colunaTabela - 1] != ' ') linhaTabela--;
            }

            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 7; j++){
                    if(tabuleiro[i][j] == 'X' && 
                    tabuleiro[i][j + 1] == 'X' && 
                    tabuleiro[i][j + 2] == 'X' && 
                    tabuleiro[i][j + 3] == 'X' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = 'X';
                        break;
                    } else if(tabuleiro[i][j] == 'X' && 
                    tabuleiro[i + 1][j] == 'X' && 
                    tabuleiro[i + 2][j] == 'X' && 
                    tabuleiro[i + 3][j] == 'X' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = 'X';
                        break;
                    } else if(tabuleiro[i][j] == 'X' &&
                    tabuleiro[i - 1][j + 1] == 'X' && 
                    tabuleiro[i - 2][j + 2] == 'X' && 
                    tabuleiro[i - 3][j + 3] == 'X' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = 'X';
                        break;
                    } else if(tabuleiro[i - 3][j - 3] == 'X' &&
                    tabuleiro[i - 2][j - 2] == 'X' && 
                    tabuleiro[i - 1][j - 1] == 'X' && 
                    tabuleiro[i][j] == 'X' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = 'X';
                        break;
                    } else continue;
                }
            }
        } else{
            system("cls");
            errorMessageGeneral();
            system("PAUSE");
        }

        //Vez do CPU
        if(colunaTabela != -1){
            flagLinhasCPU = 0;
            linhaTabelaCPU = 5;
            flagLinhasCPU = 0;

            desenharParteDeCima();

            if(tabuleiro[0][0] == '\0'){
                tabuleiro[0][0] = ' ';
            }

            printf("\n");

            while(flagColunasCPU == 0){
                colunaTabelaCPU = generateRandomInt(1, 7);
                if(colunaTabelaCPU >= 1 && colunaTabelaCPU <= 7){
                    flagColunasCPU = 1;
                }
            }

            while(flagLinhasCPU == 0){
                if(tabuleiro[linhaTabelaCPU][colunaTabelaCPU - 1] == ' '){
                    tabuleiro[linhaTabelaCPU][colunaTabelaCPU - 1] = '0';
                    flagLinhasCPU = 1;
                } else if(linhaTabelaCPU <= 0){
                    system("cls");
                    errorMessageGeneral();
                    system("PAUSE");
                    break;
                } else if(tabuleiro[linhaTabelaCPU][colunaTabelaCPU - 1] != ' ') linhaTabelaCPU--;
            }

            for(int i = 0; i < 6; i++){
                for(int j = 0; j < 7; j++){
                    if(tabuleiro[i][j] == '0' && 
                    tabuleiro[i][j + 1] == '0' && 
                    tabuleiro[i][j + 2] == '0' && 
                    tabuleiro[i][j + 3] == '0' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = '0';
                        break;
                    } else if(tabuleiro[i][j] == '0' && 
                    tabuleiro[i + 1][j] == '0' && 
                    tabuleiro[i + 2][j] == '0' && 
                    tabuleiro[i + 3][j] == '0' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = '0';
                        break;
                    } else if(tabuleiro[i][j] == '0' &&
                    tabuleiro[i - 1][j + 1] == '0' && 
                    tabuleiro[i - 2][j + 2] == '0' && 
                    tabuleiro[i - 3][j + 3] == '0' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = '0';
                        break;
                    } else if(tabuleiro[i - 3][j - 3] == '0' &&
                    tabuleiro[i - 2][j - 2] == '0' && 
                    tabuleiro[i - 1][j - 1] == '0' && 
                    tabuleiro[i][j] == '0' &&
                    tabuleiro[i][j] != ' '){
                        jogadorVencedor = '0';
                        break;
                    } else continue;
                }
            }
        } else{
            system("cls");
            errorMessageGeneral();
            system("PAUSE");
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
    }

    
    if(jogadorVencedor == 'X') pontosJogadorX++;
    else if(jogadorVencedor == '0') pontosCPU++;

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
        printf("\nO jogador vencedor é: %c\tPontuacao do Jogador X: %d\tPontuacao do CPU: %d\n", jogadorVencedor, pontosJogadorX, pontosCPU);
    } else printf("\nEmpate!\tPontuacao do Jogador X: %d\tPontuacao do CPU: %d\n", jogadorVencedor, pontosJogadorX, pontosCPU);
    system("PAUSE");
}