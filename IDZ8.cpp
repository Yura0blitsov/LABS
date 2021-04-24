#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;

class vect
{
public:
	vect()
	{
        cout << "\tВведите действительную x-координату вектора: ";
        x = Correct_value();
        cout << "\tВведите действительную y-координату вектора: ";
        y = Correct_value();
	}

    double scal_prod(vect v)
    {
        return this->x * v.x + this->y * v.y;
    }

    double module()
    {
        return sqrt(this->x * this->x + this->y * this->y);
    }

    double angle(vect v)
    {
        double cosA;
        if (this->module() != 0 && v.module() != 0)
        {
            cosA = this->scal_prod(v) / (this->module() * v.module());
        }
        else
        {
            cosA = 1;
        }

        if (cosA <= 1 || cosA >= -1)
        {
            return (acos(cosA) * 180) / PI;
        }
        else
        {
            exit(1);
        }
    }

protected:

    const double PI = 3.141592653589793;

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

	double x;
	double y;
};

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "Введите координаты первого вектора: " << endl;
    vect v1;
    cout << "Введите координаты второго вектора: " << endl;
    vect v2;
    double ang = v1.angle(v2);
    cout << "Меньший угол, который образуют вектора составляет: " << setiosflags(ios::fixed) << setprecision(3) << ang << " градусов" << endl;
}