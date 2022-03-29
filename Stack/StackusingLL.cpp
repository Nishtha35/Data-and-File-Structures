#include <cstdio>
#include <cstdlib>

struct node{
    int data;
    struct node *next;
};
struct node *top = NULL;

void push(){
    int x;
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data : ");
        scanf("%d", &n->data);
        n->next = top;
        top = n;
}

void pop(){
    struct node *temp;
    temp = top;
    if(top == NULL){
        printf("\nUnderflow");
    }
    else{
        printf("\nItem popped is %d", top->data);
        top = top->next;
        free(temp);
    }
}

void peek(){
    if(top == NULL){
        printf("\nEmpty");
    }
    else{
        printf("\nTop element is %d", top->data);
    }
}

void display(){
    struct node * temp;
    temp = top;
    if(top == NULL){
        printf("Empty");
    }
    else{
        while(temp != NULL){
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main(){
   printf("\t\t\t\t\tNishtha Sehgal\n"); 
   int c;
   do{
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