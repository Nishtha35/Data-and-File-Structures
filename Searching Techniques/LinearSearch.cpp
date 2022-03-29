// using namespace std;
#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>


int main() {
    int a[50], n, e, i;
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    printf("\nEnter elements of array: ");
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
    printf("Elements of array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
    printf("\nEnter elements to be searched for: ");
    scanf("%d", &e);
        for(i = 0; i < n; i++){
            if(a[i] == e){
                printf("Element Fount at index %d", i);
                break;
            }
        }
        if(i == n){
            printf("Element Not Found");
        }
getch();
}