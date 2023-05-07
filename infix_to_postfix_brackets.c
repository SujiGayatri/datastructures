#include<stdio.h>
#include<string.h>
int pred(char ch)
{
	switch(ch)
	{
		case '^':
			return 3;
		case '*':
		case '/':
			return 2;
		case '+':
		case '-':
			return 1;
		case '(':
			return -1;
		case ')':
			return -1;
		default:
			return 0;
	}
}
char *infix_postfix(char *infix)
{
	int i,n,top=-1,j=0;
	n=strlen(infix);
	char st[n],op;
	static char postfix[100];
	for(i=0;i<n;i++)
	{
		if(pred(infix[i]))
		{
			if(top==-1)
			{
				st[++top]=infix[i];
			}
			else if(infix[i]=='(')
			{
				st[++top]=infix[i];
			}
			else if(infix[i]==')')
			{
				op=st[top--];
				while(op!='(')
				{
					postfix[j++]=op;
					op=st[top--];
				}
			}
			else if(pred(infix[i])>pred(st[top]))
			{
				st[++top]=infix[i];
			}
			else
			{
				while(top!=-1 && pred(infix[i])<=pred(st[top]))
				{
					op=st[top--];
					postfix[j++]=op;
				}
				st[++top]=infix[i];
			}
		}
		else
		{
			postfix[j++]=infix[i];
		}
	}
	for(i=top;i>=0;i--)
	{
		postfix[j++]=st[i];
	}
	return postfix;
}
int main()
{
	char infix[100],*postfix;
	scanf("%[^\n]s",&infix);
	postfix=infix_postfix(infix);
	printf("%s",postfix);
	return 0;
}

/*
(a+b-c*d)*(e-f^g)+h/i
*/
