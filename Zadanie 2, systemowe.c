#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>



int main(int argc, char *argv[])
{
	int plik1;
	int plik2;
	char nazwa[100];
	unsigned long liczba = 1;
	char str[100] ="";
	char buff[1024]="";

printf("zapisuje co trzeci znak do nowego pliku\n");

if(argc != 2)
  {printf("Podaj nazwe pliku \n");
    
	scanf("%s", nazwa);
    
	strcat(str, nazwa);
    
	strcat(str, ".red");}
else
  {strcat(nazwa, argv[1]);
    strcat(str,argv[1]);
    strcat(str, ".red");}
  
  
if((plik1 = open(nazwa, O_RDONLY)) == -1) //je�li plik nie istnieje wyskoczy b��d
  {
    perror("open");
    return 1;
  }
  
if((plik2 = open(str, O_WRONLY)) == -1) //otwarcie drugiego pliku
  {if((plik2=creat(str,O_WRONLY))== -1)
    {
    	perror("creat");
   		return 2;}
    }
  lseek(plik1,0,SEEK_SET);
  lseek(plik2,0,SEEK_SET);
  int kursor=0; //pozycja kursora na poczatku 
while((read(plik1,buf,1)) > 0) //odczytywanie z pliku 1
  {
	if((liczba % 3) == 0) // dop�ki dzielnie przez 3 nie daje reszty, zapisuje do nowego pliku
    {
    	write(plik2,buff,1);
    	kursor++;
    	lseek(plik2, kursor,SEEK_SET );// kursor >> by kontynuowa�
    }
    lseek(plik1, liczba,SEEK_SET );  //kursor odczytuje jeden plik po drugim
   liczba++;
  }
  //zamkniecie plikow
close(plik1);
close(plik2);
  
return 0;
}
