// graph menu driven
#include<cstdio>
#include<cstdlib>

int adj_matrix[9][9], vc = 0;
int q[9], f = -1, r = -1, vis[9], s[10], stackSize = 9, top = 1;

void push(int v){
  if( top == stackSize )
    printf("\nOverflow");
  else {
    s[top] = v;
    top++; 
  }
}
int peek() {
  return s[top-1];
}

void resetVisited() {
  for(int i = 1; i <= vc; i++) {
    vis[i] = 0;
  }
}

int stackisEmpty(){
  if( top == 1)
    return 1;
  else
    return 0;
}

int pop(){
  if( stackisEmpty() ) {
    printf("\nStack is Empty!");
    return 0;
  }
  else {
    top--;
    int n = s[top];
    s[top] = 0;
    return n;
  }
}

void insVertex(int v){
  vc = vc+1;
  adj_matrix[vc][0] = v;
  adj_matrix[0][vc] = v;
  for(int i = 1; i <= vc; i++){
    adj_matrix[vc][i] = 0;
    adj_matrix[i][vc] = 0;
  }
}

void delVertex(int v){
  int i,j,k;
  j = 0;
  for(i=1;i<=vc;i++){
    if(adj_matrix[i][j] == v){
      adj_matrix[i][j] = 0;
      for(k = 1; k <= vc; k++){
        adj_matrix[i][k] = 0;
      }
    }
  }

  i=0;
  for(j = 1;j <= vc;j++){
    if(adj_matrix[i][j] == v){
      adj_matrix[i][j] = 0;
      for(k = 0;k <= vc; k++){
        adj_matrix[k][j] = 0;
      }
    }
  }
}

void insEdge(int sE, int dE){
  adj_matrix[sE][dE] = 1;
  adj_matrix[dE][sE] = 1;
}

void delEdge(int sE, int dE){
  adj_matrix[sE][dE] = 0;
  adj_matrix[dE][sE] = 0;
}

void disMatrix(){
  for(int i=0; i<=vc; i++){
    for(int j=0; j<=vc; j++){
      printf("\t%d",adj_matrix[i][j]);
    }
    printf("\n");
  }
}

void enqueue(int x){
  if(f == -1){
    f = r = 0;
  }
  else{
    r = r + 1;
  }
  q[r] = x;
}

int dequeue(){
  int temp;
  temp = q[f];
  if(r == f){
    f = r = -1;
  }
  else{
    f = f + 1;
  }
  return temp;
}

int isEmpty(){
  if(f == -1)
    return 1;
  else
    return 0;
}

void bfs(int i){
  enqueue(i);
  vis[i] = 1;
  printf("%d", i);
  while( !isEmpty()){
    i = dequeue();
    for(int j = 1; j <= vc; j++){
      if(adj_matrix[i][j] == 1 && vis[j] != 1){
        enqueue(j);
        vis[j] = 1;
        printf(" %d", j);
      }
    }
  }
}
void dfs(int i){
  push(i);
  vis[i] = 1;
  while( !stackisEmpty()){
    i = peek();
    int newVertexVisited;

    for(int j = 1; j <= vc; j++){
      newVertexVisited=0;
      if(adj_matrix[i][j] == 1 && vis[j] != 1){
        push(j);
        vis[j] = 1;
        i = s[top - 1];
        newVertexVisited = 1;
        break;
      }
    }
    if( newVertexVisited == 0 )
      printf(" %d ", pop());
  }
}

int main(){
   printf("\t\t\t\t\t\t\t\tNishtha Sehgal\n\t\t\t\t\t\t\t\t02835304420");
  int v, choice = 0, sE, dE, source;
  do{
    resetVisited();

    printf("\n-----------------GRAPH-----------------");
    printf("\n1. INSERT A VERTEX");
    printf("\n2. DELETE A VERTEX");
    printf("\n3. INSERT AN EDGE");
    printf("\n4. DELETE AN EDGE");
    printf("\n5. DISPLAY THE ADJACENCY MATRIX");
    printf("\n6. TRAVERSAL (BFS)");
    printf("\n7. TRAVERSAL (DFS)");
    printf("\n8. EXIT");
    printf("\n\nINPUT YOUR CHOICE: ");
    scanf("%d",&choice);
    switch(choice){
      case 1: printf("\nINPUT THE VERTEX TO INSERT: ");
              scanf("%d",&v);
              insVertex(v);
              break;
      case 2: printf("\nINPUT THE VERTEX TO DELETE: ");
              scanf("%d",&v);
              delVertex(v);
              break;
      case 3: printf("\nINPUT THE SOURCE VERTEX: ");
              scanf("%d",&sE);
              printf("\nINPUT THE DESTINATION VERTEX: ");
              scanf("%d",&dE);
              insEdge(sE,dE);
              break;
      case 4: printf("\nINPUT THE SOURCE VERTEX: ");
              scanf("%d",&sE);
              printf("\nINPUT THE DESTINATION VERTEX: ");
              scanf("%d",&dE);
              delEdge(sE,dE);
              break;
      case 5: printf("\n\nADJACENCY MATRIX: \n");
              disMatrix();
              break;
      case 6: printf("\nINPUT THE SOURCE: ");
              scanf("%d", &source);
              printf("\n\nTRAVERSAL OF GRAPH (BFS): ");
              bfs(source);
              break;
      case 7: printf("\nINPUT THE SOURCE: ");
              scanf("%d", &source);
              printf("\n\nTRAVERSAL OF GRAPH (DFS): ");
              dfs(source);
              break;
      case 8: printf("\n\nExiting...");
              // choice = 0;
              break;

      default: printf("\nInvalid Choice!\n");

    }
  }while(choice <= 7);
}

