#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int mas[5] = {4, 6};
    char aaa[2][30] = {"Это массив!!!", "asd"};
    char *p = aaa[1];
    setlocale(LC_ALL, "rus");

    printf("%s\n", aaa[1]);
   // printf("%d\n", mas[1] );

    printf("Размер массива %d\n", sizeof(aaa));
    //printf("Размер указателя на массива %d\n", sizeof(p));

//    if (&str == p)
//        printf("Yes");
//    else
//        printf("No");

    return 0;
}
