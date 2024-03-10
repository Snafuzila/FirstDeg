#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


int Q1(char* s1, char* s2); //all chars in s1 in s2
int Q2(char* s1, char* s2); //you can make s1 with s2
void Q3(char* s1); //delete copies of chars in s1
void Q4(char* s1);//delete copies of char in s1 and add numbers. abbcccdddd = ab2c3d4
int Q5(char* s1); //check if possible to make polyndrome out of s1
char* Q6(char* s1, int* n); //checks which chars needs to be deleted in order to make polyndrome
int Q7(char* s1, char* s2); //compare strings

void main()
{
	
}

int Q1(char* s1, char* s2)
{
	int* monim = (int*)calloc(26, sizeof(int));
	assert(monim != NULL);
	for (size_t i = 0; i < strlen(s1); i++)
	{
		monim[(s1[i] - 'a')]++;
	}
	for (size_t i = 0; i < strlen(s2); i++)
	{
		monim[(s2[i] - 'a')]--;
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (monim[i] >= 1) return 0;
	}
	free(monim);
	return 1;
}
int Q2(char* s1, char* s2)
{
	int* monim = (int*)calloc(26, sizeof(int));
	assert(monim != NULL);
	for (size_t i = 0; i < strlen(s1); i++)
	{
		monim[(s1[i] - 'a')]++;
	}
	for (size_t i = 0; i < strlen(s2); i++)
	{
		monim[(s2[i] - 'a')]--;
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (monim[i] != 0)
		{
			free(monim);
			return 0;
		}
	}
	free(monim);
	return 1;
}
void Q3(char* s1)
{
	if (s1==NULL || *s1 == '\0') return;

	char* current = s1;
	char* result = s1;
	while (*current!= '\0')
	{
		*result = *current;
		while (*(current+1) != '\0' && *(current+1)== *current)
		{
			current++;
		}
		current++;
		result++;
	}
	*result = '\0';
	return;
}
void Q4(char* s1)
{
	if (s1 == NULL || *s1 == '\0') return;
	int times;
	char* current = s1;
	char* result = s1;
	while (*current != '\0')
	{
		*result = *current;
		times = 1;
		while (*(current + 1) != '\0' && *(current + 1) == *current) // ab2Cccddddeeeee
		{
			current++;
			times++;
		}
		current++;
		result++;
		if (times > 1)
		{
			*result = ('0' + times);
			result++;
		}
	}
	*result = '\0';
	return;
}
int Q5(char* s1) 
{
	int* monim = (int*)calloc(26, sizeof(int));
	assert(monim!=NULL);
	for (size_t i = 0; i < strlen(s1); i++)
	{
		monim[s1[i]-'a']++;
	}
	int counter = 0;
	for (size_t i = 0; i < 26; i++)
	{
		if ((monim[i]) % 2 == 1) counter++;
		if (counter > 1)
		{
			free(monim);
			return 0;
		}
	}
	free(monim);
	return 1;
}
char* Q6(char* s1, int* n)
{
	int* monim = (int*)calloc(26, sizeof(int));
	assert(monim != NULL);
	for (size_t i = 0; i < strlen(s1); i++)
	{
		monim[s1[i] - 'a']++;
	}

	int counter = 0;
	char* extra = (char*)calloc(26, sizeof(char));
	assert(extra != NULL);
	int pos = 0;

	for (size_t i = 0; i < 26; i++)
	{
		if ((monim[i]) % 2 == 1)
		{
			counter++;
			if (counter > 1)
			{
				extra[pos] = 'a'+i;
				pos++;
			}

		}
	}
	extra[pos] = '\0';
	*n = counter - 1;
	free(monim);
	return extra;
}
int Q7(char* s1, char* s2)
{
	if (strlen(s1) != strlen(s2)) return 0;
	for (int i = 0; strlen(s1); i++)
	{
		s1[i] = tolower(s1[i]);
		s2[i] = tolower(s2[i]);
		if (s1[i] != s2[i]) return 0;
	}
	return 1;
}