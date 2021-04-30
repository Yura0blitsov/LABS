#include <iostream>
#include <cstdlib>
using namespace std;

void parovozikFKN(int i)
{
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "                                          ';';;''',''.\".\";''',,,," << endl;
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "                                                                _    " << endl;
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "________   ________   ________    ________   ________   |***|  | |   " << endl;
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "********   ********   ********    ********   ********   |___|  \\ / " << endl;
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "*5 курс*   *4 курс*   *3 курс*    *2 курс*   *1 курс*   ** Ф К Н **\\" << endl;
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "******** * ******** * ********  * ******** * ******** * ***********/" << endl;
    for (int n = 0; n < i; n++)
    {
        cout << " ";
    }
    cout << "00    00   00    00   00    00    00    00   00    00   (_)     (_) " << endl;
    for (int n = 0; n < i; n++)
    {
        cout << "=";
    }
    cout << "====================================================================" << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int i = 0;
    while (true)
    {
        parovozikFKN(i);
        
        system("cls");
        i++;

        if (i == 50)
        {
            i = 0;
        }

    }
}