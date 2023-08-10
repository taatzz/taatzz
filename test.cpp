#include <iostream>

using namespace std;

class Hash
{
private:
    struct node
    {
        int id;
        string name;
        string dept;
        node* next;

        node() : id(-1), name(""), dept(""), next(NULL){}
        node(int i, string n, string d) : id(i), name(n), dept(d){}
        ~node()
        { 
            //cout << "1" << endl; 
        }
    };  
    static const int maxsize = 10;
    node* HashTable[maxsize];

public:
    Hash();
    ~Hash();
    void AddNode(int, string, string);// 添加结点
    int hashfun(int);// 哈希函数
    void HashPrint();// 打印所有的结点信息
    void FindNode(int); // 查找结点
};

Hash::Hash()
{
    for(int i = 0; i < maxsize; i++)
    {
        HashTable[i] = new node();
        /*
        HashTable[i]->id = -1;
        HashTable[i]->name = "empty";
        HashTable[i]->dept = "empty";
        HashTable[i]->next = nullptr;
        */
    }
}

Hash::~Hash()
{
    for(int i = 0; i < maxsize; i++)
    {
        if(HashTable[i]->id != -1)
        {
            node* tail = HashTable[i];
            while(tail)
            {
                node* tmp = tail;
                tail = tail->next;
                tmp->next = NULL;
                delete tmp;
            }
        }
    }
}

void Hash::AddNode(int i, string n, string d)
{
    int index = hashfun(i);
    if(HashTable[index]->id == -1)
    {
        HashTable[index]->id = i;
        HashTable[index]->name = n;
        HashTable[index]->dept = d;
    }
    else
    {
        node* newnode = new node(i, n, d);
        newnode->next = NULL;
        node* tail = HashTable[index];
        while(tail->next)
        {
            tail = tail->next;
        }
        tail->next = newnode;
    }
}

int Hash::hashfun(int x)
{
    return x % maxsize;
}

void Hash::HashPrint()
{
    for(int i = 0; i < maxsize; i++)
    {
        if(HashTable[i]->id == -1)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << i + 1 << ":  ";
            node* tail = HashTable[i];
            while(tail)
            {
                cout << "id: " << tail->id << " ";
                cout << "name: " << tail->name << " ";
                cout << "dept: " << tail->dept << " " ;
                tail = tail->next;
            }
            cout << endl;
        }
    }
}

void Hash::FindNode(int x)
{
    int index = hashfun(x);
    node* cur;
    if(HashTable[index]->id != -1)
        cur =  HashTable[index];
    else
    {
        cout << "sorry don't have tihs id" << endl;
        return;
    }

    while(cur->id != x && cur->next != NULL)
    {   
        cur = cur->next;
    }
    if(cur->id == x)
    {
        cout << "id: " << cur->id <<" ";
        cout << "name: " << cur->name << " ";
        cout << "dept: " << cur->dept << " " << endl;
    }
    else
    {
        cout << "sorry don't have tihs id" << endl;
    }
}


int main(int argc, char* argv[])
{
    Hash h;

    h.AddNode(1, "Tom", "Locha");
    h.AddNode(2, "Jack", "Iced Mocha");
    h.AddNode(3, "Jery", "Tea");
    h.AddNode(13, "Blue", "Apple");

    h.FindNode(11);
    //h.HashPrint();


    return 0;
}