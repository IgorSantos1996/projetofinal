#include <stdio.h>
#include <stdlib.h>

#define LENGHT 5

void bubbleSort( int vector[LENGHT] );
void selectionSort( int vector[LENGHT] );
void InsertionSort( int vector[LENGHT] );
void QuickSort( int vector[LENGHT] , int inicio , int fim );

int printMenu();
void printMsg( int vector[LENGHT], int option );
void printArray( int vector[LENGHT] );
void vectorRead( int vector[LENGHT] );

int main()
{
    int option, vector[LENGHT];


    do
    {
        vectorRead( vector );

        option = printMenu();

        switch ( option )
        {
            case 1:
            {
                bubbleSort( vector );
                break;
            }

            case 2:
            {
                selectionSort( vector );
                break;
            }

            case 3:
            {
                InsertionSort( vector );
                break;
            }

            case 4:
            {
                printMsg( vector , 0 );
                QuickSort( vector , 0 , LENGHT-1 );
                printMsg( vector , 1 );
                system("pause");
                system("cls");
                break;
            }

            default:
                break;
        }
    } while ( option != 5 );



}

/*
Descricao
    Funcao responsavel pela selection sort
Parametro
    vetor de numeros inteiros
*/
void selectionSort ( int vector[LENGHT] )
{
    int i, j, aux;

    printMsg( vector , 0 );

	   for (i = 0; i < LENGHT; i++){
	   		for (j = i + 1; j < LENGHT; j++){
				if (vector[i] > vector[j]){
					aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;
				}
			}
	   }

    printMsg( vector , 1 );

    system("pause");
    system("cls");
}


/*
Descricao
    Funcao responsavel pela bubble sort
Parametro
    vetor de numeros inteiros
*/
void bubbleSort ( int vector[LENGHT] )
{
    int i, j, aux;

    printMsg( vector , 0 );

	   for (i = 0; i < LENGHT; i++){
	   		for (j = 0; j < LENGHT; j++){
				if (vector[i] > vector[j]){
					aux = vector[i];
					vector[i] = vector[j];
					vector[j] = aux;
				}
			}
	   }

    printMsg( vector , 1 );


    system("pause");
    system("cls");
}


/*
Descricao
    Funcao responsavel pela insertion sort
Parametro
    vetor de numeros inteiros
*/
void InsertionSort( int vetor[] )
{
	int i, k, temp;

	printMsg( vetor , 0 );

	for(i = 1; i < LENGHT; i++)
	{
		k = i;
		temp = vetor[i];
		while((k > 0) && (temp < vetor[k - 1]))
		{
			vetor[k] = vetor[k - 1];
			k--;
		}
		vetor[k] = temp;
	}

	printMsg( vetor , 1 );


    system("pause");
    system("cls");
}


/*
Descricao
    Funcao responsavel pelo quick sort
Parametro
    vetor de numeros inteiros
    unicio do array
    final do array
*/
void QuickSort(int vetor[LENGHT], int inicio, int fim)
{
	int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) QuickSort(vetor, inicio, j);
   if(i < fim) QuickSort(vetor, i, fim);
}


/*
Descricao
    Funcao responsavel pela impressao e leitura da opcao do menu
Parametro
    vetor de numeros inteiros
Retorno
    inteiro - opcao do menu
*/
int printMenu()
{
    int option = 0;

    printf("\nORDENACAO DE VETOR\n");
    printf("------------------");
    printf("\n1 - BubbleSort");
    printf("\n2 - SelectionSort");
	printf("\n3 - InsertionSort");
	printf("\n4 - QuickSort");
	printf("\n5 - Sair\n");
	printf("\n");

	scanf("%d", &option);

	return option;
}


/*
Descricao
    Funcao responsavel pela impressao do antes e depois do array
Parametro
    vetor de numeros inteiros
*/
void printMsg( int vector[LENGHT], int option )
{
    switch (option)
    {
        case 0:
        {
            printf("\nArray dado:\n");
            printArray( vector );
            break;
        }
        case 1:
        {
            printf("\nArray ordenado:\n");
            printArray( vector );
            printf("\n\n");
            break;
        }
    }
}


/*
Descricao
    Funcao responsavel pela selection sort
Parametro
    vetor de numeros inteiros
*/
void printArray( int vector[LENGHT] )
{
    int i;

    for ( i = 0 ; i < LENGHT ; i++ )
    {
        if ( i == 0 )
        {
            printf("[");
            printf("%d", vector[i]);
        }
        else
        {
            printf(",%d", vector[i]);
        }
    }
    printf("]");
    printf("\n");
}


/*
Descricao
    Funcao responsavel por salvar os valores no array
Parametro
    vetor de numeros inteiros
*/
void vectorRead( int vector[] )
{
	int i;

	printf("Informe os valores do array:\n");
	for( i = 0; i < LENGHT ; i++ )
	{
	    printf("Posicao %d: ", i);
        scanf("%d", &vector[i]);
    }

}

