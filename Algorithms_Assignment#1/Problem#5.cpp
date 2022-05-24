// C++ code for searching and deleting element in skip list

#include <bits/stdc++.h>
using namespace std;

// Class to implement node
class Node
{
public:
    int key;

    // Array to hold pointers to node of different level
    Node **forward;
    Node(int, int);
};

Node::Node(int key, int level)
{
    this->key = key;

    // Allocate memory to forward
    forward = new Node *[level + 1];

    // Fill forward array with 0(NULL)
    memset(forward, 0, sizeof(Node *) * (level + 1));
};

// Class for Skip list
class SkipList
{
    int MAXLVL;float P;int level;Node *header;

public:
    SkipList(int, float);
    int randomLevel();
    Node *createNode(int, int);
    void insert(int);
    void search(int);
    void getlayers();
    void printlayer(int);
};


SkipList::SkipList(int MAXLVL, float P)
{
    this->MAXLVL = MAXLVL;
    this->P = P;
    level = 0;
    header = new Node(-1, MAXLVL);
};

// create random level for node
int SkipList::randomLevel()
{
    float r = (float)rand() / RAND_MAX;
    int lvl = 0;
    while (r < P && lvl < MAXLVL)
    {
        lvl++;
        r = (float)rand() / RAND_MAX;
    }
    return lvl;
};

Node *SkipList::createNode(int key, int level)
{
    Node *n = new Node(key, level);
    return n;
};

void SkipList::insert(int key)
{
    Node *current = header;
    Node *update[MAXLVL + 1];
    memset(update, 0, sizeof(Node *) * (MAXLVL + 1));
    for (int i = level; i >= 0; i--)
    {
        while (current->forward[i] != NULL &&
               current->forward[i]->key < key)
            current = current->forward[i];
        update[i] = current;
    }
    current = current->forward[0];
    if (current == NULL || current->key != key)
    {         
        int rlevel = randomLevel();
        if (rlevel > level)
        {
            for (int i = level + 1; i < rlevel + 1; i++)
                update[i] = header;
            level = rlevel;
        }
        Node *n = createNode(key, rlevel);
        for (int i = 0; i <= rlevel; i++)
        {
            n->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = n;
        }
        cout << "Successfully Inserted key " << key << "\n";
    }
};

void SkipList::search(int key)
{
    int steps = 0;
    Node *current = header; int i;
    for ( i = level; i >= 0; i--)
    {
        while (current->forward[i] && current->forward[i]->key < key)
        {
            steps++;
            current = current->forward[i];
        }
    }
    current = current->forward[0];
    if (current and current->key == key)
        cout << "Found key: " << key <<",  Number of steps: "<<steps<< "\n";
};

void SkipList::getlayers()
{
    cout <<"Number of Layers: "<< level << endl;
};

void SkipList::printlayer(int layer)
{
    Node *node = header->forward[layer];
    cout << "Layer "<<layer<< " Data: ";
    while (node != NULL)
    {
        cout << node->key << " ";
        node = node->forward[layer];
    }
};

int main()
{
    srand((unsigned)time(0));

    SkipList lst(3, 0.5);

    lst.insert(3);
    lst.insert(6);
    lst.insert(7);
    lst.insert(9);
    lst.insert(12);
    lst.insert(19);
    lst.insert(17);
    lst.insert(26);
    lst.insert(21);
    lst.insert(25);

    lst.search(19);
    lst.getlayers();
    lst.printlayer(1);

    return 0;
}
