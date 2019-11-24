#include <iostream>
using namespace std;
void getMaximumPositive(int* arr, int size, int*& max) /* Max needed to be passed by reference */
{
	/**
	Description:
	Locates the maximum positive number in an array.
	If found, it sets the max pointer to address of the maximum value in the array
	In case of arrays with negative numbers only, this function sets the max pointer to a null value.
	The variable max must be a pointer type, as it can potentially be set to null.
	INPUT ARGUMENTS:
		arr: Pointer to the array
		size: Size of the input array
		max: Pointer variable to be updated
	OUTPUT:
		max: This variable is modified to point to the location of the maximum positive value in the array.
		This value is set to null if no positive numbers are found
	**/

	max = nullptr;		//Set default value of max pointer
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0)		//Only positive numbers are considered while locating the maximum
		{
			/*
			Iteratively find the maximum value and
			assign the address of the maximum value in the array to the max pointer variable
			*/
			if (max == nullptr)
				max = &arr[i];
			else if (arr[i] > * max)
				max = &arr[i];
		}
	}
}
void getMaximumNegative(int* arr, int size, int*& max) /* Max needed to be passed by reference */
{
	/**
	Description:
	Locates the maximum positive number in an array.
	If found, it sets the max pointer to address of the maximum value in the array
	In case of arrays with negative numbers only, this function sets the max pointer to a null value.
	The variable max must be a pointer type, as it can potentially be set to null.
	INPUT ARGUMENTS:
		arr: Pointer to the array
		size: Size of the input array
		max: Pointer variable to be updated
	OUTPUT:
		max: This variable is modified to point to the location of the maximum positive value in the array.
		This value is set to null if no positive numbers are found
	**/

	max = nullptr;		//Set default value of max pointer
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)		//Only negative numbers are considered while locating the maximum
		{
			/*
			Iteratively find the maximum value and
			assign the address of the maximum value in the array to the max pointer variable
			*/
			if (max == nullptr)
				max = &arr[i];
			else if (arr[i] < * max) /* greater than sign swapped to less than because function needs to find lowest value */
				max = &arr[i];
		}
	}
}

void printArrayForwards(int* arr, int size)
{
	/**
	Description:
	Prints the contents of the array in the forward order.
	Starting from the FIRST element, this function prints all the elements of the array upto array size
	INPUT ARGUMENTS:
		arr: Pointer to the array
		size: Size of the input array
	OUTPUT:
		Prints array elements to the console in forward order
	**/

	cout << "Array contents (Forwards): " << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " : ";
	cout << endl;
}
void printArrayBackwards(int* arr, int size)
{
	/**
	Description:
	Prints the contents of the array in the reverse order.
	Starting from the LAST element, this function prints all the elements of the array upto the FIRST element
	INPUT ARGUMENTS:
		arr: Pointer to the array
		size: Size of the input array
	OUTPUT:
		Prints array elements to the console in backward order
	**/

	cout << "Array contents (Backwards): " << endl;
	for (int i = size -1; i >= 0; i--) /* for loop fixed to iterate from highest index to lowest */
		cout << arr[i] << " : ";
	cout << endl;
}
void swapMaxtoFront(int* arr, int*& max_address) /* Max needed to be passed by reference */
{
	/**
	Description:
	Swaps the element at max_address with the first element of the array
	INPUT ARGUMENTS:
		arr: Pointer to the array
		max_address: Pointer to the max element
	OUTPUT:
		If max_address is null, swap is not performed
		arr: Modifies this array such that the maximum value pointed to by max_address is now at the front, while the first element is at the location pointed by max_address
		max_address: After swapping succesfully, the new location of the maximum is at the beginning of the array. Therefore, max_address is modified to point to thefront of the array.
	**/

	if (max_address == nullptr)
		return;					//Do nothing if max_address is null

	//Print the addresses and their corresponding values of the first element and the maximum element of the array
	cout << endl << "Swapping elements:" << endl;
	cout << "Address 1: " << arr << " Value: " << *arr << endl;
	cout << "Address 2: " << max_address << " Value: " << *max_address << endl << endl;

	//Code for the swap
	int temp = *arr;
	*arr = *max_address;
	*max_address = temp;

	/*
	Set max_address to the new location.
	Since the maximum value has been swapped,
	the max_address needs to point to the new location of the maximum value,
	which is now at the front of the array
	*/
	max_address = arr;
}
void PrintArray(int* arr, int size)
{
	/**
	Description:
	Calls the functions printArrayForwards and printArrayBackwards
	in order to print the array both ways, first in the forward order, followed by printing in the reverse order
	INPUT ARGUMENTS:
		arr: Pointer to the array
		size: Size of the input array
	**/

	printArrayForwards(arr, size);
	printArrayBackwards(arr, size);
}

int main()
{
	/**
	Description:
	Takes an input array from the user.
	Swaps the maximum positive element with the first element of the input array, if array contains positive numbers.
	Swaps the maximum negative element with the first element of the input array, if array contains negative numbers.
	**/

	//Initialize pointers to null
	int* array = nullptr;		//Do Not Change This Variable Definition 
	int* max = nullptr;			//Do Not Change This Variable Definition

	int arr_size;

	cout << "Enter the size of your array: ";
	cin >> arr_size;
	array = new int[arr_size];			//Reserve memory for array of size given by user
	cout << "Enter array elements: " << endl;
	for (int i = 0; i < arr_size; i++)
	{
		cout << "Element " << i + 1 << " of " << arr_size << " : ";
		cin >> array[i]; /* arr++ changes value of array permenantly so changed to arr[i] */
	}

	PrintArray(array, arr_size);


	cout << endl << endl;
	cout << "-----------------------------------------------" << endl << "Finding maximum positive number in array..." << endl;

	getMaximumPositive(array, arr_size, max);	//Max should point to the Maximum positive value in the array

	swapMaxtoFront(array, max);			//Swap the maximum positive number with the first element of the array

	PrintArray(array, arr_size);		//Print array with swapped values.

	//Print maximum positive number
	cout << endl;
	if (max == nullptr)
		cout << "***No positive numbers found in array" << endl;
	else
		cout << "***Maximum positive number in array: " << *max << endl;		//Max should point to the Maximum positive value in the array, which should now be the first element
	cout << "-----------------------------------------------" << endl;


	cout << endl;
	cout << "-----------------------------------------------" << endl << "Finding maximum negative number in array..." << endl;

	getMaximumNegative(array, arr_size, max);	//Max should point to the Maximum negative value in the array

	swapMaxtoFront(array, max);			//Swap the maximum negative number with the first element of the array

	PrintArray(array, arr_size);		//Print array with swapped values.

	//Print maximum negative number
	cout << endl;
	if (max == nullptr)
		cout << "***No negative numbers found in array" << endl;
	else
		cout << "***Maximum negative number in array: " << *max << endl;		//Max should point to the Maximum negative value in the array, which should now be the first element
	cout << "-----------------------------------------------" << endl;

	delete[] array;
	/* max's variable can not be deleted max because max pointed to a variable inside the deleted array */
	array = nullptr; /**/
	max = nullptr;
	return 0;

}