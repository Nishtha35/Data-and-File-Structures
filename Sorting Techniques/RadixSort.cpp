#include<cstdio>
#include<cstdlib>

int getmax(int a[], int n) {
    int maxx = a[0];
    int i;
    for (i = 1; i < n; i++){
        if (a[i] > maxx){
            maxx = a[i];
        }
    return maxx;
    }
}

void C_Sort(int a[], int n, int pos) {
    int b[n]; // b array
    int i, c[10] = { 0 };
 
    // Store c of occurrences in c[]
    for (i = 0; i < n; i++){
        c[(a[i] / pos) % 10]++;
    }
    for (i = 1; i < n; i++){
        c[i] = c[i] + c[i - 1];
    }
    // Build the b array
    for (i = n - 1; i >= 0; i--) {
        b[c[(a[i] / pos) % 10] - 1] = a[i];
        c[(a[i] / pos) % 10]--;
    }
    // to copy in a array
    for (i = 0; i < n; i++){
        a[i] = b[i];
    }
}

void R_Sort(int a[], int n){
    int m = getmax(a, n);
    int pos;
    for (pos = 1; m / pos > 0; pos *= 10){
        C_Sort(a, n, pos);
    }
}

int main (){ 
    int i, n, a[50];  
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    // To take size of array from user
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    // To take elements from user
    printf("\nEnter elements of array: ");
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
    //To print all the elements of array (before sorting)
    printf("Elements of array Before Sorting:\n");
        for(i = 0; i < n; i++){
            printf("%d ", a[i]);
        } 
    //To print all the elements of array (after sorting)
    R_Sort(a, n);  
    printf("\nElements of array After Sorting:\n"); 
    for(i=0; i < n; i++)  
    {  
        printf("%d ",a[i]);  
    }        
} 