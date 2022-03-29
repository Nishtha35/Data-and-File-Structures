#include <cstdio>
#include <cstdlib>

#define max 5
int s[max], top = -1; 

void push(){
    int x;
    printf("\nEnter data: ");
    scanf("%d", &x);
    if(top == max - 1){
        printf("\nOverflow");
    }
    else{
        top = top + 1;
        s[top] = x;
    }    
}

void pop(){
    int temp;
    if(top == -1){
        printf("\nUnderflow");
    }
    else{
        temp =s[top];
        top = top - 1;
        printf("\nItem popped is %d", temp);
    }
}

void peek(){
    if(top == -1){
        printf("\nUnderflow");
    }
    else{
        printf("\nTop Value: %d", s[top]);
    }
}

void display(){
    if(top == -1){
        printf("\nUnderflow");
    }
    else{
        for(int i = top; i >= 0; i-- ){
            printf("%d\n", s[i]);
        }
    }
}


int main(){
   printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
   int c;
   do{
       printf("\n\n--------------STACK--------------");
       printf("\n1. Push");
       printf("\n2. Pop");
       printf("\n3. Peek");
       printf("\n4. Display");
       printf("\n5. Exit");
       printf("\nEnter your Choice: ");
       scanf("%d", &c);
    switch(c){
       case 1:  push();
                break;
       case 2:  pop();
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