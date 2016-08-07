#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>



void creacion(char ruta [], int size, char tipo);

int main()
{

//verificando el metodo de creacion
///////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////
// primero se tiene que tener el nombre del disco XD
/// aca van los parametros ///
char archivo[]="/home/romoeoaxpuac/Escritorio/Caperucita/SoyLaMeraTos/Control/Discoxxxx.dsk";
char archivo2[]="/home/romoeoaxpuac/Escritorio/Caperucita/SoyLaMeraTos/Control/Discoxxxx.dsk";
char archivo3[] = "/home/romoeoaxpuac/Escritorio/Caperucita/SoyLaMeraTos/Control/Discoxxxx.dsk";
char comando [1024] = "";
int size = 24; // Tamaño del archivo
char tipo = 'c';

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

                    //strcat(comando,"");
                    //strcat(comando,"mkdir ");
                    //printf(x);
                    //printf(y);
                    strcpy(comando,"");
                    strcat(comando,x);
                    strcat(comando,y);
                    //printf(comando);
                    //printf("\n");
                    system(comando);
                    //system(path);

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

//system("mkdir /home/romoeoaxpuac/Escritorio/RebecaCaradeTortuca");
FILE *fp;

 	char cadena[] = "/home/romoeoaxpuac/Escritorio/SoyLaTos";

 	fp = fopen ("/home/romoeoaxpuac/Escritorio/Disco2.dsk","wb+");

 	int a= 0;
 	for(a;a<100;a++){
 	fputs( " ", fp );
    }
 	fclose ( fp );
 	////


        printf("\nHola mundo");
        return 0;
}


void creacion(char ruta [], int size, char tipo){







}
