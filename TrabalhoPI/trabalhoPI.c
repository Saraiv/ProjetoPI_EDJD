#include<stdio.h>
#include<stdlib.h>

//error messages
void errorMessageGeneral();
//main funcs
void menuIGA();
void menuJogos();
void pontosGlobais();
void pontosPJogo();
void pontosPJogadorGlobal();
void introduzirJogadores();

//structures
struct player{
    char* name;
    int points;
};

void main(){
    //função do menu principal
    menuIGA();
}

//error messages
void errorMessageGeneral(){
    printf("\nOpção inserida incorreta!\n");
}


//menu principal
void menuIGA(){
    //variaveis
    int escolha = -1, flag = 0;
    
    
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
                break;
            case 3:
                pontosPJogo();
                break;
            case 4:
                pontosPJogadorGlobal();
                break;
            case 5:
                introduzirJogadores();
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

void menuJogos(){
    //variaveis
    int escolha = -1, flag = 0;
    
    system("cls");

    //menu de todos os jogos
    printf("\nIPCA GAMES ARCH\n\n1- Adivinha o número \n2- Adivinha a carta \n");
    printf("3- Vinte-e-um \n4- Jogo do Galo (1 vs 1) \n5- Jogo do Galo (1 vs CPU) \n");
    printf("6- Jogo da Forca \n7- Quatro-em-Linha (1 vs 1) \n8- Quatro-em-Linha (1 vs CPU) \n0- Sair\n");
    scanf("%d", &escolha);
    
    switch(escolha){
        case 1:
            //Adivinha o número
            printf("\nAdivinha o numero");
            break;
        case 2:
            //Adivinha a carta
            break;
        case 3:
            //Vinte-e-um
            break;
        case 4:
            //Jogo do Galo (1 vs 1)
            break;
        case 5:
            //Jogo do Galo (1 vs CPU)
            break;
        case 6:
            //Jogo da Forca
            break;
        case 7:
            //Quatro-em-Linha (1 vs 1)
            break;
        case 8:
            //Quatro-em-Linha (1 vs CPU)
            break;
        case 0:
            flag = -1;
            break;
        default:
            errorMessageGeneral();
            break;
    }    
}

//função para pontos globais
void pontosGlobais(){

}

//função para pontos dos 10 melhores jogadores por cada jogo
void pontosPJogo(){

}

//função para pontos dos 10 melhores jogadores
void pontosPJogadorGlobal(){

}

//função para introduzir jogadores
void introduzirJogadores(){

}