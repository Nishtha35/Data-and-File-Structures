// dynamic representation
#include<cstdio>
#include<cstdlib>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root;

struct node* create(){
    int x;
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter data (0 for no node) : ");
        scanf("%d", &x);
            if(x == 0){
                return 0;
            }
        n->data = x;
        printf("\nEnter LEFT CHILD of %d--->", x);
        n->left = create();
        printf("\nEnter RIGHT CHILD of %d--->", x);
        n->right = create();
    return n;
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



int main(){
    struct node *root;
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    printf("\n-----------------BINARY TREE-----------------");
    root = NULL;
    root = create();

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\nPost order traversal: ");
    post_order_traversal(root); 

    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

}

