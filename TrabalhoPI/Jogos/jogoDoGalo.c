//Jogo_do_Galo--------------------------------
void jogoDoGalo()
{
    int flags = 0, flag = 0, flagB = 0, temp = 0, J = 1, v1 = 0, v2 = 0, P1 = 0, P2 = 0, jogador1 = 0, jogador2 = 0, c = 0, JP1 = 0, JP2 = 0, v;
    char tabuleiro[] = {'1','2','3','4','5','6','7','8','9'};
   
    //Ver o jogador que joga primeiro
    jogador1 = generateRandomInt(0, 2);
    if (jogador1 == 0)//jogador1 joga em segundo
    {
        JP2 = 1;
        jogador2 = 1;
    }
    else
        JP1 = 1;

    while (flags == 0)
    {
        while (flag == 0)
        {
            //Escreve o tabuleiro
            tabjogo(tabuleiro);

            //Input
            if (jogador1 == 1)
                printf("Jogador(1):\n-Escolha uma coordenada para jogar:\n");
            if (jogador2 == 1)
                printf("Jogador(2):\nEscolha uma coordenada para jogar:\n");
            scanf("%d", &temp);
           

            #pragma region Imprimir a jogada no tabuleiro
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
            #pragma endregion
           
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

            //FUNÇAO DE VERIFICAÇAO DE VITORIA
            v = vganhou(tabuleiro);
            
            if(v == 1)
            {
                v1 = 1;
                flag = 1;
            }
            else if(v == 2)
            {
                v2 = 1;
                flag = 1;
            }
            c++;
            if(v1 == 0 && v2 == 0 && c == 9)
                flag = 1;

           
        }

        if (v1 == 1)
        {
            system("cls");
            tabjogo(tabuleiro);
            printf("\n");
            printf("Vitoria do jogador(1)!\n");

            //Sistema de pontos
            if (JP1 == 1)
            {
                P1++;
                if(P2 - 1 < 0)
                    P2 = 0;
                else
                    P2--;
            }
            else
            {
                P1 += 2;          
                if(P2 - 2 < 0)
                    P2 = 0;
                else
                    P2 -= 2;
            }
        }
        else if(v2 == 1)
        {
            system("cls");
            tabjogo(tabuleiro);
            printf("\n");
            printf("Vitoria do jogador(2)!\n");

            //Sistema de pontos!
            if (JP2 == 1)
            {
                P2++;
                if(P1 - 1 < 0)
                    P1 = 0;
                else
                    P1--;
            }
            else
            {
                P2 += 2;          
                if(P1 - 2 < 0)
                    P1 = 0;
                else
                    P1 -= 2;
            }
        }
        else
        {
            system("cls");
            tabjogo(tabuleiro);
            printf("\n");
            printf("Empate!!\n");
        }

        //Output que mostra a scoreboard entre os dois jogadores
        printf("Pontos do jogador(1):\n%d\n\nPontos do jogador(2):\n%d\n", P1, P2);
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
            c = 0;

            jogador1 = generateRandomInt(0, 2);
            if (jogador1 == 0)//jogador1 joga em segundo
            {
                JP1 = 0;
                JP2 = 1;
                jogador2 = 1;
            }
            else
            {
                jogador2 = 0;
                JP2 = 0;
                JP1 = 1;
            }
        }
    }
}