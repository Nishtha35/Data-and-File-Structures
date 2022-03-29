#include<cstdio>
#include<cstdlib>

// to find partition position
int partition(int ar[], int l, int u){
    int p, i, j, temp;
    p = ar[l];
    i = l;
    j = u + 1;
    while(i < j){
        while(ar[i] <= p && i <= u){
            i = i + 1;
        }
        while(ar[j] > p && j >= l){
            j = j - 1;
        }
           if(i < j){
                //swappping element at i with element at j
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
}
   // swapping pivot with greatest element at i 
    temp = ar[l];
    ar[l] = ar[j];
    ar[j] = p;
    return j;
}

int Q_Sort(int ar[], int l, int u){

    if(l < u){
        // to find the pivot element so smaller elements on left and greater elements on right
        int piv = partition(ar, l, u);
        // recursive call on left of pivot
        Q_Sort(ar, l, piv - 1);
        // recursive call on right of pivot
        Q_Sort(ar, piv + 1, u);
    }
}

int main() {
    int a[50], n, i, j;
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
    printf("\nElements of array After Sorting:\n");
        Q_Sort(a, 0, n - 1);
            for (int i = 0; i < n; i++) { 
            printf("%d ", a[i]);
    }
}