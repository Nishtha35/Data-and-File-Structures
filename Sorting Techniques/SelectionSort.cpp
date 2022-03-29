#include<cstdio>
#include<cstdlib>

int main() {
    int a[50], n, i, j, min, temp;
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
    printf("\nElements of array Before Sorting:\n");
        for(i = 0; i < n; i++){
            printf("%d ", a[i]);
        }    
    printf("\nElements of array After Sorting:\n");
        for(i = 0; i < n ; i++){ // Linear search
            min = i;
                for(j = i + 1; j < n ; j++){
                    if(a[j] < a[min]){ // compare element and least element
                        min = j;
                    }
                }
                // if(min != i){
                    // swapping  a[i] and a[min]
                    temp = a[i];
                    a[i] = a[min];
                    a[min] = temp;
                // }
        }
        // to print all the elements of array (after sorting)
        for (int i = 0; i < n; i++) { 
        printf("%d ", a[i]);
    }
}