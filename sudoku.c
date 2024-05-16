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
   /*
    List* list=createList();
    return list;
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

   for (int k = 1 ; k <= 9 ; k++)
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
    */
   List* list = createList();
   int fil,col;

   //Buscar 1r casilla vac[ia]
   for (int i = 0; i < 9;i++){
      fil = i;
      for (int j = 0; j < 9; j++){
         col = j;
         if (n->sudo[i][j] == 0){
            break;
         }
      }
      if (n->sudo[fil][col] == 0){
         break;
      }
   }

   //Todas las casillas lenas
   if (fil == 9 && col == 9){
      return list;
   }

   //crear adjts.
   for (int num = 1; num <= 9; num++){
      Node* aux_node = copy(n); //Creo nuevo nodo
      aux_node->sudo[fil][col] = num;
      if(is_valid(aux_node)){
         pushBack(list, aux_node);
      } else {
         free(aux_node);
      }
   }

   return list;
}

Node* DFS(Node* initial, int* cont){
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