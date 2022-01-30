#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>

int main()
{
    long i;
    char *a;//массив из n по 1 байту (unsignet char -1 byte)
    long b=0; //присвоил ноль, тк при инициализации выдавал произвольные значения
    long c=0;
    long size;
    char name[255];
    system("chcp 1251");
    // Выделение памяти
    a = (char*)malloc(size * sizeof(long));    //указывается сначала тип данных массива, затем указывается тип переменной количества эдементов
    //работа с кириллицей
    setlocale(LC_ALL,"");
    //указатель на файл
    FILE *fin;
   //запрос имени файла
   printf ("Print Введите имя файла - ");
   gets (name);
  printf ("имя файла %s\n", name);
     //открытие файла на чтение
    //name="zipjpeg.jpg";
    fin=fopen(name,"rb");
    printf ("Открытие файла: ");
    if (fin == NULL) {printf ("ошибка\n"); return -1;}
    else printf ("выполнено \n");
    
    //поиск размера файла, для определения размера массива    
    fseek(fin, 0, SEEK_END);// устанавливает позицию в потоке данных на конец файл
    size = ftell(fin); //возвращает текущее значение указателя положения в файле количество байт, на которое указатель отстоит от начала файла.
    printf ("Размер файла  равен %ld\n", size);
    printf ("b=%ld \n", b);
    //считывание файла в массив 
     fseek(fin,0L, SEEK_SET); 
     fread(a,1, size,fin); //fread(имя массива, Размер в байтах каждого считываемого элемента, Количество элементов, файл)
       for (i=0;i<size;i++)
       {
        if (a[i]==0x50 && a[i+1]==0x4B && a[i+2]==0x01 && a[i+3]==0x02) // && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04
        {b++;}
        else {c++;}
       }
printf ("b=%ld \n", b);
printf ("c=%ld \n", c);
printf ("b+c=%ld \n", (b+c));
fclose (fin);                                      // закрыть файл
free(a); //освобождаем память выделенную под массив
return 0;
}
