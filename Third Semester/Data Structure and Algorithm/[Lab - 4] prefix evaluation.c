#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <string.h>

int evaluate_pre(char *);
int isoperand(char);
int isoperator(char);

int main()
{
	char pre[40];
	int rs;
	printf("Enter prefix expression: ");
	gets(pre);
	rs = evaluate_pre(pre);
	printf("The result of evaluation is: %d\n", rs);
	getch();
	return 0;
}

int evaluate_pre(char *pre)
{
	int i, tos = -1;
	int n, opndstk[10], opnd1, opnd2;
	int length = strlen(pre);

	for (i = length - 1; i >= 0; i--)
	{
		if (isoperand(pre[i]))
		{
			if (pre[i] >= '0' && pre[i] <= '9')
			{
				n = pre[i] - '0';
			}
			else
			{
				printf("Enter the value of %c: ", pre[i]);
				scanf("%d", &n);
			}
			opndstk[++tos] = n;
		}
		else if (isoperator(pre[i]))
		{
			opnd1 = opndstk[tos--];
			opnd2 = opndstk[tos--];
			switch (pre[i])
			{
			case '+':
				opndstk[++tos] = opnd1 + opnd2;
				break;
			case '-':
				opndstk[++tos] = opnd1 - opnd2;
				break;
			case '*':
				opndstk[++tos] = opnd1 * opnd2;
				break;
			case '/':
				opndstk[++tos] = opnd1 / opnd2;
				break;
			case '$':
				opndstk[++tos] = pow(opnd1, opnd2);
				break;
			}
		}
	}
	return opndstk[tos];
}

int isoperand(char ch)
{
	if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
		return 1;
	else
		return 0;
}

int isoperator(char ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '$')
		return 1;
	else
		return 0;
}
