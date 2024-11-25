/*В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное
слово и вывести его в файл .txt. Случай, когда самых длинных слов может быть
несколько, не обрабатывать.
Данные на входе: Строка из английских букв и пробелов. Не более
1000 символов.
Данные на выходе: Одно слово из английских букв.*/

#include <stdio.h>
#include <string.h>

const int MAX_LINE_SIZE = 1000 + 1;

void findLongestWord(char *input, char *longestWord)
{
	char currentWord[MAX_LINE_SIZE];
	int maxLen = 0;
	int currentLen = 0;
	int i = 0;

	while (input[i] != '\0')
	{
		if (input[i] != ' ')
		{
			currentWord[currentLen] = input[i];
			currentLen++;
		}
		else
		{
			currentWord[currentLen] = '\0';
			if (currentLen > maxLen)
			{
				maxLen = currentLen;
				strcpy(longestWord, currentWord);
			}
			currentLen = 0;
		}
		i++;
	}

	currentWord[currentLen] = '\0';

	if (currentLen > maxLen)
	{
		maxLen = currentLen;
		strcpy(longestWord, currentWord);
	}
}

int main()
{

	char *input_fn = "input.txt";
	char *output_fn = "output.txt";

	FILE *fi = fopen(input_fn, "r");

	char inputString[MAX_LINE_SIZE];
	char longestWord[MAX_LINE_SIZE];

	fscanf(fi, "%[^\n]", inputString);
	findLongestWord(inputString, longestWord);
	fclose(fi);

	FILE *fo = fopen(output_fn, "w");
	fprintf(fo, "%s", longestWord);
	fclose(fo);

	return 0;
}