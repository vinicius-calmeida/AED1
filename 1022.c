#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int num;
    int den;
    struct cel *prox;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} fila;

void inicializarFila(fila *f) {
    f->inicio = f->fim = NULL;
}

int filaVazia(fila *f) {
    return f->inicio == NULL;
}

void enfileirar(fila *f, int num, int den) {
    celula *nova = (celula*) malloc(sizeof(celula));
    if (nova == NULL) {
        exit(1);
    }

    nova->num = num;
    nova->den = den;
    nova->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = f->fim = nova;
    } else {
        f->fim->prox = nova;
        f->fim = nova;
    }
}

void desenfileirar(fila *f, int *num, int *den) {
    if (filaVazia(f)) {
        exit(1);
    }

    celula *temp = f->inicio;
    *num = temp->num;
    *den = temp->den;

    f->inicio = temp->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
}

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar(int *num, int *den) {
    int divisor = mdc(abs(*num), abs(*den));
    *num /= divisor;
    *den /= divisor;
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int num1, den1, num2, den2;
        char op;

        scanf("%d / %d %c %d / %d", &num1, &den1, &op, &num2, &den2);

        int res_num, res_den;

        switch (op) {
            case '+':
                res_num = num1 * den2 + num2 * den1;
                res_den = den1 * den2;
                break;
            case '-':
                res_num = num1 * den2 - num2 * den1;
                res_den = den1 * den2;
                break;
            case '*':
                res_num = num1 * num2;
                res_den = den1 * den2;
                break;
            case '/':
                res_num = num1 * den2;
                res_den = num2 * den1;
                break;
        }

        int original_num = res_num;
        int original_den = res_den;

        simplificar(&res_num, &res_den);

        printf("%d/%d = %d/%d\n", original_num, original_den, res_num, res_den);
    }

    return 0;
}
