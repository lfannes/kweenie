#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Kaart
{
public:
	Kaart(int x_, int y_, int id_)
		: x(x_), y(y_), id(id_)
		{

		}

	string str() const
	{
		ostringstream oss;
		oss << "Kaart eigenschappen\n" "positie x: " << x << "\t" << "positie y: " << y << "\n" << "id: " << id << endl;
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

	bool equal(const Kaart &other)
	{
		if (id == other.id)
		{
			cout << "The cards are not different" << endl;
			return true;
		}
		else
		{
			cout << "The cards are different" << endl;
			return false;
		}
	}

	int x;
	int y;
	int id;
};

int main()
{
	Kaart kaart1(3, 5, 8);
	Kaart kaart2(5, 8, 2);
	Kaart other();
	kaart1.print();
	kaart2.print();
	cin.get();
	kaart1.equal(kaart2);
}