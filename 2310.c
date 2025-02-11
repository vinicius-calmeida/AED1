#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


struct Jogador{
	int saques, bloqueios, ataques;
	int PontoS, PontoB, PontoA;
};

int main()
{
	short NJogadores;
	char nomeJogador[100];
	long S = 0;
    long B = 0;
    long A = 0;
    long TotalPontoS = 0;
    long TotalPontoB = 0;
    long TotalPontoA = 0;
	struct Jogador jogador;
	
	scanf("%hd", &NJogadores);
	
	while(NJogadores--)
    {
		scanf("%s %d %d %d", nomeJogador, &jogador.saques, &jogador.bloqueios, &jogador.ataques);
		scanf("%d %d %d", &jogador.PontoS, &jogador.PontoB, &jogador.PontoA);
		
        S += jogador.saques;
        B += jogador.bloqueios;
        A += jogador.ataques;	

        TotalPontoS += jogador.PontoS;
        TotalPontoB += jogador.PontoB;
        TotalPontoA += jogador.PontoA;
		
	}

	printf("Pontos de Saque: %.2lf %%.\n", (TotalPontoS*100.)/S);
	printf("Pontos de Bloqueio: %.2lf %%.\n", (TotalPontoB*100.)/B);
	printf("Pontos de Ataque: %.2lf %%.\n", (TotalPontoA*100.)/A);
	
	return 0;
}
