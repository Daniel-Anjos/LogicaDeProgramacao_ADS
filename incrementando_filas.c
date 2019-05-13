#include <stdio.h>
#include <stdlib.h>
//Utilizado para adaptar as características de idioma
#include<locale.h>

#define tamanho 5

struct tipo_fila{
    int dados[tamanho];
    int ini;
    int fim;
};

//objeto do tipo_fila para manipular a fila
struct tipo_fila fila;
int opcao;

//Protótipação das funções: Utilizado para avisar ao compilador quando as funções são declaradas após o método Main
void enfileira();
void desenfileira();
void fila_mostrar();
void menu_mostrar();

//Aqui definimos o idioma para português
int main(){
    setlocale(LC_ALL, "Portuguese");
    opcao = 1;
    fila.ini = 0;
    fila.fim = 0;
    
    while (opcao != 0){
        system ("cls");
        fila_mostrar();
        menu_mostrar();
        scanf("%d", &opcao);
        switch (opcao){
        case 1:
            enfileira();
            break;
        case 2:
            desenfileira();
            break;
        }
    }
    return(0);    
}

    void enfileira(){
        //Verifica se a fila está cheia
        if (fila.fim == tamanho){
            printf ("Fila cheia, volte outro dia \n");
            system("pause");
        }
        /*Caso não esteja, a posição final recebe o elemento 
        e o fim é incrmenetado*/
        else{
            printf("Informe o valor a ser inserido na fila: \n");
            scanf("%d", &fila.dados[fila.fim]);
            fila.fim++;
        }
    }

    //definido o tipo de retorno da função
    void desenfileira(){
        int elemento;
        if (fila.fim == fila.ini){
            printf("Fila vazia, insira elementos! \n");
            system("pause");
        }
        /*Se o inicio for igual ao fim não há itens na fila. Do contrário é provável que o fim seja 
        maior que o início (pois ele é incrementado nas inserções) */
        else{
            //pega o elemento de início e joga para a variável elemento
            elemento = fila.dados[fila.ini];
            //Arrastando os elementos para o início. 
            //Este for Vai percorrer a estrutura toda (até o i ser igual ao tamanho) e move o dado da posição acima (i +1) para a posição atual (i)
            for(int i =0; i < tamanho; i++){
                fila.dados[i] = fila.dados[i+1];
            }
            //Neste ponto o fila.fim recebe 0 para não ficar vazio, já que o elemento foi enviado para frente    
            fila.dados[fila.fim] = 0;
            fila.fim--;
            printf("Elemento Removido: ");
            printf ("%d \n", elemento);
            system("pause");
        }  
    }
    void fila_mostrar(){
        printf("[ ");
        for(int i = 0; i < tamanho; i++){
            printf("%d", fila.dados[i]);
        }
            printf("]\n");
    } 

    void menu_mostrar(){
        printf("Informe a opção desejada: \n");
        printf("1 - Inserir elemento na fila \n");
        printf("2 - Remover elemento da fila \n");
        printf("0 - Sair \n");
    }

