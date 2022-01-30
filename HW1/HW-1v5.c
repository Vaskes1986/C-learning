#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

int main()
{
    int j=0;
    int i=0;
    char *a;//массив из n по 1 байту (unsignet char -1 byte)
    int b=0; //присвоил ноль, тк при инициализации выдавал произвольные значения
    int c=0;
    int nameLength=0;
    int size;
    char name[255];
    system("cls"); //очистка экрана
    //работа с кириллицей
    setlocale(LC_ALL,"rus");
    //указатель на файл
    FILE *fin;
   //запрос имени файла
   printf ("Enter filename - ");
   gets (name);
   printf ("File name - %s\n", name);
     //открытие файла на чтение
    fin=fopen(name,"rb");
    printf ("File openning: ");
    if (fin == NULL) {printf ("Error\n"); return -1;}
    else printf ("Done \n");
    //поиск размера файла, для определения размера массива    
    fseek(fin, 0, SEEK_END);// устанавливает позицию в потоке данных на конец файл
    size = ftell(fin); //возвращает текущее значение указателя положения в файле количество байт, на которое указатель отстоит от начала файла.
    printf ("File size in bytes - %d\n", size);
    // Выделение памяти
    a = (char*)malloc((size) * sizeof(int));    //указывается сначала тип данных массива, затем указывается тип переменной количества эдементов
     //считывание файла в массив 
     fseek(fin,0L, SEEK_SET); 
     fread(a,4, (size),fin); //fread(имя массива, Размер в байтах каждого считываемого элемента, Количество элементов, файл)
       for (i=0;i<(size);i++)
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
