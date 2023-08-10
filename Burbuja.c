#include<stdio.h>
#include<string.h>

int main()
{
    int arreglo[] = {1,5,7,2,3,6,4,8,5,6};
    int aux;
    for (int i = 0; i < 10; i++)
{
    for (int j = i + 1; j < 10; j++)
    {
        if (arreglo[i] < arreglo[j]) 
        {
            aux = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = aux;
        }
    }
}
    for (int i = 0; i < 10; i++)
    {
        printf("%d",arreglo[i]);
    }
    
}