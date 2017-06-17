#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Card
{
public:
    void set_id(int id)
    {
        id_ = id;
    }
    bool equal(const Card &other) const
    {
        if (!up_)
            return false;
        if (!other.up_)
            return false;
        if (id_ == -1)
            return false;
        if (other.id_ == -1)
            return false;
        return id_ == other.id_;
    }
    void print() const
    {
        if (id_ == -1)
        {
            cout << "!";
            return;
        }
        if (up_)
            cout << id_;
        else
            cout << "?";
    }
    void turn()
    {
        up_ = !up_;
    }
private:
    int id_ = -1;
    bool up_ = false;
};

class Board
{
public:
    Board(unsigned int n)
    {
        cards_.resize(2*n);
        for (int i = 0; i < n; ++i)
        {
            cards_[2*i+0].set_id(i);
            cards_[2*i+1].set_id(i);
        }
    }
    void print() const
    {
        for (const Card &card: cards_)
            card.print();
        cout << endl;
    }
    void shuffle()
    {
        random_shuffle(cards_.begin(), cards_.end());
    }
    Card *get(unsigned int ix)
    {
        if (ix >= cards_.size())
            return nullptr;
        return &cards_[ix];
    }
private:
    vector<Card> cards_;
};

int main()
{
    cout << ">> Memory starting" << endl;

    int score = 0;
    int x = 6;

    Board board(x);
    board.shuffle();
    board.shuffle();

    board.print();

    while (score < x)
    {
        cout << "Specify the cards to turn" << endl;
        unsigned int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (a == b)
        {
            cout << "These cards are the same" << endl;
        }
        else
        {
            Card *ca = board.get(a);
            Card *cb = board.get(b);
            if (ca == nullptr || cb == nullptr)
            {
                cout << "Could not find card " << a << " or card " << b << endl;
            }
            else
            {
                ca->turn();
                cb->turn();
                board.print();
                if (ca->equal(*cb))
                {
                    cout << "Yes, I found a match" << endl;
                    score++;
                    cout << "Your score is: " << score << endl;
                }
                else
                {
                    ca->turn();
                    cb->turn();

                }
            }
        }
    }

    cout << "<< Memory finished" << endl;
    return 0;
}
