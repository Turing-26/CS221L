struct listNode
{
    int pix[3];
    string code;
    listNode *next;
    listNode(int val[], string c)
    {
        for (int i = 0; i < 3; i++)
            pix[i] = val[i];
        code = c;
    }
};

class list
{
    listNode *head;

public:
    list() : head(NULL) {}

    void insert(int val[], string c)
    {
        listNode *newNode = new listNode(val, c);

        if (!head)
            head = newNode;
        else
        {
            listNode *traverse = head;

            while (traverse->next)
                traverse = traverse->next;

            traverse->next = newNode;
        }
    }

    string search(int val[])
    {
        if (!head)
            return '\0';

        listNode *traverse = head;

        while (traverse)
        {
            if (traverse->pix[0] == val[0] && traverse->pix[1] == val[1] && traverse->pix[2] == val[2])
                return traverse->code;
        }

        return '\0';
    }
};

class HashMap
{
    int size;
    list *table;

public:
    HashMap(int s)
    {
        size = s;
        table = new list[size];
    }

    int hashFunc(int val[])
    {
        int res = 0;
        for (int i = 0; i < 3; i++)
        {
            res += val[i] * i;
        }
        return res % size;
    }

    void insert(int val[], string code)
    {
        int index = hashFunc(val);
        table[index].insert(val, code);
    }

    string search(int val[])
    {
        int index = hashFunc(val);
        return table[index].search(val);
    }
};