#include <stdio.h>
#include <stdlib.h>

#define FILAS 5
#define COLUMNAS 5

int fila_mov[] = {-1, 1, 0, 0};  
int col_mov[] = {0, 0, -1, 1};  

void dfs(int matriz[FILAS][COLUMNAS], int x, int y) {
    matriz[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nueva_fila = x + fila_mov[i];
        int nueva_col = y + col_mov[i];

        if (nueva_fila >= 0 && nueva_fila < FILAS && nueva_col >= 0 && nueva_col < COLUMNAS) {
            if (matriz[nueva_fila][nueva_col] == 1) {
                dfs(matriz, nueva_fila, nueva_col);  
            }
        }
    }
}

int contar_islas(int matriz[FILAS][COLUMNAS]) {
    int num_islas = 0;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (matriz[i][j] == 1) {
                dfs(matriz, i, j); 
                num_islas++; 
            }
        }
    }

    return num_islas;
}

int main() {
    int matriz[FILAS][COLUMNAS] = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 0, 1}
    };

    int islas = contar_islas(matriz);
    printf("El numero de islas es: %d\n", islas);

    return 0;
}
