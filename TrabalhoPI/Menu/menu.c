//menu principal
void menuJogos();
void pontosGlobais();
void pontosPJogo();
void pontosPJogadorGlobal();
void introduzirJogadores();
void receberTodosJogadoresEOrdenar();
int countJogadores();

void menuIGA(){
    //variaveis
    int escolha = -1, flag = 0, count = countJogadores() - 1;;
    struct Jogador Jogadores[200];

    do{
        system("cls");

        //menu principal
        printf("\nIPCA GAMES ARCH\n\n1- Selecionar um jogo \n2- Pontos globais \n3- Pontos dos 10 melhores jogadores p/ jogo \n");
        printf("4- Pontos dos 10 melhores jogadores \n5- Introduzir jogadores \n0- Sair\n");

        scanf("%d", &escolha);
        switch(escolha){
            case 1:
                menuJogos();
                break;
            case 2:
                pontosGlobais();
                premirTeclaContinuar();
                getChar();
                break;
            case 3:
                pontosPJogo();
                getChar();
                break;
            case 4:
                pontosPJogadorGlobal();
                premirTeclaContinuar();
                getChar();
                break;
            case 5:
                introduzirJogadores();
                premirTeclaContinuar();
                getChar();
                break;
            case 0:
                flag = -1;
                break;
            default:
                errorMessageGeneral();
                break;
        }
    } while (flag == 0);
}