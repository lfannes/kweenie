#include <iostream>
#include <string>

using namespace std;

int main()
{
	string username ;
	cout << "username: " << endl;

	cin >> username;
	cin.get();

	if (username == "lfannes") 
	{	
		cout << "username corrent :)" << endl;
		cout << " " << endl;
		string wachtwoord;
		cout << "wachtwoord: " << endl;
		cin >> wachtwoord;
		cin.get();
		if (wachtwoord == "********")
		{
			cout << "Welkom Lander Fannes" << endl;
			cout << "geef je opdracht: " << endl;
			string opdracht;
			cin >> opdracht;
			cin.get();

			if (opdracht == "school" )
			{
				cout << "Je vindt school wel leuk maar in het begin van het middelbaar vind je het eigenlijk raar en (vul je antwoordt in maar 1 woord) " << endl;
			 	string antwoordSchool;
				cin >> antwoordSchool;
				cin.get();
				cout << "Je vindt school wel leuk maar in het begin van het middelbaar vind je het eigenlijk raar en " << antwoordSchool << endl;
				cin.get();
			}
			else
			{
				if (opdracht == "geheimen")
				{
					cout << "Je geheimen zijn dat je middelbare school wel leuk vindt maar in het begin niet" << endl;
					cout << " " << endl; 
					cout << "Je vindt Robbe C niet zo leuk want hij is een aandachts mannetje." << endl;
					cout << " " << endl;
					cout << "Wil je nog iets zeggen kan je dat nu doen zo niet druk 2 keer op enter (wat je nu typt kan ik wel niet onthouden of je moet het in programeren.)" << endl;
					string typing;
					cin >> typing;
					cin.get();
					cout << "dit had je getypt: " << typing << " .Wil je het nog veranderen zo ja typ maar zo nee druk op enter." << endl;
					string extraTyping;
					cin >> extraTyping;
					cin.get();
					cout << "Dit is het geworden: " << extraTyping << endl;

				}
				else
				{
					if (opdracht == "ls")
					{
						cout << "De opdrachten zijn:" << endl;
						cout << "-school" << endl;
					}
				}
			}

		}
		else
		{
			cout << "Sorry de username " << username << " was juist maar het wachtwoord niet." << endl;
		}
	}
	else
	{
		cout << "Sorry je username " << username << " was niet correct, druk op enter om het programma af te sluiten" << endl;
		cin.get();
	}

	return 0;
}