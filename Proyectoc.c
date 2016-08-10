#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>



struct Particion{
    char path[1024];
    char unit ;
    long int size;
    char TDP;
    char ajuste[1024];
    char nombre[1024];
    struct Particion*siguiente;
};
struct Particion*primera, *ultima;
int numNodosP;
int posP;
void inicializaraParticion();
void insertarParticion(char path[], char nombre[], char tipo,char Unidad,char ajuste[],long int tamanio);
int buscarParticion(char path[],char nombre[]);
void visualizarParticiones();
int cantidadDeParticiones(char path[]);
int cantidadDeParicionesLogicas(char path[]);
int cantidadDeParticionesPrimarias(char path[]);
long int tamanioExtendida(char path[]);
void primerAjuste(char path[],char nombreParticion[],long int tamanio);
void MejorAjuste(char path[],char nombreParticion[],long int tamanio);
void PeorAjuste(char path[],char nombreParticion[],long int tamanio);
void cambiandoTamanioExtendida(char path [], long int tamanio);
long int tamanioDeParticion(char path [], char nombreParticion[]);
int VericiandoParticion(char path [], char nombreParticion[]);
int EsParticionPrimaria(char path[],char nombreParticion[]);
int EsParticionExtendida(char path[], char nombreParticion[]);
void limpiarParticion(char path[],char nombreParticion[]);
void limpiarParticionLogica(char path[], char nombreParticion[]);
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
int tamanioArchivo(char archivo[]);
void cambiarTamanioParticion(char Archivo[], char nombre[] ,long int tamanio);
long int EliminarParticion(char Archivo[],char nombre[]);
long int EliminarParticionLogica(char Archivo[], char nombre[]);
void MontandoParticion(char Archivo[], char nombre[]);

struct ParticionesMontadas{
   char path[1024];
   char nombreParticion [1024];
   char idParticion[1024];
   struct ParticionesMontadas*siguiente;
};
struct ParticionesMontadas *primeraPM, *ultimaPM;
int numNodosPM;
int posPM;
void inicializarMontada();
void insertarMontada(char path[], char nombreParticion [],char idParticion[]);
void visualizarMontadas();
int TotalDeMontadas(char path []);

int main()
{

    int op;
    char nombreParticion[1024];


    long int nuevaparticion;
    char unitparticion;
    inicializar();
    inicializaraParticion();
    inicializarMontada();
    char Comando [] = "";
    char Comando2 [] = "ComandoParaCrearArchivo";
    char Comando3 [] = "";
    char tipoParticion;
    while(op!=4)
    {

        puts("\nPara salir Ingrese Salir");
        scanf("%s",&Comando);
        printf(Comando);
        puts("\nnombre particion");
        scanf("%s",&nombreParticion);
        puts("\nIngrese el tipo de Particion");
        scanf("%s",&tipoParticion);
        puts("\nIngrese Su comando:");
        scanf("%d", &op);
        char x [] = "/home/romoeoaxpuac/Escritorio/Carpeta1/Carpeta2/Discoxxxx.dsk";
        //strcpy(Comando,x);
        int size = 24; // Tamaño del archivo
        char tipo = 'c';

        /// esto es para la parte del fdisk///
        unitparticion = 'm';
        nuevaparticion = 3;
        long int tamaniologico = 1000000;
        //tipoParticion = 'e';
        char AjusteParticion[1024] = "BF";
        int AderirTamannio = 2;
         /// para el delelte
         char modo [1024] = "full";
         //char modo [10] = "full";
        ///strcpy(AjusteParticion,"BW");
        //strcpy(nombreParticion,"Particion");
                if( unitparticion == 'b' || unitparticion == 'b'){
                    nuevaparticion = nuevaparticion;
                    AderirTamannio= AderirTamannio;
                }
                if (unitparticion == 'K' || unitparticion == 'k' || unitparticion == 'c'){
                    nuevaparticion = nuevaparticion* 1024;
                    AderirTamannio = AderirTamannio * 1024;
                    //unitparticion ='K';
                }
                if (unitparticion == 'M' || unitparticion == 'm'){
                    nuevaparticion = nuevaparticion * 1048576;
                    AderirTamannio = AderirTamannio * 1048576;
                }

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
                    size = size * 1024;
                }
                if (tipo == 'M' || tipo == 'm' || tipo == 'c'){
                    size = size * 1048576;
                }

                if(size >0 && size >= 10000000){

                    char separador[] = "/";
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

            int a;
            long int tamanio;
            //printf("%i\n",cantidadDeParicionesLogicas(Comando));
           FILE *fpx = fopen(Comando,"r");

           if(fpx != NULL){
            //printf("El archivo si Existe\n");
             fseek( fpx, 0L, SEEK_END );
           // printf("%i",ftell(fpx));
            //printf("%i",cantidadDeParticiones(Comando));
            if(tipoParticion == 'l'|| tipoParticion == 'L'){
                if((cantidadDeParicionesLogicas(Comando) == 1)&& tamanioExtendida(Comando)>tamaniologico){
                    //printf("%i ", tamanioExtendida(Comando));
                    //printf("%i ", tamaniologico);
                    //printf("%i ", tamanioExtendida(Comando)-tamaniologico);
                    //printf("\n");
                    cambiandoTamanioExtendida(Comando,tamanioExtendida(Comando)-tamaniologico);
                    insertarParticion(Comando,nombreParticion,tipoParticion,unitparticion,AjusteParticion,tamaniologico);
                    printf("PARTICAION LOGICA CREADA CON EXITO \n");
                    if(strcmp(AjusteParticion,"BF")==0){printf("Se Utilizo EL MEJOR AJUSTE \n");}if(strcmp(AjusteParticion,"FF")==0){printf("Se Utilizo EL PRIMER AJUSTE \n");}
                    if(strcmp(AjusteParticion,"WF")==0){printf("Se Utilizo EL PEOR AJUSTE \n");}
                   //pntf("%i ", tamanioExtendida(Comando));
                    //printf("%i ", tamaniologico);
                    //printf("%i ", tamanioExtendida(Comando)-tamaniologico);
                    //printf("\n");l

                }else{
                    printf("NO SE HA CREADO UNA PARTICIÓN EXTENDIDA PARA ESTE DISCO\n");
                }
            }

            if(ftell(fpx)>=10000000 && nuevaparticion>2000000 && (buscarParticion(Comando,nombreParticion)==0) &&(cantidadDeParticiones(Comando)+1<=4) && (tipoParticion != 'L'|| tipoParticion != 'l')&&(cantidadDeParicionesLogicas(Comando)!=1)   ){
                tamanio = ftell(fpx);
                remove(Comando);
                a = 1;
            }else if(cantidadDeParicionesLogicas(Comando)== 1 && (tipoParticion == 'P'|| tipoParticion == 'p') ){
                tamanio = ftell(fpx);
                remove(Comando);
                a = 1;
            }
            else {
                if(tipoParticion == 'l'|| tipoParticion == 'L'){
                }
                else
                printf("Disco Pequeño, Partición Repetido, Particiones a Tope\n");
                a = 0;
            }
              fseek( fpx, 0L, SEEK_SET );
            fclose(fpx);
           }
           else{
            printf("No se Puede Realizar la Partición Ya que el Archivo NO existe o a Excedido el número de Particiones\n");
            a = 0;//printf("No se Puede Realizar la Partición, a Excedido el número de Particiones");
           }
            //int xx= tamanioArchivo(Comando) - nuevaparticion;
            if(a == 1){
                fpx = fopen(Comando,"wr+");
                //printf("%i",nuevo);
                for(int x = 0; x<(tamanio - nuevaparticion);x++){
                    fputs( " ", fpx );
                }
                printf("Particion Realizada Con Exito\n");
                fclose(fpx);
                //insertarParticion(Comando,nombreParticion,tipoParticion,unitparticion,AjusteParticion,nuevaparticion);
                //
                insertarParticion(Comando,nombreParticion,tipoParticion,unitparticion,AjusteParticion,nuevaparticion);
            }




        break;
        case 5:
            //aca es para añadir tamaño a las particiones :D
                puts("");
                int valor = 0;
                long int tamanios;
                if(VericiandoParticion(Comando,nombreParticion) == 1){
                //printf("AGregando\n");
                FILE *fp;
                fp = fopen(Comando,"r");
                // AderirTamannio
                fseek(fp, 0L, SEEK_END);
                //printf("test.c ocupa %d bytes", ftell(fich)); 10000000
                if( AderirTamannio > 0 && ftell(fp)>=AderirTamannio){
                    tamanios = ftell(fp);
                    valor = 1;
                    //printf("SI SE PUEDE\n");
                    cambiarTamanioParticion(Comando,nombreParticion,AderirTamannio);
                    remove(Comando);
                }else if(AderirTamannio<0 && (tamanioDeParticion(Comando,nombreParticion)>(AderirTamannio*-1))){//) && VericiandoParticion(Comando,nombreParticion)>=(AderirTamannio*-1)){
                    //printf("%i\n",tamanioDeParticion(Comando,nombreParticion));
                    //printf("%i\n",AderirTamannio);
                    tamanios=ftell(fp);
                    valor = 2;
                    cambiarTamanioParticion(Comando,nombreParticion,AderirTamannio);
                     remove(Comando);
                }
                else{
                    printf("NO SE PUEDE AUMENTAR O DISMINUIR LA PARTICION, DISCO PEQUEÑO \n");
                }

                fclose ( fp );
                if(valor == 1){
                    fp = fopen(Comando,"wr+");
                //printf("%i",nuevo);
                    for(int x = 0; x<(tamanios - AderirTamannio);x++){
                        fputs( " ", fp);
                    }
                    printf("SE REDUJO EL TAMAÑO DEL DISCO\n");
                    fclose(fp);
                }
                if(valor == 2){
                    fp = fopen(Comando,"wr+");
                //printf("%i",nuevo);
                    for(int x = 0; x<(tamanios - AderirTamannio);x++){
                        fputs( " ", fp);
                    }
                    printf("SE AUMENTO EL TAMAÑO DEL DISCO\n");
                    fclose(fp);

                }
            }else{
                printf("NO SE PUDO AGREGAR Y/O REDUCIR TAMAÑO\n");

            }
        break;
        case 6:
            visualizarParticiones();

        break;
        case 7:
            /// para la parte del fast
            if(EsParticionExtendida(Comando,nombreParticion)==1 && strcmp(modo,"fast")==0 ){
                printf("SE ELIMINO PARTICION EXTENDIDA\n");
                limpiarParticion(Comando,nombreParticion);
                limpiarParticionLogica(Comando,nombreParticion);
            }

            if(EsParticionPrimaria(Comando,nombreParticion)==1 && strcmp(modo,"fast") == 0){
                printf("SE ELIMINO PARTICION PRIMARIA\n");
                limpiarParticion(Comando,nombreParticion);
            }

            if(EsParticionExtendida(Comando,nombreParticion)==0 && EsParticionPrimaria(Comando,nombreParticion)==0){
                printf("NO SE PUEDE REALIZAR LA ELIMINACION\n");
            }
            // para la parte del full
            long int tamaniosx;
            FILE *fp;
                fp = fopen(Comando,"r");
                // AderirTamannio
                fseek(fp, 0L, SEEK_END);
                tamaniosx = ftell(fp);
                fclose(fp);
            long int ax = 0;
            long int ax2 = 0;
            if(EsParticionExtendida(Comando,nombreParticion)==1 && strcmp(modo,"full")==0 ){
                printf("SE ELIMINO PARTICION EXTENDIDA*\n");
                ax = EliminarParticion(Comando,nombreParticion);
                ax2 = EliminarParticionLogica(Comando,nombreParticion);
                remove(Comando);
                fp = fopen(Comando,"wr+");
                //printf("%i",nuevo);
                    for(int x = 0; x<(tamaniosx + ax + ax2);x++){
                        fputs( " ", fp);
                    }
                    printf("SE AUMENTO EL TAMAÑO DEL DISCO\n");
                    fclose(fp);
            }

            if(EsParticionPrimaria(Comando,nombreParticion)==1 && strcmp(modo,"full") == 0){
                printf("SE ELIMINO PARTICION PRIMARIA *\n");
                //printf("%i\n",EliminarParticion(Comando,nombreParticion));
                ax = EliminarParticion(Comando,nombreParticion);
                //ax2 = EliminarParticionLogica(Comando,nombreParticion);
                remove(Comando);
                fp = fopen(Comando,"wr+");
                //printf("%i",nuevo);
                    for(int x = 0; x<(tamaniosx + ax);x++){
                        fputs( " ", fp);
                    }
                    printf("SE AUMENTO EL TAMAÑO DEL DISCO\n");
                    fclose(fp);
            }

        break;
        case 8:
            visualizar();
        break;
        case 9:
            MontandoParticion(Comando,nombreParticion);
            printf("Visualizando Las montadas \n");
            visualizarMontadas();
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

  void buscar(char path [] )   {

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

int tamanioArchivo(char archivo[]){
struct Archivo *aux;
     pos=0;
     aux=primero;
     while(pos<numNodos)
       {
          printf(" %d.- ", pos+1);
          printf(" %s\n", aux->path);
          if(strcmp(archivo, aux->path)==0)
                    {
                      //printf("\n %s EXISTE", aux );
                      return aux->tamanio;
                      //v = 1;
                   }

          aux= aux->siguiente;
          pos++;
       }
return 0;
}
void modificarTamanio(char archivo[],int tamanio){
struct Archivo *aux;
     pos=0;
     aux=primero;
     while(pos<numNodos)
       {
          printf(" %d.- ", pos+1);
          printf(" %s\n", aux->path);
          if(strcmp(archivo, aux->path)==0)
                    {
                      //printf("\n %s EXISTE", aux );
                    aux->tamanio = tamanio;
                      //v = 1;
                   }

          aux= aux->siguiente;
          pos++;
       }

}

void inicializaraParticion(){
    primera = NULL;
    ultima = NULL;
}
void insertarParticion(char path[], char nombre[], char tipo,char Unidad,char ajuste[],long int tamanio){
 struct Particion *nuevo;
    nuevo=( struct Particion*)malloc(sizeof(struct Particion));
    if(nuevo==NULL)
         printf("\n MEMORIA INSUFICIENTE\n");

     else
     {
        strcpy(nuevo->path,path);
        strcpy(nuevo->nombre,nombre);
         nuevo->TDP = tipo;
         nuevo->unit=Unidad;
        strcpy(nuevo->ajuste,ajuste);
        nuevo->size = tamanio;
         if(primera==NULL)
           {
            primera=nuevo;
            ultima=nuevo;

         }else{

           ultima->siguiente=nuevo;
           ultima=nuevo;
              }
       }
       numNodosP++;



}
int buscarParticion(char path[],char nombre[]){
struct Particion *aux;
     posP=0;
     aux=primera;
     while(posP<numNodosP)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if((strcmp(path, aux->path)==0) && ( strcmp(nombre,aux->nombre)==0))
                    {
                      //printf("\n %s EXISTE", aux );
                      return 1;
                      //v = 1;
                   }

          aux= aux->siguiente;
          posP++;
       }

return 0;
}
void visualizarParticiones(){
struct Particion *aux;

     posP=0;

     aux=primera;

     while(posP<numNodosP)
       {
          printf(" %d.- ", posP+1);
          printf("DISCO ");
          printf("%s", aux->path);
          printf(" PARTICION ");
          printf("%s ", aux->nombre);
          printf(" TIPO ");
          if(aux->TDP == 'E' || aux->TDP == 'e')
            printf("%s ","Extendida");
          if(aux->TDP == 'P' || aux->TDP =='p')
            printf("%s ","Primaria");
          if(aux->TDP == 'l' || aux->TDP=='L')
            printf("%s ","Logica");
          printf(" TAMANIO ");
          printf("%i bytes",aux->size);
          printf("\n");
          aux= aux->siguiente;

          posP++;
       }


}
int cantidadDeParticiones(char path[]){
struct Particion *aux;
     posP=0;
     aux=primera;
     int a = 0;
     while(posP<numNodosP)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if((strcmp(path, aux->path)==0) && (aux->TDP!= 'L'||aux->TDP != 'l')  )
                    {
                        a++;
                      //v = 1;
                   }

          aux= aux->siguiente;
          posP++;
       }

return a;


}
int cantidadDeParicionesLogicas(char path[]){
struct Particion *aux;
     posP=0;
     aux=primera;
     while(posP<numNodosP)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if( aux->TDP == 'E' || aux->TDP == 'e')
                    {
                        return 1;
                      //v = 1;
                   }

          aux= aux->siguiente;
          posP++;
       }

return 0;

}
int cantidadDeParticionesPrimarias(char path[]){
struct Particion *aux;
     posP=0;
     aux=primera;
     int a = 0;
     while(posP<numNodosP)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if( aux->TDP == 'E' || aux->TDP == 'e')
                    {
                        a++;
                      //v = 1;
                   }

          aux= aux->siguiente;
          posP++;
       }

return a;

}


long int tamanioExtendida(char path[]){
struct Particion *aux;
     posP=0;
     aux=primera;
     while(posP<numNodosP)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if( aux->TDP == 'E' || aux->TDP == 'e')
                    {
                        return aux->size;
                      //v = 1;
                   }

          aux= aux->siguiente;
          posP++;
       }

return 0;

}
void cambiandoTamanioExtendida(char path [], long int tamanio){
    struct Particion *aux;
     posP=0;
     aux=primera;
     while(posP<numNodosP)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if( strcmp(path,aux->path) == 0)
                    {
                    aux->size = tamanio;
                   }

          aux= aux->siguiente;
          posP++;
       }

}

void primerAjuste(char path[],char nombreParticion[],long int tamanio){
struct Particion *aux2;
     posP=0;
     aux2=primera;

struct Archivo *aux;
     pos=0;
     aux=primero;
     while(pos<numNodos)
       {
        if(strcmp(aux->path,path) == 0 ){
            printf("Se Utilizo El Primero Ajuste\n");
            aux->tamanio = -1;
        }
         while(posP<numNodosP)
            {
                aux2= aux2->siguiente;
                posP++;
            }
        if(aux->tamanio>tamanio){
            //printf("Espacio Disponible\n");
            insertarParticion(path,nombreParticion,'c','k','FF',tamanio);
        }
          aux= aux->siguiente;
          pos++;
       }

}
void MejorAjuste(char path[],char nombreParticion[],long int tamanio){
struct Particion *aux2;
     posP=0;
     aux2=primera;

struct Archivo *aux;
     pos=0;
     aux=primero;
     char a = 'c';
     char b= 'k';
     while(pos<numNodos)
       {
        if(strcmp(aux->path,path) == 0 ){
            printf("Se Utilizo El Primero Ajuste\n");
            aux->tamanio = -1;
            //primero vamsos a comprar el tamño del arhiciv
            //luevo camos a ir agrandando las particones onde se deben colorcar
            // y listo se agregar
            //primero vamsos a comprar el tamño del arhiciv
            //luevo camos a ir agrandando las particones onde se deben colorcar
            // y listo se agregar
            while(aux->tamanio>tamanio){
                insertarParticion(path,nombreParticion,b,a,"BF",tamanio);
            }
        }

          aux= aux->siguiente;
          pos++;
       }

}
void PeorAjuste(char path[],char nombreParticion[],long int tamanio){
struct Particion *aux2;
     posP=0;
     aux2=primera;

struct Archivo *aux;
     pos=0;
     aux=primero;
     char a = 'c';
     char b= 'k';
     while(pos<numNodos)
       {
        if(strcmp(aux->path,path) == 0 ){
            printf("Se Utilizo El Primero Ajuste\n");
            aux->tamanio = -1;
            //primero vamsos a comprar el tamño del arhiciv
            //luevo camos a ir agrandando las particones onde se deben colorcar
            // y listo se agregar
            //primero vamsos a comprar el tamño del arhiciv
            //luevo camos a ir agrandando las particones onde se deben colorcar
            // y listo se agregar
            while(aux->tamanio>tamanio){
                insertarParticion(path,nombreParticion,b,a,"BF",tamanio);
            }
        }

          aux= aux->siguiente;
          pos++;
       }


}
int VericiandoParticion(char path [], char nombreParticion[]){
struct Particion *aux;

     posP=0;

     aux=primera;

     while(posP<numNodosP)
       {
          if(strcmp(aux->path,path)==0 && strcmp(aux->nombre,nombreParticion)==0){
                    if(aux->TDP!= 'l' && aux->TDP != 'L')
                    return 1;


          }
          aux= aux->siguiente;

          posP++;
       }


return 0;
}

long int tamanioDeParticion(char path [], char nombreParticion[]){
struct Particion *aux;

     posP=0;

     aux=primera;

     while(posP<numNodosP)
       {
          if(strcmp(aux->path,path)==0 && strcmp(aux->nombre,nombreParticion)==0){
                    //printf("%i\n",aux->size);
                    return aux->size;


          }
          aux= aux->siguiente;

          posP++;
       }


return 0;



}
void cambiarTamanioParticion(char Archivo[], char nombre[] ,long int tamanio){

struct Particion *aux;

     posP=0;
    long int a;
     aux=primera;

     while(posP<numNodosP)
       {
          if(strcmp(aux->path,Archivo)==0 && strcmp(aux->nombre,nombre)==0){
                a = aux->size + tamanio;
                if(tamanio>0){
                    aux->size = aux->size + tamanio;
                }
                else if(tamanio<0 && (a >=0)){
                    //printf("%i\n",a);
                    aux->size = aux->size + tamanio;
                }
                else{
                    printf("EL TAMAÑO DE LA PARTICIÓN NO ES SUFICIENTE\n");
                }
          }
          aux= aux->siguiente;

          posP++;
       }




}


int EsParticionPrimaria(char path[],char nombreParticion[]){

struct Particion *aux;

     posP=0;

     aux=primera;

     while(posP<numNodosP)
       {
          if(strcmp(aux->path,path)==0 && strcmp(aux->nombre,nombreParticion)==0 && (aux->TDP == 'P'|| aux->TDP == 'p')){
                    //printf("%i\n",aux->size);
                    return 1;


          }
          aux= aux->siguiente;

          posP++;
       }


return 0;

}
int EsParticionExtendida(char path[], char nombreParticion[]){
    struct Particion *aux;

     posP=0;

     aux=primera;

     while(posP<numNodosP)
       {
          if(strcmp(aux->path,path)==0 && strcmp(aux->nombre,nombreParticion)==0 && (aux->TDP == 'E'|| aux->TDP == 'e')){
                    //printf("%i\n",aux->size);
                    return 1;


          }
          aux= aux->siguiente;

          posP++;
       }


return 0;
}


void limpiarParticion(char path[],char nombreParticion[]){
 struct Particion *aux;

     posP=0;

     aux=primera;

     while(posP<numNodosP)
       {
          if(strcmp(aux->path,path)==0 && strcmp(aux->nombre,nombreParticion)==0){
                    //printf("%i\n",aux->size);
                    strcpy(aux->nombre,"Libre");
                    strcpy(aux->ajuste,"");
                    //aux->TDP = ' ';

          }
          aux= aux->siguiente;

          posP++;
       }



}
void limpiarParticionLogica(char path[], char nombreParticion[]){

struct Particion *aux;

     posP=0;

     aux=primera;
     while(posP<numNodosP)
       {
          if(strcmp(aux->path,path)==0 &&(aux->TDP=='l'||aux->TDP=='L')){
                    //printf("%i\n",aux->size);
                    strcpy(aux->nombre,"Libre");
                    strcpy(aux->ajuste,"");

          }
          aux= aux->siguiente;

          posP++;
       }

}

long int EliminarParticion(char Archivo[],char nombre[]){
 struct Particion *aux;

     posP=0;

     aux=primera;
     long int tam= 0;
     while(posP<numNodosP)
       {
          if(strcmp(aux->path,Archivo)==0 && strcmp(aux->nombre,nombre)==0){
                    //printf("%i\n",aux->size);
                    tam = aux->size;
                    strcpy(aux->nombre,"");
                    strcpy(aux->ajuste,"");
                    strcpy(aux->path,"");
                    aux->TDP = ' ';
                    aux->size = 0;
                    //aux->TDP = ' ';

          }
          aux= aux->siguiente;

          posP++;
       }


return tam;
}
long int EliminarParticionLogica(char Archivo[], char nombre[]){
struct Particion *aux;

     posP=0;
     long int pp = 0;
     aux=primera;

     while(posP<numNodosP)
       {
       //printf("VAMOS BIEN\n");
          if(strcmp(aux->path,Archivo)==0 &&(aux->TDP=='l'||aux->TDP=='L')){
                    //printf("%i\n",aux->size);
                    pp = pp + aux->size;
                    strcpy(aux->nombre,"");
                    strcpy(aux->ajuste,"");
                    strcpy(aux->path,"");
                    aux->TDP = ' ';
                    aux->size = 0;

          }
          aux= aux->siguiente;

          posP++;
       }

return pp;
}

void MontandoParticion(char Archivo[], char nombre[]){

struct Archivo *aux;
     pos=0;
     aux=primero;
      while(pos<numNodos)
       {
          //printf(" %d.- ", pos+1);
          //printf(" %s\n", aux->path);
          if(strcmp(aux->path,Archivo)== 0){
            if(pos+1 == 1){
                printf("La Letra es A\n");
                char id [1024] = "VDa";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 2){
                printf("La Letra es B\n");
                char id [1024] = "VDb";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 3){
                printf("La Letra es C\n");
                char id [1024] = "VDc";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 4){
                printf("La Letra es D\n");
                char id [1024] = "VDd";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 5){
                printf("La Letra es E\n");
                char id [1024] = "VDe";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 6){
                printf("La Letra es F\n");
                char id [1024] = "VDf";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 7){
                printf("La Letra es G\n");
                char id [1024] = "VDg";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 8){
                printf("La Letra es H\n");
                char id [1024] = "VDh";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 9){
                printf("La Letra es I\n");
                char id [1024] = "VDi";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 10){
                printf("La Letra es J\n");
               char id [1024] = "VDj";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 11){
                printf("La Letra es K\n");
                char id [1024] = "VDk";
                insertarMontada(Archivo,nombre,id);
            }
            if(pos+1 == 12){
                printf("La Letra es L\n");
                char id [1024] = "VDl";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 13){
                printf("La Letra es M\n");
                char id [1024] = "VDm";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 14){
                printf("La Letra es N\n");
               char id [1024] = "VDn";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 15){
                printf("La Letra es O\n");
                char id [1024] = "VDo";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 16){
                printf("La Letra es P\n");
                char id [1024] = "VDp";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 17){
                printf("La Letra es Q\n");
                char id [1024] = "VDq";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 18){
                printf("La Letra es R\n");
                char id [1024] = "VDr";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 19){
                printf("La Letra es S\n");
                char id [1024] = "VDs";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 20){
                printf("La Letra es T\n");
                char id [1024] = "VDt";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 21){
                printf("La Letra es U\n");
                char id [1024] = "VDu";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 22){
                printf("La Letra es V\n");
                char id [1024] = "VDv";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 23){
                printf("La Letra es W\n");
                char id [1024] = "VDw";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 24){
                printf("La Letra es X\n");
                char id [1024] = "VDx";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 25){
                printf("La Letra es Y\n");
                char id [1024] = "VDy";
                insertarMontada(Archivo,nombre,id);
            }
             if(pos+1 == 26){
                printf("La Letra es Z\n");
                char id [1024] = "VDz";
                insertarMontada(Archivo,nombre,id);
            }


          }
          aux= aux->siguiente;
          pos++;
       }


}

void inicializarMontada(){
    primeraPM = NULL;
    ultimaPM = NULL;
}
void insertarMontada(char path[], char nombreParticion [],char idParticion[]){
 struct ParticionesMontadas *nuevo;
    nuevo=( struct ParticionesMontadas*)malloc(sizeof(struct ParticionesMontadas));
    if(nuevo==NULL)
         printf("\n MEMORIA INSUFICIENTE\n");

     else
     {
        strcpy(nuevo->path,path);
        strcpy(nuevo->nombreParticion,nombreParticion);
        strcpy(nuevo->idParticion,idParticion);
         if(primeraPM==NULL)
           {
            primeraPM =nuevo;
            ultimaPM =nuevo;

         }else{

           ultimaPM->siguiente=nuevo;
           ultimaPM=nuevo;
              }
       }
       numNodosPM ++;





}
void visualizarMontadas(){
struct ParticionesMontadas *aux;
     posPM=0;

     aux=primeraPM;

     while(posPM<numNodosPM)
       { printf(" %d.- ", posPM+1);
         printf(" %s", aux->path);
         printf(" %s", aux->nombreParticion);
         printf(" %s\n",aux->idParticion);
          aux= aux->siguiente;
          posPM++;
       }

    if(numNodosPM==0)
       printf("\n LISTA VACIA");


}
int TotalDeMontadas(char path []){
    struct ParticionesMontadas *aux;
     posPM=0;
     int a = 0;
     aux=primeraPM;
     while(posPM<numNodosPM)
       { //printf(" %d.- ", posPM+1);
         //printf(" %s", aux->path);
         //printf(" %s\n",aux->idParticion);
         if(strcmp(aux->path,path)){
            a++;
         }
          aux= aux->siguiente;
          posPM++;
       }
return a;

}

