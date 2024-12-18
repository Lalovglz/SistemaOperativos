# Codigos de programas


# Política y filosofía


## Fragmentacion interna
Esta ocurre cuando la memoria se divide en secciones de tamaño montado, cuando un metodo solicita memoria, se le asigna una de las secciones, en caso de que la memoria asignada es mayor, el espacio sobrante se le demomina fragmentacion interna

![Fragmentacion interna](https://media.geeksforgeeks.org/wp-content/uploads/20190924115421/Untitled-Diagram-146.png "Ilustracion de la fragmentacion interna")

Esto afecta la memoria de las siguientes maneras:
* Uso ineficiente de memoria ya que no se aprovecha el sobrante de memoria
* Desperdicio de recurso, si muchos bloques tienen desperdicio al memoria puede llegar a requerir mas espacio para almacenar los mismo datos
* SI el sistema se sobrecarga y hay poco espacio libre, el sistema puede comenzar a hcaer intercambio con el disco, lo cual puede ser mas lento que acceder a la RAM


## Fragmentacion externa
Esta  ocurre cuando el bloque asignado al proceso, es de menor tamaño que es solicitado por el proceso y no sea contigua, nos llevaria a usar alguna estrategia de de asignacion de memoria de primer ajuste o mejor ajuste

![Fragmentacion externa](https://media.geeksforgeeks.org/wp-content/uploads/20200729172413/2581.png "Ilustracion de la fragmentacion externa")

Esto afecta la memoria de las siguientes maneras:
* Aunque haya memoria libre, puede dificultar la asignacion de bloques grandes para procesos, lo que provocaria fallos
* Se reduce la eficiencia del sistema porque tiene que realizar mas trabajo al momento de asignar memoria por el los bloques de memoria contiguos o para reorganizar la memoria
* Puede generar sobrecarga administrativa ya que provoca mas busquedas y msa trabajo por parte del sistema para gestionar la memoria


## Politicas de reemplazo de paginas en Sistemas Operativos

**LRU (Least Recently Used)**
Lo que hace es reemplaza la pagina que no se ha utilizado durante el mayor tiempo

Ventajas: Normalmente ofrece un buen rendimiento y en muy intuitva, ya que reemplaza las paginas menos utilizadas recientemente

Desventajas: Requiere un seguimiento de los accesos a las paginas, lo que es costoso en recursos como tiempo y espacio

**FIFO (First-In, First-Out)**
Reemplaza la pagina que fue cargada primero en la memoria

Ventajas: Facil de implementar y de bajo costo de recursos

Desventajas: No es tan eficiente ya que no tiene en cuenta la frecuencia que se usa la pagina y puede provocar que se eliminen mas paginas de las necesarias

**Optima (Optimal Page Replacement)**
Reemplaza la pagina que no sera utilizada durante el mayor periodo de tiempo en el futuro

Ventajas: En teoria es el algoritmo ya que minimiza el numero de fallos de la pagina

Desventajas: Es imposible implementarlo porque es necesario conocer el futuro, lo que realmente no es posible

**Clock (Algoritmo de reloj)**
Se usa en una estructura circular para seguir el acceso a las paginas, utiliza un bit de referencia para indicar si la pagina ha sido accedida recientemente

Ventajas: Es mas eficiente que la LRU en terminos de implementacion y no requiere tanto espacio, es muy util para sistemas con recursos limitados

Desventajas: No es tan preciso como LRU, ya que solo marca si una pagina ha sido utilizada recientemente

**LFU (Least Frequently Used)**
Reemplaza la pagina que ha sido utilizada menos veces

Ventajas: Es eficaz cuando hay una clara diferencia entre la frecuencia de uso de las paginas

Desventajas: Requiere mantener un contador de la frecuencia de acceso a cada pagina, lo que aumenta la sobrecarga, ademas de que puede no ser eficiente si el patron de acceso cambia con el tiempo


**Las politicas dependen de ciertas cincunstancias pero como el tiempo de carga de trabajo o los recursos disponibles en el sistem, sin embargo, a rasgos generales piendo que las opciones mas practicacs y balanceadas en termino de su eficiencia y su facilidad de implementacion son LRU y Clock, la LFU me llama la atencion pero siento que necesita ser perfeccionada**



**Particiones fijas**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PARTICIONES 100
#define MAX_PROCESOS 100

typedef struct {
    int tamano;
    int id_de_proceso; 
} Particion;

void imprime_memoria(Particion Particions[], int numero_de_particiones) {
    printf("\nEstado de la memoria:\n");
    for (int i = 0; i < numero_de_particiones; i++) {
        if (Particions[i].id_de_proceso == -1) {
            printf("Partición %d: %d KB (Libre)\n", i + 1, Particions[i].tamano);
        } else {
            printf("Partición %d: %d KB (Proceso %d)\n", i + 1, Particions[i].tamano, Particions[i].id_de_proceso);
        }
    }
    printf("\n");
}

int main() {
    int memoria_total, numero_de_particiones;
    Particion Particions[MAX_PARTICIONES];

    printf("Ingrese el tamaño total de la memoria (KB): ");
    scanf("%d", &memoria_total);

    printf("Ingrese el número de particiones: ");
    scanf("%d", &numero_de_particiones);

    if (numero_de_particiones > MAX_PARTICIONES) {
        printf("Número máximo de particiones excedido (%d).\n", MAX_PARTICIONES);
        return 1;
    }

    int tamano_total_particion = 0;
    for (int i = 0; i < numero_de_particiones; i++) {
        printf("Ingrese el tamaño de la partición %d (KB): ", i + 1);
        scanf("%d", &Particions[i].tamano);
        Particions[i].id_de_proceso = -1; 
        tamano_total_particion += Particions[i].tamano;
    }

    if (tamano_total_particion > memoria_total) {
        printf("Error: El tamaño total de las particiones excede el tamaño de la memoria.\n");
        return 1;
    }

    int op;
    do {
        printf("\n--- Menú ---\n");
        printf("1. Asignar proceso\n");
        printf("2. Liberar proceso\n");
        printf("3. Mostrar estado de la memoria\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                int id_de_proceso, tam_proceso;
                printf("Ingrese el ID del proceso: ");
                scanf("%d", &id_de_proceso);
                printf("Ingrese el tamaño del proceso (KB): ");
                scanf("%d", &tam_proceso);

                int asignado = 0;
                for (int i = 0; i < numero_de_particiones; i++) {
                    if (Particions[i].id_de_proceso == -1 && Particions[i].tamano >= tam_proceso) {
                        Particions[i].id_de_proceso = id_de_proceso;
                        asignado = 1;
                        printf("Proceso %d asignado a la partición %d.\n", id_de_proceso, i + 1);
                        break;
                    }
                }
                if (!asignado) {
                    printf("No se encontró una partición disponible para el proceso %d.\n", id_de_proceso);
                }
                break;
            }
            case 2: {
                int id_de_proceso;
                printf("Ingrese el ID del proceso a liberar: ");
                scanf("%d", &id_de_proceso);

                int libre = 0;
                for (int i = 0; i < numero_de_particiones; i++) {
                    if (Particions[i].id_de_proceso == id_de_proceso) {
                        Particions[i].id_de_proceso = -1;
                        libre = 1;
                        printf("Proceso %d liberado de la partición %d.\n", id_de_proceso, i + 1);
                        break;
                    }
                }
                if (!libre) {
                    printf("No se encontró el proceso %d en ninguna partición.\n", id_de_proceso);
                }
                break;
            }
            case 3:
                imprime_memoria(Particions, numero_de_particiones);
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (op != 4);

    return 0;
}
```


# ***Primera cabida***

1. INICIO
2. Conocer el tamaño de memoria total que se tiene
3. Conocer el numero de bloques y su tamaño establecido
4. Crear un proceso con un tamaño definido
5. Iterar los bloques para conocer si estan en uso o libres
6. Si esta libre verifica si cabe en ese bloque
7. Si cabe entra en el bloque, si no simplemente sigue buscando otro bloque
8. Si no encuentra ninguno libre o niguno del tamaño donde pueda entrar, no carga el proceso y notifica que no se pudo agregar
9. FIN


# ***ORGANIZACIÓN DE MEMORIA VIRTUAL***

### ***Paginacion***
Es una tecnica de gestion de memoria que divide la memoria fisica y la memoria virtual en bloques de tamaño fijo llamados paginas.Los procesos tambien se dividen en paginas y se asignan a marcos de memoria en memoria fisica

***Ventajas:***

* Elimina la fragmentacion externa ya que no es necesario que los bloques de memoria esten contiguos
* Permite utilizar toda la memoria disponible, incluso si los bloques son de tamaño variable
* Facilida de proteccion y aislamiento de proecesos ya que cada pagina tiene un mapeo unico en memoria fisica

***Desventajas:***

* Conlleva a fragmentacion interna ya que las paginas no se llenan completamente, por lo que se pierde espacio dentro de ellas
* Requiere tablas de paginas para hacer el mapeo de direcciones, lo que consume recursos
* La conversion de direcciones virtuales a fisicas puede ralentizar el acceso a memoria 

### ***Segmentación***
Es una tecnica de gestion de memoria que divide la memoria en segmentos logicos de tamaño variable, cada segmento puede tener un tamaño diferente segun las necesidades del proceso

***Ventajas:*** 

* Es mas natural y flexible, adaptandose a diferentes partes del programa
* Al ser segmentado, se puede gestionar de forma individual cada parte del programa
* Cada segmento puede tener permisos especificosd 

***Desventajas:***

* Pueden quedar huecos entre los segmentos debido a la asginacion variable de memoria
* El tamaño variable de los segmentos puede causar que algunas areas de memoria no se utilicen eficientemente
* Puede ser mas complicado de gestionar y asignar segmentos de tamaño variable


**Tabla de paginas**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BLOQUES 10
#define TAM_BLOQUES 4
#define TAM_MEMORIA 40

typedef struct {
    int id;
    int tamano;
    int idProceso;
    int estado;
} Pagina;

typedef struct {
    int id;
    int tamano;
    int idPagina;
    int estado;
} Marco;

typedef struct {
    int id;
    int idPaginas[MAX_BLOQUES];
    int tamano;
} Proceso;

int main() {
    Pagina Paginas[MAX_BLOQUES];
    Marco Marcos[MAX_BLOQUES];
    Proceso Procesos[MAX_BLOQUES];
    for(int i=0;i<MAX_BLOQUES;i++){
        Paginas[i].id=i;
        Marcos[i].id=i;
        Paginas[i].estado=0;
        Marcos[i].estado=0;
        Paginas[i].tamano=4;
        Marcos[i].tamano=4;
        
        for(int x=0;x<MAX_BLOQUES;x++){
            Procesos[i].idPaginas[x]=-1;
        }
    }

    printf("\nCuenta con un tamano total de la memoria de %d (B) ",TAM_MEMORIA);
    printf("\nCon un total de 10 paginas y consigo 10 marcos de 4 B ");

    int op,noProceso=0;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Nuevo proceso\n");
        printf("2. Mostrar estado de la memoria\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                int tam_proceso;
                printf("Ingrese el tamano del proceso (B): ");
                scanf("%d", &tam_proceso);
                int asignado = 0;
                for (int i = 0; i < MAX_BLOQUES; i++) {
                        int paginas=0;
                    if (Paginas[i].estado == 0 && Paginas[i].tamano >= tam_proceso) {
                        Paginas[i].estado=1;
                        Marcos[i].estado=1;
                        Paginas[i].idProceso = noProceso;
                        Marcos[i].idPagina=i;
                        Procesos[noProceso].idPaginas[paginas]=Paginas[i].id;
                        
                        printf("Proceso %d asignado a la pagina %d en el marco %d.\n", noProceso, i, i);
                        noProceso++;
                        asignado = 1;
                        break;
                    }

                    if(Paginas[i].estado == 0 && Paginas[i].tamano<tam_proceso ){
                        int tamRes=tam_proceso-4;
                        Paginas[i].estado=1;
                        Marcos[i].estado=1;
                        Paginas[i].idProceso=noProceso;
                        Marcos[i].idPagina=i;
                        Procesos[noProceso].idPaginas[paginas]=Paginas[i].id;
                        paginas++;
                        for(int a=i+1;a<MAX_BLOQUES;a++){
                            
                            if(Paginas[a].tamano<tamRes){
                                Paginas[a].estado=1;
                                Marcos[a].estado=1;
                                Paginas[a].idProceso=noProceso;
                                Marcos[a].idPagina=a;
                                Procesos[noProceso].idPaginas[paginas]=Paginas[a].id;
                                paginas++;
                                
                            }
                            else{
                                Paginas[a].estado=1;
                                Marcos[a].estado=1;
                                Paginas[a].idProceso=noProceso;
                                Marcos[a].idPagina=a;
                                Procesos[noProceso].idPaginas[paginas]=Paginas[a].id;
                               paginas++;
                                printf("\nProceso %d, asignado en: \n",noProceso);
                                for(int t=0;t<paginas;t++){
                                    if(Procesos[noProceso].idPaginas[t] != -1){
                                        int p=Procesos[noProceso].idPaginas[t];
                                        printf("La pagina %d en el marco %d.\n", p, p);
                                    }                               
                                } 
                                noProceso++;
                                asignado=1;
                                break;
                            }
                            tamRes=tamRes-4;
                        }
                        break;
                    }
                }
                if (asignado==0) {
                    printf("No se encontro una particion disponible para el proceso %d.\n", noProceso);
                }
                break;
            }
            case 2:
                for(int i=0;i<MAX_BLOQUES;i++){
                    if(Procesos[i].idPaginas[0] != -1){
                    printf("\nEl proceso %d, esta en la(s) pagina(s):",i);
                    for(int x=0;x<MAX_BLOQUES;x++){
                        if(Procesos[i].idPaginas[x] != -1){
                        int p=Procesos[i].idPaginas[x];
                        printf(" Pagina %d--marco %d. ",p,p);
                        }
                    }
                    }
                }
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (op != 4);

    return 0;
}
```




**LRU**

```c
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>

    #define MAX_PROCESOS 100
    #define MAX_BLOQUES 10
    #define TAM_BLOQUES 4
    #define TAM_MEMORIA 40

    typedef struct {
        int id;
        int tamano;
        int idProceso;
        int estado;
    } Pagina;

    typedef struct {
        int id;
        int tamano;
        int idPagina;
        int estado;
    } Marco;

    typedef struct {
        int id;
        int idPaginas[MAX_BLOQUES];
        int tamano;
        int contador;
    } Proceso;

    int main() {
        Pagina Paginas[MAX_BLOQUES];
        Marco Marcos[MAX_BLOQUES];
        Proceso Procesos[MAX_PROCESOS];
        
        for (int i = 0; i < MAX_BLOQUES; i++) {
            Paginas[i].id = i;
            Marcos[i].id = i;
            Paginas[i].estado = 0;
            Marcos[i].estado = 0;
            Paginas[i].tamano = 4;
            Marcos[i].tamano = 4;
            
            for (int x = 0; x < MAX_BLOQUES; x++) {
                Procesos[i].idPaginas[x] = -1;
            }
        }
        
        for (int i = 0; i < MAX_PROCESOS; i++) {
            Procesos[i].contador = 0;
            Procesos[i].id = -1;
        }

        printf("\nCuenta con un tamano total de la memoria de %d (B) ", TAM_MEMORIA);
        printf("\nCon un total de 10 paginas y consigo 10 marcos de 4 B ");

        int op, noProceso = 0;
        do {
            printf("\n--- Menu ---\n");
            printf("1. Nuevo proceso\n");
            printf("2. Mostrar estado de la memoria\n");
            printf("3. Acceder a proceso\n");
            printf("4. Liberar proceso por LRU\n");
            printf("5. Salir\n");
            printf("Seleccione una opcion: ");
            scanf("%d", &op);

            switch (op) {
                case 1: {
                    int tam_proceso;
                    printf("Ingrese el tamano del proceso (B): ");
                    scanf("%d", &tam_proceso);
                    int asignado = 0;
                    for (int i = 0; i < MAX_BLOQUES; i++) {
                        int paginas = 0;

                        if (Paginas[i].estado == 0 && Paginas[i].tamano >= tam_proceso) {
                            Paginas[i].estado = 1;
                            Marcos[i].estado = 1;
                            Paginas[i].idProceso = noProceso;
                            Marcos[i].idPagina = i;
                            Procesos[noProceso].idPaginas[paginas] = Paginas[i].id;
                            Procesos[noProceso].contador = 0;
                            Procesos[noProceso].id = noProceso;
                            printf("Proceso %d asignado a la pagina %d en el marco %d.\n", Procesos[noProceso].id, i, i);
                            noProceso++;
                            asignado = 1;
                            break;
                        }

                        if (Paginas[i].estado == 0 && Paginas[i].tamano < tam_proceso) {
                            int tamRes = tam_proceso - 4;
                            Paginas[i].estado = 1;
                            Marcos[i].estado = 1;
                            Paginas[i].idProceso = noProceso;
                            Marcos[i].idPagina = i;
                            Procesos[noProceso].idPaginas[paginas] = Paginas[i].id;
                            paginas++;

                            for (int a = i + 1; a < MAX_BLOQUES; a++) {
                                if (Paginas[a].tamano <= tamRes) {
                                    Paginas[a].estado = 1;
                                    Marcos[a].estado = 1;
                                    Paginas[a].idProceso = noProceso;
                                    Marcos[a].idPagina = a;
                                    Procesos[noProceso].idPaginas[paginas] = Paginas[a].id;
                                    paginas++;
                                } else {
                                    Paginas[a].estado = 1;
                                    Marcos[a].estado = 1;
                                    Paginas[a].idProceso = noProceso;
                                    Marcos[a].idPagina = a;
                                    Procesos[noProceso].idPaginas[paginas] = Paginas[a].id;
                                    Procesos[noProceso].contador = 0;
                                    paginas++;
                                    Procesos[noProceso].id = noProceso;
                                    printf("\nProceso %d, asignado en: \n", Procesos[noProceso].id);
                                    for (int t = 0; t < paginas; t++) {
                                        if (Procesos[noProceso].idPaginas[t] != -1) {
                                            int p = Procesos[noProceso].idPaginas[t];
                                            printf("La pagina %d en el marco %d.\n", p, p);
                                        }
                                    }
                                    noProceso++;
                                    asignado = 1;
                                    break;
                                }
                                tamRes = tamRes - 4;
                            }
                            break;
                        }
                    }

                    if (asignado == 0) {
                        printf("No se encontro una particion disponible para el proceso %d.\n", noProceso);
                    }
                    break;
                }

                case 2:
                    for (int i = 0; i < MAX_PROCESOS; i++) {
                        if (Procesos[i].id != -1) {
                            printf("\n(%d)Proceso %d esta en las siguientes paginas: ",Procesos[i].contador, Procesos[i].id);
                            for (int x = 0; x < MAX_BLOQUES; x++) {
                                if (Procesos[i].idPaginas[x] != -1) {
                                    int p = Procesos[i].idPaginas[x];
                                    printf("Pagina %d--marco %d. ", p, p);
                                }
                            }
                        }
                    }
                    break;

                case 3:
                    {
                        int idAcceso = -1, accedido = 0;
                        printf("\nIngrese el ID del proceso al que desea acceder: ");
                        scanf("%d", &idAcceso);

                        printf("Accediendo al proceso con el id %d...\n", idAcceso);
                        for (int i = 0; i < MAX_PROCESOS; i++) {
                            if (Procesos[i].id == idAcceso) {
                                Procesos[i].contador = 0; 
                                accedido = 1;
                            } else {
                                Procesos[i].contador++; 
                            }
                        }

                        if (accedido == 0) {
                            printf("El proceso solicitado no se encuentra\n");
                        }
                    }
                    break;

                case 4: {
                        int idEliminar = -1;
                        int mayorContador = -1; 

                            for (int i = 0; i < MAX_PROCESOS; i++) {
                                if (Procesos[i].id != -1) { 
                                    if (Procesos[i].contador > mayorContador) { 
                                        mayorContador = Procesos[i].contador; 
                                        idEliminar = Procesos[i].id; 
                                    }
                                }
                            }

                            if (idEliminar != -1) {
                                for (int i = 0; i < MAX_PROCESOS; i++) {
                                    if (Procesos[i].id == idEliminar) {
                                        for (int a = 0; a < MAX_BLOQUES; a++) {
                                            if (Procesos[i].idPaginas[a] != -1) { 
                                                int idPagina = Procesos[i].idPaginas[a];
                                                Paginas[idPagina].estado = 0;
                                                Paginas[idPagina].idProceso = -1;
                                                Marcos[idPagina].estado = 0;
                                                Marcos[idPagina].idPagina = -1;
                                                Procesos[i].idPaginas[a] = -1; 
                                            }
                                        }
        
                                        Procesos[i].id = -1;
                                        Procesos[i].contador = 0;
                                        printf("Se libero el proceso %d.\n", idEliminar);
                                        break; 
                                    }
                                }
                            } else {
                                printf("No hay procesos para liberar.\n");
                            }
                            break;
                        }
                case 5:
                    printf("Saliendo del programa.\n");
                    break;

                default:
                    printf("Opcion no valida.\n");
            }
        } while (op != 5);

        return 0;
    }

```


# Proceso de traducción de direcciones virtuales a físicas en un sistema con memoria virtual

![Diagrama](imagenes/Captura%20de%20pantalla%202024-12-02%20210104.png "Diagrama de proceso")



# **Windows y su administracion de memoria virtual**

En de manera general la administracion de memoria virtual lo que hace es simular que el sistema tiene mas almacenamiento, logra esto pasando ciertos procesos de menor prioridad, los procesos se almacenan en bloques llamados paginas, de un tamaño comunmente de 4 KB.

Las paginas son cargadas en la RAM segun sus necesidades, si la RAM se llena las paginas menos usadas se guardan temporalmente en un archivo de paginacion(pagefile), es un archivo que se ubica en el disco duro, el sistema decide cuanto espacio usar.

Windows utiliza dos tipos de asignaciones 
* Memoria virtual privada. Especificamente para una aplicacion
* Memoria compartida. Para varias aplicaciones

Para traducir las direcciones windows usa la unidad de administracion de memoria (MMU), para traducir las direcciones vrituales en direcciones fisicas, lo cual se hace mediante tablas de paginas administradas por el sistema operativo.

Cuando la memoria fisica se llena, mueve las paginas menos utilizadas al archivo de paginacion, cuando una pagina almacenada en el disco vuelve a ser necesaria, se carga nuevamente en la ram, esto se le conoce como **swapping**.

Windows administra la memoria virtual con base en prioridades de procesos o aplicaciones, los procesos criticos del sistema tienen una mayor prioridad para usar la RAM


**SWAPPING**

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_BLOQUES 5
#define TAM_BLOQUES 4
#define TAM_MEMORIA 20

typedef struct {
    int id;
    int tamano;
    int idProceso;
    int estado;
} Pagina;

typedef struct {
    int id;
    int tamano;
    int idPagina;
    int estado;
} Marco;

typedef struct {
    int id;
    int idPagina;
    int tamano;
    int estado;
} Proceso;

int main() {
    Pagina Paginas[MAX_BLOQUES];
    Pagina PaginasSec[MAX_BLOQUES];
    Marco Marcos[MAX_BLOQUES];
    Marco MarcosSec[MAX_BLOQUES];
    Proceso Procesos[50];
    for(int i=0;i<MAX_BLOQUES;i++){
        Paginas[i].id=i;
        Marcos[i].id=i;
        Paginas[i].estado=0;
        Marcos[i].estado=0;
        Paginas[i].tamano=4;
        Marcos[i].tamano=4;

        PaginasSec[i].id=i;
        MarcosSec[i].id=i;
        PaginasSec[i].estado=0;
        MarcosSec[i].estado=0;
        PaginasSec[i].tamano=4;
        MarcosSec[i].tamano=4;
    }

    printf("\nCuenta con un tamano total de la memoria de %d (B) ",TAM_MEMORIA);
    printf("\nCon un total de 5 paginas y consigo 5 marcos de 4 B ");

    int op,noProceso=0,ocupadas=0;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Nuevo proceso\n");
        printf("2. Mostrar procesos\n");
        printf("3. Terminar proceso\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);

        switch (op) {
            case 1: {
                int tam_proceso;
                printf("Ingrese el tamano del proceso (B): ");
                scanf("%d", &tam_proceso);
                int asignado = 0;

                if(ocupadas==5){
                        
                            int temp=100,aa,ocuSec=0;
                            for(int a=0;a<MAX_BLOQUES;a++){
                                    if(Paginas[a].estado==1){
                                        if(temp>Paginas[a].idProceso && Paginas[a].idProceso != -1){    
                                        temp=Paginas[a].idProceso;
                                        aa=a;
                                        }
                                    }
                            }
                            printf("\nEl mas viejo es %d",temp);
                            printf("\nAsignara el id %d",noProceso);
                                        
                            for(int b=0;b<MAX_BLOQUES;b++){
                                if(PaginasSec[b].estado==0){
                                    Procesos[noProceso].idPagina=Paginas[aa].id;
                                    Paginas[aa].idProceso=noProceso;
                                    noProceso++;
                                    asignado=1;
                                    Procesos[temp].idPagina=PaginasSec[b].id;
                                    PaginasSec[b].estado=1;
                                    MarcosSec[b].estado=1;
                                    PaginasSec[b].idProceso = temp;
                                    MarcosSec[b].idPagina=b;
                                    break;
                                }else{
                                    ocuSec++;
                                }
                            } 
                            if(ocuSec==5)printf("No se asigno el proceso, no hay espacio");
                    
                    }

                for (int i = 0; i < MAX_BLOQUES; i++) {
                    if (Paginas[i].estado == 0 && Paginas[i].tamano >= tam_proceso) {
                        Paginas[i].estado=1;
                        Marcos[i].estado=1;
                        Paginas[i].idProceso = noProceso;
                        Marcos[i].idPagina=i;
                        Procesos[noProceso].idPagina=Paginas[i].id;
                        
                        printf("Proceso %d asignado a la pagina %d en el marco %d.\n", noProceso, i, i);
                        noProceso++;
                        asignado = 1;
                        ocupadas++;
                        
                        printf("\nOcupadas %d",ocupadas);
                        break;
                    }
                    
                }
                

                
                if (asignado==0) {
                    printf("No se encontro una particion disponible para el proceso %d.\n", noProceso);
                }
                break;
            }
            case 2:
                {
                printf("RAM");
                for(int i=0;i<MAX_BLOQUES;i++){
                    if(Paginas[i].estado == 1){
                    printf("\nEl proceso %d, esta en la pagina principal: %d",Paginas[i].idProceso,Paginas[i].id);
                    //int sec=0;
                    }
                }
                printf("\nALMACENAMIENTO SECUNDARIO");
                    for(int a=0;a<MAX_BLOQUES;a++){
                        if(PaginasSec[a].estado==1){
                        printf("\nProceso %d, en la pagina secundario No. %d",PaginasSec[a].idProceso,PaginasSec[a].id);
                        }
                    }
                break;
                }
            case 3:
               {
                int temp=100,tempSec=100,ocuSec=0,ocu=0,idLiberar = -1,idLiberarSec = -1;
                            for(int a=0;a<MAX_BLOQUES;a++){
                                //printf("ID: %d",Procesos[a].id);
                                    if(Paginas[a].estado==1){
                                        if(temp>Paginas[a].idProceso && Paginas[a].idProceso != -1){    
                                        temp=Paginas[a].idProceso;
                                        idLiberar=a;
                                        
                                        }
                                        ocu++;
                                    }
                            }
                            for(int a=0;a<MAX_BLOQUES;a++){
                                //printf("ID: %d",Procesos[a].id);
                                    if(PaginasSec[a].estado==1){
                                        if(tempSec>PaginasSec[a].idProceso && PaginasSec[a].idProceso != -1){    
                                        tempSec=PaginasSec[a].idProceso;
                                        idLiberarSec=a;
                                        
                                        }
                                        ocuSec++;
                                    }
                            }
                            printf("El mas viejo principal es %d\n",temp);
                            printf("El mas viejo secundario es %d\n",tempSec);
                            if(ocuSec == 0){
                                printf("ninguna secundaria ocupada\n");
                                Paginas[idLiberar].estado = 0;
                                ocupadas--;
                            }else{
                                Paginas[idLiberar].idProceso=noProceso;
                                noProceso++;
                                PaginasSec[idLiberarSec].estado=0;
                            }
                            if(ocu==0)printf("No hay procesos para liberar");

                break;
               }
            case 4:
             printf("Saliendo del programa.\n");
            break;
            default:
                printf("Opción no válida.\n");
        }
    } while (op != 4);

    return 0;
}
```


# Controladores de dispositivos


### Bloque

Estos se utilizan para interactuar con dispositivos de almacenamiento que manejan datos en bloques, tales como discos duros, discos solidos y unidades de estado solido, estos controladores, manejan la lectura y escritura de bloques de datos en el dispositivo. 

**Caracteristicas**

* Manejan datos en bloques
* Utilizan un sistem de direcciones de bloques para acceder a los datos
* Puede realizar operaciones de lectura y escritura en bloques 

### Caracter

Se utilizan para interactuar con dispositivos de entrada/salida con datos en forma de caracteres, como teclados, impresoras y terminales. Manejan la lectura y escritura de caracteres en el dispositivo.

**Caracteristicas**

- Manejan datos en forma de caracteres
- Utilizan un sistema de direcciones de caracteres para acceder a los datos
- Pueden realizar operaciones de lectura y escritura de caracteres


**Manejador de dispositivos**


```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ocupado true
#define libre false

bool estado = libre; 
bool terminado = false;  
char datos[1000];     
char buffer[1000];

void leerUSB() {
    while (estado == ocupado) {
        printf("USB ocupada, esperando...\n");
    }
    
    terminado = false;  
    estado = ocupado;  
    printf("Leyendo datos de la USB...\n%s",datos);
    terminado = true;  
    strcpy(buffer, datos);
    printf("Contenido de la USB: %s\n",buffer);
    estado = libre;  
}

void escribirUSB() {
    while (estado == ocupado) {
        printf("USB ocupada, esperando...\n");
    }
    terminado = false;  
    estado = ocupado;  
    printf("Escribiendo datos en la USB... \n");
    strcat(datos, buffer);

    terminado = true;  
    estado = libre;  
}

int main() {
   
    printf("\nINSERTANDO USB\nCONEXION ESTABLECIDA");
    int op=0;
    do{
        printf("\n1. Leer datos de USB");
        printf("\n2. Aniadir datos");
        printf("\n3. Salir");
        printf("\nEliga un opcion: ");
        scanf("%d",&op);

        switch(op){

        case 1:
            leerUSB();
        break;

        case 2:
        {
            char dato[50];
            printf("\nEscriba lo que desea aniadir a la USB: ");
            scanf("%49s",&dato);
            strcpy(buffer,dato);
            escribirUSB();
        }
        break;

        case 3:
        printf("Desconectando USB...");
        break;
        
        default:
        printf("\nIngrese una opcion valida...");

        }
    }while(op != 3);

    return 0;
}

```


# Interrupciones por E/S

Es un mecanismo que permite a los dispositivos perifericos como teclados, impresonas o discos, comunicarse con el procesador de manera eficiente. Cuando un dispositivo necesita atencion del procesador, envia una señal de interrupcion, deteniendo el flujo de la ejecucion del procesador para atender la solicitud.

El sistema operativo administra las interrupciones por E/S, generando una interrupcion, un dispositivo genera un señal de interrupcion al controlador de interrupciones del sistema, el controlador de interrupciones envia la señal al procesador y este guarda el estado actual de ejecucion y transfiere el control al manejador de interrupciones, el manejador identifica el dispositivo que genero la interrupcion y ejecuta las acciones necesarias, como leer datos o enviar datos de respuesta, una vez atendida la ejecucion el sistema operativo restaura el estado previo del procesador y continua con la ejecucion normal

**Principales ventajas de usar interrupciones por E/S**

* Eficiencia. Evitando que el procesador este continuamente consultando si un dispositivo necesita atencion
* Prioridad. Permite gestionar tareas urgentes sin demorar otros procesos

1. INICIO
2. Configurar variables y la cola de E/S
3. Enivar la solicitud de E/S al sistema operativo
4. Guarda la solicitud en la cola correspondiente
5. El controlador del dispositivo comienza a ejecutar la operacion, mientras que el procesador continua ejecutando otras tareas
6. Cuando termina su tarea envia la señal de interrupcion
7. El procesador detiene la tares que estaba ejecutando, mientras que el controlador de interrupciones del sistema operativo toma el control
8. El sistema identifica el dispositivo que genero la interrupcion y ejecuta el codigo necesario para procesar la solicitud de E/S
9. Extrae los datos necesarios y/o confirma que la operacion finalizo
10. Una vez procesada, se elimina la solicitud de la cola
11. El procesador continua con la tara que habia pausado antes de la interrupcion
12. FIN



**Manejo de interrupciones**

```c
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ocupado true
#define libre false

bool estadoUSB = libre; 
bool terminado = false;  
char datos[1000] = "";     
char buffer[1000] = "";

typedef struct {
    int id;
    char nombre[50];
    int idFunciones[5];
    int estado;
} Dispositivo;

typedef struct {
    int id;
    char nombre[50];
} Funcion;

void leerUSB() {
    while (estadoUSB == ocupado) {
        printf("USB ocupada, esperando...\n");
    }
    
    terminado = false;  
    estadoUSB = ocupado;  
    printf("Leyendo datos de la USB...\n");
    terminado = true;  
    strcpy(buffer, datos);
    printf("Contenido de la USB: %s\n", buffer);
    estadoUSB = libre;  
}

void escribirUSB() {
    while (estadoUSB == ocupado) {
        printf("USB ocupada, esperando...\n");
    }
    char dato[50];
    printf("Ingrese lo que desea anadir a la USB: ");
    scanf("%s", dato);

    strcpy(buffer, dato);

    terminado = false;  
    estadoUSB = ocupado;  
    printf("Escribiendo datos en la USB... \n");
    strcat(datos, buffer);

    terminado = true;  
    estadoUSB = libre;  
}

int main() {
    
    Funcion funcion1 = {1, "leer"};
    Funcion funcion2 = {2, "escribir"};
    Funcion funcion3 = {3, "proyectar"};

    
    Dispositivo dispositivo1 = {1, "USB", {funcion1.id, funcion2.id}, 0};
    Dispositivo dispositivo2 = {2, "Proyector", {funcion3.id}, 0};

    int opc = 0;
    do {
        printf("\nDispositivo: %s, ID (%i)", dispositivo1.nombre, dispositivo1.id);
        printf("\nDispositivo: %s, ID (%i)", dispositivo2.nombre, dispositivo2.id);
        printf("\n0. Salir del sistema");
        printf("\nElija el ID de un dispositivo: ");
        scanf("%d", &opc);

        if (opc == 1) {
            if (dispositivo2.estado == 1) {
                printf("\nEl dispositivo: %s, ha sido interrumpido", dispositivo2.nombre);
                dispositivo2.estado = 2;
                dispositivo1.estado = 1;

                int op = 0;
                do {
                    printf("\nFuncion 1: %s", funcion1.nombre);
                    printf("\nFuncion 2: %s", funcion2.nombre);
                    printf("\n0. Salir\nElija la funcion que desea realizar: ");
                    scanf("%d", &op);

                    if (op == 1) {
                        leerUSB();
                    } else if (op == 2) {
                        escribirUSB();
                        printf("\nSe han anadido los datos.");
                    } else if (op == 0) {
                        dispositivo1.estado = 0;
                        printf("\nEl dispositivo: %s, esta siendo ejecutado nuevamente", dispositivo2.nombre);
                        dispositivo2.estado = 1;
                    }

                } while (op != 0);
            } else {
                int op = 0;
                do {
                    printf("\nFuncion 1: %s", funcion1.nombre);
                    printf("\nFuncion 2: %s", funcion2.nombre);
                    printf("\n0. Salir\nElija la funcion que desea realizar: ");
                    scanf("%d", &op);

                    if (op == 1) {
                        leerUSB();
                    } else if (op == 2) {
                        escribirUSB();
                        printf("\nSe han anadido los datos.");
                    } else if (op == 0) {
                        printf("Saliendo del dispositivo...");
                    }

                } while (op != 0);
            }
        } else if (opc == 2) {
            int op = 0;
            do {
                printf("\nFuncion 1: %s", funcion3.nombre);
                printf("\n2. Dejar de %s", funcion3.nombre);
                printf("\n0. Salir\nElija la funcion que desea realizar: ");
                scanf("%d", &op);

                if (op == 1) {
                    printf("El dispositivo: %s, esta ejecutando la funcion: %s", dispositivo2.nombre, funcion3.nombre);
                    dispositivo2.estado = 1;
                    op = 0;
                } else if (op == 2) {
                    printf("Se detuvo la funcion: %s", funcion3.nombre);
                    dispositivo2.estado = 0;
                    op = 0;
                } else if (op == 0) {
                    printf("Saliendo del dispositivo...");
                }

            } while (op != 0);
        } else if (opc == 0) {
            printf("Saliendo del sistema...");
        } else {
            printf("Opcion no valida.\n");
        }

    } while (opc != 0);

    return 0;
}
```


# Cola de E/S

Es una estructura de datos que utilizan los sistemas operativos para gestionar y organizar las solicitudes de entrada/salida de los dispositivos periféricos. Su principal función es asegurar que las operaciones de E/S se procesen de manera ordenada, eficiente y sin conflictos, especialmente cuando varios procesos o dispositivos requieren atención simultáneamente.

**Ventajas**

* Eficiencia. Evita que el procesador este continuamente consultadno si el dispositivo necesita atencion
* Prioridad. Permiten gestionar tareas urgentes sin demorar otros procesos 


**Cola con prioridad**


```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _nodo
{
    int valor;         
    int prioridad;     
    struct _nodo *siguiente;
} nodo;

nodo *genera_proceso(int prioridad)
{
    static int contador = 1;
    nodo *nuevo = (nodo *)malloc(sizeof(nodo));
    if (nuevo == NULL)
    {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevo->valor = contador++;
    nuevo->prioridad = prioridad;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertar_por_prioridad(nodo **cabeza, int prioridad)
{
    nodo *nuevoNodo = genera_proceso(prioridad);

    if (*cabeza == NULL || (*cabeza)->prioridad < nuevoNodo->prioridad)
    {
        nuevoNodo->siguiente = *cabeza;
        *cabeza = nuevoNodo;
    }
    else
    {
        nodo *temp = *cabeza;
        while (temp->siguiente != NULL && temp->siguiente->prioridad >= nuevoNodo->prioridad)
        {
            temp = temp->siguiente;
        }
        nuevoNodo->siguiente = temp->siguiente;
        temp->siguiente = nuevoNodo;
    }
}

void imprimir_lista(nodo *cabeza)
{
    nodo *temp = cabeza;
    while (temp != NULL)
    {
        printf("Proceso %d (Prioridad: %d) -> ", temp->valor, temp->prioridad);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void atender(nodo **cabeza)
{
    if (*cabeza == NULL)
    {
        printf("No hay procesos para atender.\n");
        return;
    }
    else
    {
        nodo *temp = *cabeza;

        printf("Atendiendo proceso %d (Prioridad: %d)\n", temp->valor, temp->prioridad);

        *cabeza = temp->siguiente;
        free(temp);
    }
}

int main()
{
    srand(time(NULL));
    nodo *cabeza = NULL;
    int op = 0, prioridad = 0;

    do
    {
        printf("\n1. Generar proceso con prioridad\n");
        printf("2. Atender proceso\n");
        printf("3. Mostrar lista de procesos\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Ingrese la prioridad del proceso (mayor valor = mayor prioridad): ");
            scanf("%d", &prioridad);
            insertar_por_prioridad(&cabeza, prioridad);
            break;
        case 2:
            atender(&cabeza);
            break;
        case 3:
            imprimir_lista(cabeza);
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida\n");
        }
    } while (op != 4);

    return 0;
}

```


# Manejador de dispositivos

```C
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[30];
    int estado;  
    void (*encender)(char* nombre);  
    void (*apagar)(char* nombre);    
    void (*mostrarEstado)(char* nombre); 
} Dispositivo;

void encenderDispositivo(char* nombre) {
    printf("%s: El dispositivo esta ENCENDIDO.\n", nombre);
}

void apagarDispositivo(char* nombre) {
    printf("%s: El dispositivo esta APAGADO.\n", nombre);
}

void mostrarEstadoDispositivo(char* nombre) {
    printf("%s: Mostrando el estado del dispositivo...\n", nombre);
}

void inicializarDispositivo(Dispositivo* dispositivo, const char* nombre) {
    strncpy(dispositivo->nombre, nombre, sizeof(dispositivo->nombre) - 1);
    dispositivo->estado = 0; 
    dispositivo->encender = encenderDispositivo;
    dispositivo->apagar = apagarDispositivo;
    dispositivo->mostrarEstado = mostrarEstadoDispositivo;
}

int main() {
    
    Dispositivo dispositivos[3];

    inicializarDispositivo(&dispositivos[0], "USB");
    inicializarDispositivo(&dispositivos[1], "Mouse");
    inicializarDispositivo(&dispositivos[2], "Monitor");

    printf("Operaciones sobre dispositivos:\n");

    dispositivos[0].encender(dispositivos[0].nombre);
    dispositivos[2].encender(dispositivos[2].nombre);
    dispositivos[1].encender(dispositivos[1].nombre);
    
    dispositivos[1].mostrarEstado(dispositivos[1].nombre);
    dispositivos[0].mostrarEstado(dispositivos[0].nombre);
    dispositivos[2].mostrarEstado(dispositivos[2].nombre);

    dispositivos[2].apagar(dispositivos[2].nombre);
    dispositivos[1].apagar(dispositivos[1].nombre);
    dispositivos[0].apagar(dispositivos[0].nombre);
    
    
    

    return 0;
}
```

# Flujo disco magnetico

1. Inicio

* Se inicia el proceso de lectura.

2. Solicitar acceso al archivo

* El sistema operativo recibe una solicitud de acceso al archivo.

* El sistema verifica si el archivo existe en el disco.

3. Verificación de disponibilidad

* El sistema comprueba si el disco está disponible para la lectura.

* Si el disco está ocupado (por ejemplo, en uso por otro proceso), se espera hasta que esté libre.

4. Acceder al controlador de disco

* El sistema operativo pasa la solicitud al controlador de disco.

5. Localización del archivo en el disco

* El controlador de disco busca la ubicación física del archivo en el disco magnético. Esto se realiza mediante una tabla de asignación de archivos (FAT) o un sistema de gestión de archivos similar.

6. Movimiento del cabezal de lectura/escritura

* El controlador mueve el cabezal de lectura/escritura a la pista donde se encuentra el archivo.

7. Lectura de los datos

* Una vez el cabezal está en la pista correcta, comienza la lectura de los bloques de datos desde el disco magnético.

8. Transferencia de datos al sistema

* Los datos leídos se transfieren al buffer de memoria o directamente al espacio de memoria que el proceso necesita.

9. Fin de la lectura

* Una vez que todos los datos han sido leídos, el proceso de lectura se completa.

10. Fin

# Programa disco magnetico

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISCO_LIBRE 1
#define DISCO_OCUPADO 0
#define MAX_ARCHIVOS 5
#define TAMANO_MAX_ARCHIVO 1024  // En bytes

typedef struct {
    char nombre[50];
    char datos[TAMANO_MAX_ARCHIVO];  
    int ocupado;  
} Archivo;

typedef struct {
    Archivo archivos[MAX_ARCHIVOS];
    int estado_disco;  
} Disco;

void inicializar_disco(Disco* disco) {
    disco->estado_disco = DISCO_LIBRE;
    for (int i = 0; i < MAX_ARCHIVOS; i++) {
        disco->archivos[i].ocupado = 0;
    }
}

int buscar_archivo(Disco* disco, const char* nombre) {
    for (int i = 0; i < MAX_ARCHIVOS; i++) {
        if (disco->archivos[i].ocupado && strcmp(disco->archivos[i].nombre, nombre) == 0) {
            return i;  
        }
    }
    return -1;  
}

void leer_archivo(Disco* disco, const char* nombre) {
    if (disco->estado_disco == DISCO_OCUPADO) {
        printf("El disco está ocupado, esperando...\n");
        return;
    }

    disco->estado_disco = DISCO_OCUPADO;

    int indice = buscar_archivo(disco, nombre);
    if (indice == -1) {
        printf("Archivo no encontrado en el disco.\n");
    } else {
        printf("Leyendo el archivo: %s\n", disco->archivos[indice].nombre);
        printf("Contenido del archivo: %s\n", disco->archivos[indice].datos);
    }

    disco->estado_disco = DISCO_LIBRE;
}

void crear_archivo(Disco* disco, const char* nombre, const char* contenido) {
    for (int i = 0; i < MAX_ARCHIVOS; i++) {
        if (!disco->archivos[i].ocupado) {
            strcpy(disco->archivos[i].nombre, nombre);
            strcpy(disco->archivos[i].datos, contenido);
            disco->archivos[i].ocupado = 1;
            printf("Archivo '%s' creado con exito.\n", nombre);
            return;
        }
    }
    printf("No hay espacio disponible para crear un nuevo archivo.\n");
}

int main() {
    Disco disco;
    inicializar_disco(&disco);

    crear_archivo(&disco, "documento1.txt", "Este es el contenido del documento 1.");
    crear_archivo(&disco, "documento2.txt", "Contenido del documento 2. Informacion importante.");

    leer_archivo(&disco, "documento1.txt");
    leer_archivo(&disco, "documento2.txt");
    leer_archivo(&disco, "documento_inexistente.txt");

    return 0;
}
```

# E/S asincronas con archivos

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>  

#define BUFFER_SIZE 1024 
#define FILENAME "archivo_simulado.txt"

char buffer[BUFFER_SIZE];

DWORD WINAPI write_async(LPVOID arg) {
    FILE* archivo = fopen(FILENAME, "w");  
    if (archivo == NULL) {
        perror("Error al abrir el archivo para escritura");
        return 1;
    }

    strcpy(buffer, "Hola, Esta es una simulacion de E/S asincronica en C.");
    printf("Simulando escritura asincrona... escribiendo en el archivo: %s\n", buffer);

    Sleep(2000); 

    fprintf(archivo, "%s\n", buffer);
    fclose(archivo);

    printf("Simulacion de escritura completada.\n");
    return 0;
}

DWORD WINAPI read_async(LPVOID arg) {
    FILE* archivo = fopen(FILENAME, "r");  
    if (archivo == NULL) {
        perror("Error al abrir el archivo para lectura");
        return 1;
    }

    Sleep(1000);  

    printf("Simulando lectura asincrona... leyendo desde el archivo...\n");
    fgets(buffer, BUFFER_SIZE, archivo);
    fclose(archivo);

    printf("Simulacion de lectura completada. Contenido leido: %s\n", buffer);
    return 0;
}

int main() {
    HANDLE hilo_lectura, hilo_escritura;

    hilo_escritura = CreateThread(NULL, 0, write_async, NULL, 0, NULL);
    if (hilo_escritura == NULL) {
        perror("Error al crear el hilo de escritura");
        return 1;
    }

    hilo_lectura = CreateThread(NULL, 0, read_async, NULL, 0, NULL);
    if (hilo_lectura == NULL) {
        perror("Error al crear el hilo de lectura");
        return 1;
    }

    WaitForSingleObject(hilo_escritura, INFINITE);
    WaitForSingleObject(hilo_lectura, INFINITE);

    CloseHandle(hilo_escritura);
    CloseHandle(hilo_lectura);

    return 0;
}
```

# Elevator (SCAN)

```c
#include <stdio.h>
#include <stdlib.h>

int comparar_enteros(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void algoritmo_scan(int solicitudes[], int num_solicitudes, int cabezal, int tam_disco, int direccion) {
    int movimiento_total = 0; 
    int distancia, pista_actual;
    int izquierda[num_solicitudes], derecha[num_solicitudes];
    int contador_izquierda = 0, contador_derecha = 0;

    for (int i = 0; i < num_solicitudes; i++) {
        if (solicitudes[i] < cabezal) {
            izquierda[contador_izquierda++] = solicitudes[i];
        } else {
            derecha[contador_derecha++] = solicitudes[i];
        }
    }

    qsort(izquierda, contador_izquierda, sizeof(int), comparar_enteros);
    qsort(derecha, contador_derecha, sizeof(int), comparar_enteros);

    printf("Orden de acceso a los cilindros: ");

    if (direccion == 1) {
        for (int i = 0; i < contador_derecha; i++) {
            pista_actual = derecha[i];
            printf("%d ", pista_actual);
            distancia = abs(pista_actual - cabezal);
            movimiento_total += distancia;
            cabezal = pista_actual;
        }

        if (cabezal != tam_disco - 1) {
            printf("%d ", tam_disco - 1);
            movimiento_total += abs(tam_disco - 1 - cabezal);
            cabezal = tam_disco - 1;
        }

        for (int i = contador_izquierda - 1; i >= 0; i--) {
            pista_actual = izquierda[i];
            printf("%d ", pista_actual);
            distancia = abs(pista_actual - cabezal);
            movimiento_total += distancia;
            cabezal = pista_actual;
        }
    } else {
        for (int i = contador_izquierda - 1; i >= 0; i--) {
            pista_actual = izquierda[i];
            printf("%d ", pista_actual);
            distancia = abs(pista_actual - cabezal);
            movimiento_total += distancia;
            cabezal = pista_actual;
        }

        if (cabezal != 0) {
            printf("0 ");
            movimiento_total += cabezal;
            cabezal = 0;
        }

        for (int i = 0; i < contador_derecha; i++) {
            pista_actual = derecha[i];
            printf("%d ", pista_actual);
            distancia = abs(pista_actual - cabezal);
            movimiento_total += distancia;
            cabezal = pista_actual;
        }
    }

    printf("\nMovimiento total del cabezal: %d cilindros\n", movimiento_total);
}

int main() {
    int num_solicitudes, cabezal, tam_disco, direccion;

    printf("Introduce el numero de solicitudes de cilindros: ");
    scanf("%d", &num_solicitudes);

    int solicitudes[num_solicitudes];
    printf("Introduce las solicitudes de cilindros:\n");
    for (int i = 0; i < num_solicitudes; i++) {
        scanf("%d", &solicitudes[i]);
    }

    printf("Introduce la posicion inicial del cabezal: ");
    scanf("%d", &cabezal);

    printf("Introduce el tamanio del disco (numero total de cilindros): ");
    scanf("%d", &tam_disco);

    printf("Introduce la direccion inicial (0 -> abajo, 1 -> arriba): ");
    scanf("%d", &direccion);

    algoritmo_scan(solicitudes, num_solicitudes, cabezal, tam_disco, direccion);

    return 0;
}
```

# Multiples dispositivos

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void teclado(char* buffer) {
    printf("[Teclado] Capturando datos del usuario...\n");
    strcpy(buffer, "Datos ingresados desde el teclado");
    sleep(1); 
    printf("[Teclado] Datos listos para enviar: %s\n", buffer);
}

void disco_duro(const char* input_buffer, char* disco_buffer) {
    printf("[Disco Duro] Recibiendo datos del teclado...\n");
    strcpy(disco_buffer, input_buffer);
    sleep(2); 
    printf("[Disco Duro] Datos guardados en el disco: %s\n", disco_buffer);
}

void impresora(const char* disco_buffer) {
    printf("[Impresora] Recibiendo datos del disco duro...\n");
    sleep(1);
    printf("[Impresora] Imprimiendo: %s\n", disco_buffer);
}

void flujo_interaccion() {
    printf("\n[Flujo de Interacción]:\n");
    printf("Teclado ---> Disco Duro ---> Impresora\n");
    printf("   ^_____________________________|\n");
    printf("El teclado pasa datos al disco, y la impresora los utiliza.\n\n");
}

int main() {
    char teclado_buffer[1024];   
    char disco_buffer[1024];   

    flujo_interaccion();

    teclado(teclado_buffer);

    disco_duro(teclado_buffer, disco_buffer);

    impresora(disco_buffer);

    printf("\n[Simulación completada]: Todos los dispositivos han interactuado.\n");
    return 0;
}
```

# La memoria caché en los sistemas operativos modernos


Utilizan memoria caché para optimizar las operaciones de entrada/salida (E/S). La memoria caché es un área de memoria rápida y pequeña que se utiliza para almacenar datos que se acceden con frecuencia.

1. Caché de disco: Los sistemas operativos modernos utilizan una caché de disco para almacenar datos que se leen y se escriben en el disco duro. La caché de disco se utiliza para reducir el número de accesos al disco duro.
2. Caché de archivos: Los sistemas operativos modernos también utilizan una caché de archivos para almacenar datos de archivos que se acceden con frecuencia. 
3. Caché de bloques: Utilizan una caché de bloques para almacenar datos de bloques de disco que se acceden con frecuencia.
4. Caché de dispositivos: Los sistemas operativos modernos también utilizan una caché de dispositivos para almacenar datos de dispositivos de E/S que se acceden con frecuencia. 


**Beneficios**

* Mejora del rendimiento: La memoria caché puede reducir significativamente el tiempo que se tarda en acceder a los datos de E/S.
* Reducción del tráfico de E/S: La memoria caché puede reducir el número de accesos a los dispositivos de E/S, lo que puede reducir el tráfico de E/S.
* Mejora de la eficiencia: La memoria caché puede mejorar la eficiencia del sistema al reducir el número de accesos a los dispositivos de E/S.