#include <stdio.h>
#include <conio.h>
// #include <string.h>

int isOperand(char);
int isOperator(char);
int priority(char);
void conversion(char *);

void main()
{
    char infix[100];
    printf("Enter the infix expression: ");
    gets(infix);
    conversion(infix);
}
int isOperand(char ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$')
        return 1;
    else
        return 0;
}

int priority(char ch)
{
    if (ch == '$')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

void conversion(char *ch)
{
    char opstack[100], poststring[100];
    int i = 0, top = -1;
    while (*ch != '\0')
    {
        if (isOperand(*ch))
        {
            poststring[i++] = *ch;
        }
        else if (isOperator(*ch))
        {
            if (top == -1)
            {
                opstack[++top] = *ch;
            }
            // else if (*ch == '(')
            // {
            //     opstack[++top] = *ch;
            // }
            else if (priority(*ch) > priority(opstack[top]))
            {
                opstack[++top] = *ch;
            }
            else
            {
                while (priority(*ch) <= priority(opstack[top]))
                {
                    poststring[i++] = opstack[top--];
                }
                opstack[++top] = *ch;
            }
        }
        else if (*ch == '(')
        {
            opstack[++top] = *ch;
        }
        else if (*ch == ')')
        {
            while (opstack[top] != '(')
            {
                poststring[i++] = opstack[top--];
            }
            if (top != -1 && opstack[top] == '(')
            {
                top--;
            }
        }
        ch++;
    }

    while (top != -1)
    {
        poststring[i++] = opstack[top--];
    }
    poststring[i] = '\0';

    printf("The postfix expression is: %s\n", poststring);
}
