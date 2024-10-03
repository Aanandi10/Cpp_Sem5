#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Expr class definition
class Expr 
{
    string expression;  // stores the input expression

    // Function to evaluate based on operator precedence
    int applyOp(char op, int a, int b) 
  {
        switch (op)
	{
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return 0;
   }

    // Function to determine precedence of operators
    int precedence(char op) 
    {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

public:
    // Constructor to store the expression
    Expr(const char* expr) : expression(expr) {}

    // Function to evaluate the expression
    int eval()
    {
        stack<int> values;  // Stack to store numbers
        stack<char> ops;    // Stack to store operators

        for (size_t i = 0; i < expression.length(); i++)
	{
            // If current character is a digit, push it to values stack
            if (isdigit(expression[i]))
	    {
                values.push(expression[i] - '0');
            }
            // If current character is an operator
            else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
	    {
                // While top of 'ops' has the same or greater precedence, apply operator to values
                while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) 
		{
                    int val2 = values.top();
                    values.pop();
                    int val1 = values.top();
                    values.pop();
                    char op = ops.top();
                    ops.pop();
                    values.push(applyOp(op, val1, val2));
                }
                // Push current operator to 'ops'
                ops.push(expression[i]);
            }
        }

        // Apply remaining operators to remaining values
        while (!ops.empty()) 
	{
            int val2 = values.top();
            values.pop();
            int val1 = values.top();
            values.pop();
            char op = ops.top();
            ops.pop();
            values.push(applyOp(op, val1, val2));
        }

        // Top of 'values' contains the result of the expression
        return values.top();
    }

    // Function to print the expression
    void print()
    {
        cout << "Expression: " << expression << endl;
    }
};

int main() 
{
    Expr x("8/4+3*4-3");
    
    cout << "x = " << x.eval() << "\n";
    x.print();

    return 0;
}
