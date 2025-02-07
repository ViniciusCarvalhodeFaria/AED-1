#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 51
#define MAX_INPUT 2550

void Merge(int start, int mid, int end, char arr[][MAX_LEN]) {
    int i, j, k;
    char (*temp)[MAX_LEN] = malloc((end - start) * sizeof(char[MAX_LEN]));
    i = start; 
    j = mid; 
    k = 0;

    while (i < mid && j < end) {
        if (strlen(arr[i]) >= strlen(arr[j])) {
            strcpy(temp[k++], arr[i++]);
        } else {
            strcpy(temp[k++], arr[j++]);
        }
    }

    while (i < mid) {
        strcpy(temp[k++], arr[i++]);
    }

    while (j < end) {
        strcpy(temp[k++], arr[j++]);
    }

    for (i = start, k = 0; i < end; i++, k++) {
        strcpy(arr[i], temp[k]);
    }

    free(temp);
}

void MergeSort(int start, int end, char arr[][MAX_LEN]) {
    if (start < end - 1) {
        int mid = (start + end) / 2;
        MergeSort(start, mid, arr);
        MergeSort(mid, end, arr);
        Merge(start, mid, end, arr);
    }
}

int main() {
    int num_cases;
    char *word, words[50][MAX_LEN], input[MAX_INPUT]; 

    scanf("%d", &num_cases);
    getchar(); 

    for (int i = 0; i < num_cases; i++) {
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; 

        word = strtok(input, " ");
        int count = 0;

        while (word != NULL) {
            strcpy(words[count++], word);
            word = strtok(NULL, " ");
        }

        MergeSort(0, count, words);

        for (int j = 0; j < count; j++) {
            printf("%s", words[j]);
            if (j < count - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
