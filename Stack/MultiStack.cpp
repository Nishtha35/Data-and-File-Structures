#include <cstdio>
#include <cstdlib>
#define maxx 10
int s[maxx], top = -1, top1 = maxx;

void pushA(){
    int val;
    printf("\n Enter value: ");
    scanf("%d",&val);
        if(top == top1-1)
            printf("\n Overflow");
        else{
            top = top + 1;
            s[top] = val;
        }
}

int popA(){
    int temp;
    if(top == -1){
        printf("\n Underflow");
    }
    else{
        temp =s[top];
        top = top - 1;
        printf("\nItem popped from Stack A is %d", temp);
    }
}

void displayA(){
    int i;
    if(top == -1)
        printf("\n Stack A is empty");
    else{
        for(i = top; i >= 0; i--)
            printf("%d\n", s[i]);
    }
}

void pushB(){
    int val;
    printf("\n Enter the value: ");
    scanf("%d", &val);
        if(top1-1 == top)
            printf("\n Overflow");
        else{
            top1 = top1 - 1;
            s[top1] = val;
        }
}

int popB(){
    int temp;
    if(top1 == maxx){
        printf("\n Underflow");
    }
    else{
        temp =s[top1];
        top1 = top1 - 1;
        printf("\nItem popped from Stack B is %d", temp);
    }
}

void displayB(){
    int j;
    if(top1 == maxx)
        printf("\n Stack B is Empty");
    else{
        for(j = top1; j < maxx; j++)
        printf("%d\n", s[j]);
    }
}


int main(){
    int c, val;
    printf("\t\t\t\t\tNishtha Sehgal\n"); 
    do{
        printf("\n -----Menu----- ");
        printf("\n 1. PUSH element into Stack A");
        printf("\n 2. PUSH element into Stack B");
        printf("\n 3. POP element from Stack A");
        printf("\n 4. POP element from Stack B");
        printf("\n 5. Display the Stack A");
        printf("\n 6. Display the Stack B");
        printf("\n 7. Exit");
        printf("\n Enter your choice: ");
        scanf("%d",&c);
        switch(c){
            case 1: pushA();
                    break;
            case 2: pushB();
                    break;
            case 3: popA();
                    break;
            case 4: popB();
                    break;
            case 5: printf("\nElements of Stack A are :\n");
                    displayA();
                    break;
            case 6: printf("\nElements of Stack B are :\n");
                    displayB();
                    break;
            case 7: break;
            default: printf("\nInvalid Choice");
                    break;
        }
    }while(c <= 6);
}