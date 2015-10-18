#include <iostream>
#include <string>

using namespace std;


void poets_tanden();

void kleren_uit ()
{
	cout << "Begin " << __func__ << endl;
	cout << "Einde " << __func__ << endl;	
}

void pyjama_aan ()
{ 
	cout << "Begin " << __func__ << endl;
	cout << "Einde " << __func__ << endl;	
}

void slapen(int slaap_uren, string slaap_geluid)
{
	for (int i = 0; i < slaap_uren; ++i)
	{
		cout << "IK moet pipi doen" << endl;
		cout << slaap_geluid << endl;
	}
}

void ga_slapen(int slaap_minuten, string naam, string slaap_geluid)
{
	cout << "Begin " << __func__ << " van " << naam << endl;
	poets_tanden();
	kleren_uit();
	pyjama_aan();
	slapen(slaap_minuten/60, slaap_geluid);
	cout << "Einde " << __func__ << endl;
}

void poets_tanden()
{
	cout << "Begin " << __func__ << endl;
	cout << "Einde " << __func__ << endl;
}

int main()
{
	ga_slapen(480, "papa", "is 8===>");
	cout << endl;
	ga_slapen(60, "mama", "knornknor");
	return 0;
}