#include <iostream>

using namespace std;

void print_sterretjes(int aantal)
{
	for (int j = 0; j < aantal; ++j)
	{
		cout << "<0 ";
	}
	cout << endl;
}

int main()
{
	int aantal=10;
	//cin >> aantal;
	cout << aantal << endl;
	for (int i = 0; i < aantal; ++i)
	{
		print_sterretjes(2*aantal);

	}
	cout << "het programma sluit" << endl;
	return 0;
}