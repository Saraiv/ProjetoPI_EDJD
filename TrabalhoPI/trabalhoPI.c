#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//error messages
void errorMessageGeneral();
//main funcs
void menuIGA();
void menuJogos();
void pontosGlobais();
void pontosPJogo();
void pontosPJogadorGlobal();
void introduzirJogadores();

//jogos
void adivinhaONumero();
void Adivinha_a_Carta();
void vinteEUm();

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
            adivinhaONumero();
            break;
        case 2:
            //Adivinha a carta
            adivinhaACarta();
            break;
        case 3:
            //Vinte-e-um
            vinteEUm();
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

int generateRandomInt(int min, int max) {
    srand((unsigned)time(NULL));
    return min + rand() % (max - min);
}


//jogos
void adivinhaONumero(){
    int numAAdivinhar = 0, num = 0, flag = 0, tentativas = 0, tentativasFalhadas = 0, pontuacao = 0;

    num = generateRandomInt(0, 100);

    while(flag == 0){
        system("cls");
        
        // printf("\n%d\n", num);

        printf("\nEscreva um número: ");
        scanf("%d", &numAAdivinhar);

        tentativas++;

        if(num == numAAdivinhar){
            printf("\nAcertou!\n");
            printf("\nTentativas: %d\n", tentativas);
            
            //sistema de pontos
            if(tentativas <= 0) pontuacao = 0; 
            else if(tentativas == 1) pontuacao = 10; 
            else if(tentativas >= 10) pontuacao = 0;
            else pontuacao = 10 - tentativasFalhadas;

            printf("\nPontos: %d\n", pontuacao);
            printf("\n\n");
            system("PAUSE");
            flag = -1;
        } else if(numAAdivinhar < num){
            printf("\nNúmero maior\n");
            printf("\n\n");
            tentativasFalhadas++;
            system("PAUSE");
        } else if(numAAdivinhar > num){
            printf("\nNúmero menor\n");
            tentativasFalhadas++;
            printf("\n\n");
            system("PAUSE");
        } else{
            printf("\nErrou!\n");
            printf("\n\n");
            system("PAUSE");
        } 
    }
}

void adivinhaACarta()
{
    system("cls");
    // N- Naipe aleatorio || carta- carta aleatoria || Tc- Tentativa de acertar a carta || naipes- tentativa de acertar os naipes 
    // nt- numero de tentativas|| P- Pontos
    int N = 0, carta = 0, Tc = 0, flag1 = 0, flag2 = 0, nt = 0, P = 0;
    char naipes[10], NC[10] = "0";
    
    //criar carta aleatoria
    carta = generateRandomInt(1, 13);
    
    //Criar a comparação de strings n=1(Copas) n=2(Espadas) n=3(Paus) n=4(Ouros)
    
    N = generateRandomInt(1, 4);
    
    if (N == 1)
       memcpy(NC, "copas", 10);
    if(N == 2)
        memcpy(NC, "espadas", 10);
    if(N == 3)
        memcpy(NC, "paus", 10);
    if (N == 4)
        memcpy(NC, "ouros", 10);

    //----------------------------------------------
   
    while (flag1 == 0 || flag2 == 0)
    {

        if (flag1 == 0) {
            
            //Input do utilizador
            printf("\tOuros Copas Espadas Paus\n\t    Escolha um naipe:\n");
            scanf("%s", &naipes);
            
            //Converter todos os caracteres para minuscula assim o programa nao e sensivel a maiusculas e minusculas
            for (int i = 0; naipes[i] != '\0'; i++) {
                if (naipes[i] >= 'A' && naipes[i] <= 'Z') {
                    naipes[i] = naipes[i] + 32;
                }
            }

            //Sistema de comparação do input NAIPES

            if (strcmp(naipes, NC) == 0) {
                printf("\nAcertou o naipe!!\n");
                flag1 = 1;
            }
            if (strcmp(naipes, NC) != 0)
                printf("\nFalhou o naipe!!\n");
        }

        if (flag2 == 0) {
            printf("\tCada carta tem um valor correspondente ao seu simbolo\n\t\tAs-1 Valete-11 Dama-12 Rei-13\n\t\t\tEscolha a carta:\n");
            scanf("%d", &Tc);
            //Sistema de comparação do input Cartas
            if (Tc < carta)
                printf("%c O valor da carta e superior %c\n", 30, 30);
            if (Tc > carta)
                printf("%c O valor da carta e inferior %c\n", 31, 31);
            if (Tc == carta)
            {
                printf("Acertou o valor da carta!\n");
                flag2 = 1;
            }
        }
        
        //Contar o numero de tentativas
        nt++;
    }

    //Atribuição dos pontos
    P = 6 - nt;
    if (P < 0)
        P = 0;

    while (flag1 == 1)
    {
        system("cls");
        printf("\nA sua pontuacao foi: %d\nPrecisou de %d tentativas.\n", P, nt);
        printf("Se pretende sair prima (0)\n");
        scanf("%d", &flag1);
        
    }
}

void vinteEUm(){
    
}