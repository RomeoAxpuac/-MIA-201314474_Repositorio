#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Archivo{
   char path[1024];
   int tamanio;
   char tipo;
   struct Archivo *siguiente;
};

struct Archivo *primero, *ultimo;
int numNodos;
int pos;
void inicializar();
void insertar_ultimo(char path[],int tamanio, char tipo);
void buscar(char path[]);
void eliminar(char path[]);
void visualizar();
void creacion(char archivo [], char archivo2 [],char archivo3 [],int size, char tipo);

int main()
{

    int op;
    inicializar();
    char Comando [] = "";
    char Comando2 [] = "ComandoParaCrearArchivo";
    char Comando3 [] = "";
    while(op!=4)
    {
        puts("\nPara salir Ingrese Salir");
        scanf("%s",&Comando);
        printf(Comando);
        puts("Ingrese Su comando:");
        scanf("%d", &op);
        char x [] = "/home/romoeoaxpuac/Escritorio/Carpeta1/Carpeta2/Discoxxxx.dsk";
        //strcpy(Comando,x);
        int size = 24; // Tamaño del archivo
        char tipo = 'c';

        switch(op)
        {
            case 1: puts("");
                //verificando el metodo de creacion
                ///////////////////////////////////////
                ///////////////////////////////////////
                //////////////////////////////////////
                // primero se tiene que tener el nombre del disco XD
                 //puts(Comando);
                char archivo[]= "/home/romoeoaxpuac/Escritorio/Caperucita/SoyLaMeraTos/Control/Discoxxxx.dsk";
                //puts(Comando);
                char archivo2[] = "/home/romoeoaxpuac/Escritorio/Caperucita/SoyLaMeraTos/Control/Discoxxxx.dsk";
                char archivo3[] ="/home/romoeoaxpuac/Escritorio/Caperucita/SoyLaMeraTos/Control/Discoxxxx.dsk";
                strcpy(archivo,Comando);
                strcpy(archivo2,Comando);
                strcpy(archivo3,Comando);
                //strcpy(archivo2,Comando2);
                //strcpy(archivo3,Comando3);
             //   puts("el archivo");
             //   puts(archivo);
             //   puts(archivo2);
             //   puts(archivo3);
             //   puts("---");
                char comando [1024] = "";



                if (tipo == 'K' || tipo == 'k'){
                    size = size * 1000;
                }
                if (tipo == 'M' || tipo == 'm' || tipo == 'c'){
                    size = size * 1000000;
                }

                if(size >0 && size >= 10000000){

                    char separador[] = "\/";
                    char h [] = "";
                    char * trozo;
                    int valor = 0;
                    trozo = strtok( archivo, separador);

                    while( trozo != NULL ) {
                        strcpy(h,trozo);
                        //printf(h);
                        //printf( "Trozo : %s \n", trozo);//<- buscando .dsk
                        trozo = strtok( NULL, separador);
                    }
                    //verificamos si el archivo tiene la extension devida
                    if ( (strstr(h,".dsk") == NULL) && (strstr(h,".DSK") == NULL) ){
                            puts("El Disco no se puede crear, el comando se encuentra en defecto");
                    }else {
                        //verificando existencia y creacion de directorios:D
                        char path [] = "";
                        char * trozo2;

                        trozo2 = strtok(archivo3,"/");

                        while(trozo2 != NULL){
                            DIR * directorio;
                            struct dirent * vacio;
                            char *x = path;
                            directorio = opendir(x);
                            if(directorio){
                                    //puts("hola");
                                closedir(directorio);
                            }else if(path != "" && strlen(path)>0){
                                char *x = "mkdir ";
                                char *y = path;
                                //puts("VAmos Bien");
                                //strcat(comando,"");
                                //strcat(comando,"mkdir ");
                                //printf(x);
                                //printf(y);
                                //puts(path);
                                strcpy(comando,"");
                                strcat(comando,x);
                                strcat(comando,y);
                                //printf(comando);
                                //printf("\n");
                                //system(comando);
                                system(comando);

                            }

                            strcat(path,"/");
                            strcat(path,trozo2);
                            trozo2 = strtok(NULL,"/");
                        }


                    //CREAMOS EL OBJETO DE ARCHIVOS Y VEMOS SI NO HA SIDO CREADO CON anterioridad
                    FILE *fpx = fopen(archivo2,"r");
                    if( fpx != NULL) {
                        printf("Error, El Disco Ya Existe");
                        fclose(fpx);
                    }
                //si el archivo no existe pos lo creamos
                    else {
                        FILE *fpx2 = fopen(archivo2,"wb+");
                        int a= 0;
                        for(a;a<size;a++){
                            fputs( " ", fpx2 );
                        }
                        fclose((fpx2));
                        insertar_ultimo(archivo2,size,tipo);
                        printf("Disco Creado Con Exito");
                    }
            }
            ///////////////////////////////////////
            ///////////////////////////////////////
            //////////////////////////////////////
        }
        else {
            printf("El tamaño del archivo es incorrecto");
        }
        break;
        case 2:
            if(remove(Comando)==0) // Eliminamos el archivo
                printf("El archivo fue eliminado satisfactoriamente\n");
            else
                printf("No se pudo eliminar el archivo\n");

        break;

        case 3:
            puts("");
            FILE *fpx = fopen(Comando,"r");
                    if( fpx != NULL) {
                        printf("El Archivo si Existe");
                        fclose(fpx);
                    }
                //si el archivo no existe pos lo creamos
                    else {
                        puts("No se puede Realizar la Partición ya que el Archivo No Existe");
                    }
        break;
        case 5:
            visualizar();
        break;
        case 6:
            buscar(Comando);

        break;
            case 4: break;
        }
    }



//system("mkdir /home/romoeoaxpuac/Escritorio/RebecaCaradeTortuca");
FILE *fp;

 	char cadena[] = "/home/romoeoaxpuac/Escritorio/SoyLaTos.dsk";

 	fp = fopen ("/home/romoeoaxpuac/Escritorio/Disco2.dsk","wb+");

 	int a= 0;
 	for(a;a<100;a++){
 	fputs( " ", fp );
    }
 	fclose ( fp );
 	////


        printf("\nHola mundo");
        printf("\n");

        return 0;
}


void creacion(char archivo [], char archivo2 [],char archivo3 [],int size, char tipo){ // Tamaño del archivo

if (tipo == 'K' || tipo == 'k'){
    size = size * 1000;
}
if (tipo == 'M' || tipo == 'm' || tipo == 'c'){
    size = size * 1000000;
}
char archivito1 [] = "";
strcpy(archivito1,archivo);
puts(archivito1);
if(size >0 && size >= 10000000){
            // comprobando si tiene extensión dsk
        char separador[] = "/";
        char h [] = "";
        char  * trozo;
        int valor = 0;
        trozo = strtok( archivito1, "/");





            //CREAMOS EL OBJETO DE ARCHIVOS Y VEMOS SI NO HA SIDO CREADO CON anterioridad
            FILE *fpx = fopen(archivo2,"r");
                if( fpx != NULL) {
                    printf("Error, El Disco Ya Existe");
                    fclose(fpx);
                }
                //si el archivo no existe pos lo creamos
                else {
                    FILE *fpx2 = fopen(archivo2,"wb+");
                        int a= 0;
                        for(a;a<size;a++){
                            fputs( " ", fpx2 );
                        }
                    fclose((fpx2));
                    printf("Disco Creado Con Exito");
                }

///////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////
}
else {
    printf("El tamaño del archivo es incorrecto");

}

}

void inicializar(){
      primero=NULL;
      ultimo=NULL;
}
void insertar_ultimo(char path[],int tamanio, char tipo){
    struct Archivo *nuevo;
    nuevo=( struct Archivo*)malloc(sizeof(struct Archivo));
    if(nuevo==NULL)

         printf("\n MEMORIA INSUFICIENTE\n");

     else
     {
        strcpy(nuevo->path,path);
        nuevo->tamanio = tamanio;
        nuevo->tipo = tipo;
        nuevo->siguiente=NULL;
         if(primero==NULL)
           {
            primero=nuevo;

            ultimo=nuevo;

         }else{

           ultimo->siguiente=nuevo;

           ultimo=nuevo;
              }
       }
       numNodos++;

    }


void visualizar(){

struct Archivo *aux;

     pos=0;

     aux=primero;

     while(pos<numNodos)
       {
          printf(" %d.- ", pos+1);

          printf(" %s\n", aux->path);

          aux= aux->siguiente;

          pos++;
       }

    if(numNodos==0)
       printf("\n LISTA VACIA");
}

  void buscar(char path [] )
   {

     struct Archivo *aux;
     pos=0;
     aux=primero;
     while(pos<numNodos)
       {
          printf(" %d.- ", pos+1);
          printf(" %s\n", aux->path);
          if(strcmp(path, aux->path)==0)
                    {
                      printf("\n %s EXISTE", aux );
                      //v = 1;
                   }

          aux= aux->siguiente;
          pos++;
       }

    if(numNodos==0)
       printf("\n LISTA VACIA");


}



