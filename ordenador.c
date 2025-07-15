#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

// Função para imprimir o array
void printArray(Pessoa arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s - %d\n", arr[i].nome, arr[i].idade);
}

// Bubble Sort
void bubbleSort(Pessoa arr[], int n, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            (*comparacoes)++;
            if (strcmp(arr[j].nome, arr[j+1].nome) > 0) {
                Pessoa temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                (*trocas)++;
            }
        }
    }
}

// Selection Sort
void selectionSort(Pessoa arr[], int n, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            (*comparacoes)++;
            if (strcmp(arr[j].nome, arr[min_idx].nome) < 0)
                min_idx = j;
        }
        if (min_idx != i) {
            Pessoa temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
            (*trocas)++;
        }
    }
}

// Insertion Sort
void insertionSort(Pessoa arr[], int n, int *comparacoes, int *trocas) {
    *comparacoes = 0;
    *trocas = 0;
    for (int i = 1; i < n; i++) {
        Pessoa key = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j].nome, key.nome) > 0) {
            (*comparacoes)++;
            arr[j+1] = arr[j];
            (*trocas)++;
            j--;
        }
        if (j >= 0) (*comparacoes)++;
        arr[j+1] = key;
    }
}

// Função para copiar array
void copiaArray(Pessoa dest[], Pessoa src[], int n) {
    for (int i = 0; i < n; i++)
        dest[i] = src[i];
}

// Função para medir tempo médio
// Executa o algoritmo 5 vezes e retorna o tempo médio em ms
// Os valores de comparações e trocas são do último teste
double tempoMedio(void (*sort)(Pessoa[], int, int*, int*), Pessoa arr[], int n, int *comparacoes, int *trocas) {
    clock_t start, end;
    double total = 0;
    Pessoa *temp = malloc(n * sizeof(Pessoa));
    int c, t;
    for (int i = 0; i < 5; i++) {
        copiaArray(temp, arr, n);
        start = clock();
        sort(temp, n, &c, &t);
        end = clock();
        total += ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    }
    *comparacoes = c;
    *trocas = t;
    free(temp);
    return total / 5.0;
}

int main() {
    int n;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // Limpa o buffer
    Pessoa *pessoas = malloc(n * sizeof(Pessoa));
    for (int i = 0; i < n; i++) {
        printf("Nome da pessoa %d: ", i+1);
        fgets(pessoas[i].nome, 100, stdin);
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0'; // Remove o \n
        printf("Idade da pessoa %d: ", i+1);
        scanf("%d", &pessoas[i].idade);
        getchar(); // Limpa o buffer
    }

    int comp, troc;
    double tempo;

    printf("\nBubble Sort:\n");
    tempo = tempoMedio(bubbleSort, pessoas, n, &comp, &troc);
    bubbleSort(pessoas, n, &comp, &troc);
    printArray(pessoas, n);
    printf("Comparacoes: %d, Trocas: %d, Tempo medio: %.2f ms\n\n", comp, troc, tempo);

    printf("Selection Sort:\n");
    tempo = tempoMedio(selectionSort, pessoas, n, &comp, &troc);
    selectionSort(pessoas, n, &comp, &troc);
    printArray(pessoas, n);
    printf("Comparacoes: %d, Trocas: %d, Tempo medio: %.2f ms\n\n", comp, troc, tempo);

    printf("Insertion Sort:\n");
    tempo = tempoMedio(insertionSort, pessoas, n, &comp, &troc);
    insertionSort(pessoas, n, &comp, &troc);
    printArray(pessoas, n);
    printf("Comparacoes: %d, Trocas: %d, Tempo medio: %.2f ms\n\n", comp, troc, tempo);

    free(pessoas);
    return 0;
}
