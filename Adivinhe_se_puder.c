#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int dificuldade=0, x=0, modo=0, tentativa=0, i=0, denovo=1;

    while(denovo==1) {
        printf("\n\t- - - - - - - - Adivivnhe se puder - - - - - - - - \n\n");
        printf("Bem vindo ao Adivinhe se Puder! Escolha o nivel de dificuldade:\n\t1. Facil (numeros entre 1 e 100)\n\t2. Medio (numeros entre 1 e 200)\n\t3. Dificil (numeros entre 1 e 300)\n:. ");
        scanf("%d", &dificuldade);

        while ((dificuldade<1) || (dificuldade>3)) {
            printf("Coekkkkk eh 1, 2 ou 3 manezao...\n:. ");
            scanf("%d", &dificuldade);
        }
        if(dificuldade==1) x=100;
        else if(dificuldade==2) x=200;
        else if  (dificuldade==3) x=300;

        printf("\nBeleza! Agora, escolha o modo de jogo:\n\t1. Single player\n\t2. Multiplayer\n:. ");
        scanf("%d", &modo);

        if(modo==1) { // singleplayer
            // Gera um número aleatório entre 1 e x
            int numeroAleatorio = rand() % x + 1;

            //printf("%d shhhhhhh\n", numeroAleatorio);
            printf("\nDigite seu primeiro palpite:\n:. "); i=1;
            while (scanf("%d", &tentativa)) {
                if(tentativa == numeroAleatorio) break;
                i++;
                if (tentativa > numeroAleatorio) printf("Tente numeros menores!\n:. ");
                else printf("Tente numeros maiores!\n:. ");
            }
            printf("\n\t- - - PARABENS!!!! Voce acertou o numero %d em %d tentativas! - - -\n\tPontuacao final: %d\n\n", numeroAleatorio, i, x-i);
        }
        else if(modo==2) { // multiplayer
            int numeroAleatorio=0;
            printf("Player 1, digite o numero secreto: ");
            scanf("%d", &numeroAleatorio);
            while ((numeroAleatorio>x) || (numeroAleatorio<1)) {
                printf("Coekkkkk entre 1 e %d tabacudo...\n:. ", x);
                scanf("%d", &numeroAleatorio);
            }
            for (int k = 0; k < 100; k++) {printf("\n");}   

            //printf("%d shhhhhhh\n", numeroAleatorio);
            printf("\nPlayer 2, digite seu primeiro palpite:\n:. "); i=1;

            while (scanf("%d", &tentativa)) {
                if(tentativa == numeroAleatorio) break;
                i++;
                if (tentativa > numeroAleatorio) printf("Tente numeros menores!\n:. ");
                else printf("Tente numeros maiores!\n:. ");
            }

            printf("\n\t- - - PARABENS!!!! Voce acertou o numero %d em %d tentativas! - - -\nPontuacao final: %d\n\n", numeroAleatorio, i, x-i);
            
        }
        else {
            while ((modo<1) || (modo>2)) {
                printf("Coekkkkk eh 1 ou 2 bobinho...\n:. ");
                scanf("%d", &modo);
            }
        }

        printf("1. Jogar novamente\n2. Sair\n:. "); scanf("%d", &denovo); printf("\n");
    }

    return 0;
}
