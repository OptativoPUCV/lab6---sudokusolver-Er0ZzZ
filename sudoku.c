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

int is_valid(Node* n) {
    int i, j, k;

    // Verificar filas y columnas
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            // Verificar fila
            for (k = 0; k < 9; k++) {
                if (k != j && n->sudo[i][k] == n->sudo[i][j]) return 0;
            }
            // Verificar columna
            for (k = 0; k < 9; k++) {
                if (k != i && n->sudo[k][j] == n->sudo[i][j]) return 0;
            }
        }
    }

    // Verificar submatrices de 3x3
    for (i = 0; i < 9; i += 3) {
        for (j = 0; j < 9; j += 3) {
            for (int x = i; x < i + 3; x++) {
                for (int y = j; y < j + 3; y++) {
                    for (int a = i; a < i + 3; a++) {
                        for (int b = j; b < j + 3; b++) {
                            if ((x != a || y != b) && n->sudo[x][y] == n->sudo[a][b]) return 0;
                        }
                    }
                }
            }
        }
    }
    return 1; // Si no se encontraron problemas, el estado es válido
}




List* get_adj_nodes(Node* n){
   List* list=createList();
   for(int i=0;i<9;i++)
      {
         for(int j=0;j<9;j++)
            {
               if(n->sudo[i][j]==0)
               {
                  for(int k=1;k<10;k++)
                     {
                        Node* adj= copy(n);
                        adj->sudo[i][j]=k;
                        if(is_valid(adj))
                           pushBack(list,adj);  
                     }
               }  
            }
      }
   return list;
}


int is_final(Node* n){
    return 0;
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