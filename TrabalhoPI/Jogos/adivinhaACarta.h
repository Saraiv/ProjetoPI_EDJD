//Normal includes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//helpers functions
char naipeToString(int naipe);
int generateRandomInt(int min, int max);
void errorMessageGeneral();
void errorMessageGame();

//JOGO DOIS
void adivinhaACarta()
{
    system("cls");
    // N- Naipe aleatorio || carta- carta aleatoria || Tc- Tentativa de acertar a carta || naipes- tentativa de acertar os naipes 
    // nt- numero de tentativas|| P- Pontos || np- numero de pontos
    int N = 0, carta = 0, Tc = 0, flag1 = 0, flag2 = 0, nt = 0,np = 0, P = 0;
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
    printf("\n%s", NC);
    printf("\n%d", carta);
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
                printf("\nAcertou o naipe!!\n\n");
                flag1 = 1;
            }
            if (strcmp(naipes, NC) != 0)
                printf("\nFalhou o naipe!!\n\n");
        }

        if (flag2 == 0) {
            printf("\tCada carta tem um valor correspondente ao seu simbolo\n\t\tAs-1 Valete-11 Dama-12 Rei-13\n\t\t\tEscolha a carta:\n");
            scanf("%d", &Tc);
            //Sistema de comparação do input Cartas
            if (Tc < carta)
                printf("%c O valor da carta e superior %c\n\n", 30, 30);
            if (Tc > carta)
                printf("%c O valor da carta e inferior %c\n\n", 31, 31);
            if (Tc == carta)
            {
                printf("Acertou o valor da carta!\n\n");
                flag2 = 1;
            }
        }
        
        //Contar o numero de tentativas
        if(flag1 == 0 || flag2 == 0)
            np++;
        nt++;
    }

    //Atribuição dos pontos
    P = 6 - np;
    if (P < 0)
        P = 0;

    while (flag1 == 1)
    {
        system("cls");
        printf("\nA sua pontuacao foi: %d\nPrecisou de %d tentativa(s).\n", P, nt);
        printf("Se pretende sair prima (0)\n");
        scanf("%d", &flag1);
        
    }
}