#include <cassert>
#include <iostream>
using namespace std;

template <class type>
class LinkedList
{
private:
    struct node
    {
        type value;
        node *next;
    };
    node *head; //[0]
public:
    LinkedList()
    {
        head = nullptr;
    }
    void add(type item)
    {
        node *tmp = new node;
        tmp->value = item;
        tmp->next = head;

        head = tmp;
    }
    void add(int index, type item)
    {
        int sz = size();
        if (index > sz)
            return;
        if (index == 0)
        {
            add(item);
            return;
        }

        node *it = head;
        for (int i = 0; i < index - 1; i++)
        {
            it = it->next;
        }
        node *tmp = new node;
        tmp->value = item;
        tmp->next = it->next;
        it->next = tmp;
    }
    type get(int index)
    {
        if (index > size() - 1)
            return NULL;
        node *it = head;
        for (int i = 0; i < index; i++)
        {
            it = it->next;
        }
        return it->value;
    }
    type remove(int index)
    {
        if (index > size() - 1)
            return NULL;

        if (index == 0)
        {
            node *tmp = head;
            head = tmp->next;
            type value = tmp->value;
            delete tmp;
            return value;
        }

        node *it = head;
        for (int i = 0; i < index - 1; i++)
        {
            it = it->next;
        }
        node *wanted = it->next;
        it->next = wanted->next;

        type val = wanted->value;

        delete wanted;

        return val;
    }
    type dropLast()
    {
        node *prev = head;
        node *current = head->next;

        while (current->next != nullptr)
        {
            current = current->next;
            prev = prev->next;
        }
        type val = current->value;
        delete current;
        prev->next = nullptr;
        return val;
    }
    void reverse()
    {
        if (empty())
            return;
        node *prev = nullptr;
        node *current = head;
        while (current != nullptr)
        {
            node *tmp = current->next;
            current->next = prev;
            prev = current;
            current = tmp;
        }
        head = prev;
    }
    // bool search(type target){
    //     if(empty()) retutn NULL;
    //     node *it = head;
    //     type result = NULL;
    //     while(it != nullptr && result != target){
    //         if(it->value == target) result = 
    //     }
    // }
    bool empty(){
        return head == nullptr;
    }
    int size()
    {
        node *it = head;
        int sz = 0;
        while (it != nullptr)
        {
            sz++;
            it = it->next;
        }
        return sz;
    }
    ~LinkedList()
    {
        while (size() > 0)
        {
            remove(0);
        }
    }
};

int main()
{
    LinkedList<int> list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << "[ ";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.get(i) << " ,";
    }
    cout << " ]" << endl;

    list.reverse();


    cout << "[ ";
    for (int i = 0; i < list.size(); i++)
    {
        cout << list.get(i) << " ,";
    }
    cout << " ]" << endl;

    cout << "last " << list.dropLast() << endl;

    return 0;
}
