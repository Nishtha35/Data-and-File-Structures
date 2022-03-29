#include<cstdio>
#include<cstdlib>

void S_Sort(int a[], int n){    
    int i, j, k, t;    
    for (i = n / 2; i > 0; i = i / 2){    
        for (j = i; j < n; j++){    
            for(k = j - i; k >= 0; k = k - i){    
                if (a[k+i] >= a[k]){    
                    break;    
                }
                else{    
                    t = a[k+i];    
                    a[k+i] = a[k];    
                    a[k] = t;    
                }    
            }    
        }    
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
    S_Sort(a , n);  
    printf("\nElements of array After Sorting:\n"); 
    for(i=0; i < n; i++){  
        printf("%d ",a[i]);  
    }        
}  