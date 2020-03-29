#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <QString>
#include <QFile>

class functions
{
public:
    static int getDataFromConsole(int *target_1, int *target_2);

    static int getDataFromFile(int *target_1, int *target_2, QString inpath);

    static void quickSort(int *arr, int first, int last);

private:
    struct List
    {
        List *next =0;
        int data=0;
    };

    static int check(int *arr,int N);
    /*  Функция проверки сортировки на правильность.
     *  Возвращает 1 - если массив отсортирован по возрастанию,
     *  0 - если не сортирован
     */
};

#endif // FUNCTIONS_H
