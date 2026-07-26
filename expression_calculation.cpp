#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int periority(char &symbol)
{
    switch (symbol)
    {
    case '-':
    case '+':
        return 1;
    case '/':
    case '*':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

string exp_to_postfix(string expression)
{
    stack<char> symbols_stack;
    string postfixed = "";

    // cout << "expression size " << expression.size() << endl;

    for (int i = 0; i < expression.size(); i++)
    {
        char current = expression[i];
        // cout << "current char " << current << endl;

        if (current >= '0' && current <= '9')
        {
            postfixed += (current);
            postfixed += ' ';
        }
        else if (current == '+' || current == '-' || current == '/' || current == '*' || current == '^')
        {
            if (!symbols_stack.empty() && periority(current) <= periority(symbols_stack.top()))
            {
                postfixed += symbols_stack.top();
                postfixed += ' ';
                symbols_stack.pop();
            }
            symbols_stack.push(current);
        }
        else if (current == '(')
        {
            symbols_stack.push('(');
        }
        else if (current == ')')
        {
            while (!symbols_stack.empty() && symbols_stack.top() != '(')
            {
                postfixed += symbols_stack.top();
                postfixed += ' ';
                symbols_stack.pop();
            }
            symbols_stack.pop();
        }
    }
    while (!symbols_stack.empty())
    {
        postfixed += symbols_stack.top();
        postfixed += ' ';

        symbols_stack.pop();
    }
    return postfixed;
}

int calc(int num_1, int num_2, char op)
{
    switch (op)
    {
    case '+':
        return num_1 + num_2;
    case '-':
        return num_1 - num_2;
    case '*':
        return num_1 * num_2;
    case '/':
        return num_1 / num_2;
    case '^':
        return pow(num_1, num_2);
    default:
        return -1;
    }
}

int calc_exp(string expression)
{
    string postfix = exp_to_postfix(expression);
    stack<int> operataions;

    string current_num = "";
    for (int i = 0; i < postfix.size(); i++)
    {
        char current_char = postfix[i];
        cout << current_char << endl;
        if (current_char == ' ')
        {
            if (current_num != "")
            {
                operataions.push(stoi(current_num));
                current_num = "";
            }
        }
        else if (current_char >= '0' && current_char <= '9')
        {
            current_num += current_char;
        }
        else if (current_char == '+' || current_char == '-' || current_char == '/' || current_char == '*' || current_char == '^')
        {
            int num_1 = operataions.top();
            operataions.pop();
            int num_2 = operataions.top();
            operataions.pop();
            operataions.push(calc(num_1, num_2, current_char));
        }
    }
    return operataions.top();
}

int main()
{
    // cout << "Enter your expression" << endl;
    string expression;
    cin >> expression;
    // cout << expression;
    cout << calc_exp(expression) << endl;
    cout << exp_to_postfix(expression) << endl;
    return 0;
}
