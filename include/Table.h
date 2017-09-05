#ifndef ORDERED_TABLE_TABLE_H
#define ORDERED_TABLE_TABLE_H


#include <iostream>

template <class T, class D>
class Table
{
protected:
    D* chart;
    T* key;
    int count;
    int size;
public:
    explicit Table(int);
    void Add(D val, T k);
    void Del(T k);
    D& operator[](T k);
    D operator=(Table&);
    int getlen();
    void getall();
};

template <class T, class D>
Table<T, D>::Table(int s)
{
    size = s;
    count = 0;
    chart = new D[size];
    key = new T[size];
}

template <class T, class D>
void Table<T, D>::Add(D val, T k)
{
    if (count >= size) throw 1;
    count++;
    chart[count - 1] = val;
    key[count - 1] = k;
}

template <class T, class D>
void Table<T, D>::Del(T k)
{
    int tmp = 0;
    while (key[tmp] != k && tmp<=count)
        tmp++;
    for (int i = tmp; i < count-1; i++)
    {
        chart[i] = chart[i + 1];
        key[i] = key[i + 1];
    }
    count--;
}

template <class T, class D>
D& Table<T, D>::operator[](T k)
{
    for (int i = 0; i < size; i++)
        if (key[i] == k)
            return chart[i];
    return chart[0];
}

template <class T, class D>
D Table<T, D>::operator=(Table& A)
{
    count = A.count;
    size = A.size;
    chart = new D[size];
    key = new T[size];
    for (int i = 0; i < count; i++)
    {
        chart[i] = A.chart[i];
        key[i] = A.key[i];
    }
    return *this;
}

template <class T, class D>
int Table<T, D>::getlen()
{
    return count;
}

template <class T, class D>
void Table<T, D>::getall()
{
    for (int i = 0; i < count; i++)
        std::cout << chart[i]<<" ";
    std::cout << std::endl;
}


#endif //ORDERED_TABLE_TABLE_H
