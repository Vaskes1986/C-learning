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
    //char name[255];
    int d[185];
    // system("chcp 1251");
    system("cls");
    // Выделение памяти
    //работа с кириллицей
    setlocale(LC_ALL,"rus");
    //указатель на файл
    FILE *fin;
   //запрос имени файла
  // printf ("Enter filename - ");
   //gets (name);
   //printf ("File name - %s\n", name);
     //открытие файла на чтение
    //name="zipjpeg.jpg";
    fin=fopen("C:\\Users\\Vaskes\\Desktop\\C\\Projects\\Git\\C-learning\\HW1\\zipjpeg.jpg","rb");
    printf ("File openning: ");
    if (fin == NULL) {printf ("Error\n"); return -1;}
    else printf ("Done \n");
    
    //поиск размера файла, для определения размера массива    
    fseek(fin, 0, SEEK_END);// устанавливает позицию в потоке данных на конец файл
    size = ftell(fin); //возвращает текущее значение указателя положения в файле количество байт, на которое указатель отстоит от начала файла.
    printf ("File size in bytes - %d\n", size);
    a = (char*)malloc((size) * sizeof(int));    //указывается сначала тип данных массива, затем указывается тип переменной количества эдементов
     //считывание файла в массив 
     fseek(fin,0L, SEEK_SET); 
     fread(a,4, (size),fin); //fread(имя массива, Размер в байтах каждого считываемого элемента, Количество элементов, файл)
       for (i=0;i<(size);i++)
       {
        if (a[i]==0x50 && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04) // && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04
        {
           j=(i+30);
           nameLength=a[i+26];
           c=nameLength+j;
           //printf ("namelength=%d \n", nameLength);
           printf ("File #%d \n", b);
           printf ("nameLength=%d \n", nameLength);
           for (j;j<c;j++) 
           {
            printf ("%c", a[j]);
           }
            printf ("\n");
            b++;}
        //else {c++;}
       }
printf ("b=%d \n", b);
//printf ("c=%d \n", c);
//printf ("b+c=%d \n", (b+c));
//for (j=0;j<185;j++){printf ("d=%d \n", d[j]);}

fclose (fin);                                      // закрыть файл
free(a); //освобождаем память выделенную под массив
return 0;
}
