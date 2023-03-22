// TODO: finish the following class, and override the corresponding operator
#include <iostream>
#include <vector>
using namespace std;
class MyArray
{
private:
    int *arr;
    int size;

public:
    class Iterator
    {
    public:
        int *pos;
        int *head;
        int *tail;

        Iterator operator++()
        {
            pos++;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator iter1 = *this;
            pos++;
            return iter1;
        }

        Iterator operator--()
        {
            pos--;
            return *this;
        }
        Iterator operator--(int)
        {
            Iterator iter1 = *this;
            pos--;
            return iter1;
        }

        bool operator==(Iterator para)
        {
            if (this->pos == para.pos)
                return true;
            else
                return false;
        }

        bool operator!=(Iterator para)
        {
            if (this->pos != para.pos)
                return true;
            else
                return false;
        }

        Iterator operator+(int len)
        {
            pos += len;
            return *this;
        }

        Iterator operator-(int len)
        {
            pos -= len;
            return *this;
        }

        bool get(int &value) const
        {
            if (pos == nullptr || pos < head || pos >= tail || head == tail)
            {
                return false;
            }
            value = *pos;
            return true;
        }

        bool put(int value)
        {
            if (pos == nullptr || pos < head || pos >= tail || head == tail)
            {
                return false;
            }
            *pos = value;
            return true;
        }

        Iterator(int *arr, int size, char situ)
        {
            head = arr;
            tail = arr + size;
            // Tail targets at end(). It is overflow.
            if (situ == 'b')
                pos = head;
            if (situ == 'e')
                pos = tail;
        }

        ~Iterator()
        {
        }
    };

private:
    vector<Iterator *> MyIters;

public:
    MyArray(int sz)
    {
        arr = new int[sz];
        size = sz;
    }
    ~MyArray()
    {
        for (auto iter : MyIters)
        {
            iter->pos = nullptr;
        }
        delete[] arr;
        arr = nullptr;
    }
    Iterator begin()
    {
        Iterator iter(arr, size, 'b');
        MyIters.push_back(&iter);
        return iter;
    }
    Iterator end()
    {
        Iterator iter(arr, size, 'e');
        MyIters.push_back(&iter);
        return iter;
    }
};

int main()
{
    MyArray x(1);
    auto iter = x.begin();
    iter.put(99);
    int z = 0;
    x.~MyArray();
    iter.get(z);
    cout << z;
    return 0;
}