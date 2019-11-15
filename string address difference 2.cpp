#include <iostream>
using namespace std;

int main()
{
	char inputString[1000];

	cout << "Enter Input String:\n";
	cin.getline(inputString, 1001);

	int endIndex = 0;
	while (inputString[endIndex + 1] != '\0')
		endIndex++;

	char* addressStart = &inputString[0];
	char* addressEnd = &inputString[endIndex];

	cout << '\n'
		<< "Start address: " << (void*)addressStart << '\n'
		<< "End address: " << (void*)addressEnd << '\n'
		<< (void*)addressEnd << " - " << (void*)addressStart << " := " << (addressEnd - addressStart);
	;

	return 0;
}