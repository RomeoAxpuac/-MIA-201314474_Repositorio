#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main()
{

char linea[] = "/home/romoeoaxpuac/Escritorio/RebecaCaradeTortuca";
    char separador[] = "\/";

    char *trozo = NULL;

    trozo = strtok( linea, separador);

    while( trozo != NULL ) {
        printf( "Trozo : %s \n", trozo);
        trozo = strtok( NULL, separador);
    }

/*
//wb+
FILE * f;
f = fopen("/home/romoeoaxpuac/Escritorio/Disco1.dsk","wb+");
fclose(f);
*/



system("mkdir /home/romoeoaxpuac/Escritorio/RebecaCaradeTortuca");
FILE *fp;

 	char cadena[] = "/home/romoeoaxpuac/Escritorio/SoyLaTos";

 	fp = fopen ("/home/romoeoaxpuac/Escritorio/Disco2.dsk","wb+");

 	int a= 0;
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );
 	////



        printf("Hola mundo");
        return 0;
}
