#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    long i;
    unsigned char a[1195612];//массив из n по 1 байту (unsignet char -1 byte)
    long b=0; //присвоил ноль, тк при инициализации выдавал произвольные значения
    int n;
    long c=0;
    long size;
        
    //работа с кириллицей
    setlocale(LC_ALL,"rus");
    //указатель на файл
    FILE *fin;
    //открытие файла на чтение
    fin=fopen("C:\\Users\\Vaskes\\Desktop\\C\\Projects\\Git\\C-learning\\HW1\\zipjpeg.jpg","rb");
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
     n=fread(a,1, size,fin); //fread(имя массива, Размер в байтах каждого считываемого элемента, Количество элементов, файл)
       for (i=0;i<1195612;i++)
       {
        if (a[i]==0x50 && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04) // && a[i+1]==0x4B && a[i+2]==0x03 && a[i+3]==0x04
        {b++;}
        else {c++;}
       }
printf ("b=%ld \n", b);
printf ("c=%ld \n", c);
printf ("b+c=%ld \n", (b+c));
fclose (fin);                                      // закрыть файл
return 0;
}
