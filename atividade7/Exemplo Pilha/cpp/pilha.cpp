#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define N 5

typedef struct PILHA{
	int dados[N];
	int topo;
};

void inicializaPilha(PILHA *p){
	int i;
	for(i=0; i < N; i++){
		p->dados[i] = 0;
	}
	p->topo = 0;
}

void novaPagina(int dado, PILHA *p){
	if(p->topo == N){
		printf("MAX\n");
		return;
	}
	else{
		p->dados[p->topo] = dado;
		p->topo++;
		return;
	}
}

int removerHistorico(PILHA *p){
	if(p->topo == 0){
		printf("Historico Limpo\n");
		return 1;
	}
	else {
		p->topo--;
		return p->dados[p->topo];
	}
}

void historico(PILHA *p){
	int i;
	printf("Historico de navegacao: \n");
	for(i = 0; i < p->topo ; i++){
		printf("%d ", p->dados[i]);
	}
}

int main(){
	
	PILHA p1;
	
	inicializaPilha(&p1);
	
	novaPagina(1, &p1);
	novaPagina(2, &p1);
	novaPagina(3, &p1);
	novaPagina(4, &p1);
	novaPagina(5, &p1);
	
	historico(&p1);
	
	printf("\n");
	system("pause");
	system("cls");
	
	printf("Apagar Historico: \n");
	
	printf("Removendo do Historico: %d\n", removerHistorico(&p1));
	printf("Removendo do Historico: %d\n", removerHistorico(&p1));
	printf("Removendo do Historico: %d\n", removerHistorico(&p1));
	printf("Removendo do Historico: %d\n", removerHistorico(&p1));
	printf("Removendo do Historico: %d\n", removerHistorico(&p1));
	printf("\n");
	
	removerHistorico(&p1);
	
	return 0;
}
