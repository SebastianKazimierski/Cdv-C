#include<unistd.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>


int main(int argc, char *argv[])
void process();
{
    FILE *plik1;
    int stat;
    char nazwa[100] = "";
    pid_t process_id; 
    process_id = fork(); //tworzenie nowego procesu (-1 nieudane, 0 stworzony nowy proces, 1 zwraca do rodzica)
    if(process_id==0)
    {
    //proces dziecka
        if (argc<2) 
        {
            printf("za malo argumentow\n");
            exit(1); // konczy proces
        }
        else
        {
            strcat(nazwa, argv[1]);
            if((plik1 = fopen(nazwa, "w")) == NULL) //otwieramy plik albo tworzymy
            {
              perror("fopen");
              return 2;
            }
        		for (int i = 9; i<=99; i++)
            {
                	if(i%3==0)
            {
                	frintf(plik1,"%d\n", i);
			}
            }
            	fclose(plik1);
            	exit(0);
        }
    }
    else //czekanie
    {
   	//proces rodzica
        wait(&stat);
    }
    if (WIFEXITED(stat))
    {printf("zakoñczono: %d\n\n",WEXITSTATUS(stat)); // rezultat}
    
	
	
	return 0;
}
