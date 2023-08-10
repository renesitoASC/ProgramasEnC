#include<stdio.h>
#include<string.h>
#define V 2

typedef struct 
{
    int NroUnidad;                              // Entre 1 y 50
    char PatenteVehiculo[8];                    
    char MarcayModelo[15];                      // No mas de 15 char
    int AnoDeFabri;                             // 2018 en adelante
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
void MostrarMoviles(InformacionMoviles M[]);                                                // Listado encolumnado de los datos de cada movil
void cotizarViaje(InformacionCliente C[]);    
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

void seleccion(int opc, InformacionCliente C[], InformacionMoviles M[])
{
    switch (opc)
    {
    case 1:
        IngresoDatos(M);
        break;
        case 2: 
            MostrarMoviles(M);
            break;
            case 3:
                CalculoTarifa(C);
                break;
    }
    return;
}

int Menu()
{
    int opc;

    printf("\nBienvendio a la agencia de remiseria.\n");
    printf("\n1- Ingresar datos de un vehiculo.\n");
    printf("2- Mostrar los datos ingresados.\n");
    printf("3- Cotizar el viaje (Es necesario que se proporcione mas informacion).\n");
    printf("0- SALIR.\n");

    do
    {
        printf("\nIngrese la opcion que desee realizar: ");
        scanf("%d",&opc);
    } while (opc < 0 || opc > 3);

    return opc;
}

void IngresoDatos(InformacionMoviles M[])
{
    int NroUnidad,AnoFabri;
    char Patente[7];
    char Marcaymodelo[15];
    char combustible;
    char categoria;
    char estado;

    for (int i = 0; i < V; i++)
    {
        do
        {
            printf("Ingrese el numero de la unidad del movil %d: ",i+1);
            scanf("%d",&NroUnidad);
        } while (NroUnidad < 1 || NroUnidad > 50);
        M[i].NroUnidad = NroUnidad;
        
        do
    {
        printf("Ingrese la patente del vehiculo %d: ", i+1);
        fflush(stdin);
        gets(Patente);
    } while (strlen(Patente) < 1 || strlen(Patente) > 7);
    strcpy(M[i].PatenteVehiculo, Patente);

        do
    {
        printf("Ingrese la marca y modelo del movil %d: ", i+1);
        fflush(stdin);
        gets(Marcaymodelo);
        if (strlen(Marcaymodelo) > 15)
        {
            printf("Error. Intente de nuevo\n");
        }
    } while (strlen(Marcaymodelo) < 1 || strlen(Marcaymodelo) > 15);
    strcpy(M[i].MarcayModelo, Marcaymodelo);

        do
    {
            printf("Ingrese el ano de fabricacion del movil %d: ",i+1);
            scanf("%d",&AnoFabri);
            if (AnoFabri < 2018)
            {
                printf("Error. Vehiculo viejo. Intente nuevamente.\n");
            }
    } while (AnoFabri < 1000 || AnoFabri > 9999 || AnoFabri <= 2018);
        M[i].AnoDeFabri = AnoFabri;

        do
    {
            printf("Indique el tipo de combustible del movil %d (Nafta=N, Gas=G, GasOIL=GO): ", i+1);
            getchar();
            scanf(" %c", &combustible);
            if (combustible != 'N' && combustible != 'G' && combustible != 'GO')
            {
                printf("Error al ingresar combustible. Intente de nuevo (Atento a mayusculas)\n");
            }
    } while (combustible != 'N' && combustible != 'G' && combustible != 'GO');
        M[i].TipoDeCombustible = combustible;

        do
    {
            printf("Que categoria es el movil %d? (A=Urbanos B=Hasta 60km C=Mas de 60km): ", i+1);
            getchar();
            scanf(" %c", &categoria);
            if (categoria != 'A' && categoria != 'B' && categoria != 'C')
            {
                printf("Error al ingresar la categoria del movil. (Atento a mayusculas)");
            }
        } while (categoria != 'A' && categoria != 'B' && categoria != 'C');
        M[i].CategoriaInterna = categoria;

        do
        {
            printf("Ingrese el estado del movil %d (Ocupado=O, Desocupado=C): ", i+1);
            getchar();
            scanf(" %c", &estado);
            if (estado != 'O' && estado != 'D')
            {
                printf("Error al ingresar el estado del movil. (Atento a mayusculas)");
            }
        } while (estado != 'O' && estado != 'D');
        M[i].Estado = estado;
    }
}

void MostrarMoviles(InformacionMoviles M[])
{
    for (int i = 0; i < V; i++)
    {
        printf("El numero de unidad del movil %d es: %d\n", i+1,M[i].NroUnidad);
        printf("La patente del movil %d es: %c\n",i+1,M[i].PatenteVehiculo);
        printf("La marca y el modelo del movil %d es: %c\n",i+1,M[i].MarcayModelo);
        printf("El ano de fabricacion del movil %d es: %d\n",i+1,M[i].AnoDeFabri);
        printf("El tipo de combustible del movil %d es: %c\n",i+1,M[i].TipoDeCombustible);
        printf("La categoria del movil %d es: %c\n",i+1,M[i].CategoriaInterna);
        printf("El estado del movil %d es: %c\n",i+1,M[i].Estado);
    }
}

void cotizarViaje(InformacionCliente C[])
{
    char NombreApellido[30];
    char partida[30];
    char destino[30];
    float kms;

    for (int i = 0; i < V; i++)
    {
        do
        {
            printf("Ingrese el nombre y apellido de cliente: ");
            fflush(stdin);
            gets(NombreApellido);

            if (strlen(NombreApellido) > 30)
            {
                printf("Error al ingresar el nombre del cliente.");
            } 
        } while (strlen(NombreApellido) < 1 || strlen(NombreApellido) > 30);
        
        
    }
    
}