//Função para introduzir jogadores
void introduzirJogadores(){
    char Jogador[10];
    char writeFile;
    int flag = 0;
    do{
        system("cls");
        printf("INSERCAO DE JOGADORES");
        printf("\n\nNome do jogador ate 10 caracteres:\n");
        scanf("%s", Jogador);
        if(strlen(Jogador) <= 10 && strlen(Jogador) > 0){
            flag = 1;
        } else {
            printf("\nHouve algum erro na insercao do jogador!\nTente novamente.");
            flag = 0;
            premirTeclaContinuar();
            getChar();
        }
        getChar();
    }while(flag == 0);

    FILE *fJogadores = NULL;

	fJogadores = fopen("Ficheiros/Jogadores.txt", "a");

	if(fJogadores == NULL){
		perror("Error");
	}

	fprintf(fJogadores, "%s 0 0 0 0 0 0 0 0\n", Jogador);
	
	fclose(fJogadores);

    printf("\n\nJogador adicionado com sucesso!\n");
}