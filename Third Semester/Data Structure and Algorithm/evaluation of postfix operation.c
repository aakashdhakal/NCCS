#include<stdio.h>

#include<math.h>

int evaluate_post(char * );
int isoperand(char);
int isoperator(char);

int main() {
  char post[40];
  int rs;
  printf("Enter postfix expression: ");
  gets(post);
  rs = evaluate_post(post);
  printf("The result of evaluation is: %d", rs);
  getch();
  return 0;

}
int evaluate_post(char *post ) {
  int i, tos = -1;
  int n, opndstk[10], opnd1, opnd2;
  while (*post!= '\0') {
    if (isoperand(*post)) {
      printf("Enter the value of %c", *post);
      scanf("%d", & n);
      opndstk[++tos] = n;
    } else if (isoperator(*post)) {
      opnd1 = opndstk[tos--];
      opnd2 = opndstk[tos--];
      switch (*post) {
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
        opndstk[++tos] = (pow(opnd1, opnd2));
        break;
      }
    }
  }
	return opndstk[tos];
}
int isoperand(char ch){
	if(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z')
return 1;
else
return 0;
}
int isoperator(char ch)
{
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='$')
return 1;
else
return 0;
}
