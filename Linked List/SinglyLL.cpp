#include<cstdio>
#include<conio.h>
#include<cstdlib>

struct node{
    int data;
    struct node *next;    
};

struct node *head, *n, *temp, *p;
int count = 0;
void createlist(){
    head = NULL;
    int choice; 
    while(choice){
        n = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &n->data);
        n->next = NULL;
            if(head == NULL){
                head = temp = n;
            }
            else{
                temp->next = n;
                temp = n;
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

void ins_beg(){
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at beginning");
    printf("\nEnter data: ");
    scanf("%d", &n->data);
        if(head == NULL){
            n->next = NULL;
            head = n;
        }
        else{
            n->next = head;
            head = n;
        }
}

void ins_end(){
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at end");
    printf("\nEnter data: ");
    scanf("%d", &n->data);
    n->next = NULL;
    temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
}

void ins_pos(){
    int pos, i = 1, count ;
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at specific position");
    printf("\nEnter position: ");
    scanf("%d", &pos);
        if(pos > count){
            printf("\nInvalid position!");
        }
        else{
            temp = head;
                while (i < pos){
                    temp = temp->next;
                    i++;
                }
            printf("Enter data: ");
            scanf("%d", &n->data);
            n->next = temp->next;
            temp->next = n;
        }
}

void del_beg(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else{
        temp = head;
        head = head->next;
        printf("\nNode Deleted from beginning= %d",temp->data);
        free(temp);
    }
}

void del_end(){
    if(head == NULL){
        printf("List is Empty!");
    }
    else{
        temp = head;
            while (temp->next != 0){
                p = temp;
                temp = temp->next;
            }
            if(temp == head){
                head = NULL;
                free(temp);
            }
            else{
                p->next = NULL;
                free(temp);
            }
        printf("\nDeleted Node from the End"); 
    }
}

void del_pos(){
    int pos, i = 1;
    printf("\nDeletion from specific position");
    printf("\nEnter position: ");
    scanf("%d", &pos);
        if(pos > count){
            printf("\nInvalid position!");
        }
        else{
            temp = head;
                while (i < pos - 1){
                    temp = temp->next;
                    i++;
                }
            n = temp->next;
            temp->next = n->next;
            free(n);
        }
}

// void reverselist(){
//     struct node *p, *t, *n;    
//     p = 0;
//     printf("\nReverse of linked list");
//     temp = n = head;
//         while (n != 0){
//             n = n->next;
//             temp->next = p;
//             p = temp;
//             temp= n;
//         }
//         head = p;
    
// }

int main(){

    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
   int c;
   do{
       printf("\n\n--------------SINGLY LINKED LIST--------------");
       printf("\n1. Create List");
       printf("\n2. Insert at Beginning");
       printf("\n3. Insert at End");
       printf("\n4. Insert at Position ");
       printf("\n5. Delete from Beginning");
       printf("\n6. Delete from End");
       printf("\n7. Delete from Position ");
       printf("\n8. Display List");
       printf("\n9. Exit");
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
       case 9:  break;
       default: printf("\nInvalid choice");
    }
   }while(c <= 8);

}