#include<cstdio>
#include<cstdlib>

int temp;  
  
void heapify(int arr[], int n, int i){  

    int largest = i;    
    int left = 2 * i + 1;    
    int right = 2 * i + 2;    
  
        if (left < n && arr[left] >arr[largest]){  
            largest = left;  
        }
        if (right < n && arr[right] > arr[largest]){  
            largest = right;  
        }
        if (largest != i){  
            temp = arr[i];  
            arr[i]= arr[largest];   
            arr[largest] = temp;  
            heapify(arr, n, largest);  
        }  
}  
  
void heapSort(int arr[], int n){  
    
    int i;  
    for (i = n / 2 - 1; i >= 0; i--){  
        heapify(arr, n, i);  
    }
    for (i = n - 1; i >= 0; i--){  
        temp = arr[0];  
        arr[0]= arr[i];   
        arr[i] = temp;  
        heapify(arr, i, 0);  
    }  
}  
  
int main(){ 
    int arr[50], i, n; 
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    printf("\nEnter size of array: ");
    scanf("%d", &n);
    printf("\nEnter elements of array: ");
        for(i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
    printf("\nElements of array:\n");
        for(i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
    heapSort(arr, n);  
  
    printf("\nSorted Elements:\n");  
        for (i=0; i < n; ++i){  
            printf("%d ",arr[i]);  
        }
}  