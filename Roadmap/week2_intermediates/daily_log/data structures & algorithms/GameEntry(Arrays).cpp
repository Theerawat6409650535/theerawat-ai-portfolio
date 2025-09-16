#include <iostream>
using namespace std;

class IndexOutOfBounds : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error; // สืบทอด ctor ของ runtime_error
};

// a game score entry
class GameEntry
{
public:
    GameEntry(const string &n = "", int s = 0); // constructor
    string getName() const;                     // method : get player name
    int getScore() const;                       // method : get score
private:
    string name; // player's name
    int score;   // player's score
};

// provide the definitions of the class constructor
GameEntry::GameEntry(const string &n, int s)
    : name(n), score(s) {}

// provide the definitions of accessors method
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

class Scores
{
public:
    Scores(int maxEnt = 10);      // constructor
    ~Scores();                    // destructor
    void add(const GameEntry &e); // add a game entry
    GameEntry remove(int i);      // remove the i th entry
private:
    int maxEntries;     // maximum number of entries
    int numEntries;     // actual number if entries
    GameEntry *entries; // array of game entries
};

Scores::Scores(int maxEnt)
{
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores()
{
    delete[] entries;
}

void Scores::add(const GameEntry &e)
{
    int newScore = e.getScore();
    if (numEntries == maxEntries)
    {
        if (entries[maxEntries - 1].getScore() < newScore)
        {
            numEntries--;
        }
        else
            return;
    }

    // insertion sorting
    int i = numEntries - 1;
    while (i >= 0 && newScore > entries[i].getScore())
    {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
    numEntries++;
}

GameEntry Scores::remove(int i)
{
    if (i < 0 || i >= numEntries)
        throw IndexOutOfBounds("Invalid index");
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++)
    {
        entries[j - 1] = entries[j];
    }
    numEntries--;
    return e;
}

int main(int argc, char **argv)
{
}
