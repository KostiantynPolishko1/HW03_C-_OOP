#include <iostream>
#include <time.h>

int checkValue();

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

	cout << "\nrange of values in arr:\n";
	cout << "\tmin -> ";
	minV = checkValue();

	cout << "\tmax -> ";
	maxV = checkValue();

	//swap function
	if (minV > maxV) {
		int temp = minV;
		minV = maxV;
		maxV = temp;
	}

	//fill arr by random values
	int varV = maxV - minV;

	for (short i = 0; i < size;)
	{
		int arrV = minV + (rand() % varV);

		for (short j = 0; j < i; j++)
			if (arrV == arr[j])
				break;

		arr[i] = arrV;
		i++;
	}

	cout << "\nbefore reverse\n\tarr: ";
	for (short i = 0; i < size; i++)
		cout << arr[i] << ", ";

	cout << "\n";
    return 0;
}

int checkValue()
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