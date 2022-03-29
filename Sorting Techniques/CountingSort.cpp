#include<cstdio>
#include<cstdlib> 
 
void C_Sort(int a[], int p, int n){
    int i, j;
    int b[15], c[100];
    for (i = 0; i <= p; i++){
        c[i] = 0;
    }
    for (j = 1; j <= n; j++){
        c[a[j]] = c[a[j]] + 1;
    }
    for (i = 1; i <= p; i++){
        c[i] = c[i] + c[i-1];
    }
    for (j = n; j >= 1; j--){
        b[c[a[j]]] = a[j];
        c[a[j]] = c[a[j]] - 1;
    }
    // to copy in a array
    for (i = 0; i < n; i++){
        a[i] = b[i];
    }
    // printf("\nElements of array After Sorting:\n"); 
    // for (i = 1; i <= n; i++){
    //     printf("%d ", b[i]);
    // }
}

int main(){
    int n, p = 0, a[15], i;
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    // To take size of array from user
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    // To take elements from user
    printf("\nEnter elements of array: ");
        for (i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if (a[i] > p){
                p = a[i];
            }
        }
    //To print all the elements of array (before sorting)
    printf("Elements of array Before Sorting:\n");
        for(i = 0; i <= n; i++){
            printf("%d ", a[i]);
        }
    C_Sort(a, p, n);
    printf("\nElements of array After Sorting:\n"); 
    for(i=0; i <= n; i++){  
        printf("%d ",a[i]);  
    }   

}