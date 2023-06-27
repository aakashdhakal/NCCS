#include <stdio.h>
#include <conio.h>
#include <string.h>

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
    char opstack[100], prestring[100];
    int i = 0, top = -1;
    int length = strlen(ch);

    for (int j = length - 1; j >= 0; j--)
    {
        if (isOperand(ch[j]))
        {
            prestring[i++] = ch[j];
        }
        else if (isOperator(ch[j]))
        {
            if (top == -1)
            {
                opstack[++top] = ch[j];
            }
            else if (priority(ch[j]) >= priority(opstack[top]))
            {
                opstack[++top] = ch[j];
            }
            else
            {
                while (top != -1 && priority(ch[j]) < priority(opstack[top]))
                {
                    prestring[i++] = opstack[top--];
                }
                opstack[++top] = ch[j];
            }
        }
        else if (ch[j] == ')')
        {
            opstack[++top] = ch[j];
        }
        else if (ch[j] == '(')
        {
            while (top != -1 && opstack[top] != ')')
            {
                prestring[i++] = opstack[top--];
            }
            if (top != -1 && opstack[top] == ')')
            {
                top--;
            }
        }
    }

    while (top != -1)
    {
        prestring[i++] = opstack[top--];
    }
    prestring[i] = '\0';

    printf("The prefix expression is: ");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%c", prestring[j]);
    }
    printf("\n");
}
