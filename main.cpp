#include <functions.h>

using namespace std;



int main()
{
    char temp;

    char inputPath [2048];

    int *target_1 = 0,
        *target_2 = 0;

    int size = 0;

    bool readyToGo = 0;

    system("clear");

    while (1)
    {
        if (!readyToGo)
        {
            cout << "Chouse enter type: \n\t1 - enter data from file \n\t2 - enter data from console"
                 << "\n\t0 - exit"<< endl << "Answer: ";

            cin >> temp;

                switch (temp)
                {
                    case '1':
                    {
                        cout << "Enter path to file with blocks: ";
                        cin >> inputPath;

                        size = functions::getDataFromFile(target_1, target_2, inputPath);

                        if (size<0)
                        {
                            continue;
                        }
                        else
                        {
                            readyToGo = true;
                        }

                        break;
                    }
                    case '2':
                    {
                        size = functions::getDataFromConsole(target_1, target_2);

                        readyToGo = true;
                        break;
                    }
                    case '0':
                    {
                        return 0;
                    }
                    default:
                    {
                        continue;
                    }
                }
        }
        else
        {
            cout << "Chouse enter type: \n\t1 - sort with max summs\n\t2 - Sort with min summs"
                 << "\n\t3 - clear block\n\t0 - exit"<< endl << "Answer: ";

            cin >> temp;

            switch (temp)
            {
                case '1':
                {

                    functions::quickSort(target_1, 0, size-1);

                    functions::quickSort(target_2, 0, size-1);

                    cout << endl << "Sorted blocks:\n" << endl;
                    cout << "#\tFirst block:\tSecond block:\t\t Mult:\n";

                    for (int i = 0; i<size; i++)
                    {
                        cout << i << '\t' << target_1[i] << "\t\t" << target_2[i]
                                << "\t\t" << target_1[i]*target_2[i] << endl;
                    }

                    cout << "--------------" << endl;


                    qint64 maxsumm = 0;

                    for (int i = 0; i<size; i++)
                    {
                        maxsumm += target_1[i] * target_2[i];
                    }

                    break;
                }
                case '2':
                {
                    //sort up-to-down and up-to-up;
                    //summ to qint64

                    break;
                }
                case '3':
                {
                    delete [] target_1;
                    delete [] target_2;
                    readyToGo = 0;

                    system("clear");

                    break;
                }
                case '0':
                {
                    delete [] target_1;
                    delete [] target_2;

                    return 0;
                }
                default:
                {
                    continue;
                }
            }
        }
    }
}
