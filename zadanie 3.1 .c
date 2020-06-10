#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include <time.h>

int main(int argc,char *argv[])
{
char buffer[3];
ssize_t ret_in;
int readit;

readit = open("liczby.txt",  argv[1] ); 	// otwieranie pliku
if(readit==-1)
{
	exit(1);
}
while((ret_in=read(readit, &buffer, 2)) > 0) // zczytuje i wyswietla
{
	int number = (((int)buffer[0] -48)*10 + (int)buffer[1] -48);
	int result = number*3 ;
	printf("%d*3=%d\n",number,result);	
}
close(readit);

return 0;
}
