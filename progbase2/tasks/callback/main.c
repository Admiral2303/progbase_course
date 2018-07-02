#include <stdlib.h>
#include <stdio.h>
#include<string.h>




struct Tournir_member{
    char name[20];
    int penalty_points;
    int year;
};

typedef struct Tournir_member Tournir_member;


void Array_foreachReversed(int arr[], int len, void (*action)(int, int));
void Array_foreach(int arr[], int len, void (*action)(int, int));
void printArr(int * arr, int count);
void callback_func(int index, int value);
void printstruct(Tournir_member self[], int size);



int asc(const void * a, const void * b) {
    int i = *(int *)a;
    int j = *(int *)b;
    int  k = 10;

    while(1){ 
       if(i < -10 || i > 10){
           i = i / k;
       }
       if(j < -10 || j > 10){
           j = j / k;
       }
       if(i > -10 && i < 10 && j > -10 && j < 10){
            break;
       }
     }
     return i - j;
}


int asc_struct(const void * a, const void * b) {
    const Tournir_member * self = a;
    const Tournir_member * self1 = b;
    int i = self->penalty_points;
    int j = self1->penalty_points;
    return i - j;
}





int main(void) {
    Tournir_member arr1[4];
    strcpy(arr1[0].name,"misha"); 
    arr1[0].penalty_points = 5;
    arr1[0].year = 1998;
    
    strcpy(arr1[1].name,"ilya"); 
    arr1[1].penalty_points = 10;
    arr1[1].year = 1997;
    
    strcpy(arr1[2].name,"sanya"); 
    arr1[2].penalty_points = 7;
    arr1[2].year = 2000;
    
    strcpy(arr1[3].name,"vadim"); 
    arr1[3].penalty_points = 3;
    arr1[3].year = 1999;


    int arr[] = {5, 343, -5874, 47, 4785, 412, -112, -1};
    int arr2[] = {5, 343, -5874, -47, -58, 47 , -5};
    int length2 = sizeof(arr2) / sizeof (arr2[0]);
    int length = sizeof(arr) / sizeof (arr[0]);
    int length1 = sizeof(arr1) / sizeof (arr1[0]);
    
    printf("Вхідний масив \n");
    printArr(arr, length);
    puts("\nВикористовуючи стандартну функцію qsort() і callback-функції,виконати сортування масиву чисел у порядку зростання першої цифри.");
    printf("\nВихідний масив: \n");
    qsort(arr, length, sizeof(arr[0]), asc);
    printArr(arr, length);
    puts("");
    puts("\nОписати структуру Учасник турніру і за допомогою qsort(), виконати сортування масиву елементів Учасник турніру у порядку зростання   кількісті штрафних балів.");
    qsort(arr1,length1,sizeof(arr1[0]),asc_struct);
    printstruct(arr1, length1);
    printArr(arr2, length);
    puts("Створити функцію:яка проходиться по масиву arr у прямому порядку і для кожного значення викликає callback-функцію action із двома аргументами: поточне значення у масиві та індекс поточного елемента масиву.");
    Array_foreach(arr2,length2, callback_func);
    puts("");
    puts("Створити функцію: яка проходиться по масиву arr у зворотньому порядку і для кожного значення викликає callback-функцію action із двома аргументами: поточне значення у масиві та індекс поточного елемента масиву.");
    Array_foreachReversed(arr2,length2, callback_func);

    return 0;
}



void printstruct(Tournir_member self[], int size){
    for(int i = 0; i < size; i++){
        printf("name: %s\n", self[i].name);
        printf("penalty points: %i\n",self[i].penalty_points);
        printf("year %i\n\n",self[i].year);
    }

}

void printArr(int * arr, int count) {
    for (int i = 0; i < count; i++) {
        printf("%i ", arr[i]);
    }
    puts("");
}



void Array_foreach(int arr[], int len, void (*action)(int, int)){
    for(int i = 0; i < len; i++){
        action(i, arr[i]);
    }

}

void Array_foreachReversed(int arr[], int len, void (*action)(int, int)){
     for(int i = len; i >= 0; i--){
        action(i, arr[i]);
    }
}


void callback_func(int index, int value){
    if(value < 0){
        printf("index: %i, value = %i\n", index, value);
    }
}
