#include <stdlib.h>
#include <string.h>
#include <stdio.h>

 

FILE *arquivo;

 

struct paciente {
	char nome[100];
	char sobrenome[100];
	int idade;
	float peso;
	float altura; 
};

 

void salvarArquivo(struct paciente p) {
	arquivo = fopen("log_atendimento.txt", "a");
	char conteudo[400];

	p.nome[strcspn(p.nome, "\n")] = '\0';
	p.sobrenome[strcspn(p.sobrenome, "\n")] = '\0';

	sprintf(conteudo, "%s %s %d %f %f \n", p.nome, p.sobrenome, p.idade, p.peso, p.altura);

	fprintf(arquivo, conteudo);
	fclose(arquivo);
}

 

void registraPaciente() {
	struct paciente p;

	printf("\nPrimeiro Nome: ");
	fgets(p.nome, 100, stdin);

	printf("Sobrenome: ");
	fgets(p.sobrenome, 100, stdin);

	printf("Idade: ");
	scanf("%d", &p.idade);

	printf("Peso: ");
	scanf("%f", &p.peso);

	printf("Altura: ");
	scanf("%f", &p.altura);

	salvarArquivo(p);
}

 

void infoArquivo() {
	int cont_caracteres =0;
	int cont_linhas = 0;
	char c;

	arquivo = fopen("log_atendimento.txt", "r");

	if(arquivo == NULL) {
		printf("\n Sem registro de atendimento \n\n");
	} else {
		for(c = getc(arquivo); c != EOF; c = getc(arquivo)) {
			cont_caracteres = cont_caracteres + 1;
			if(c == '\n') 
				cont_linhas = cont_linhas + 1;
		}
	}

	fclose(arquivo);

	printf("\n O arquivo tem %d caracteres \n", cont_caracteres);
	printf("O arquivo tem %d linhas \n\n", cont_linhas);
}

 

int main(int argc, char *argv[]) {
	printf("### Registro de Atendimento do Paciente ### \n");

	int opcao = -1;

	// Menu 
	printf("Menu: \n");
	printf("1. Registrar paciente \n");
	printf("2. Informacoes do Arquivo \n");
	printf("0. Fim \n");

	while(1) {
		printf("\n Entre a opcao escolhida: ");
		scanf("%d", &opcao);
		getchar();

		if (opcao == 1) {
			registraPaciente();
		}
		else if (opcao == 2) {
			infoArquivo();
		}
		else if (opcao == 0) {
			printf("Tchau!! \n\n");
			break;
		}
		else {
			printf("> Opcao invalida \n");
		}
	}
	return 0;
}
