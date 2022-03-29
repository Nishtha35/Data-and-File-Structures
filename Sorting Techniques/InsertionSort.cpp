#include<cstdio>
#include<cstdlib>

int main() {
    int a[50], n, i, j, f, temp;
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
    printf("\nElements of array After Sorting:\n");
        for(i = 1; i < n; i++){
            temp = a[i];
                for(j = i - 1; j >= 0; j--){
                    if(a[j] > temp){
                        a[j + 1] = a[j];
                    }
                    else{
                        break;
                    }
                }
                a[j + 1] = temp;
        }
    // to print all the elements of array (after sorting)
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}