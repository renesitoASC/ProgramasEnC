#include<stdio.h>

void Opciones();
void IngresarDatos();
void MostrarDatos();
void Promedio();
void MaxyMin();
int menu();
#define T 10

int main()
{
   int op;
   int array[T] = {0};

   do
   {
    op = menu();
    Opciones(op,array);
   } while (op != 0);

   printf("\nFIN DEL PROGRAMA.");

   return 0;
}

int menu()
{
    int opcionElegida;
    printf("\nMenu de opciones.\n");
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
        IngresarDatos(array);
        break;
            case 2:
                MostrarDatos(array);
                break;
                case 3:
                    Promedio(array);
                    break;
                    case 4:
                        MaxyMin(array);
                        break;
    }
}

void IngresarDatos(int array[T])
{
    for (int i = 0; i < T; i++)
        {
            printf("Ingrese un valor para la posicion %d del array: ",i + 1);
            scanf("%d",&array[i]);
        }
        return;
}

void MostrarDatos(int array[T])
{
    for (int i = 0; i < T; i++)
    {
        printf("El valor numero %d es %d\n",i + 1, array[i]);
    }
    return;
}

void Promedio(int array[])
{
    int suma=0,promedio;

    for (int i = 0; i < T; i++)
    {
        suma += array[i];
    }
    
    promedio = suma / T;
    printf("El promedio de los valores del array es de: %d",promedio);
}

void MaxyMin(int array[])
{
    int maximo = array[0];
    int minimo = array[0];

    for (int i = 0; i < T; i++)
    {
        if (array[i] > maximo)
        {
            maximo = array[i];
        }
        if (array[i] < minimo)
        {
            minimo = array[i];
        }
    }
    printf("El valor maximo del array es de: %d\n",maximo);
    printf("El valor minimo del array es de: %d",minimo);
}