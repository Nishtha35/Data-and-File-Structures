#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
	struct node*left;
	struct node*right;
};

typedef struct node BST;
BST *loc, *par;

void search(BST *root, int item){
    BST *save,*ptr;
    if (root == NULL){
        loc = NULL;
        par = NULL;
    }
    if (item == root -> data){
    loc = root;
    par = NULL;
    return;
    }
    if (item < root->data){
        save = root;
        ptr = root->left;
    }
    else{
        save = root;
        ptr = root -> right;
    }
    while( ptr != NULL){
        if (ptr -> data == item){
            loc = ptr;
            par = save;
            return;
        }
        if(item < ptr->data){
            save = ptr;
            ptr = ptr->left;
        }
        else{
            save = ptr;
            ptr = ptr->right;
        }
    }
    loc = NULL;
    par = save;
    return;
}
 
struct node* findmin(struct node*r){
	if (r == NULL)
		return NULL;
	else if (r->left!=NULL)
		return findmin(r->left);
	else if (r->left == NULL)
		return r;
}

struct node*insert(struct node*r, int x){
	if (r == NULL){
            r = (struct node*)malloc(sizeof(struct node));
            r->data = x;
            r->left = r->right = NULL;
            return r;
	}
	else if (x < r->data)
            r->left = insert(r->left, x);
	else if (x > r->data)
            r->right = insert(r->right, x);
	return r;
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->left);
      printf("%d ",root->data);          
      inorder_traversal(root->right);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->left);
      post_order_traversal(root->right);
      printf("%d ", root->data);
   }
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->left);
      pre_order_traversal(root->right);
   }
}

struct node* del(struct node*r, int x){
	struct node *t;
	if(r == NULL)
		printf("\nElement not found");
	else if (x < r->data)
            r->left = del(r->left, x);
	else if (x > r->data)
            r->right = del(r->right, x);
	else if ((r->left != NULL) && (r->right != NULL)){
            t = findmin(r->right);
            r->data = t->data;
            r->right = del(r->right, r->data);
	}
	else{
            t = r;
            if (r->left == NULL)
                r = r->right;
            else if (r->right == NULL)
                r = r->left;
            free(t);
	}
	return r;
}


int heighttree(node*root){
    if(root == NULL){
        return 0;
    }
    int l = heighttree(root->left);
    int r = heighttree(root->right);
     if(l > r){
        return l + 1;
     }
     else{
        return r + 1;
     }
}

int smallest_node(struct node* root) {
  struct node* current = root;
    while (current->left != NULL){
        current = current->left;
    }
    return(current->data);
}

int largest_node(struct node* root){  
  struct node* current = root;
    while (current->right != NULL){
        current = current->right;
    } 
    return (current->data);
}

static int count = 0;

int countnodes(struct node *root){
    if(root != NULL){
        countnodes(root->left);
        count++;
        countnodes(root->right);
    }
    return count;
}

int leaf_nodes(struct node *root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    return leaf_nodes(root->left) + leaf_nodes(root->right);
}

int main(){
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    struct node* root = NULL;
    int x, c = 1, z;
    int element;
    char ch;
    printf("\nEnter an element: ");
    scanf("%d", &x);
    root = insert(root, x);
    printf("\nDo you want to enter another element :y or n");
    scanf(" %c",&ch);
    while (ch == 'y'){
        printf("\nEnter an element:");
        scanf("%d", &x);
        root = insert(root,x);
        printf("\nPress y or n to insert another element: y or n: ");
        scanf(" %c", &ch);
    }
    do{ 
        printf("\n\n--------------BINARY SEARCH TREE--------------");
        printf("\n1 Insertion of node ");
        printf("\n2 Deletion of node ");
        printf("\n3 Search an element ");
        printf("\n4 Inorder traversal ");
        printf("\n5 Preorder traversal ");
        printf("\n6 Postorder traversal ");
        printf("\n7 Height of tree ");
        printf("\n8 Smallest node ");
        printf("\n9 Largest node ");
        printf("\n10 Total nodes ");
        printf("\n11 No. of leaf nodes ");
        printf("\n12 Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1: printf("\nEnter the item:");
                    scanf("%d", &z);
                    root = insert(root,z);
                    break;
            case 2: printf("\nEnter the data to be deleted:");
                    scanf("%d", &z);
                    root = del(root, z);
		            break;
            case 3: printf("\nEnter element to be searched:  ");
                    scanf("%d", &element);
                    search(root, element);
                        if(loc != NULL)
                            printf("\n%d Found in Binary Search Tree !!\n",element);
                        else
                            printf("\nIt is not present in Binary Search Tree\n");
                    break;
            case 4: printf("\nInorder:  ");
                    inorder_traversal(root);
                    break;
            case 5: printf("\nPreorder:  ");
                    pre_order_traversal(root);
                    break;
            case 6: printf("\nPostorder:  ");
                    post_order_traversal(root);
                    break;
            case 7: printf("Height of tree is %d", heighttree(root));
                    break;
            case 8: printf("Smallest node is %d", smallest_node(root));
                    break;
            case 9: printf("Largest node is %d", largest_node(root));
                    break;
            case 10: printf("Number of nodes = %d", countnodes(root));
                    break;
            case 11: printf("Number of leaf nodes = %d", leaf_nodes(root)); 
                    break;
            case 12: break;
            default: printf("Invalid choice! ");
        }
    }while(c <= 11);
    
}