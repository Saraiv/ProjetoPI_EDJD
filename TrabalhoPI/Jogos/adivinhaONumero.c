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

    char* jogador = umJogadorEscolhido();
    char* player;
    player = malloc(sizeof(jogador));
    player = jogador;
    getChar();

    while(flag == 0){
        system("cls");

        printf("\nADIVINHA O NUMERO\n");

        printf("\nEscreva um numero: ");
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

            adicionarPontosAoJogador(player, pontuacaoPlayer, AdivinhaNumero);

            printf("\n\n");
            getChar();
            flag = -1;
        } else if(numAAdivinhar < num){
            printf("\nNumero maior\n");
            printf("\n\n");
            //incrementacao para numero de tentativas falhadas
            tentativasFalhadas++;
            premirTeclaContinuar();
            getChar();
            getChar();
        } else if(numAAdivinhar > num){
            printf("\nNumero menor\n");
            //incrementacao para numero de tentativas falhadas
            tentativasFalhadas++;
            printf("\n\n");
            premirTeclaContinuar();
            getChar();
            getChar();
        } else{
            errorMessageGame();
            printf("\n\n");
            premirTeclaContinuar();
            getChar();
            getChar();
        } 
    }
}