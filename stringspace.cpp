#include <iostream>
using namespace std;


void removeExtraWhiteSpaces(char src[], char dest[], int src_max_size = 1000) // Function accepts a source string and a destination string and copies the values of the source string into the destination strings excluding the extra whitespaces. 
{
	int spaceCount = 0; // variable for storing the number of consecutive white-spaces

	for (int i = 0, j = 0; i < src_max_size; i++)
	{
		if (src[i] == ' ') //spaceCount is incremented when a whitespace occurs in the source string
			spaceCount++;
		else
			spaceCount = 0; // if any other character occurs then spaceCount is reset 

		if (spaceCount == 0 or spaceCount == 1) // if the character is not a consecutive space then its value is stored into the destination string
		{
			dest[j] = src[i]; 
			j++; // the index for the destination string is incremented for the next cycle
		}
	}
}

void removeExtraWhiteSpaces(char src[], char dest[], int src_max_size = 1000) // Function accepts a source string and a destination string and copies the values of the source string into the destination strings excluding the extra whitespaces. 
{
	dest[0] = src[0]; // first value is copied over from source string to destination string
	for (int i = 1, j = 0; i < src_max_size; i++) // all consecutive values are copied over from source string to destination string unless the value is a consective space
	{
		if (src[i] != ' ' || src[i - 1] != ' ') // unless both the character and the character before it in the source string are spaces, it is copied over to destination string
		{
			dest[j] = src[i];
			j++;
		}
	}
}

void main()
{
	char src[1000];
	char dest[1000];
	cout << "Enter Input String : " << endl;
	cin.getline(src, 1000);

	removeExtraWhiteSpaces(src, dest, 1000);
	cout << "Result String" << endl;
	cout << dest;
}