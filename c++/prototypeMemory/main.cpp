#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Card
{
public:
	Card(string n_, int x_, int y_, int id_)
		: x(x_), y(y_), id(id_), n(n_)
		{
			cout << "The card are succes loaded in." << endl;
			cout << str() << endl;
		}

	string str() const
	{
		ostringstream oss;
		oss << "\nCard specifications\n" << "name: " << n << "\nposition x: " << x << "\t" << "position y: " << y << "\n" << "id: " << id << "\n" << upAnsw() << endl;
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

	int x;
	int y;
	int id;
	string n;
	bool up_ = false;
};

int main()
{
	Card card1("Smiley Poop", 3, 5, 8);
	Card card2("Smiley Poop", 5, 8, 8);
	Card other();
	card1.turn();
	card1.equal(card2);
}