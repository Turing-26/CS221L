#include <list>
template <typename V>

struct ListNode
{
    V value[3];
    ListNode *next;
    ListNode()
    {
        next = NULL;
    }
    ListNode(V v)
    {
        value = v;
        next = NULL;
    }
};

template <typename V>
class HashMap;

template <typename V>

class List
{
    ListNode<V> *head;

public:
    List() : head(NULL) {}

    void insert(ListNode<V> *newListNode)
    {
        if (!head)
            head = newListNode;
        else
        {
            ListNode<V> *traverse = head;

            while (traverse->next)
            {
                traverse = traverse->next;
            }

            traverse->next = newListNode;
        }
    }

    bool search(V val[])
    {
        ListNode<V> *traverse = head;

        while (traverse)
        {
            if (val[0] == traverse->value[0] && val[1] == traverse->value[1] && val[2] == traverse->value[2])
                return true;

            traverse = traverse->next;
        }

        return false;
    }

    void deleteListNode(V val[])
    {
        ListNode<V> *traverse = head, *prev = NULL;

        while (traverse)
        {
            if (val[0] == traverse->value[0] && val[1] == traverse->value[1] && val[2] == traverse->value[2] && prev == NULL)
            {
                head = NULL;
                break;
            }
            else if (val[0] == traverse->value[0] && val[1] == traverse->value[1] && val[2] == traverse->value[2])
            {
                prev->next = traverse->next;
                break;
            }

            prev = traverse;
            traverse = traverse->next;
        }
    }
};

template <typename V>

class HashMap
{
    int size;
    List<V> *table;

public:
    HashMap(int a)
    {
        size = a;
        table = new List<V>[size];
    }

    int hashFunc(int k)
    {
        return k % size;
    }

    void insert(V value)
    {
        ListNode<V> *newListNode = new ListNode<V>(value);
        int index = hashFunc(value);
        table[index].insert(newListNode);
    }

    bool search(int val)
    {
        int index = hashFunc(val);
        return table[index].search(val);
    }

    void deleteEntry(int val)
    {
        int index = hashFunc(val);
        table[index].deleteListNode(val);
    }
};