#include <iostream>

using namespace std;

int* findMax(int array[], int aantal)
	{
		int* max = nullptr;
		for (int i = 0; i < aantal; ++i)
		{
			auto &value = array[i];

			if (max == nullptr)
				max = &value;

			if (value > *max)
				max = &value;
		}
		return max;
	}

int main()
{
	int a;
	
	cout << "Aantal getallen: ";
	cin >> a;
	int arr[a];
	for (int i = 0; i < a; ++i)
	{
		cout << "Enter the " << i+1 << "e number ";
		cin >> arr[i];
	}

	int* max = findMax(arr, a);
	cout << "\nHet hoogste getal is " << *max << endl;

	return 0;
}