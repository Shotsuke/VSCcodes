#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
};

struct linklist
{
    Node *head;
    Node *tail;
};

void tailaddone(linklist *list, int val)
{
    Node *node = (Node *)malloc(sizeof(Node *));
    if (node == nullptr)
    {
        printf("Error: malloc failed.\n");
        return;
    }
    node->value = val;

    if (list->head == nullptr)
    {
        list->head = node;
        list->tail = node;
        node->next = node;
    }
    else
    {
        list->tail->next = node;
        list->tail = node;
        node->next = list->head;
    }
    return;
}

void headaddone(linklist *list, int val)
{
    Node *node = (Node *)malloc(sizeof(Node *));
    if (node == nullptr)
    {
        printf("Error: malloc failed.\n");
        return;
    }
    node->value = val;

    if (list->head == nullptr)
    {
        list->head = node;
        list->tail = node;
        node->next = node;
    }
    else
    {
        node->next = list->head;
        list->head = node;
        list->tail->next = node;
    }
    return;
}

void deleteone(linklist *list, int val)
{
    if (list->head == nullptr)
    {
        printf("An empty linklist.\n");
        return;
    }
    Node *cur = list->head;
    if (val == cur->value)
    {
        if (list->head == list->tail)
        {
            list->head = nullptr;
            list->tail = nullptr;
            free(cur);
        }
        else
        {
            list->tail->next = cur->next;
            list->head = cur->next;
            free(cur);
        }
    }
    else
    {
        do
        {
            if (cur->next->value == val)
            {
                Node *temp = cur->next;
                cur->next = temp->next;
                free(temp);
                return;
            }
            else
            {
                cur = cur->next;
            }
        } while (cur != list->head);
        printf("Not find this required value to delete.\n");
    }
    return;
}

void printlinklist(const linklist *list)
{
    Node *now = list->head;
    if (now == nullptr)
    {
        printf("The list to be printed is empty.\n");
        return;
    }
    do
    {
        printf("%d ", now->value);
        now = now->next;
    } while (now != list->head);
    return;
}

signed main()
{
    linklist sol = {nullptr, nullptr};
    for (int i = 0; i < 1; i++)
    {
        headaddone(&sol, i);
    }
    headaddone(&sol, -1);
    deleteone(&sol, -1);
    deleteone(&sol, 2);
    printlinklist(&sol);
    return 0;
}