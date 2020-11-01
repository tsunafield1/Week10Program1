#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int paren(char*);
int main()
{
	char s[100001];
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		if (paren(s) == 1) printf("yes\n");
		else printf("no\n");
	}
}

int paren(char* a)
{
	int st[50001],index = 0,i;
	for (i = 0; *(a + i) != '\0'; i++)
	{
		if (*(a + i) == '(')
		{
			st[index] = 1;
			index++;
		}
		else if (*(a + i) == '{')
		{
			st[index] = 2;
			index++;
		}
		else if (*(a + i) == '[')
		{
			st[index] = 3;
			index++;
		}
		if (*(a + i) == ')')
		{
			if (st[index - 1] != 1) return 0;
			index--;
		}
		else if (*(a + i) == '}')
		{
			if (st[index - 1] != 2) return 0;
			index--;
		}
		else if (*(a + i) == ']')
		{
			if (st[index - 1] != 3) return 0;
			index--;
		}
	}
	if (index != 0) return 0;
	return 1;
}