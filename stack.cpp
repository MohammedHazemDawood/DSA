#include <iostream>
using namespace std;

template <class t>
class stack
{
private:
    struct node
    {
        t value;
        node *next;
    };

public:
    node *top = nullptr;

    void push(t& item)
    {
        node *n_node = new node;
        n_node->next = top;
        n_node->value = item;
        top = n_node;
    }
    void pop()
    {
        if (top == nullptr)
            return;
        node *temp = top;
        top = temp->next;
        delete temp;
    }
    bool is_empty()
    {
        return top == nullptr;
    }
    int size()
    {
        int size = 0;
        node *it = top;
        while (it != nullptr)
        {
            size++;
            it = it->next;
        }
        return size;
    }
};

int main()
{
    stack<int> my_stack;
    for (int i = 0; i < 10; i++)
    {
        my_stack.push(i);
    }
    cout << my_stack.size() << endl;
    my_stack.pop();
    cout << my_stack.size() << endl;
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    cout << my_stack.is_empty() << endl;
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    my_stack.pop();
    cout << my_stack.is_empty() << endl;
    return 0;
}
