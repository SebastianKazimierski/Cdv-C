#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

if(argc != 2)
  {printf("error\n");
		return 1;
  }
char nazwapliku[64];
strcat(nazwapliku, argv[1]);
int dir; //* zapisuje otwarcie katalogu
FILE *wp; //* wskaznik, plik
DIR *diretc; //* wskaznik, otwieranie /etc
struct dirent *pdiretc; //* otwiera katalog
int process_id,pidrodzic;
pidrodzic = 0;
process_id = fork();
if(process_id < 0){fprintf(stderr, "blad\n");
    exit(1);
  }
else if(process_id == 0){
  	if(dir =mkdir("zaliczenie", 0744)  != 0 && errno != EEXIST){perror("mkdir");
    exit(1);
  }
if ((wp=fopen(nazwapliku, "w")) == NULL) {perror("fopen");
    exit(1);
  }
if((diretc= opendir("/etc")) == NULL) {perror("opendir: ");
    exit(1);
  }
  while ((pdiretc = readdir(diretc)) != NULL)//*odczyt /etc i zapis do pliku
  {
    if(pdiretc->d_type == DT_REG)
    	{
    		fputs(pdiretc->d_name, wp);
    		fputc('\n', wp);
    	}
  						}	
  
printf("pid dziecka: %d \npid rodzica: %d\n",getpid(),getppid());
closedir (diretc);//*zamkykanie
fclose(wp);
exit(0);
}
pidrodzic = wait(&process_id);
if (WIFEXITED(process_id)){
printf("Proces dziecka zakonczony\n");
}
return 0;
}
