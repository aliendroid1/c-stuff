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

	cout << '\n'
		 << "Start address: " << (&inputString) << '\n'
		 << "End address: " << (&inputString + endIndex) << '\n'
		 << (&inputString + endIndex) << " - " << (&inputString) << " := " << ((&inputString + endIndex) - (&inputString)) << '\n'
		;

	return 0;
}