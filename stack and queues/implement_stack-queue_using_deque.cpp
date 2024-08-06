#include <bits/stdc++.h>

using namespace std;

struct DQueNode
{
    int value;
    DQueNode *next;
    DQueNode *prev;
};

class Deque
{

private:
    DQueNode *head;
    DQueNode *tail;

public:
    Deque()
    {
        head = tail = NULL;
    }
    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    int size()
    {
        if (!isEmpty())
        {
            DQueNode *temp = head;
            int len = 0;
            while (temp != NULL)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    void insert_first(int element)
    {
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    void insert_last(int element)
    {
        DQueNode *temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        if (head == NULL)
        {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else
        {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    void remove_first()
    {
        if (!isEmpty())
        {
            DQueNode *temp = head;
            head = head->next;
            if (head)
                head->prev = NULL;
            delete temp;
            if (head == NULL)
                tail = NULL;
            return;
        }
        cout << "list is empty" << endl;
    }

    void remove_last()
    {
        if (!isEmpty())
        {
            DQueNode *temp = tail;
            tail = tail->prev;
            if (head)
                tail->next = NULL;
            delete temp;
            if (tail == NULL)
                head = NULL;
            return;
        }
        cout << "list is empty" << endl;
    }

    void display()
    {
        if (!isEmpty())
        {
            DQueNode *temp = head;
            while (temp != NULL)
            {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "list is empty" << endl;
    }
};

class Stack : public Deque
{
    void push(int element)
    {
        insert_last(element);
    }
    void pop()
    {
        remove_last();
    }
};

class Queue : public Deque
{
    void enqueue(int element)
    {
        insert_last(element);
    }
    void dequeue()
    {
        remove_first();
    }
};