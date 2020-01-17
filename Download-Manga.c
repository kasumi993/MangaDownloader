#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int x=0,a=0,code=0,indice=0;
char chaine1[]="-";
char chaine2[]=",";
char syscommand[500];
char* pwdir; 
char buff[PATH_MAX + 1];

int main(int argc, char *argv[]){

pwdir = getcwd( buff, PATH_MAX + 1 );
    if(argc==3){
        indice=1;
    }
    if(argc>=5){
	int result1=strcmp(argv[3],chaine1);
	int result2;

	if ((argc==5) && (result1==0)){
       		indice=2;
        }else{
		int i=3;

		do{
			result2=strcmp(argv[i],chaine2);
			if (result2==0){
                		indice=3;
				i=i+2;
			}else {indice=4;}
              	}while(i<argc && result2==0);
	     }
    }

switch(indice){
	case 1: code=1;
		printf("vous voulez telecharger le chapitre %s de %s. Veuillez Patienter s'il vous plait...\n",argv[2],argv[1]);
		sprintf(syscommand,"docker run -v \"%s\":/home/manga -e ARGUMENTS=\"%d %s %s\" download-container",pwdir,code,argv[1],argv[2]);
		printf("%s",syscommand);
		system(syscommand);
		break;
	case 2: code=2;
		printf("vous voulez telecharger les chapitres de %s à %s de %s. Veuillez Patienter s'il vous plait...\n",argv[2],argv[4],argv[1]);
		sprintf(syscommand,"docker run -v \"%s\":/home/manga -e ARGUMENTS=\"%d %s %s %s\" download-container",pwdir,code,argv[1],argv[2],argv[4]);
		printf("%s",syscommand);
		system(syscommand);
		break;
	case 3: code=3;
		int u=2;
		printf("vous voulez telecharger ces chapitres. Veuillez Patienter s'il vous plait...\n");
		 while(u<=argc){
		sprintf(syscommand,"docker run -v \"%s\":/home/manga -e ARGUMENTS=\"%d %s %s\" download-container",pwdir,code,argv[1],argv[u]);
		printf("%s",syscommand);
		system(syscommand);
		u=u+2;
		}
		break;
	default: printf("\n OUPS!! il semblerait que la syntaxe ne soit pas correcte.\n \n Veuillez respecter un de ces formats:\n \n 1- ./Download-Manga nomManga numeroChapitre \n 2- ./Download-Manga nomManga numeroChapitreDebut - numeroChapitreFin \n 3- ./Download-Manga nomManga numeroChapitre , numeroChapitre , ...\n") ;
}

return 0;
}
