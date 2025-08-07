#include<iostream>
using namespace std;

/*
A19.1 Define a class Game with an array of 5 int variables as instance
member to store the score of each of 5 rounds. Provide method to
setScore(int round, int score). Also provide method getScore(int round).
(Completed)
*/
class Game
{
    private:
        int scores[5]; // to store the score of each of 5 rounds
    public:
        void setScore(int round, int score) { scores[round - 1] = score; }
        int getScore(int round) { return scores[round - 1]; }
};

int main()
{
    Game g1;
    g1.setScore(1, 45);
    g1.setScore(2, 90);
    g1.setScore(3, 25);
    g1.setScore(4, 50);
    g1.setScore(5, 100);
    cout<<"Game Scores are:"<<endl;
    int i;
    for(i = 0; i < 5; i++)
        cout<<"Round"<<i + 1<<" : "<<g1.getScore(i + 1)<<endl;
    return 0;
}
