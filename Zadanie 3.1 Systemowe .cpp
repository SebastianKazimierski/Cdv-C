#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>


int main(int argc,char *argv[])
{
	// zmienne
	char buffer[3];
	ssize_t ret_in;
	int czytaj;

	// otwiera plik
	czytaj = open("liczby.txt",  argv[1] ); 
	if(czytaj==-1)
	{
		exit(1);
	}
	while((ret_in=read(czytaj, &buffer, 2)) > 0) //zczytuje numery i wyswietla
	{
		int number = (((int)buffer[0] -48)*10 + (int)buffer[1] -48);
		int result = number*3 ;
		printf("%d * 3=%d\n",number,result);	
			
	}
	close(czytaj);

	return 0;
              }
