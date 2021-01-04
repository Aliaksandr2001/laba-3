#include <iostream>
#include <locale.h>
using namespace std;

class matrix {
private:

    int N;
    int M;
    double** array;
    int* ms;
    int x;

public:

    matrix() {
        this->N = 0;
        this->M = 0;
        array = new double* [N];
        for (int i = 0; i < N; i++)
            array[i] = new double[M];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                array[i][j] = 0;
            }
        this->x = 1;
        this->ms = new int[x];
    }

    matrix(double** elements, int n, int m) {
        cout << "Инициализация" << endl;
        N = n; M = m;
        this->array = new double* [this->N];
        for (int i = 0; i < N; i++)
            this->array[i] = new double[this->M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                this->array[i][j] = elements[i][j];
        }
    }

    matrix(const matrix& other) {
        this->N = other.N;
        this->M = other.M;

        this->array = new double* [other.N];
        for (int i = 0; i < N; i++)
            this->array[i] = new double[other.M];

        for (int i = 0; i < other.N; i++) {
            for (int j = 0; j < other.M; j++) {
                this->array[i][j] = other.array[i][j];
            }
        }
        cout << "Вызвался конструктор копирования" << endl;

    }

    matrix operator +(const matrix& sum) {
        cout << "Перегрузка оператором +" << endl;
        matrix temp;

        temp.array = new double* [N];
        for (int i = 0; i < N; i++)
            temp.array[i] = new double[M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp.array[i][j] = this->array[i][j] + sum.array[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << temp.array[i][j] << " ";
            cout << endl;
        }

        return temp;
    }


    void setmas(int kol, int* mas) {
        this->x = kol;
        for (int i = 0; i < kol; i++) {
            this->ms[i] = mas[i];
        }
    }

    friend bool operator> (const  matrix& mt1, const   matrix& mt2);

    friend bool operator < (const  matrix& mt1, const  matrix& mt2);

    matrix operator++(int value)
    {
        matrix temp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                this->array[i][j]++;
            }
        }
        return temp;
    }

    friend ostream& operator<<(ostream& out, const matrix& Matrix);
    friend void Print(matrix& prin);

};

void Print(matrix& prin) {
    cout << endl << "Функция Print:" << endl;
    for (int i = 0; i < prin.N; i++) {
        for (int j = 0; j < prin.M; j++)
            cout << prin.array[i][j] << " ";
        cout << endl;
    }
}

bool operator > (const  matrix& mt1, const  matrix& mt2)
{
    return ((mt1.N * mt1.M) > (mt2.N * mt2.M));
}

bool operator < (const  matrix& mt1, const  matrix& mt2)
{
    return ((mt1.N * mt1.M) < (mt2.N * mt2.M));
}

ostream& operator<<(ostream& out, const matrix& Matrix)
{
    for (int i = 0; i < Matrix.N; i++)
    {
        for (int j = 0; j < Matrix.M; j++)
        {
            out << Matrix.array[i][j] << " ";
        }
        out << endl;
    }
    return out;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    matrix matr[3];

    double** elements;
    int n; int m;
    cout << "Введите размеры матрицы: ";
    cout << endl << "N = ";
    bool a1 = true;
    do
    {
        cin >> n;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a1 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a1);
    cout << "M = ";
    bool a2 = true;
    do
    {
        cin >> m;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a2 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a2);

    elements = new double* [n];
    for (int i = 0; i < n; i++)
        elements[i] = new double[m];
    int k = 0;
    for (k = 0; k < 3; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Введите элемент [" << i << "][" << j << "] = ";
                bool a = true;
                do
                {
                    cin >> elements[i][j];
                    if (cin.fail())
                        cout << "Повторите попытку" << endl;
                    else
                        a = false;
                    cin.clear();
                    cin.ignore(cin.rdbuf()->in_avail());
                } while (a);
            }
        }
        matr[k] = { elements, n, m };
    }


    for (int k = 0; k < 3; k++)
        cout << matr[k] << endl;
    system("pause");

    matrix sum;
    int m1 = 0, m2 = 0;
    cout << "Выберите матрицы для сложения: ";
    bool a3 = true;
    do
    {
        cin >> m1;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a3 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a3);
    bool a4 = true;
    do
    {
        cin >> m2;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a4 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a4);
    if (m1 >= 0 && m1 < k && m2 >= 0 && m2 < k) {
        sum = matr[m1] + matr[m2];
        cout << sum << endl;
    }
    system("pause");

    matr[1]++;
    
    cout << matr[1] << endl;
    matrix matrix;
    m = 3;
    n = 3;
    elements = new double* [n];
    for (int i = 0; i < n; i++)
        elements[i] = new double[m];
    k = 0;
    for (k = 0; k < 1; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Введите элемент [" << i << "][" << j << "] = ";
                bool a = true;
                do
                {
                    cin >> elements[i][j];
                    if (cin.fail())
                        cout << "Повторите попытку" << endl;
                    else
                        a = false;
                    cin.clear();
                    cin.ignore(cin.rdbuf()->in_avail());
                } while (a);
            }
        }
        matrix = { elements, m, n };
    }

    cout << matr[0] << endl;
    cout << matrix << endl;
    if (matr[0] > matrix)
        cout << "Первая матрица больше второй\n";
    else
        cout << "Первая матрица меньше второй или равна ей\n";

    if (matr[0] < matrix)
        cout << "Первая матрица меньше второй\n";
    else
        cout << "Первая матрица больше второй или равна ей\n";

    return 0;
}