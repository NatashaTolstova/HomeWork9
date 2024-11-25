/*В файле .txt дано предложение. Необходимо определить, сколько слов
заканчиваются на букву 'а'. Ответ записать в файл .txt.
Данные на входе: Строка из английских букв и пробелов не более 1000
символов.
Данные на выходе: Одно целое число*/

#include <stdio.h>
#include <string.h>

const int MAX_LINE_SIZE = 1000 + 1;

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";

	FILE *fi = fopen(input_fn, "r");

	char word[MAX_LINE_SIZE];

	int countWordsWithA = 0;
	while (fscanf(fi, "%s", word) == 1)
	{
		int posEndSymbol = strlen(word) - 1;
		if (word[posEndSymbol] == 'a')
		{
			countWordsWithA++;
		}
	}
	fclose(fi);

	FILE *fo = fopen(output_fn, "w");
	fprintf(fo, "%d", countWordsWithA);
	fclose(fo);
}