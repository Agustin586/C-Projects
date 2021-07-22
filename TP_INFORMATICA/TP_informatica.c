#include <conio.h>
#include <stdio.h>
#include <string.h>

#define MAX_PELICULAS   100
#define DIAS            7
#define MAX_LONG_NOMBRE 60
#define TOP10           10

// Declaracion de variables globales
_Bool Cant_opc1;
typedef struct {
    int ID,Views_dia[DIAS];
    float Punt_dia[DIAS],Views_Total,Punt_Total;
    char Nombre[MAX_LONG_NOMBRE];
}peliculas;

peliculas ListaPeliculas[MAX_PELICULAS];

// Lista de funciones
void Inicializar (void);    // Inicializa la lista de peliculas por archivos basuras
void OPCION1 (void);        // Ingresa a la opcion 1 y realiza el procesamiento de datos
void OPCION2 (void);        // Ingresa a la opcion 2 y realiza ...
void OPCION3 (void);        // ...
void OPCION4 (void);        // ...
void CargarArchivo (FILE *archivo,int num_archiv);                  // Esta funcion se encarga de cargar los archivo al registro
void RANKING (void);                                                // Se encarga de procesar la opcion 1
void CargaTotalViews (void);                                        // Carga el total del views en el registro
int BuscaID (int id);                                               // Busca la id en el registro
void CargarTop10 (float Top10_views[],int Top10_id[]);              // Carga el top10 de peliculas en dos arreglos
void OrdenarListaPeliculas (void);                                  // Ordena el registro segun el total de views de forma descendete
void MostrarTop10 (float Top10_views[],int Top10_id[]);             // Muestra el top10 de views y su id
void GRABAR_TOP10(FILE *top10,float Top10_views[],int Top10_id[]);  // Graba en un archivo top10.txt los datos correspondientes
void AccionesComunes(void);                                         // Llama a funciones que son comunes a mas de una opcion
float VALORACION_PONDERADA(int lugar);
void DIA_MAS(int indice, float Views_t_dias[], char eldia[][15]);	// Muestra el dia y la cantidad de las mayores visualizaciones

// Funcion principal //
// -------------------------------------- //
int main ()
{
    FILE *archivo_pelicula,*archivo_datos7dias;
    int opcion, cantpelis;

    printf("Bievenidos al programa\n");
    // Inicializamos el registro
    Inicializar();
    // Abre el archivo y carga los datos al registro
    CargarArchivo(archivo_pelicula,1);      // Abre el archivo peliculas.txt
    CargarArchivo(archivo_datos7dias,2);    // Abre el archivo datos_7dias.txt
    // Inicializamos las funciones que son comunes a varias opciones
    AccionesComunes();

    printf("\nMenu:\n1:Ranking y top10\n2:Valoracion semanal\n3:Filtro cantidad de visualizaciones\n4:Pico visualizaciones\n0:Cerrar\n\nOpcion:");
    scanf("%d",&opcion);
    while (opcion < 0 || opcion > 4)
    {
        printf("Ingrese de nuevo\n");
        printf("\nMenu:\n1:Ranking y top10\n2:Valoracion semanal\n3:Filtro cantidad de visualizaciones\n4:Pico visualizaciones\n0:Cerrar\n\nOpcion:");
        scanf("%d",&opcion);
    }

    while (opcion != 0)
    {
        switch (opcion)
        {
            case 1:
            {
                OPCION1();
            break;
            }
            case 2:
            {
                OPCION2();
            break;
            }
            case 3:
           {
                int views,i;
                printf("Ingrese cantidad de visualizaciones: ");
                scanf("%d", &views);
                printf("\n");
                cantpelis=0;
                i=0;
                while(i<MAX_PELICULAS)
                {
                    while(views<ListaPeliculas[i].Views_Total)
                    {
                        peliculas aux;
                        int long_nombre = strlen(ListaPeliculas[i].Nombre); // strlen
                        aux = ListaPeliculas[i];
                        for (int indice = long_nombre; indice < 43; indice++)
                        {
                            strcat(aux.Nombre," ");   //
                        }
                        
                        printf("===============================================================================================\n");
                        printf("Pelicula:\t\t\t\t\t\tVisualizaciones:\n%s\t\t%.0f\n", aux.Nombre, aux.Views_Total);
                        printf("===============================================================================================\n");
                        cantpelis=cantpelis+1;
                        i=i+1;
                    }
                    i = i + 1;
                }
                if(cantpelis==0)
                    printf("Ningun titulo fue visto tantas veces!\n\n");
            break;
            }
            case 4:
            {
                OPCION4();
            break;
            }
        }
        printf("\nMenu:\n1:Ranking y top10\n2:Valoracion semanal\n3:Filtro cantidad de visualizaciones\n4:Pico visualizaciones\n0:Cerrar\n\nOpcion:");
        scanf("%d",&opcion);
        while (opcion < 0 || opcion > 4)
        {
            printf("Ingrese de nuevo\n");
            printf("\nMenu:\n1:Ranking y top10\n2:Valoracion semanal\n3:Filtro cantidad de visualizaciones\n4:Pico visualizaciones\n0:Cerrar\n\nOpcion:");
            scanf("%d",&opcion);
        }
    }
    printf("\nGracias por usar el programa");

    getch();
    return 0;
}
// -------------------------------------- //

// Funciones de inicializacion //
// -------------------------------------- //
void Inicializar (void)
{   
    for (int i = 0; i < MAX_PELICULAS; i++)
    {
        ListaPeliculas[i].ID = 0;
        ListaPeliculas[i].Punt_Total = 0;
        ListaPeliculas[i].Views_Total = 0;
        for (int j = 0; j < DIAS; j++)
        {
            ListaPeliculas[i].Punt_dia[j] = 0;
            ListaPeliculas[i].Views_dia[j] = 0;
        }
    }
    return;
}
void CargarArchivo (FILE *archivo,int num_archivo)
{
    if (num_archivo == 1)
    {
        if ((archivo = fopen("peliculas.txt", "r")) == NULL)    
            printf ( "Error en la apertura. Es posible que el fichero no exista \n");
        else
        {
            for (int i = 0;i < MAX_PELICULAS; i++)
            {
                if (!feof(archivo))
                {
                    fscanf (archivo, "%d%s\n", &ListaPeliculas[i].ID, ListaPeliculas[i].Nombre);
                }
                // Muestra por pantalla toda la lista del archivo
                // printf("\n%d %s",ListaPeliculas[i].ID, ListaPeliculas[i].Nombre);
            }
        }
    }
    else if (num_archivo == 2)
    {
        int id_aux,dia,views,lista;
        float punt;
        if ((archivo = fopen("datos_7dias.txt", "r")) == NULL)
            printf ( "Error en la apertura. Es posible que el fichero no exista \n");
        else
        {
            while (!feof(archivo))
            {
                fscanf (archivo, "%d%d%d%f",&id_aux,&dia,&views,&punt);
                lista = BuscaID(id_aux);
                if (lista == MAX_PELICULAS+1)
                    printf("La pelicula no existe");
                else
                {
                    ListaPeliculas[lista].Views_dia[dia-1] = views;
                    ListaPeliculas[lista].Punt_dia[dia-1] = punt;   
                }
            }
        }
        // printf("\n\n");
        // for (int i = 0; i < MAX_PELICULAS; i++)
        // {
        //     printf("Id:\tDia:\tViews:\tPuntuacion:");
        //     for (int dia_ = 0; dia_ < DIAS; dia_++)
        //     {
        //         printf("\n%d\t%d\t%d\t%.2f",ListaPeliculas[i].ID,dia_+1,ListaPeliculas[i].Views_dia[dia_],ListaPeliculas[i].Punt_dia[dia_]);  
        //     }
        //     printf("\n\n");
        // }
    }
    fclose(archivo);
    return;
}
// -------------------------------------- //

// Funciones de menu //
// -------------------------------------- //

void OPCION1 (void)
{
    RANKING();
    return;
}
// -------------------------------------- //

void OPCION2 (void)
{
    //variables
    int cont,id,lugar;
    float ponderada;

    //inicio
    printf("Id de la pelicula a buscar valoracion:");
    scanf("%i",&id);
    cont=0;
    // Buscamos la id de la pelicula para ver si la ingresada existe y corresponde con las guardadas
    for(int i=0; i < MAX_PELICULAS; i++)
    {
        if(id == ListaPeliculas[i].ID)
        {
            cont=cont+1;
            lugar=i;
        }
    }
    if(cont == 1)
    {
        ponderada = VALORACION_PONDERADA(lugar);
        printf("\nLa valoracion semanal de la pelicula %i ,%s es %.2f\n\n",ListaPeliculas[lugar].ID,ListaPeliculas[lugar].Nombre,ponderada);
    }
    else printf("\nEl codigo de pelicula no existe\n\n");
    return;
}
// -------------------------------------- //

void OPCION4 (void)
{
    int indice;
    float Views_t_dias[7], num_may;
    char eldia[7][15]={"lunes","martes","miercoles","jueves","viernes","sabado","domingo"};
    
    for(int j = 0; j < DIAS; j++)	//limpia el arreglo
    {
        Views_t_dias[j] = 0;
    }
    
    //Suma el total de views de cada pelicula correspondiente a cada dia
    for(int lista = 0;lista < MAX_PELICULAS;lista++)
    {
        for(int dia = 0; dia < DIAS; dia++)
        {
			Views_t_dias[dia] = Views_t_dias[dia] + ListaPeliculas[lista].Views_dia[dia];
        }
    }
    
    for(int dia = 0; dia < DIAS; dia++)
    {
    	if(dia==0) num_may=0, indice=0;
		
		if(Views_t_dias[dia] > num_may)	num_may=Views_t_dias[dia], indice=dia;
	}
	
	DIA_MAS(indice,Views_t_dias,eldia);
}
// -------------------------------------- //

// -------------------------------------- //
// Funciones relacionadas con la opcion 4 //
// -------------------------------------- //
void DIA_MAS(int indice, float Views_t_dias[], char eldia[][15])	
{
	printf("\n\n");
	printf("El dia con mas visualizaciones fue el %s",eldia[indice]);
	printf(" con %.0f",Views_t_dias[indice]);
	printf(" visualizaciones");
	printf("\n\n");
	
	return;
}
// -------------------------------------- //

// -------------------------------------- //
// Funciones relacionadas con la opcion 1 //
// -------------------------------------- //
void RANKING (void)
{
    FILE *archivo_top10;
    float Top10_views[TOP10];
    int Top10_id[TOP10];

    //Carga el total de visualizaciones
	// if (!Cant_opc1) CargaTotalViews();
    //Genera una nueva lista con el top10 de visualizaciones y de IDs de peliculas 
    CargarTop10(Top10_views,Top10_id);
    //Muestra por pantalla toda la lista
    MostrarTop10(Top10_views,Top10_id);
    //Graba todo a un archivo
    GRABAR_TOP10(archivo_top10,Top10_views,Top10_id);
    // Permite no cargar dos o mas veces el total de views en la lista de peliculas
    // Cant_opc1 = 1;

    return;
}
int BuscaID(int id)
{
    int indice;

    // Comienza la busqueda de la id, recorriendo la lista de peliculas existentes
    for (int i = 0; i < MAX_PELICULAS; i++)
    {
        if (ListaPeliculas[i].ID == id)
        {
            indice = i;
            return indice;
        }    
    }
    // En caso de no encontrar el id de la pelicula devuelve el indice 101
    // dando a entender que no existe
    return MAX_PELICULAS+1;
}
void CargarTop10(float Top10_views[],int Top10_id[])
{
    // Limpiamos el arreglo para borrar los archivos basuras //
    for (int top10 = 0; top10 < 10; top10++)
    {
        Top10_views[top10] = 0;
        Top10_id[top10] = 0;
    }
    // Ordenamos la lista de peliculas según su total de visualizaciones //
    // OrdenarListaPeliculas ();
    //Copia los 10 primeros elementos del arreglo en el top10
    for (int top10 = 0; top10 < 10; top10++)
    {
        Top10_views[top10] = ListaPeliculas[top10].Views_Total;
        Top10_id[top10] = ListaPeliculas[top10].ID;
    }
    
    return;
}
void OrdenarListaPeliculas (void)
{
    peliculas aux;
    int lista,j,lugar;

    // Ordenamiento por seleccion //
    for ( lista = 0; lista < MAX_PELICULAS-1; lista++)
    {
        aux = ListaPeliculas[lista];
        lugar = lista;

        for ( j = lista+1; j < MAX_PELICULAS; j++)
        {
            if (ListaPeliculas[j].Views_Total > aux.Views_Total)
            {
                aux = ListaPeliculas[j];
                lugar = j;
            }
        }
        // Intercambia los registros //
        ListaPeliculas[lugar] = ListaPeliculas[lista];
        ListaPeliculas[lista] = aux;        
    }
    return;
}
void MostrarTop10 (float Top10_views[],int Top10_id[])
{
    printf("\n");
    // for (int i = 0; i < MAX_PELICULAS; i++)
    // {
    //     printf("Id:\tDia:\tViews:\tPuntuacion:\tTotal Views:");
    //     for (int dia_ = 0; dia_ < DIAS; dia_++)
    //     {
    //         printf("\n%d\t%d\t%d\t%.2f\t",ListaPeliculas[i].ID,dia_+1,ListaPeliculas[i].Views_dia[dia_],ListaPeliculas[i].Punt_dia[dia_]);  
    //     }
    //     printf("\t%.0f",ListaPeliculas[i].Views_Total);
    //     printf("\n\n");
    // }
    for (int i = 0; i < MAX_PELICULAS; i++)
    {
        printf("Id:\tTotal Views:");
        printf("\n%d",ListaPeliculas[i].ID);  
        printf("\t%.0f",ListaPeliculas[i].Views_Total);
        printf("\n\n");
    }
    // Muestra por pantalla los datos
    printf("\nID:\tViews:\t");
    for (int top10 = 0; top10 < 10; top10++)
    {
        printf("\n%d\t%.0f",Top10_id[top10],Top10_views[top10]);
    }
    printf("\n");
    return;
}
void GRABAR_TOP10(FILE *top10,float Top10_views[],int Top10_id[])
{
    // Abre el archivo como escritura
    if ((top10 = fopen("top10.txt", "w")) == NULL)    
            printf ( "Error en la apertura. Es posible que el fichero no exista \n");
    // Comienza a escribir
    fprintf(top10,"ID:\tViews:\n");
    for (int i = 0; i < TOP10; i++)
    {
        fprintf(top10,"%d\t%.0f\n",Top10_id[i],Top10_views[i]);
    }
    // Cierra el archivo top10.txt
    fclose(top10);
    return;
}
// -------------------------------------- //

// Funciones relacionadas con la opcion 2 //
// -------------------------------------- //
float VALORACION_PONDERADA(int lugar)
{
    // Variables
    int total;
    float ponderada,puntuacion;

    puntuacion = 0;
    // Recorremos la lista buscando 
    for(int i = 0; i < DIAS; i++)
    {
        puntuacion = puntuacion + ( ListaPeliculas[lugar].Views_dia[i] * 1.0 * ListaPeliculas[lugar].Punt_dia[i] );
    }
    if(ListaPeliculas[lugar].Views_Total != 0) ponderada = puntuacion / ListaPeliculas[lugar].Views_Total;
    else    return 0;
    // Suma = Views Totales
    return(ponderada);
}
// -------------------------------------- //

// Funciones relacionadas con varias opciones //
// -------------------------------------- //
void AccionesComunes(void)
{
    CargaTotalViews();
    OrdenarListaPeliculas ();

    return;
}
void CargaTotalViews(void)
{
    int dia,lista;

    //Suma el total de views de cada pelicula
    for (lista = 0;lista < MAX_PELICULAS; lista++)
    {
        for ( dia = 0; dia < DIAS; dia++)
        {
            ListaPeliculas[lista].Views_Total = ListaPeliculas[lista].Views_dia[dia] + ListaPeliculas[lista].Views_Total;
        }
    }
    return;
}
// -------------------------------------- //



