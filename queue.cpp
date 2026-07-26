#include <iostream>
using namespace std;

// circular approach
// fixed size
template <class t>
class CircularQueue
{
private:
    int front = -1;
    int rear = -1;

    int count = 0;

    t *array = nullptr;
    int size;

public:
    CircularQueue(int k)
    {
        array = new t[k];
        size = k;
    }

    bool enQueue(t value)
    {
        if (isFull())
            return false;
        if (isEmpty())
            front = 0;
        rear = (rear + 1) % size;
        array[rear] = value;
        count++;
        return true;
    }

    bool deQueue()
    {
        if (isEmpty())
            return false;
        front = (front + 1) % size;
        count--;
        return true;
    }

    t Front()
    {
        return array[front];
    }

    t Rear()
    {
        return array[rear];
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == size;
    }
};

template <class r>
class LinkedQueue
{
private:
    struct node
    {
        node *next = nullptr;
        r value;
    };
    node *front = nullptr;
    node *rear = nullptr;

public:
    void enque(r item)
    {
        node *tmp = new node;
        tmp->value = item;

        if (empty())
        {
            rear = front = tmp;
            return;
        }

        rear->next = tmp;
        rear = tmp;
    }

    bool deque()
    {
        if (empty())
            return false;
        node *tmp = front;
        front = tmp->next;
        delete tmp;
    }
    bool empty()
    {
        return front == nullptr;
    }

    ~LinkedQueue()
    {
        while (!empty())
            deque();
    }
};

int main()
{
    CircularQueue<string> circularQueue(10);
    return 0;
}
