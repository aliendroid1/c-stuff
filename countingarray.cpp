#include <iostream>
#include <vector>
using namespace std;


void CountFrequency(int inputArray[],int inputArraySize)
{
	vector< vector<int> >categorizedElements;
	vector<int>elements;
	elements.push_back(inputArray[0]);
	categorizedElements.push_back(elements);

	bool repeat;
	int i, j;
	for (i = 1; i < inputArraySize; i++)
	{
		repeat = false;	
		for (j = 0; j < categorizedElements.size(); j++)
		{
			if (inputArray[i] == categorizedElements[j][0])
				repeat = true;
		}

		if (repeat == false)
		{
			vector<int> elements;
			elements.push_back(inputArray[i]);
			categorizedElements.push_back(elements);
		}
		else
			categorizedElements[j].push_back(inputArray[i]);
	}

	cout << "number -> count\n";
	for (int i = 0; i < categorizedElements.size(); i++)
	{
		cout << categorizedElements[i][0] << " -> "  << categorizedElements[i].size() << "\n";
	}
}

int main()
{
	int *inputArray;
	int inputArraySize;

	cout << "Size of array: ";
	cin >> inputArraySize;

	inputArray = new int[inputArraySize];

	for (int i = 0; i < inputArraySize; i++)
	{
		cout << "Enter Element " << i << ": ";
		cin >> inputArray[i];
	}

	CountFrequency(inputArray, inputArraySize);

	return 0;
}