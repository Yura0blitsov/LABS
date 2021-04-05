#include <iostream>
using namespace std;


struct complex
{
    double Re_z;
    double Im_z;
};

complex Add(const complex& z1, const complex& z2)
{
    complex z;

    z.Re_z = z1.Re_z + z2.Re_z;
    z.Im_z = z1.Im_z + z2.Im_z;

    return z;
}

complex Sub(const complex& z1, const complex& z2)
{
    complex z;

    z.Re_z = z1.Re_z - z2.Re_z;
    z.Im_z = z1.Im_z - z2.Im_z;

    return z;
}

complex Mul(const complex& z1, const complex& z2)
{
    complex z;

    z.Re_z = (z1.Re_z * z2.Re_z) - (z1.Im_z * z2.Im_z);
    z.Im_z = (z1.Re_z * z2.Im_z) + (z1.Im_z * z2.Re_z);

    return z;
}

complex Div(const complex& z1, const complex& z2)
{
    complex z;

    z.Re_z = (z1.Re_z * z2.Re_z + z1.Im_z * z2.Im_z) / (z2.Re_z * z2.Re_z + z2.Im_z * z2.Im_z);
    z.Im_z = (z1.Im_z * z2.Re_z - z1.Re_z * z2.Im_z) / (z2.Re_z * z2.Re_z + z2.Im_z * z2.Im_z);

    return z;
}

void Output(const complex& z)
{

    if (z.Im_z != 0 && z.Re_z != 0)
    {
        if (z.Im_z > 0)
        {
            cout << z.Re_z << " + " << z.Im_z << " i";
        }

        if (z.Im_z < 0)
        {
            cout << z.Re_z << " - " << -z.Im_z << " i";
        }
    }

    if (z.Im_z == 0 || z.Re_z == 0)
    {
        if (z.Im_z == 0 && z.Re_z == 0)
        {
            cout << 0;
        }

        if (z.Im_z != 0 && z.Re_z == 0)
        {
            cout << z.Im_z << "i";
        }

        if (z.Im_z == 0 && z.Re_z != 0)
        {
            cout << z.Re_z;
        }
    }
}

double Correct_value(void)
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

complex Input(void)
{
    cout << "\tВведите действительную часть числа: ";
    complex z;
    z.Re_z = Correct_value();
    cout << "\tВведите мнимую часть числа без символа \"i\": ";
    z.Im_z = Correct_value();
    return z;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите числа в алгебраической форме комплексного числа: " << endl;

    cout << "z1:" << endl;
    const complex z1 = Input();
    cout << "z2:" << endl;
    const complex z2 = Input();

    cout << endl;

    complex z = Add(z1, z2);
    cout << "Результат сложения чисел z1 и z2: ";
    Output(z);
    cout << endl;

    z = Sub(z1, z2);
    cout << "Результат вычитания из числа z1 числа z2: ";
    Output(z);
    cout << endl;
        
    z = Div(z1, z2);
    cout << "Результат деления числа z1 на число z2: ";
    Output(z);
    cout << endl;

    z = Mul(z1, z2);
    cout << "Результат умножения числа z1 на число z2: ";
    Output(z);
    cout << endl;
}
