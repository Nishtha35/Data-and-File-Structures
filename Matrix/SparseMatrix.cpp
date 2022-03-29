#include<cstdio>
#include<conio.h>
#include<cstdlib>

int main(){
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    int a[100][100], i, j, m, n, count =0, h, nz;
    printf("\nEnter number of Rows and Columns: ");
    scanf("%d %d", &m, &n);
    printf("\nEnter elemets of Matrix:");
        for(i = 0; i < m; i ++){
            for(j = 0; j < n; j ++){
                scanf("%d", &a[i][j]);
                    if(a[i][j] == 0){
                        count++;
                    }
            }
        }
    printf("\nGiven Matrix:\n");
        for(i = 0; i < m; i ++){
            for(j = 0; j < n; j ++){
                printf("%d ", a[i][j]);         
            }
            printf("\n");
        }
    h = ((m * n) / 2);
    nz = (m * n) - count;
    if(count > h){
        printf("\nZero: %d",count);
        printf("\nNon Zero: %d",nz);
        printf("\nSparse Matrix!");

        printf("\n\nThree column representation:\n");
        printf("\n Rows Columns Values");
        printf("\n  %d\t %d\t %d\t", m, n, nz); 
            for(i = 0; i < m; i ++){
                for(j = 0; j < n; j ++){
                    if(a[i][j] != 0){
                        printf("\n  %d\t %d\t %d\t", i, j, a[i][j]); 
                    }
                            
                }
            }
    }
    else{
        printf("\nZero: %d",count);
        printf("\nNon Zero: %d",nz);
        printf("\nNot Sparse Matrix!");
    }
    getch();
    return 0;
}