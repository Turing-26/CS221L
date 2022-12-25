#include <iostream>
#include <string>
#include "queues.h"
#include "hashMap.h"
using namespace std;

template <class T>
struct TreeNode
{
    T data[3];
    unsigned int freq;
    int *arrloc;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T val[], int f)
    {
        left = right = NULL;
        for (int i = 0; i < 3; i++)
            data[i] = val[i];
        freq = f;
    }
    TreeNode(int f)
    {
        left = right = NULL;
        freq = f;
        for (int i = 0; i < 3; i++)
            data[i] = 0;
    }
};

template <class T>
class HuffmanTree
{
    PriorityQueue<TreeNode<int> *> pq;
    TreeNode<int> *root;
    int len, width;

    void makeHuffcode(TreeNode<int> *node, string code)
    {
        if (node)
        {
            makeHuffcode(node->left, code + '0');
            if (node->left == NULL && node->right == NULL)
                cout << node->freq << " " << code << endl;
            makeHuffcode(node->right, code + '1');
        }
    }

public:
    HuffmanTree() : root(NULL)
    {
    }

    void insert(int val[], int freq)
    {
        TreeNode<int> *node = new TreeNode<int>(val, freq);
        pq.enqueue(node);
    }

    void buildTree()
    {
        TreeNode<int> *node, *min1, *min2;
        int size = pq.size();
        // cout << size;

        while (pq.size() - 1 != 1)
        {
            min1 = pq.getMin();
            pq.dequeue();
            min2 = pq.getMin();
            pq.dequeue();
            cout << min1->freq << " " << min2->freq << endl;

            node = new TreeNode<int>(min1->freq + min2->freq);
            node->left = min1;
            node->right = min2;

            cout << node->freq << endl;
            pq.enqueue(node);
        }

        min1 = pq.getMin();
        pq.dequeue();
        min2 = pq.getMin();
        // pq.dequeue();
        cout << min1->freq << " " << min2->freq << " " << endl;
        node = new TreeNode<int>(min1->freq + pq.getMin()->freq);
        node->left = min1;
        node->right = min2;
        root = node;
        cout << root->freq << endl;
    }

    void makeHuffcode()
    {
        makeHuffcode(root, "");
    }
};

int main()
{
    HuffmanTree<int> hf;

    int arr[3] = {3, 120, 4};
    hf.insert(arr, 3);

    for (int i = 0; i < 3; i++)
        arr[i] = 20;
    hf.insert(arr, 2);

    for (int i = 0; i < 3; i++)
        arr[i] = 55;
    hf.insert(arr, 6);

    for (int i = 0; i < 3; i++)
        arr[i] = 4;
    hf.insert(arr, 5);

    for (int i = 0; i < 3; i++)
        arr[i] = 66;
    hf.insert(arr, 1);

    for (int i = 0; i < 3; i++)
        arr[i] = 156;
    hf.insert(arr, 7);

    for (int i = 0; i < 3; i++)
        arr[i] = 99;
    hf.insert(arr, 4);
    hf.buildTree();
    cout << "--------------------------------------------\n";
    hf.makeHuffcode();
}