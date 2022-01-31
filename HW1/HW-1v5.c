#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <sys\stat.h>

int main(int argc, char** argv)
{
    int j=0;
    int i=0;
    char *a;//массив из n по 1 байту (unsignet char -1 byte)
    int b=0; //присвоил ноль, тк при инициализации выдавал произвольные значения
    int c=0;
    int nameLength=0;
    int size;
    struct stat buff;
    //char name[255];
    //работа с кириллицей
    setlocale(LC_ALL,"");
    //указатель на файл
    FILE *fin;
   //запрос имени файла
   printf("Size of command line arguments %d \n", argc);
   printf ("File name - %s\n", argv[1]);
     //открытие файла на чтение
    fin=fopen(argv[1],"rb");
    printf ("File openning: ");
    if (fin == NULL) {printf ("Error\n"); return -1;}
    else printf ("Done \n");
    //поиск размера файла, для определения размера массива    
    fstat (fileno (fin), &buff);
    size=buff.st_size;
    printf ("File size in bytes - %d\n", size);
    // Выделение памяти
    a = (char*)malloc((size) * sizeof(int));    //указывается сначала тип данных массива, затем указывается тип переменной количества эдементов
     //считывание файла в массив 
    fread(a,1, size,fin); //fread(имя массива, Размер в байтах каждого считываемого элемента, Количество элементов, файл)
       for (i=0;i<size;i++)
       {
        if (a[i]==0x50 && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04) // && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04
        {
           j=(i+30); //начало имени файла 
           nameLength=a[i+26]; //размер в байтах имени файла
           c=nameLength+j; //конец файла
           printf ("File #%d \t", (b+1));
           for (j;j<c;j++) 
           {printf ("%c", a[j]);}
            printf ("\n");
            b++;}
        }
if (b) 
    printf ("Total number of files=%d \n", b);
else 
    printf ("NO zip files discovered\n");
fclose (fin);                                      // закрыть файл
free(a); //освобождаем память выделенную под массив
return 0;
}
