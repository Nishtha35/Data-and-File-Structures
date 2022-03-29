#include<cstdio>
#include<cstdlib>

int nodes = 15;
int arr[] = {'\0', 1, 4, 15, 7, 9, 10, 13, 8, '\0', 31, 24, 60, 35, 71};

int rightchild(int i){
    
    if(arr[i] != '\0' && ((2 * i) + 1) <= nodes)
        return (2 * i) + 1;
    return -1;
}

int leftchild(int i){
    if(arr[i] != '\0' && (2 * i) <= nodes)
        return 2 * i;
    return -1;
}

void preorder(int i){
    if(i > 0 && arr[i] != '\0'){
        printf(" %d ",arr[i]); 
        preorder(leftchild(i)); 
        preorder(rightchild(i)); 
    }
}

void postorder(int i){
    if(i > 0 && arr[i] != '\0'){
        postorder(leftchild(i)); 
        postorder(rightchild(i)); 
        printf(" %d ",arr[i]);
    }
}

void inorder(int i){
    if(i > 0 && arr[i] != '\0'){
        inorder(leftchild(i)); 
        printf(" %d ",arr[i]); 
        inorder(rightchild(i)); 
    }
}

int main(){
    printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
    printf("\nPreorder:\n");
    preorder(1);
    printf("\nPostorder:\n");
    postorder(1);
    printf("\nInorder:\n");
    inorder(1);
    printf("\n");
    return 0;
}