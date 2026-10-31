#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

class stack
{
private:
    int arr[100];
    int top;

public:
    stack()
    {
        top = -1;
    }

    void push(int val)
    {
        top++;
        arr[top] = val;
    }

    int pop()
    {
        int p = arr[top];
        top--;
        return (p);
    }
};

int evaluate(char x, int op1, int op2)
{
    if (x == '+')
        return (op1 + op2);
    if (x == '-')
        return (op1 - op2);
    if (x == '*')
        return (op1 * op2);
    if (x == '/')
        return (op1 / op2);
    if (x == '%')
        return (op1 % op2);
    if (x == '$')
        return (pow(op1, op2));

    return 0;
}

int main(void)
{
    stack s;
    char x;
    int op1, op2, val;

    cout << "\nEnter postfix expression: ";

    while ((x = getchar()) != '\n')
    {
        if (isdigit(x))
        {
            s.push(x - '0');
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();

            val = evaluate(x, op1, op2);

            s.push(val);
        }
    }

    val = s.pop();
    cout << "\nAnswer = " << val;

    return 0;
}

/*
PS D:\Atharva_Dighe> cd "d:\Atharva_Dighe\" ; if ($?) { g++ Postfix_expression.cpp -o Postfix_expression } ; if ($?) { .\Postfix_expression }

Enter postfix expression: 546+*493/+*

Answer = 350
PS D:\Atharva_Dighe> 
*/