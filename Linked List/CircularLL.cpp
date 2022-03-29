#include<cstdio>
#include<conio.h>
#include<cstdlib>

struct node{
    int data;
    struct node *next;    
};

struct node *head, *temp, *n, *tail;
int count = 0;

void createlist(){
    tail = NULL;
    int choice = 1; 
    while(choice){
        n = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &n->data);
        n->next = NULL;
            if(tail == NULL){
                tail = n;
                tail->next = n;
            }
            else{
                n->next = tail->next;
                tail->next = n;
                tail = n;
            }
        printf("Want to enter more data?(0,1): ");
        scanf("%d", &choice);
        // printf("%d", tail->next->data);
    }
}

void printlist(){
    struct node *temp;
    if(tail == NULL){
        printf("List is empty!");
    }
    else{
        temp = tail->next;
        printf("\nElements in Linked list:->\n");
        while(temp->next != tail->next){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
}

void ins_beg(){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at beginning");
    printf("\nEnter data: ");
    scanf("%d", &n->data);
    n->next = NULL;
        if(tail == NULL){
            tail = n;
            tail->next = NULL;
        }
        else{
            n->next = tail->next;
            tail->next = n;
        }
}

void ins_end(){
    n = (struct node*)malloc(sizeof(struct node));
    printf("\nInsertion at end");
    printf("\nEnter data: ");
    scanf("%d", &n->data);
    n->next = NULL;
    if(tail == NULL){
        tail = n;
        tail->next = n;
    }
    else{
        n->next = tail->next;
        tail->next = n;
        tail = n;
    }
}

void ins_pos(){
    struct node *n, *temp;
    int pos, i = 1, count ;
    printf("\nInsertion at specific position");
    printf("\nEnter position: ");
    scanf("%d", &pos);
        if(pos < 1 || pos > count){
            printf("\nInvalid position!");
        }
        else if(pos == 1){
            ins_beg();
        }
            else{
                n = (struct node*)malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &n->data);
                n->next = NULL;
                temp = tail->next;
                    while (i < pos - 1){
                        temp = temp->next;
                        i++;
                    }
                n->next = temp->next;
                temp->next = n;
            }
}

del_beg(){
    struct node *temp;
    temp =  tail->next;
        if(tail == NULL){
            printf("List is empty!");
        }
        else if(temp->next == temp){
            tail = NULL;
            free(temp);
        }
            else{
                tail->next = temp->next;
                free(temp);
            }
        printf("\nDeleted Node from beginning\n");
}

void del_end(){
    struct node *temp, *p;
    temp =  tail->next;
        if(tail == NULL){
            printf("List is empty!");
        }
        else if(temp->next == temp){
            tail = NULL;
            free(temp);
        }
            else{
                while(temp->next != tail->next){
                    p = temp;
                    temp = temp->next;
                }
                p->next = tail->next;
                tail = p;
                free(temp);
            }
        printf("\nDeleted Node from end\n");

}

void del_pos(){
    struct node *p, *temp, *n;
    int pos, i = 1, count;
    temp = tail->next;
    printf("\nDeletion from specific position");
    printf("\nEnter position: ");
    scanf("%d", &pos);
        if(pos < 1 || pos > count){
            printf("\nInvalid position!");
        }
        else if(pos == 1){
            del_beg();
        }
            else{
                while(i < pos - 1){
                    temp = temp->next;
                    i++;
                }    
                p = temp->next;
                temp->next = p->next;
                free(p);
            }
}

void reverselist(){
    struct node *n, *temp, *p;
    temp = tail->next;
    n = temp->next;
        if(tail == NULL){
            printf("List is empty!");
        }
        else{
            while(temp != tail){
                p = temp;
                temp = n;
                n =  temp->next;
                temp->next = p;
            }
        n->next = tail;
        tail= n;
        }
}

int main(){
    createlist();
    printlist();
    ins_beg();
    printlist();
    ins_end();
    printlist();
    ins_pos();
    printlist();
    del_beg();
    printlist();
    del_end();
    printlist();
    del_pos();
    printlist();
    reverselist();
    printlist();
}