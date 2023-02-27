#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int value;
    struct Node *next;

    // Node(int val) {
    //    value = val;
    //     next = nullptr;
    // }
};

struct LinkedList
{
    Node *head, *tail;
};

// 只需要完成此函数
// 可以定义其它函数作为这个函数的子过程，但是不需要自行定义main函数
// 不可以另外定义数组/STL容器

void insertSorted(LinkedList &list, vector<int> &vec)
{
    Node *cur = (Node *)malloc(sizeof(Node *));
    cur = list.head;
    bool flag;
    for (int i = 0; i < vec.size(); i++)
    {
        Node *insertone = (Node *)malloc(sizeof(Node *));
        insertone->value = vec[i];
        insertone->next = nullptr;

        if (list.head == nullptr)
        { // An empty linkedlist.
            list.head = insertone;
            list.tail = insertone;
        }

        else if (vec[i] <= list.head->value)
        { // The new one is not bigger than the first element.
            insertone->next = list.head;
            list.head = insertone;
        }

        else if (cur == list.tail)
        { // The new one is bigger than the last element.
            cur->next = insertone;
            list.tail = insertone;
        }
        else
        {
            flag = false;
            while (vec[i] > cur->next->value)
            { // Find the proper position.
                cur = cur->next;
                if (cur == list.tail)
                {
                    cur->next = insertone;
                    list.tail = insertone;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            { // Insert it.
                insertone->next = cur->next;
                cur->next = insertone;
            }
        }
        cur = insertone;
    }
    return;
}
signed main()
{
    Node *a = (Node *)malloc(sizeof(Node *));
    Node *b = (Node *)malloc(sizeof(Node *));
    Node *c = (Node *)malloc(sizeof(Node *));
    Node *d = (Node *)malloc(sizeof(Node *));
    LinkedList ll;
    a->value = 2;
    a->next = b;
    b->value = 5;
    b->next = c;
    c->value = 7;
    c->next = d;
    d->value = 8;
    d->next = nullptr;
    ll.head = a;
    ll.tail = d;
    vector<int> x = {1, 3, 4};
    insertSorted(ll, x);
    return 0;
}