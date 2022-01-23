#include <stdio.h>
#include <stdlib.h>


int main()
{
    int mas[5] = {4, 6};
    char str[] = "Это массив!!!";
    char *p = str;
    //setlocale(0, "rus");

    printf("%d\n", mas[0]);
    printf("%d\n", *mas );

    printf("Размер массива %d\n", sizeof(str));
    printf("Размер указателя на массива %d\n", sizeof(p));

//    if (&str == p)
//        printf("Yes");
//    else
//        printf("No");

    return 0;
}
