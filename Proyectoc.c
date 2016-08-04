#include <stdio.h>
#include <stdlib.h>

int main()
{
/*
//wb+
FILE * f;
f = fopen("/home/romoeoaxpuac/Escritorio/Disco1.dsk","wb+");
fclose(f);
*/
FILE *fp;

 	char cadena[] = " ";

 	fp = fopen ("/home/romoeoaxpuac/Escritorio/Disco1.dsk","wb+");

 	int a= 0;
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );
 	////
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );
 	for(a;a<100;a++){
 	fputs( cadena, fp );
    }
 	fclose ( fp );


        printf("Hola mundo");
        return 0;
}
