#include<cstdio>
#include<cstdlib>

void merge(int a[], int l, int m, int u){  
    int i = l,
    j = m + 1,
    f,
    k = l;  
    int b[10];  
    while(i <= m && j <= u){  
        if(a[i] < a[j]){  
            b[k] = a[i];  
            i = i + 1;  
        }  
        else{  
            b[k] = a[j];  
            j = j + 1;   
        }  
        k = k + 1;  
    }  
    if(i > m){  
        while(j <= u){  
            b[k] = a[j];  
            k = k + 1;  
            j = j + 1;  
        }  
    }  
    else{  
        while(i <= m){  
            b[k] = a[i];  
            k = k + 1;  
            i = i + 1;  
        }  
    }  
    f = l;  
    while(f < k){  
        a[f] = b[f];  
        f = f + 1;  
    }  
}


void M_Sort(int a[], int l, int u){  
    int m;  
    if(l < u){  
        m = ( l + u ) / 2;  
        M_Sort(a, l, m);  
        M_Sort(a, m + 1, u);  
        merge(a, l, m, u);  
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
    M_Sort(a , 0, n - 1);  
    printf("\nElements of array After Sorting:\n"); 
    for(i=0; i < n; i++)  
    {  
        printf("%d ",a[i]);  
    }        
}  