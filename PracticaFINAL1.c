#include<stdio.h>
#include<stdlib.h>
#define V 50

typedef struct 
{
    int NroUnidad;                              // Entre 1 y 50
    char PatenteVehiculo[7];                    
    char MarcayModelo[15];                      // No mas de 15 char
    int AñoDeFabri[4];                          // 2018 en adelante
    char TipoDeCombustible;                     // Nafta,Gas,GasOIL
    char CategoriaInterna;                       // A=Urbanos     B=Hasta 60km    C=Mas de 60km
    char Estado;                                // Ocupado, Desocupado
} InformacionMoviles;

typedef struct 
{
    char NombreyApellidoCliente[30];
    char DireccionDePartida[30];
    char DireccionDeDestino[30];
    float DistanciaEnKM;                        
} InformacionCliente;

void seleccion(int opc, InformacionCliente C[], InformacionMoviles M[]);
void IngresoDatos(InformacionMoviles M[]);                            // Validar los datos ingresados.
void MostrarMoviles();                                                // Listado encolumnado de los datos de cada movil
void cotizarViaje();    
int Menu();
int CalculoTarifa();
int BuscarMoviles();


int main()
{
    int opcion;
    InformacionMoviles M[V];
    InformacionCliente C[V];
    do
    {
        opcion = Menu();
        seleccion(opcion, M, C);
    } while (opcion != 0);
    
    printf("Fin del programa");

    return 0;
}

void seleccion(int opc, InformacionCliente *C, InformacionMoviles *M)
{
    switch (opc)
    {
    case 1:
        IngresoDatos(M);
        break;
        /*case 2: 
            MostrarMoviles(M);
            break;
            case 3:
                CalculoTarifa(C);
                break;*/
    }
    return;
}

int Menu()
{
    int opc;

    printf("Bienvendio a la agencia de remiseria.\n");
    printf("\n1- Ingresar datos de un vehiculo.\n");
    printf("2- Mostrar los datos ingresados.\n");
    printf("3- Cotizar el viaje (Es necesario que se proporcione mas informacion).\n");
    printf("0- SALIR.\n");

    do
    {
        printf("\n Ingrese la opcion que desee realizar: ");
        scanf("%d",&opc);
    } while (opc < 0 || opc > 3);

    return opc;
}

void IngresoDatos(InformacionMoviles M[])
{
    int NroUnidad,AñoFabri;
    for (int i = 0; i < V; i++)
    {
        do
        {
            printf("Ingrese el numero de la unidad del movil %d",i+1);
            scanf("%d",&NroUnidad);
        } while (NroUnidad < 1 || NroUnidad > 50);
        M[i].NroUnidad = NroUnidad;
        
        do
        {
            /* code */
        } while (/* condition */);
        
    }
    
}