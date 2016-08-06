#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>





int main()
{

//verificando el metodo de creacion
///////////////////////////////////////
///////////////////////////////////////
//////////////////////////////////////
// primero se tiene que tener el nombre del disco XD
/// aca van los parametros ///
char archivo[]="/home/romoeoaxpuac/Escritorio/Discoxxxx.dsk";
char archivo2[]="/home/romoeoaxpuac/Escritorio/Discoxxxx.dsk";
char archivo3[]="/home/romoeoaxpuac/Escritorio/Discoxxxx.dsk";
int size = 24; // Tamaño del archivo
char tipo = 'c';

if (tipo == 'K' || tipo == 'k'){
    size = size * 1000;
}
if (tipo == 'M' || tipo == 'm' || tipo == 'c'){
    size = size * 1000000;
}

if(size >0){

char separador[] = "\/";
        char h [] = "";
        char h2 [] = "/";
        char * trozo2;
        char * trozo;
        int valor = 0;
        trozo = strtok( archivo, separador);

        while( trozo != NULL ) {
        strcpy(h,trozo);
        strcat(h2,h);
        //printf(h);
        //printf( "Trozo : %s \n", trozo);//<- buscando .dsk
        trozo = strtok( NULL, separador);
        }
        //verificamos si el archivo tiene la extension devida
        if ( (strstr(h,".dsk") == NULL) && (strstr(h,".DSK") == NULL) ){
            puts("El Disco no se puede crear, el comando se encuentra en defecto");
        }else {

            puts(h2);

        /*

                //verificamos la existencia del directorio
                DIR * directorio;
                struct dirent * vacio;
                directorio = opendir("/home/romoeoaxpuac/Escritorio/PACK");
                if(directorio){
                    puts("hola");
                    closedir(directorio);
                }else{
                    puts("adios");
                }
        */
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
