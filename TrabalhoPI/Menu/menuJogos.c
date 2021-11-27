#include"../Ficheiros/adicionarJogadores.c"

void menuJogos(){
    //variaveis
    int escolha = -1, flag = 0;
    
    system("cls");

    //menu de todos os jogos
    printf("\nIPCA GAMES ARCH\n\n1- Adivinha o numero \n2- Adivinha a carta \n");
    printf("3- Vinte-e-um \n4- Jogo do Galo (1 vs 1) \n5- Jogo do Galo (1 vs CPU) \n");
    printf("6- Jogo da Forca \n7- Quatro-em-Linha (1 vs 1) \n8- Quatro-em-Linha (1 vs CPU) \n0- Sair\n");
    scanf("%d", &escolha);
    
    switch(escolha){
        case 1:
            //Adivinha o número
            adivinhaONumero();
            premirTeclaContinuar();
            getChar();
            break;
        case 2:
            //Adivinha a carta
            adivinhaACarta();
            premirTeclaContinuar();
            getChar();
            break;
        case 3:
            //Vinte-e-um
            vinteEUm();
            premirTeclaContinuar();
            getChar();
            break;
        case 4:
            //Jogo do Galo (1 vs 1)
            jogoDoGalo();
            premirTeclaContinuar();
            getChar();
            break;
        case 5:
            //Jogo do Galo (1 vs CPU)
            jogoDoGaloVsCPU();
            premirTeclaContinuar();
            getChar();
            break;
        case 6:
            //Jogo da Forca
            premirTeclaContinuar();
            getChar();
            break;
        case 7:
            //Quatro-em-Linha (1 vs 1)
            quatroEmLinha();
            premirTeclaContinuar();
            getChar();
            break;
        case 8:
            //Quatro-em-Linha (1 vs CPU)
            quatroEmLinhaVsCPU();
            premirTeclaContinuar();
            getChar();
            break;
        case 0:
            flag = -1;
            break;
        default:
            premirTeclaContinuar();
            getChar();
            errorMessageGeneral();
            break;
    }    
}