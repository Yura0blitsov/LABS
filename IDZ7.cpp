#include <iostream>
using namespace std;


class Poly
{
public:
    
    Poly()
    {
        do 
        {
            cout << "Введите действительный коэффициент А: ";
            A = Correct_value();
            if (A == 0)
            {
                cout << "Для полинома третьей степени коэффициент А не должен быть равен 0!" << endl;
            }
        } while (A == 0);
        cout << "Введите действительный коэффициент B: ";
        B = Correct_value();
        cout << "Введите действительный коэффициент C: ";
        C = Correct_value();
        cout << "Введите действительный коэффициент D: ";
        D = Correct_value();
    }

    void Extremes()
    {
        double a = A * 3;
        double b = B * 2;
        double c = C;

        double Discr = b * b - 4 * a * c;

        if (Discr == 0)
        {
            double x = (-b) / (2 * a);
            double y = A * x * x * x + B * x * x + C * x + D;
            if (a > 0)
            {
                cout << "В точке (x,y) = " << "(" << x << "," << y << ")" << "-минимум" << endl;
            }
            if (a < 0)
            {
                cout << "В точке (x,y) = " << "(" << x << "," << y << ")" << "-максимум" << endl;
            }
        }

        if (Discr > 0)
        {
            double x1 = ((-b) + abs(sqrt(Discr))) / (2 * a);
            double y1 = A * x1 * x1 * x1 + B * x1 * x1 + C * x1 + D;
            double x2 = ((-b) - abs(sqrt(Discr))) / (2 * a);
            double y2 = A * x2 * x2 * x2 + B * x2 * x2 + C * x2 + D;

            double condit1 = a * 2 * x1 + b;
            double condit2 = a * 2 * x2 + b;
            if (condit1 > 0)
            {
                cout << "В точке (x,y) = " << "(" << x1 << "," << y1 << ")" << "-минимум" << endl;
            }
            else
            {
                cout << "В точке (x,y) = " << "(" << x1 << "," << y1 << ")" << "-максимум" << endl;
            }
            if (condit2 < 0)
            {
                cout << "В точке (x,y) = " << "(" << x2 << "," << y2 << ")" << "-максимум" << endl;
            }
            else
            {
                cout << "В точке (x,y) = " << "(" << x2 << "," << y2 << ")" << "-минимум" << endl;
            }
        }
        if (Discr < 0)
        {
            cout << "Точек экстремума нет" << endl;
        }
    }
private:
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
    double A;
    double B;
    double C;
    double D;
};


int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите коэффициенты A,B,C,D полинома Ax^3 + Bx^2 + Cx + D: " << endl;

    Poly x;
    x.Extremes();
    
}
