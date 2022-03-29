#include<cstdio>
#include<conio.h>
#include<cstdlib>

struct node{
    int data;
    struct node *next; 
    struct node *prev;    
};

struct node *head, *temp, *n, *tail;
int count = 0;

void createlist(){
    head = NULL;
    int choice = 1; 
    while(choice){
        n = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &n->data);
        n->prev = NULL;
        n->next = NULL;
            if(head == NULL){
                head = tail = n;
            }
            else{
                tail->next = n;
                n->prev = tail;
                tail = n;
            }
        printf("Want to enter more data?(0,1): ");
        scanf("%d", &choice);
    }
}

void printlist(){
    temp = head;
    printf("\nElements in Linked list:->\n");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
        count++;
    }
}

void printlistback(){
    tail = n;
    temp = tail;
    printf("\nElements in Linked list(reverse):->\n");
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
        count++;
    }
}

void ins_beg(){
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at beginning");
    printf("\nEnter data: ");
    scanf("%d", &n->data);
    n->prev = NULL;
    n->next = NULL;

    head->prev = n;
    n->next = head; 
    head = n;   
}

void ins_end(){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at end");
    printf("\nEnter data: ");
    scanf("%d", &n->data);
    n->prev = NULL;
    n->next = NULL;   
        if(head == NULL){
            head = n;
            tail = n;
            n->next = NULL;
            n->prev = NULL;
        }
        else{
            tail->next =  n;
            n->prev = tail;
            tail = n;
            tail->next = NULL;
        }
    
}

void ins_pos(){
    struct node *temp;
    int pos, i = 1, count ;
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at specific position");
    printf("\nEnter position: ");
    scanf("%d", &pos);
        if(pos > count){
            printf("\nInvalid position!");
        }
        else if(pos == 1){
            ins_beg();
        }
        else{
            temp = head;
            printf("Enter data: ");
            scanf("%d", &n->data);         
                while (i < pos - 1){
                    temp = temp->next;
                    i++;
                }
            n->prev = temp;
            n->next = temp->next;
            temp->next = n;
            n->next->prev = n;
        }
}

void del_beg(){
    struct node *temp;
    if(head == NULL){
        printf("List is empty!");
    }
    else{
        temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
        printf("\nDeleted Node from beginning\n");
    }
}

void del_end(){
    struct node *temp;
    if(tail == NULL){
        printf("List is empty!");
    }
    else{
        temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
        printf("\nDeleted Node from end\n");
    }
}

void del_pos(){
    struct node *temp;
    int pos, i = 1;
    temp = head;
    printf("\nEnter position: ");
    scanf("%d", &pos);
        while(i < pos){
            temp = temp->next;
            i++;   
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);    
}

void reverselist(){
    struct node *temp, *n;
    if(head == NULL){
        printf("List is empty!");
    }
    else{
        temp = head;
        while(temp != NULL){
            n = temp->next;
            temp->next = temp->prev;
            temp->prev = n;
            temp = n;
        }
        temp = head;
        head = tail;
        tail = temp;
    }
}

int main(){
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
   int c;
   do{
       printf("\n\n--------------DOUBLY LINKED LIST--------------");
       printf("\n1. Create List");
       printf("\n2. Insert at Beginning");
       printf("\n3. Insert at End");
       printf("\n4. Insert at Position ");
       printf("\n5. Delete from Beginning");
       printf("\n6. Delete from End");
       printf("\n7. Delete from Position ");
       printf("\n8. Display List(Forward)");
       printf("\n9. Display List(Backward)");
       printf("\n10. Exit");
       printf("\nEnter your Choice: ");
       scanf("%d", &c);
    switch(c){
       case 1:  createlist();
                break;
       case 2:  ins_beg();
                break;
       case 3:  ins_end();
                break;
       case 4:  ins_pos();
                break;
       case 5:  del_beg();
                break;
       case 6:  del_end();
                break;
       case 7:  del_pos();
                break;
       case 8:  printlist();
                break;
       case 9:  printlistback();
                break;
       case 10:  break;
       default: printf("\nInvalid choice");
    }
   }while(c <= 9);

}