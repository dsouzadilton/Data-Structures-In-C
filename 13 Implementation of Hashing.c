#include <stdio.h>
#include <conio.h>

int total_size;
int hash_table(int key){
    int i;
    i = key % total_size;
    return i;
}

int hash_table_linear(int key){
    int i;
    i = (key + 1) % total_size;
    return i;
}

int hash_table_quad(int key, int j){
    int i;
    i = (key + (j *j)) % total_size;
    return i;
}

int main(){
    int key, array[20], hash[20], i, n, s, select, j, k;
    printf("Enter the size of the Hash table: ");
    scanf("%d", &total_size);
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < total_size; i++)
        hash[i] = -1;
    printf("Enter Elements: ");
    for (i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    do{
        printf("\n 1.Linear Probing\t2.Quadratic Probing\t3.Exit\n ");
        scanf("%d", &select);
        switch (select){
            case 1:
                for (k = 0; k < n; k++){
                    key = array[k];
                    i = hash_table(key);
                    while (hash[i] != -1)
                        i = hash_table_linear(i);
                    hash[i] = key;
                }
                printf("\nThe elements in the array are: ");
                for (i = 0; i < total_size; i++)
                    printf("\n Element at position %d: %d", i, hash[i]);
                break;
            case 2:
                for (i = 0; i < total_size; i++)
                    hash[i] = -1;
                for (k = 0; k < n; k++){
                    j = 1;
                    key = array[k];
                    i = hash_table(key);
                    while (hash[i] != -1){
                        i = hash_table_quad(i, j);
                        j++;
                    }
                    hash[i] = key;
                }
                printf("\nThe elements in the array are: ");
                for (i = 0; i < total_size; i++)
                    printf("\n Element at position %d: %d", i, hash[i]);
                break;
        }
    }while (select != 3);
    return 0;
}