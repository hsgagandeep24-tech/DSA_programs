/*
Algorithm for Infix to Postfix Conversion
1. Initialize an empty stack to store operators and an empty postfix expression.
2. Scan the infix expression from left to right, one character at a time.
3. If the scanned character is an operand, add it directly to the postfix expression.
4. If the scanned character is an opening parenthesis (, push it onto the stack.
5. If the scanned character is a closing parenthesis ), pop the operators from the stack and add them to the postfix expression until an opening parenthesis ( is found. Then remove the opening parenthesis from the stack.
6. If the scanned character is an operator, compare its precedence with the operator at the top of the stack.
7. If the operator at the top of the stack has higher or equal precedence, pop it and add it to the postfix expression. Repeat this until the condition is false or the stack becomes empty.
8. Push the current operator onto the stack.
9. Repeat the above steps until the complete infix expression has been scanned.
10. After scanning the complete expression, pop all the remaining operators from the stack and add them to the postfix expression.
11. The resulting expression is the required postfix expression.
*/
/*
#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char x)
{
    if (x == '^')
        return 3;

    if (x == '*' || x == '/')
        return 2;

    if (x == '+' || x == '-')
        return 1;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        // If operand, add to postfix
        if (isalnum(x))
        {
            postfix[j++] = x;
        }

        // If opening parenthesis, push
        else if (x == '(')
        {
            push(x);
        }

        // If closing parenthesis
        else if (x == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            pop(); // Remove '('
        }

        // If operator
        else
        {
            while (top != -1 &&
                   precedence(stack[top]) >= precedence(x))
            {
                postfix[j++] = pop();
            }

            push(x);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
*/

// Evaluation of Postfix
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    stack[++top] = value;
}

int pop()
{
    return stack[top--];
}

int evaluatePostfix(char postfix[])
{
    int i, a, b, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch (postfix[i])
            {
            case '+':
                result = a + b;
                break;

            case '-':
                result = a - b;
                break;

            case '*':
                result = a * b;
                break;

            case '/':
                result = a / b;
                break;

            case '%':
                result = a % b;
                break;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    result = evaluatePostfix(postfix);

    printf("Result = %d\n", result);

    return 0;
}