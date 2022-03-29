#include<cstdio>
#include<cstdlib>
 
#define MAX 5
 
int pqueue[MAX];
int f, r;
 
// to check priority and place of element
void check(int x){
    int i,j;
 
    for (i = 0; i <= r; i++){
        if (x >= pqueue[i]){
            for (j = r + 1; j > i; j--){
                pqueue[j] = pqueue[j - 1];
            }
            pqueue[i] = x;
            return;
        }
    }
    pqueue[i] = x;
} 

// to create empty priority queue
void create(){
    f = r = -1;
}
 
void insert(int x){
    if (r >= MAX - 1){
        printf("\nOverflow");
        return;
    }
    if ((f == -1) && (r == -1)){
        f++;
        r++;
        pqueue[r] = x;
        return;
    }    
    else
        check(x);
    r++;
}
 

void deletee(int x){
    int i;
 
    if ((f==-1) && (r==-1)){
        printf("\nEmpty");
        return;
    }
 
    for (i = 0; i <= r; i++){
        if (x == pqueue[i]){
            for (; i < r; i++){
                pqueue[i] = pqueue[i + 1];
            }
 
        pqueue[i] = -99;
        r--;
 
        if (r == -1) 
            f = -1;
        return;
        }
    }
    printf("\n%d not found in queue", x);
}
 

void display(){
    if ((f == -1) && (r == -1)){
        printf("\nQueue is empty");
        return;
    }
 
    for (; f <= r; f++){
        printf(" %d ", pqueue[f]);
    }
 
    f = 0;
}



int main(){
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    int n, ch;
    create();
    while (1){  
        printf("\n-----------------PRIORITY QUEUE-----------------");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display ");
        printf("\n4. Exit");
        printf("\nEnter your choice : ");    
        scanf("%d", &ch);
        
 
        switch (ch){
                case 1:     printf("\nEnter value to be inserted : ");
                            scanf("%d",&n);
                            insert(n);
                            break;
                case 2:     printf("\nEnter value to delete : ");
                            scanf("%d",&n);
                            deletee(n);
                            break;
                case 3:     display();
                            break;
                case 4:     exit(0);
                default:    printf("\nInvalid choice");
        }
    }
}