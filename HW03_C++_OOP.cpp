#include <iostream>
#include <time.h>

int checkValue(void);

void fill_arr(int* const arr, const int& sizeRef, const int* const pmin, const int* const pmax);

void reverse_arr(int* const arr, const int& sizeRef);

void print_arr(int* const arr, const int& sizeRef);

int main(void)
{
    
	using std::cout;
    using std::cin;
    using std::endl;

	srand(time(NULL));
	
	int size = 0, minV = 0, maxV = 0;

    cout << "START!\n";
    
    cout << "size of arr -> ";
    size = checkValue();
	size = size < 0 ? abs(size) : size;

	int* arr = new (std::nothrow) int[size] {0};

	//check block of arr before to fill it
	if (!size) {
		cout << "\tarr: " << *arr << "\n";
		exit(0);
	}
	else if (!arr) {
		cout << "RAM size is not available!";
		exit(0);
	}

	do {
	cout << "\nrange of values in arr:\n";

		cout << "\tmin -> ";
		minV = checkValue();

		cout << "\tmax -> ";
		maxV = checkValue();

		if (abs(maxV) - abs(minV) >= size)
			break;

		system("CLS");
		cout << "ERROR! range (min...max) < size\n";

	} while (true);

	//swap function
	if (minV > maxV) {
		int temp = minV;
		minV = maxV;
		maxV = temp;
	}

	//fill arr by random values
	fill_arr(arr, size, &minV, &maxV);

	cout << "\nbefore reverse (start -> end)\n\tarr size " << size << ": ";
	print_arr(arr, size);

	//function of reverse
	reverse_arr(arr, size);

	cout << "\nafter reverse (end <- start)\n\tarr size " << size << ": ";
	print_arr(arr, size);

	delete[] arr;
	arr = nullptr;

    return 0;
}

int checkValue(void)
{
	int a = 0;
	while (true) // the cycle continues until the user enters the correct value
	{
		std::cin >> a;
		if (std::cin.fail()) // if the previous extraction was unsuccessful,
		{
			std::cout << "Incorrect input.\n\tEnter value in digit format: ";
			std::cin.clear(); // then return the cin to 'normal' mode of operation
			std::cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
		}
		else // if all is well, return a
		{
			std::cin.ignore(32767, '\n'); // and remove the previous input values from the input buffer
			return a;
		}
	}
}

void fill_arr(int* const arr, const int& sizeRef, const int* const pmin, const int* const pmax) {
	int varV = *pmax - *pmin;

	for (short i = 0; i < sizeRef;)
	{
		int arrV = *pmin + (rand() % varV);
		bool flag = false;

		for (short j = 0; j < i; j++)
			if (arrV == *(arr + j)) {
				flag = true;
				break;
			}

		if (!flag) {
			*(arr + i) = arrV;
			i++;
		}
	}
};

void reverse_arr(int* const arr, const int& sizeRef) {

	for (short i = 0; i < (int)sizeRef / 2; i++) 
	{
		int tempV = *(arr + i);
		*(arr + i) = *(arr + ((sizeRef - 1) - i));
		*(arr + ((sizeRef - 1) - i)) = tempV;
	}
};

void print_arr(int *const arr, const int &sizeRef) {

	for (short i = 0; i < sizeRef; i++)
		std::cout << *(arr + i) << ", ";
	
	std::cout << "\n";
};