#include <iostream>
using namespace std;

void countFrequency(int inputArray[], int inputArraySize) /* declaring function for printing every unique number and the number of times it occurs in an array */
{
	int* frequencies = new int[inputArraySize];                               // this array will contain the frequency values for each unique element in the input array

	for (int i = 0; i < inputArraySize; i++)                                  // all values in frequencies array initialized to 1
		frequencies[i] = 1; 

	for (int i = 0; i < inputArraySize; i++) /* loop to set all elements in frequencies array to actual frequencies of their respective elements in input array  */
		for (int j = i + 1; j < inputArraySize; j++) 
		{
			if (frequencies[i] == 1 && inputArray[i] == inputArray[j])        // runs when input array element i is not itself a repeat but input array element j is its repeat 
			{
				frequencies[j] = -1;                                          // -1 is used as a mark to flag frequency values of repeat elements so they can be ignored 
				frequencies[i]++;                                             // input array element's respective frequency is incremented 
			}
		}
	cout << "number -> count\n";
	for (int i = 0; i < inputArraySize; i++) /* printing array elements and their respective frequencies */
	{
		if (frequencies[i] !=  -1)                                            // ignoring repeat elements
			cout << inputArray[i] << " -> " << frequencies[i] << endl;
	}
}

int main()
{
	int* inputArray;
	int inputArraySize;
	cout << "Size of inputArray: "; 
	cin >> inputArraySize; 
	inputArray = new int[inputArraySize]; 
	for (int i = 0; i < inputArraySize; i++) /* getting input values and assigning them to respective input array elements  */
	{
		cout << "Enter Element " << i << ": ";
		cin >> inputArray[i];
	}
	countFrequency(inputArray, inputArraySize);                               // invoking function that prints every unique number and the number of times it occurs in an array */
}