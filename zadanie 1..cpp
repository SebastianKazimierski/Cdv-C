#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv)
{
    int ch;
    int count = 0;
    char name[20];
    FILE *fp, *out;

    fp = fopen(argv[1], "r");  // argv[1] to nazwa pliku

    strncpy(name, argv[1], 5); 
    name[7] = '\0';              
    strcat(name, ".red");        // dodawanie .red do nazwy pliku

    out = fopen(name, "w");   

    while((ch=getc(fp)) != EOF)  // kopiowanie tresci pliku
        if (count++ % 3 == 0)    // zapisuje tylko co trzecie slowo
        {
            putc(ch, out);
        }
    fclose(out);
    fclose(fp);
}
