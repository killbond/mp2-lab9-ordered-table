#ifndef ORDERED_TABLE_ORDERED_TABLE_H
#define ORDERED_TABLE_ORDERED_TABLE_H


#include "Table.h"

template <class T, class D>
class OrderedTable :public Table<T, D>
{
public:
    explicit OrderedTable(int);
    void add(D,T);
    void del(T);
    D& operator[](T);
};

template <class T, class D>
OrderedTable<T, D>::OrderedTable(int s) :Table<T, D>(s) {}


template <class T, class D>
void OrderedTable<T, D>::add(D val, T k)
{
    if (this->count == 0)
    {
        this->chart[0] = val;
        this->key[0] = k;
        this->count++;
        return;
    }

    if (this->key[0] > k)
    {
        for (int i = this->count; i > 0; i--)
        {
            this->chart[i] = this->chart[i - 1];
            this->key[i] = this->key[i - 1];
        }
        this->chart[0] = val;
        this->key[0] = k;
        this->count++;
        return;
    }

    if (this->key[this->count-1] < k)
    {
        this->chart[this->count+1] = val;
        this->key[this->count+1] = k;
        this->count++;
        return;
    }
    int left = 0;
    int right = this->count;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if ((this->key[mid] == k) || (this->key[mid] < k && this->key[mid+1]>k ))
        {
            for (int i = this->count; i > mid; i--)
            {
                this->chart[i] = this->chart[i - 1];
                this->key[i] = this->key[i - 1];
            }
            this->chart[mid+1] = val;
            this->key[mid+1] = k;
            this->count++;
            return;
        }
        if (k < this->key[mid])
        {
            right = mid ;
        }
        else
        {
            left = mid + 1;
        }
    }
}


template <class T, class D>
void OrderedTable<T, D>::del(T k)
{
    int left = 0;
    int right = this->count;
    int mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if ((this->key[mid] == k) || (this->key[mid] < k && this->key[mid + 1]>k))
        {
            for (int i = mid; i < this->count; i++)
            {
                this->chart[i] = this->chart[i + 1];
                this->key[i] = this->key[i + 1];
            }
            return;
        }
        if (k < this->key[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
}


template <class T, class D>
D& OrderedTable<T, D>::operator[](T k)
{
    int left = 0, right = this->count, mid;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (this->key[mid] == k)
        {
            return this->chart[mid];
        }
        if (k < this->key[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

}


#endif //ORDERED_TABLE_ORDERED_TABLE_H
