#include <cstdio>
#include <cstdlib>

#define max 5
int q[max]; 
int f = -1, r = -1; 

void enqueue(){
    int x;
    printf("Enter element to be inserted: ");
    scanf("%d",&x);
        if(r == max - 1){
            printf("\nOverflow");
        }
        else if(r == -1 && f == -1){
            f = 0, r = 0;
        }
            else{
                r = r + 1;
            }
        q[r] = x;
}

void dequeue(){
    
    if(f == -1 || r == -1){
        printf("\nUnderflow");
    }
    else if(f == r){
        f = r = -1;
    }
        else{
            printf("\nElement deleted %d", q[f]);
            f = f + 1;   
    }
}

void peek(){
    if(f == -1 && r == -1){
        printf("\nUnderflow");
    }
    else{
        printf("%d", q[f]);
    }
}

void display(){
    int i;
    if(f == -1 && r == -1){
        printf("\nQueue is Empty");
    }
    else{
        printf("\nQueue is\n");
            for(i = f; i < r + 1; i++){
            printf(" %d", q[i]);
        }
        printf("\n");
    }
}

int main (){
   printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
   int c;
   do{
       printf("\n\n--------------LINEAR QUEUE--------------");
       printf("\n1. Enqueue");
       printf("\n2. Dequeue");
       printf("\n3. Peek");
       printf("\n4. Display");
       printf("\n5. Exit");
       printf("\nEnter your Choice: ");
       scanf("%d", &c);
    switch(c){
       case 1:  enqueue();
                break;
       case 2:  dequeue();
                break;
       case 3:  peek();
                break;
       case 4:  display();
                break;
       case 5:  break;
       default: printf("\nInvalid choice");
    }
   }while(c <= 4);

}