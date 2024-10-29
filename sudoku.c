#include <stdio.h>

int verificarLinha(int sudoku[9][9]) {
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++) {
            int existe[10] = {0};
            if(existe[sudoku[i][j]]) {
                return 0;
            }
            existe[sudoku[i][j]] = 1;
        }
    }
    return 1;
}

int verificarColuna(int sudoku[9][9]) {
    for (int j = 0; j < 9; j++) {
        int existe[10] = {0};
        for (int i = 0; i < 9; i++) {
            if(existe[sudoku[i][j]]) {
                return 0;
            }
            existe[sudoku[i][j]] = 1;
        }
    }
    return 1;
}

int verificarBloco(int sudoku[9][9]) {
    for (int blocoI = 0; blocoI < 9; blocoI += 3) {
        for (int blocoJ = 0; blocoJ < 9; blocoJ += 3) {
            int existe[10] = {0};
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (existe[sudoku[blocoI + i][blocoJ + j]]) {
                        return 0;
                    }
                    existe[sudoku[blocoI + i][blocoJ + j]] = 1;
                }
            }
        }
    }
    return 1;
}

int main() {
    int numeroMatrizes, sudoku[9][9];
    scanf("%d", &numeroMatrizes);
    int verifica[numeroMatrizes];

    for (int k = 0; k < numeroMatrizes; k++) {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++) {
                    scanf("%d", &sudoku[i][j]);
            }
        }
        if (verificarLinha(sudoku) && verificarColuna(sudoku) && verificarBloco(sudoku)){
            verifica[k] = 1;
        } else {
            verifica[k] = 0;
        }
    }
    for (int k = 0; k < numeroMatrizes; k++)
    {
        printf("Instancia %d\n", k + 1);
        printf("%s\n\n", verifica[k] == 1 ? "SIM" : "NAO");
    }
}
