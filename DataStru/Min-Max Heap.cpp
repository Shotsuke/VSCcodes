#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class minmaxHeap
{
    vector<int> elements;

public:
    minmaxHeap() { elements.push_back(INT_MIN); }
    void insert(int key)
    {
        if (isempty())
        {
            elements.push_back(key);
            return;
        }
        elements.push_back(key);
        pushUp(elements.size() - 1);
    }

    bool inIncreaseLevel(int index)
    {
        int level = (int)log2(index);
        return !(level & 1);
    }
    bool inDecreaseLevel(int index)
    {
        int level = (int)log2(index);
        return (level & 1);
    }

    void pushUp(int index)
    {
        if (index != 1)
        {
            if (inIncreaseLevel(index))
            { // 在递增的层数上
                if (elements[index] < elements[index / 2])
                { // 比起递减层要小，因此比所有递减层的键值小
                    pushUpMin(index);
                }
                else
                { // 比起递减层要大，则应当改变位置到递减层上
                    swap(elements[index], elements[index / 2]);
                    index /= 2;
                    pushUpMax(index);
                }
            }
            else
            {
                if (elements[index] > elements[index / 2])
                {
                    pushUpMax(index);
                }
                else
                {
                    swap(elements[index], elements[index / 2]);
                    index /= 2;
                    pushUpMin(index);
                }
            }
        }
    }
    void pushUpMin(int index)
    {
        while (index / 4 >= 1 && elements[index] < elements[index / 4])
        {
            swap(elements[index], elements[index / 4]);
            index /= 4;
        }
    }
    void pushUpMax(int index)
    {
        while (index / 4 >= 1 && elements[index] > elements[index / 4])
        {
            swap(elements[index], elements[index / 4]);
            index /= 4;
        }
    }

    void pushDown(int index)
    {
        if (inIncreaseLevel(index))
        {
            pushDownMin(index);
        }
        else
        {
            pushDownMax(index);
        }
    }
    void pushDownMin(int index)
    {
        int smallestChild = findSmallestChild(index);
        if (smallestChild != -1 && elements[index] > elements[smallestChild])
        {
            swap(elements[index], elements[smallestChild]);
            pushDownMin(smallestChild);
        }
    }
    void pushDownMax(int index)
    {
        int largestChild = findLargestChild(index);
        if (largestChild != -1 && elements[index] < elements[largestChild])
        {
            swap(elements[index], elements[largestChild]);
            pushDownMax(largestChild);
        }
    }

    int findSmallestChild(int index)
    {
        int leftChild = 4 * index;
        int minChild = -1;
        for (int i = 0; i < 3 && leftChild + i < elements.size(); ++i)
        {
            if (minChild == -1 || elements[leftChild + i] < elements[minChild])
            {
                minChild = leftChild + i;
            }
        }
        return minChild;
    }
    int findLargestChild(int index)
    {
        int leftChild = 4 * index;
        int maxChild = -1;
        for (int i = 0; i < 3 && leftChild + i < elements.size(); ++i)
        {
            if (maxChild == -1 || elements[leftChild + i] > elements[maxChild])
            {
                maxChild = leftChild + i;
            }
        }
        return maxChild;
    }

    bool isempty() { return elements.size() == 1; }

    int getmin()
    {
        if (!isempty())
            return elements[1];
        else
        {
            return elements[0];
        }
    }
    int getmax()
    {
        switch (elements.size())
        {
        case 1:
            return elements[0];
            break;
        case 2:
            return elements[1];
            break;
        case 3:
            return elements[2];
            break;
        case 4:
            return max(elements[2], elements[3]);
            break;
        }
    }
    int findMaxIndex()
    {
        switch (elements.size())
        {
        case 1:
            return -1;
            break;
        case 2:
            return 1;
            break;
        case 3:
            return 2;
            break;
        case 4:
            if (elements[2] > elements[3])
                return 2;
            else
                return 3;
            break;
        }
    }

    void deleteMin()
    {
        if (!isempty())
        {
            elements[1] = elements.back();
            elements.pop_back();
            pushDownMin(1);
        }
    }
    void deleteMax()
    {
        if (!isempty())
        {
            int maxIndex = findMaxIndex();
            elements[maxIndex] = elements.back();
            elements.pop_back();
            pushDownMax(maxIndex);
        }
    }
    void print()
    {
        for (int i = 1; i < elements.size(); ++i)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};
signed main()
{
    minmaxHeap heap;
    heap.insert(1);
    heap.insert(9);
    heap.insert(3);
    heap.insert(4);
    heap.insert(8);
    heap.insert(10);
    heap.insert(2);
    heap.insert(5);
    heap.print();
    return 0;
}