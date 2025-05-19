#pragma once

#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 255

typedef struct String
{
	char string[MAX_SIZE];
	int length;
}String;

// ³õÊ¼»¯´®
int InitString(String* s)
{ 
	s->length = 0;

	return 1;
}

int StrAssign(String* s, char c[])
{
	int i = 0;
	while (c[i])
	{
		s->string[s->length++] = c[i++];
	}

	return 1;
}


int Index(String* s, char c[], int c_length)
{
	if (c_length > s->length)
	{
		return 0;
	}

	int i = 0, j = 0;
	while (i < s->length - c_length && j < c_length)
	{
		if (s->string[i] == c[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}

	if (j == c_length)
	{
		return i - c_length;
	}
	else
	{
		return 0;
	}

}

int Get_next(char c[], int c_length)
{
	int* next = (int*)malloc(sizeof(int) * (c_length + 1));
	next[0] = 0;
	next[1] = 0;
	next[2] = 1;

	int j = 1, i = 0;
	while (j < c_length && c[j])
	{
		if (c[i] == c[j])
		{
			next[++j] = ++i;
		}
		else
		{
			i = 0;
			next[++j] = i;
		}
	}

	for (int i = 0; i < c_length + 1; i++)
	{
		printf("%d ", next[i]);
	}
}

int Index_kmp(String s, char c[], int c_length)
{
	if (s.length < c_length)
	{
		return 0;
	}

	Get_next(c, c_length);

}