#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
class MyArray
{
private:
    T *data; //回收(區域自動變數)
    int n;   //回收(區域自動變數)
    int c;   //回收(區域自動變數)
    T guard;

public:
    // constructor
    MyArray(int m = 10)
    {
        c = m;
        n = 0;
        data = new T[c]; //new出來的要自己刪掉
    }
    MyArray(MyArray &other)
    {
        c = other.c;
        n = other.n;
        data = new int[c];
        for (int i = 0; i < n; i++)
        {
            data[i] = other.data[i];
        }
    }
    MyArray(const T *p, int m)
    {
        n = m;
        c = n + 6;
        data a = new int[c];
        for (int i = 0; i < n; i++)
        {
            data[i] = p[i];
        }
    }
    ~MyArray()
    {
        delete[] data;
    }
    T &operator[](int i)
    {
        if (i < 0 || i > n)
        {
            cout << "out of bound ..." << endl;
            return guard;
        }
        return data[i];
    }
    void push(const T &e)
    {
        if (n >= c) // overflow
        {
            // overflow strategy
            // doubling
            T *temp = new T[c * 2];
            for (int i = 0; i < n; i++)
            {
                temp[i] = data[i];
            }
            c *= 2;
            delete[] data;
            data = temp;
        }
        data[n] = e;
        n++;
    }
    // compare ops

    // array ops

    // int size()
    int size()
    {
        return n;
    }
    void show
    {
        cout << "(n,c):<" << n << "," << c << ")" << endl;
        cout << "[";
        for (int i = 0; i < n; i++)
        {
            cout << setw(5) << data[i];
            if (i != n - 1)
            {
                cout << ",";
            }
        }
        cout << "]" << endl;
    }
};

int main()
{
    int ary0[7] = {1, 3, 5, 7, 2, 4, 6};
    MyArray<int> ary1, ary2(8), ary3(ary0, 7);
    ary1.show();
    ary2.show();
    ary3.show();

    ary3[3] = 22;
    ary3.show();
    cout << ary3[2] << endl;

    ary1.push(11);
    ary1.push(22);
    ary1.push(33);
    ary1.show();
    return 0;
}