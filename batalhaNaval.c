#include <stdio.h>

#define TAM 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

// Função para verificar se uma posição está dentro do tabuleiro
int dentroLimites(int linha, int coluna) {
    return linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM;
}

// Função para verificar se um navio pode ser colocado sem sobreposição
int podeColocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int novaLinha = linha + i * direcaoLinha;
        int novaColuna = coluna + i * direcaoColuna;

        if (!dentroLimites(novaLinha, novaColuna) || tabuleiro[novaLinha][novaColuna] != AGUA) {
            return 0; // Fora do tabuleiro ou já ocupado
        }
    }
    return 1;
}

// Função para colocar um navio no tabuleiro
void colocarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcaoLinha, int direcaoColuna) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i * direcaoLinha][coluna + i * direcaoColuna] = NAVIO;
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro:\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = { {0} }; // Inicializa o tabuleiro com 0 (água)

    // Coordenadas e direções predefinidas para 4 navios
    // Dois lineares: horizontal e vertical
    int navios[4][4] = {
        {0, 0, 0, 1},   // horizontal (linha constante, coluna aumenta)
        {2, 5, 1, 0},   // vertical (linha aumenta, coluna constante)
        {4, 4, 1, 1},   // diagonal principal (i,i)
        {7, 2, -1, 1}   // diagonal secundária (i, 9-i)
    };

    // Colocar os navios
    for (int i = 0; i < 4; i++) {
        int linha = navios[i][0];
        int coluna = navios[i][1];
        int direcaoLinha = navios[i][2];
        int direcaoColuna = navios[i][3];

        if (podeColocarNavio(tabuleiro, linha, coluna, direcaoLinha, direcaoColuna)) {
            colocarNavio(tabuleiro, linha, coluna, direcaoLinha, direcaoColuna);
        } else {
            printf("Erro: Não foi possível posicionar o navio %d.\n", i + 1);
        }
    }

    // Exibir o tabuleiro
    imprimirTabuleiro(tabuleiro);

    return 0;
}

