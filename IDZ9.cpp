#include <iostream>
#include <math.h>
using namespace std;

class MyCos
{
public:

    MyCos()
    {
        cout << "Введите верхнюю границу ряда: ";
        n = Correct_value_int();
        p = new double[n + 1];
        cout << "Введите x: ";
        double x = Correct_value_doub();
        p[0] = 1;

        for (int k = 1; k <= n; k++)
        {
            double temp = x;
            int fuct = 1;
            for (int j = 2; j <= 2 * k; j++)
            {
                fuct *= j;
            }
            
            p[k] = (pow(-1,k) * pow(temp, 2 * k)) / (fuct);
        }
    }

    void output(void)
    {
        double s = 0;
        for (int k = 0; k < n; k++)
        {
            s += p[k];
        }
        cout << endl;
        cout << "Cos(x) = " << s << endl;
    }

    ~MyCos()
    {
        delete[] p;
    }

protected:

    double Correct_value_doub(void)
    {
        double temp = 0;
        do
        {
            if (!cin.good())
            {
                cout << "Некорректный ввод действительного числа! Повторите попытку!" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cin >> temp;
        } while (!cin.good());
        return temp;
    }

    int Correct_value_int(void)
    {
        int n = 0;
        do
        {
            if (!cin.good())
            {
                cout << "Некорректный ввод числа! Повторите попытку!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            cin >> n;
            cin.clear();
            cin.ignore(1000, '\n');
            if (n <= 0)
            {
                cout << "Верхняя граница должна быть положительным числом!" << endl;
            }
        } while (!cin.good() || n <= 0);
        return n;
    }

    int n;
    double* p;
};

int main()
{
    setlocale(LC_ALL, "rus");
    MyCos obj;
    obj.output();
}