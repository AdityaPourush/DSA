#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head = nullptr;

    void merge(LinkedList &l1, LinkedList &l2)
    {
        Node *dummyhead = new Node(-1);
        Node *temp = dummyhead;
        Node *itr1 = l1.head;
        Node *itr2 = l2.head;

        while (itr1 != nullptr && itr2 != nullptr)
        {
            if (itr1->data <= itr2->data)
            {
                temp->next = itr1;
                itr1 = itr1->next;
            }
            else
            {
                temp->next = itr2;
                itr2 = itr2->next;
            }
            temp=temp->next;
        }

        while (itr1 != nullptr)
        {
            temp->next = itr1;
            itr1 = itr1->next;
        }
        while (itr2 != nullptr)
        {
            temp->next = itr2;
            itr2 = itr2->next;
        }

        l1.head = dummyhead->next;
    }

    void print_list()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList L1;
    LinkedList L2;
    int n;
    cin >> n;
    vector<Node *> nodes1(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        nodes1[i] = new Node(k);
    }
    L1.head = nodes1[0];
    for (int i = 0; i < n - 1; i++)
    {
        nodes1[i]->next = nodes1[i + 1];
    }

    int m;
    cin >> m;
    vector<Node *> nodes2(m);
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        nodes2[i] = new Node(k);
    }
    L2.head = nodes2[0];
    for (int i = 0; i < m - 1; i++)
    {
        nodes2[i]->next = nodes2[i + 1];
    }

    L1.merge(L1, L2);
    L1.print_list();

    return 0;
}