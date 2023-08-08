#include<stdio.h>

void Opciones();
void IngresarDatos();
int menu();
#define T 10

int main()
{
   int op;
   int array[T] = {0};

   do
   {
    op = menu();
    Opciones(op,array[T]);
   } while (op != 0);

   printf("\nFIN DEL PROGRAMA.");

   return 0;
}

int menu()
{
    int opcionElegida;
    printf("Menu de opciones.\n");
    printf("\n1- Agregar valores al array\n");
    printf("2- Mostrar los valores del array\n");
    printf("3- Calcular el promedio de los valores del array\n");
    printf("4- Mostrar el valor maximo y minimo del array\n");
    printf("0- Salir del menu\n");

    do
    {
        printf("\nIngrese una opcion: ");
        scanf("%d",&opcionElegida);
        if (opcionElegida > 4)
        {
            printf("Error al ingresar la opcion.Intente nuevamente.");
        }
        
    } while (opcionElegida < 0 || opcionElegida > 4);

    return opcionElegida;
    
}

void Opciones(int op,int array[T])
{
    switch (op)
    {
    case 1:
        IngresarDatos(array[T]);
        break;
    
    }
}

void IngresarDatos(int array[T])
{
    for (int i = 0; i <= T; i++)
        {
            printf("Ingrese un valor para la posicion %d del array: ",i + 1);
            scanf("%d",&array[i]);
        }
}