#include <stdio.h>
#include <stdlib.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){

   for(int i = 0 ; i < 9 ; i++){
      int fila[10] = {0};
      for(int j = 0 ; j < 9 ; j++){
         if(n->sudo[i][j] != 0 && fila[n->sudo[i][j]] == 1){
            return 0;
         }
         fila[n->sudo[i][j]] = 1;
      }
   }
    return 1;
}


List* get_adj_nodes(Node* n){
   List* list=createList();
   int columna;
   int fila;
   for (int i = 0 ; i < 9 ; i++)
   {
      fila = i;
      for (int j = 0 ; j < 9 ; j++)
      {
         columna = j;
         if(n->sudo[i][j] == 0)
         {
            break;
         }
      }
      if (n->sudo[fila][columna] == 0)
      {
         break;
      }
   }
   if (fila == 9 && columna == 9){
      return list;
   }

   for (int k = 1 ; k <= 9; k++)
      {
         Node *aux = copy(n);
         aux->sudo[fila][columna] = k;
         if (is_valid(aux))
         {
            pushBack(list,aux);
         }
         else   
            free(aux);
      }

   return list;
   
}


int is_final(Node* n)
{
   for (int i = 0 ; i < 9 ; i++)
      {
         for (int j = 0 ; j < 9 ; j++)
            {
               if (n->sudo[i][j] == 0)
                  {
                     return 0;
                  }
            }
      }
    return 1;
    
}

Node* DFS(Node* initial, int* cont)
{
   Stack* stack = createStack();
   push(stack,initial);

   while (get_size(stack) != 0)
      {
         Node* n = top(stack);
         pop(stack);
         if (is_final(n))
            {
               return n;
            }
         List* list = get_adj_nodes(n);
         Node* aux = first(list);
         while (aux != NULL)
            {
               push(stack,aux);
               aux = next(list);
            }
         free(n);
      }
   return NULL;

}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/