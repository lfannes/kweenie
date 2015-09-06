#include <iostream>

using namespace std;

void print (char ch, int aantal)
{
	for (int i = 0; i < aantal; ++i)
	{
		cout << ch;
	}
}

void print_lijn (int lijn, int aantal_lijnen)
{
	const int aantal_spaties = aantal_lijnen-1 - lijn;
	const int aantal_sterren = 2 * lijn + 1;
	print (' ', aantal_spaties);
	print ('*', aantal_sterren);
}

int main()
{
	int aantal_lijnen = 26;
	for (int lijn = 0; lijn < aantal_lijnen; ++lijn)
	{
		print_lijn(lijn, aantal_lijnen);
		cout << endl;
		/* code */
	}
	return 0;
}