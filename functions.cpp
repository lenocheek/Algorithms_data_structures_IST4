#include "functions.h"
#include <QDebug>

using namespace std;

int functions::getDataFromConsole(int *target_1, int *target_2)
{
    qDebug() << Q_FUNC_INFO;

    int size = 0;

    target_1 = 0;
    target_2 = 0;

    bool okSize = 1;

    while (okSize)
    {
        cout << "Enter sequences size: ";
        cin >> size;

        if (size > 50)
        {
            cout << "It's to much! Are you seriously?" << endl;
            continue;
        }

        if (size <= 0)
        {
            cout << "Wrong size!" << endl;
            continue;
        }
        else
        {
            okSize = 0;
        }
    }

    target_1 = new int [size];
    target_2 = new int [size];

    cout << "\nFirst block:" << endl;

    for (int i = 0; i<size; i++)
    {
        cout << "Id " << i << ": ";
        cin >> target_1[i];
    }

    cout << "--------------";
    cout << "\nSecond block:" << endl;

    for (int i = 0; i<size; i++)
    {
        cout << "Id " << i << ": ";
        cin >> target_2[i];
    }

    cout << "--------------" << "END READING" << "\n\nBlocks:\n";

    cout << "#\tFirst block:\tSecond block:\n";

    for (int i = 0; i<size; i++)
    {
        cout << i << '\t' << target_1[i] << "\t\t" << target_2[i] << endl;
    }

    cout << endl;

    return size;
}

int functions::getDataFromFile(int *target_1, int *target_2, QString inpath)
{
   qDebug() << Q_FUNC_INFO;

   List *head = new List;
   List *curPosition = head;

   target_1 = 0;
   int counter_1 = 0;

   target_2 = 0;
   int counter_2 = 0;

   int counterAll=0;

   QFile infile(inpath);

#define MaXLEN 256

   char str [MaXLEN];

   readingLoop:

   while(!infile.atEnd())
   {
       infile.readLine(str, MaXLEN);

       if (QString(str)!="NEXT_BLOCK")
       {
          curPosition->data = atoi(str);

          curPosition->next = new List;
          curPosition = curPosition->next;

          counterAll++;
       }
       else
       {
           goto fromListToArray_1;
       }
   }

   infile.close();

   goto fromListToArray_2;


   fromListToArray_1:
   {
       if (counterAll == 0)
       {
           cout<<"WRONG BLOCK SIZE: zero components in block readed" << endl;
           return 0;
       }

       target_1 = new int[counterAll];

       curPosition = head;

       while(curPosition)
       {
           target_1[counter_1] = curPosition->data;
       }

       curPosition = head;

       while (curPosition)
       {
           List *temp = curPosition;
           curPosition = curPosition->next;

           delete temp;
       }

       curPosition = head = new List;

       goto readingLoop;
   }

   fromListToArray_2:
   {
       if (counter_1!=counterAll)
       {
           cout<<"WRONG BLOCK SIZE:\t"<< (counter_1 > counterAll ? "Second block greater then first" : "Second block less then first");

           delete [] target_1;

           curPosition = head;

           while (curPosition)
           {
               List *temp = curPosition;
               curPosition = curPosition->next;

               delete temp;
           }

           return -1;
       }

       target_2 = new int[counterAll];


       curPosition = head;

       while(curPosition)
       {
           target_2[counter_2++] = curPosition->data;
       }

       curPosition = head;

       while (curPosition)
       {
           List *temp = curPosition;
           curPosition = curPosition->next;

           delete temp;
       }

       cout << "--------------" << "END READING" << "\nBlocks:";

       cout << "#\tFirst block:\t\t Second block:\n";

       for (int i = 0; i<counter_2; i++)
       {
           cout << i << '\t' << target_1[i] << "\t\t" << target_2[i] << endl;
       }

       cout << "--------------" << endl;

       return counter_2;
   }
}

void functions::quickSort(int *arr, int first, int last)
{
    qDebug() << Q_FUNC_INFO;

    int i = first, j = last;

    int x = arr[(first + last) / 2]; //Опорный элемент из середины строки

    // int x = arr[first]; //Опорный элемент из начала строки

    // int x = arr[last]; //Опорный элемент из конца строки

    // int x = arr[first+rand()%(last-first+1)]; //Опорный элемент из случайного места массива.

    do
    {

        while (arr[i] < x)
        {
            i++;
        }

        while (arr[j] > x)
        {
            j--;
        }

        if (i <= j)
        {
            if (arr[i] > arr[j])

            {
                int temp = arr[i];

                arr[i]=arr[j];

                arr[j]=temp;
            }

            i++;

            j--;
        }
    }

    while (i <= j);

    if (i < last)
    {
        quickSort(arr, i, last);
    }

    if (first < j)
    {
        quickSort(arr, first, j);
    }
}

int functions::check(int *arr, int N)
{
    int i;

    for (i=0; i<N-1; i++)
    {
        if (arr[i+1]<arr[i])
        {
            return 0;
        }
    }

    return 1;
}
