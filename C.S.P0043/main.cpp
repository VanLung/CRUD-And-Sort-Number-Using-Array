#include <stdio.h>
#include <stdlib.h>
const int MAX_SIZE = 100;

int printTheMenu();
int clean();
int addAValue(int array[], int *n, int value);
int searchAValue(int array[], int n, int value);
int removeTheFirstExistenceOfValue(int array[], int *n, int value);
int removeTheAllExistencesOfValue(int array[], int *n, int value);
int printOutTheArray(int array[], int n);
int sortTheArrayWithAscending(int array[], int bray[], int n);
int sortTheArrayWithDescending(int array[], int bray[], int n);

int main() {
    int choice, value;
    char d;
    int bray[MAX_SIZE];
    int array[] = {1, 8, 2, 5, 5, 4, 3, 4, 0, 7, 0, 8, 2, 5, 9, 9, 7};
    int n = sizeof(array) / sizeof(int);
    do
    {
        printTheMenu();
        do
        {
            printf("Input your choice: \n");
        }while(((scanf("%d%c", &choice, &d) != 2 || d != '\n') && clean()));
        switch(choice){
            case 1:
            {
                if(n == MAX_SIZE)
                    printf("The array is full.\n");
                else{
                    do
                    {
                        printf("Input the value: \n");
                    }while(((scanf("%d%c", &value, &d) != 2 || d != '\n') && clean()));
                    addAValue(array, &n, value);
                    printf("\nADDED!\n");
                }
                break;
            }
            case 2:
            {
                if(n == 0)
                    printf("The array is empty.\n");
                else{
                    do
                    {
                        printf("Input the value: \n");
                    }while(((scanf("%d%c", &value, &d) != 2 || d != '\n') && clean()));
                    searchAValue(array, n, value);
                }
                break;
            }
            case 3:
            {
                if(n == 0)
                    printf("The array is empty.\n");
                else{
                    do
                    {
                        printf("Input the value: \n");
                    }while(((scanf("%d%c", &value, &d) != 2 || d != '\n') && clean()));
                    removeTheFirstExistenceOfValue(array, &n, value);                   
                }
                break;
            }
            case 4:
            {
                if(n == 0)
                    printf("The array is empty.\n");
                else{
                    do
                    {
                        printf("Input the value: \n");
                    }while(((scanf("%d%c", &value, &d) != 2 || d != '\n') && clean()));
                    removeTheAllExistencesOfValue(array, &n, value);                   
                }
                break;
            }
            case 5:
                printOutTheArray(array, n);
                break;
            case 6:
                sortTheArrayWithAscending(array, bray, n);
                break;
            case 7:
                sortTheArrayWithDescending(array, bray, n);
                break;
            default:
                printf("Thank you.\n");
                break;
        }
    }while(choice >=1 && choice <= 7);
}
int printTheMenu(){
    printf("\nMENU\n");
    printf("1.ADD A VALUE.\n");
    printf("2.SEARCH A VALUE.\n");
    printf("3.DELETE THE FIRST VALUE.\n");
    printf("4.DELETE THE ALL VALUE.\n");
    printf("5.PRINT OUT THE ARRAY.\n");
    printf("6.SORT THE ARRAY WITH ASCENDING.\n");
    printf("7.SORT THE ARRAY WITH DESCENDING.\n");
    printf("QUIT.\n");
}
int clean(){
    while(getchar() != '\n');
    return 1;
}
int addAValue(int array[], int *n, int value) {
    array[*n] = value;
    ++(*n);
    for(int i = 0; i < *n; i++)
        printf("%d\t", array[i]);
}
int searchAValue(int array[], int n, int value){
    int count = 0;
    printf("The positive of number %d is at:\t", value);
    for(int i =0; i < n; i++)
    {
        if(array[i] == value)
        {
            ++count;
            printf("%d\t", i);
        }
    }
    if(count == 0)
        printf("NOT FOUND.\n");
}
int removeTheFirstExistenceOfValue(int array[], int *n, int value){
    int count = 0;
    for(int i = 0; i < *n; i++)
    {
        if(array[i] == value){
            ++count;
            for(int j = i; j < *n; j++)
                array[j] = array[j + 1];
            --(*n);
            break;
        }
    }
    if(count == 0)
        printf("NOT FOUND.\n");
}
int removeTheAllExistencesOfValue(int array[], int *n, int value){
    int count = 0;
    for(int i = 0; i < *n; i++)
    {
        if(array[i] == value){
            ++count;
            for(int j = i; j < *n; j++)
                array[j] = array[j + 1];
            --(*n);
            --i;
        }
    }
    if(count == 0)
        printf("NOT FOUND.\n");
}
int printOutTheArray(int array[], int n){
    printf("The array after changing: \n");
    for(int i = 0; i < n; i++)
        printf("%d\t", array[i]);
}
int sortTheArrayWithAscending(int array[], int bray[], int n){
    int t;
    for(int i = 0; i < n; i++)
        bray[i] = array[i];
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(bray[j] > bray[j + 1])
            {
                t = bray[j];
                bray[j] = bray[j + 1];
                bray[j + 1] = t;
            }
        }
    }
    printf("\nThe array after sorting with ascending:\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", bray[i]);
}
int sortTheArrayWithDescending(int array[], int bray[], int n){
    int t;
    for(int i = 0; i < n; i++)
        bray[i] = array[i];
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(bray[j] < bray[j + 1])
            {
                t = bray[j];
                bray[j] = bray[j + 1];
                bray[j + 1] = t;
            }
        }
    }
    printf("\nThe array after sorting with descending:\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", bray[i]);
}