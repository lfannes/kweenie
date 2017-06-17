#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int Score;

class Card
{
public:
	Card(string n_, int x_, int y_, int id_, int nb_)
		: x(x_), y(y_), id(id_), n(n_), nb(nb_)
		{
			cout << "The card are succes loaded in." << endl;
			cout  << endl;
		}

	string str() const
	{
		ostringstream oss;
		oss << "\nCard specifications\n" << "name: " << n << "\nposition x: " << x << "\t" << "position y: " << y << "\n" << "id: " << id << "\n" << upAnsw() << endl;
		return oss.str();
	}

	string answStr()
	{
		ostringstream oss;
		oss << nb << ")\t" << n << "\nposition x: " << x << "\t" << "position y: " << y << "\n" << upAnsw() << "\n\n" << endl;
		return oss.str();
	}

	void print() const
	{
		cout << str();
	}

	void set(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	bool equal(const Card &other)
	{
		if (id == other.id)
		{
			cout << "\nCard " << id <<  " are not different with card " << other.id << endl;
			return true;
		}
		else
		{
			cout << "\nCards" << other.id << " are different with " << other.id << endl;
			return false;
		}
	}

	string upAnsw() const
	{
		if (up_ == true)
			return "The card lights up.";
		else
			return "The card lights down.";
	}

	void turn()
	{
		up_ = !up_;
		cout << "\n" << n << " card is turning.\n" << upAnsw() << endl;
	}

	void trash()
	{
		cout << "trash is active\n" << endl;
	}

	void getScore(const Card &other)
	{
		Score++;
		cout << n << " en " << other.n << " hebben een punten gescoord.\n" << endl;
		cout << "Score: " << Score << endl;
		trash();
	}

	int nb;
	int x;
	int y;
	int id;
	string n;
	bool up_ = false;
};

string play()
{
	string prompt;
	Card card1("Smiley Poop", 3, 5, 8, 1);
	Card card2("Smiley Poop", 5, 8, 8, 2);

	cout << "What did you want to do? (turning, controle, exit)" << endl;
	getline(cin, prompt);
	cout << endl;
	if (prompt == "turning")
	{
			int selc1;
			int selc2;
			cout << "Which cards do you want to turn around?\n" << endl;
			cout << card1.answStr() << card2.answStr() << endl;
			cout << "\nHINT: every card calls Smily Poop\n" << endl;
			cout << "Enter the number of card 1 wich you want turn around" << endl;
			cin >> selc1;
			switch (selc1)
			{
				case 1: cout << "l" << endl;
				break;

				case 2: cout << "re" << endl;
				break;

				default: cout << "That number is not valid" << endl;
				cin.get();
				play();
				break;
			}
			cout << "Enter the number of card 2 wich you want turn around" << endl;
			cin >> selc2;
			switch (selc2)
			{
				case 1: cout << "l2" << endl;
				break;

				case 2: cout << "re2" << endl;
				break;

				default: cout << "That number is not valid\n" << endl;
				cin.get();
				play();
				break;
			}
			if (selc1 == selc2)
			{
				cout << "You have selected the same cards!\n" << endl;
				play();
			}
			Card &ca = (selc1 == 1 ? card1 : card2);
			
	}
	else if (prompt == "controle")
	{
		cout << "gaint kakie" << endl;
	}
	else if (prompt == "exit")
	{
		cout << "program has been closed" << endl;
	}
	else
	{
		cout << "I did not understand, try it again" << endl;
		play();
	}
}

int main()
{
	play();
}