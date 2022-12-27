#include <iostream>
#include <string>
using namespace std;

template <class T>
struct listNode
{
    int pix[3];
    T code;
    listNode *next;
    listNode(int val[], T c)
    {
        for (int i = 0; i < 3; i++)
            pix[i] = val[i];
        code = c;
    }
};

template <class T>

class list
{
    listNode<T> *head;

public:
    list() : head(NULL) {}

    void insert(int val[], T c)
    {
        listNode<T> *newNode = new listNode<T>(val, c);

        if (!head)
            head = newNode;
        else
        {
            listNode<T> *traverse = head;

            while (traverse->next)
            {
                if (traverse->pix[0] == val[0] && traverse->pix[1] == val[1] && traverse->pix[2] == val[2])
                {
                    traverse->code = c;
                    return;
                }
                traverse = traverse->next;
            }

            traverse->next = newNode;
        }
    }

    T *search(int val[])
    {
        if (!head)
            return NULL;

        listNode<T> *traverse = head;

        while (traverse)
        {
            if (traverse->pix[0] == val[0] && traverse->pix[1] == val[1] && traverse->pix[2] == val[2])
                return &(traverse->code);
        }

        return NULL;
    }
};

template <class T>

class HashMap
{
    int size;
    list<T> *table;

public:
    HashMap(int s = 1511)
    {
        size = s;
        table = new list<T>[size];
    }

    int hashFunc(int val[])
    {
        int res = 0;
        for (int i = 0; i < 3; i++)
        {
            res += val[i] * (i + 1);
        }
        return res % size;
    }

    void insert(int val[], T code)
    {
        int index = hashFunc(val);
        table[index].insert(val, code);
    }

    T *search(int val[])
    {
        int index = hashFunc(val);
        T *temp = table[index].search(val);
        return temp;
    }
};