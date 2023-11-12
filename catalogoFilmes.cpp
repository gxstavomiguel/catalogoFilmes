#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id;
    char titulo[100];
    char descricao[200];
    char categoria[50];
    float nota;
} Filme;


void exportarCatalogo(Filme catalogo[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%.2f\n", catalogo[i].id, catalogo[i].titulo, catalogo[i].descricao, catalogo[i].categoria, catalogo[i].nota);
    }

    fclose(arquivo);
}


int lerCatalogo(Filme catalogo[], const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    int tamanho = 0;
    char linha[500]; 

    while (fgets(linha, sizeof(linha), arquivo)) {
        sscanf(linha,"%d, %f", &catalogo[tamanho].id, catalogo[tamanho].titulo, catalogo[tamanho].descricao, catalogo[tamanho].categoria, &catalogo[tamanho].nota);
        tamanho++;
    }

    fclose(arquivo);
    return tamanho;
}

int main() {
    Filme catalogo[100]; 
    int tamCatalogo = 0;

    
    catalogo[tamCatalogo].id = 1;
    strcpy(catalogo[tamCatalogo].titulo, "Filme 1");
    strcpy(catalogo[tamCatalogo].descricao, "Descricao do Filme 1");
    strcpy(catalogo[tamCatalogo].categoria, "Acao");
    catalogo[tamCatalogo].nota = 4.5;
    tamCatalogo++;

    catalogo[tamCatalogo].id = 2;
    strcpy(catalogo[tamCatalogo].titulo, "Filme 2");
    strcpy(catalogo[tamCatalogo].descricao, "Descricao do Filme 2");
    strcpy(catalogo[tamCatalogo].categoria, "Comedia");
    catalogo[tamCatalogo].nota = 3.8;
    tamCatalogo++;

    
    exportarCatalogo(catalogo, tamCatalogo, "catalogo.txt");

    
    int tamanhoLido = lerCatalogo(catalogo, "catalogo.txt");

    
    for (int i = 0; i < tamanhoLido; i++) {
        printf("ID: %d\n", catalogo[i].id);
        printf("Titulo: %s\n", catalogo[i].titulo);
        printf("Descricao: %s\n", catalogo[i].descricao);
        printf("Categoria: %s\n", catalogo[i].categoria);
        printf("Nota: %.2f\n\n", catalogo[i].nota);
    }

    return 0;
}

