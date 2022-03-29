#include<cstdio>
#include<conio.h>
#include<cstdlib>

int main(){
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    int a[100][100], i, j, n, s;
    printf("\nEnter number of Rows and Columns: ");
    scanf("%d %d", &n, &n);
    printf("Enter elemets of Matrix:\n");
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                scanf("%d", &a[i][j]);
            }
        }

    printf("\nGiven Matrix:\n");
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                printf("%d ", a[i][j]);         
            }
            printf("\n");
        }
    
    //Transpose of Matrix
    printf("\nTranspose of Matrix:\n");
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                printf("%d ", a[j][i]);         
            }
            printf("\n");
        }
    
    //Row-wise Sum
    printf("\nRow wise Sum:\n");
        for(i = 0; i < n; i ++){
            s = 0;
            for(j = 0; j < n; j ++){
                s = s + a[i][j];        
            }
            printf("\nSum of Row %d is %d ", i+1, s); 
        }
    
    //Column-wise Sum
    printf("\n\nColumn wise Sum:\n");
        for(j = 0; j < n; j ++){
            s = 0;
            for(i = 0; i < n; i ++){
                s = s + a[i][j];        
            }
            printf("\nSum of Column %d is %d ", j+1, s); 
        }
    
    // Upper triangular Matrix
    printf("\n\nUpper Triangular Matrix:\n");
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                if(i < j){
                    printf(" %d", a[i][j]);
                }
                else{
                    printf(" 0");
                }      
            }
            printf("\n");
        }
    
    // Lower triangular Matrix
    printf("\n\nLower Triangular Matrix:\n");
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                if(i > j){
                    printf(" %d", a[i][j]);
                }
                else{
                    printf(" 0");
                }      
            }
            printf("\n");
        }

    // Diagonal Elements
    printf("\n\nDiagonal Elemets:\n");
        for(i = 0; i < n; i ++){
            for(j = 0; j < n; j ++){
                if(i == j){
                    printf(" %d", a[i][j]);
                }
                else{
                    printf(" 0");
                }      
            }
            printf("\n");
        }
    
getch();
}