#include <iostream>
using namespace std;

int main()
{
	char inputChar = '?';
	const int CHARLIMIT = 30, WORDLIMIT = 30;
	char inputString[WORDLIMIT][CHARLIMIT];
	char outputString[WORDLIMIT][CHARLIMIT];

	for (int i = 0; i < WORDLIMIT; i++)
		for (int j = 0; j < CHARLIMIT; j++)
			inputString[i][j] = outputString[i][j] = '-';

	int finalWordIndex = 0;

	for (int i = 0; i < WORDLIMIT; i++)
		for (int j = 0; j < CHARLIMIT; j++)
		{
			finalWordIndex = i;
			inputString[i][j] = ' ';
			cin.get(inputChar);
			if (inputChar == '\n')
				goto outOfLoops;
			inputString[i][j] = inputChar;
			if (inputChar == ' ')
				break;
		}
outOfLoops:

	for (int i = 0; i <= finalWordIndex; i++)
		for (int j = 0; j < CHARLIMIT; j++)
			outputString[i][j] = inputString[finalWordIndex - i][j];

	for (int i = 0; i <= finalWordIndex; i++)
		for (int j = 0; outputString[i][j] != '-'; j++)
			cout << outputString[i][j];

	return 0;
}