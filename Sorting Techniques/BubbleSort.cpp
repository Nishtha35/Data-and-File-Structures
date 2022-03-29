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
    printf("\nElements of array Before Sorting:\n");
        for(i = 0; i < n; i++){
            printf("%d ", a[i]);
        }    
    printf("\nElements of array After Sorting:\n");
        for(i = 0; i < n; i++){ // for pass(traversing whole array)
            f = 0;
            for(j = 0; j < n - i; j++){ // for comparison in pass
                if(a[j] > a[j + 1]){
                    // swapping a[j] and a[j+1]
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    f = 1;   // if swapping is done
                }
            }0
            if(f == 0){  // to check swapping is not done
                break;
            }
        }
    // to print all the elements of array (after sorting)
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}