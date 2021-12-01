void jogoDaForca() {
	char* player = umJogadorEscolhido();
    getChar();

	int vidas = 6;
	char letras_inseridas[26];
	char tentativa[50];
	int i;

	char palavras[26][50] = { //[quantas palavras][tamanho das palavras]
		"vaca",
		"abelha",
		"cavalo",
		"sapo",
		"ovelha",
		"passaro",
		"albatroz",
		"anta",
		"aranha",
		"borboleta",
		"bufalo",
		"baleia",
		"castor",
		"chimpanze",
		"coala",
		"foca",
		"gafanhoto",
		"ganso",
		"jacare",
		"raposa",
		"crocodilo",
		"tigre",
		"vespa",
		"urubu"
	};

	char* palavraescolhida;
	palavraescolhida = palavras[generateRandomInt(0, 25)];
	for (i = 0; i < strlen(palavraescolhida); i++) {
		tentativa[i] = '_';
	}
	tentativa[i] = '\0';
	
	
	int n_jogadas=0;
	char erro1 = ' ', erro2 = ' ', erro3 = ' ', erro4 = ' ', erro5 = ' ', erro6 = ' ', erro7 = ' ';

    system("cls");

	while (vidas != 0 && strcmp(palavraescolhida,tentativa)!=0) {

		
		char letra_inserida, letracerta;
		printf("%s\n\n\n", tentativa);  //Printa a palavra aleatória escolhida

		printf("Dica: ANIMAL!\n\n");

		printf("  _______       \n");
		printf(" |/      |      \n");
		printf(" |       %c      \n", erro1);
		printf(" |       %c    \n",  erro2);
		printf(" |       %c    \n", erro3);
		printf(" |       %c   \n", erro4);
		printf(" |              \n", erro5);
		printf("_|___           \n");
		printf("\n\n");

		printf("Introduza uma letra: ");
		//scanf("%c", &letra_inserida);
		letra_inserida = getValidChar();

		int acertou = 0;

		letras_inseridas[n_jogadas] = letra_inserida;

		for (i = 0; i < strlen(palavraescolhida); i++) {
			if (palavraescolhida[i] == letra_inserida ) {
				acertou = 1;
				tentativa[i] = letra_inserida;		
				printf("Acertou a letra na casa numero %d\n\n",i+1);
			}
		}

		if (acertou == 0) {
			printf("Errou a letra\n");
			vidas= vidas - 1;
			printf("Vidas restantes: %d\n\n\n", vidas);

		}
		n_jogadas = n_jogadas + 1;	
		if (vidas == 5)
			erro1 = 001;
		if (vidas == 4)
			erro1 = 'O';
		if (vidas == 3)
			erro2 = 197;
		if (vidas == 2)
			erro3 = '|';
		if (vidas == 1)
			erro4 = 94;
		system("pause");
		system("cls");
	}

	if (vidas == 0) {
		printf("GAME OVER!\n\n");
		printf("A palavra era : %s\n\n", palavraescolhida);

		getChar();

	}
	else {
		printf("VOCE GANHOU O JOGO!\n\n");
		printf("A palavra era : %s\n\n", palavraescolhida);
		adicionarPontosAoJogador(player, 1, AdivinhaNumero);
		getChar();
	}
	system("pause");
}