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

// modified inorder traversal-->asc order = BST
int is_BST(struct node* root) {
    static struct node *prev = NULL;
   if(root != NULL) {   // if root = Null there is no node so there is no tree
      // check left side of root is BST
      if(!is_BST(root->left)){ 
          return 0;
      }
      // check root data is > prev data
      if(prev !=NULL && root->data <= prev->data){
          return 0;
      }
      prev = root;
      // run same function for right tree of root
      return is_BST(root->right);
   }
   else{
       return 1; 
       
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
    printf("\n-----------------BINARY SEARCH TREE-----------------");
    root = NULL;
    root = create();

    printf("\nPreorder traversal: ");
    pre_order_traversal(root);

    printf("\nPostorder traversal: ");
    post_order_traversal(root);  

    printf("\nInorder traversal: ");
    inorder_traversal(root);

    printf("\n");
    printf("%d", is_BST(root));

}

