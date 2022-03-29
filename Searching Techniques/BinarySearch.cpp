#include<iostream>
#include<cstdio>
#include<conio.h>
#include<cstdlib>

int main() {
    int a[50], n, i, e, l, r, m;
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
        l = 0;
        r = n-1;
        while(l < r){
            m = (l + r) / 2;
                if( e == a[m]){
                    printf("\nElement %d found at index %d", e, m);
                    break;
                }
                else if(e < a[m]){
                    r = m -1;
                }
                    else{
                        l = m + 1;
                    }
        }
        if( l > r){
            printf("Element Not Found");
        }        
getch();
}