#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include<fcntl.h>


int randomRange(int, int);

int main(int argc, char *argv[])
{
    const int low = 10;
    const int up = 99;
	int fd;
	int liczba;
	FILE *plik;
	plik = fopen("liczby.txt", "w");
	if(plik == NULL){
		printf("Nie uda³o siê stworzyæ pliku");
	exit(1);}
    char buffer[12];
    srand(time(0));

    char tab[9];
    int r_num;
    int i;
	fd = open("liczby.txt", O_CREAT | O_RDWR, 0777);
    for(i = 0 ; i<10; i++)
    {      
	    r_num = randomRange(low, up);
        sprintf(buffer,"%d", r_num);
        strcat(buffer,"\n");
        printf(buffer);
        write(fd, buffer, 3);
    }
	fclose (plik);
    return 0;
}

int randomRange(int lower, int upper)
{
    int num;
    num = (rand() % (upper - lower +1) + lower);
    return num;
}


