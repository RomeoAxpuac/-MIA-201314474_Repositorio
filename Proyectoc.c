#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{
/*
char linea[] = "/home/romoeoaxpuac/Escritorio/RebecaCaradeTortuca";
    char separador[] = "\/";

    char *trozo = NULL;

    trozo = strtok( linea, separador);

    while( trozo != NULL ) {
        printf( "Trozo : %s \n", trozo);
        trozo = strtok( NULL, separador);
    }

/*
*/


// linea de comando que crea la carpeta XD"

//Comprobando Si Existe El archivo

char archivo[]="/home/romoeoaxpuac/Escritorio/Discoxx.dsk";
int size = 101; // nombre y ruta de el archivo
char cad[] = " ";
FILE *fpx = fopen(archivo,"r"); //<-abriendl el archivo para su busqueda

        char separador[] = "\/";
        char h [] = "";
        char * trozo = NULL;
        trozo = strtok( archivo, separador);
        /*
        while( trozo != NULL ) {
        strcpy(h,trozo);
        //printf(h);
        //printf( "Trozo : %s \n", trozo);//<- buscando .dsk
        trozo = strtok( NULL, separador);
        }
        //nombre del disco -> printf(h);
        if (strstr(h,".dsk") == NULL){
        puts("El Disco no se puede crear, el comando se encuentra en defecto");
        }else {
        puts("Ciudad incorrecta");
        }
*/
    //esta parte examina si ya existe el archivo
    if( fpx != NULL) {
        printf("Error, El Disco Ya Existe\n");
        fclose(fpx);
    }
    //aca es para ver si el archivo no existe y tiene la extensón .dsk
    else {
            FILE *fpx2 = fopen(archivo,"wb+");
            int a= 0;
            for(a;a<size;a++){
                fputs( cad, fpx2 );
            }
            fclose((fpx2));
            printf("Disco Creado Con Exito");
}

//////

//system("mkdir /home/romoeoaxpuac/Escritorio/RebecaCaradeTortuca");
FILE *fp;

 	char cadena[] = "/home/romoeoaxpuac/Escritorio/SoyLaTos";

 	fp = fopen ("/home/romoeoaxpuac/Escritorio/Disco2.dsk","wb+");

 	int a= 0;
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );
 	////

/*******
Vuelve irse la luz en la ciudad,
Pienso en ti aqui en la oscuridad...
Como cuando marcas sin querer...
Cuelgo antes que puedas contestar.
Tal vez, tal vez, tal vez, tal vez,
Nunca mas nos vamos a encontrar
Tal vez, tal vez, tal vez, tal vez,
el amor no vuelva por acá.


******/

        printf("Hola mundo");
        return 0;
}
