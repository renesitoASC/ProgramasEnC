#include <stdio.h>

int menu();
void opciones(int op, int num1, int num2);

int main()
{
    int op,num1,num2;

    do
    {
        op = menu();
        opciones(op, num1, num2);
    } while (op != 0);

    return 0;
}

int menu()
{
    int opcion, num1, num2;

    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo numero: ");
    scanf("%d", &num2);

    printf("\nMenu de opciones\n-------------------------\n");
    printf("1- Suma de los numeros.\n");
    printf("2- Resta de los numeros.\n");
    printf("3- Multiplicacion de los numeros.\n");
    printf("4- Division de los numeros.\n");
    printf("5- Mostrar los numeros ingresados.\n");
    printf("0- Salir del menu\n");
    printf("-------------------------\n");

    do
    {
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        if (opcion < 0 || opcion > 5)
        {
            printf("Error en el ingreso de opcion.\n");
        }
    } while (opcion < 0 || opcion > 5);

    opciones(opcion, num1, num2);

    return opcion;
}

void opciones(int op, int num1, int num2)
{
    switch (op)
    {
    case 1:
        printf("La suma de los numeros es: %d\n", num1 + num2);
        break;
    case 2:
        printf("La resta de los numeros es: %d\n", num1 - num2);
        break;
    case 3:
        printf("La multiplicacion de los numeros es: %d\n", num1 * num2);
        break;
    case 4:
        if (num2 != 0)
        {
            printf("La division de los numeros es: %.2f\n", (float)num1 / num2);
        }
        else
        {
            printf("No es posible dividir por cero.\n");
        }
        break;
    case 5:
        printf("Los numeros ingresados son: %d y %d\n", num1, num2);
        break;
    case 0:
        printf("Usted ha salido del menu.\n");
        break;
    default:
        printf("Opción inválida.\n");
        break;
    }
}
