#include<iostream>
using namespace std;

/*
A19.2 In question 1, derive a class GameResult with an array of 5 int
type variables to store the result in each round. Result value is 2 for
win, 0 for lose and 1 for draw. Provide methods to set Result and
getResult. Write method to calculate final result of the game.
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
class GameResult: public Game
{
    private:
        int results[5];  // to store the result in each round
    public:
        void setResult(int round, int result) { results[round - 1] = result; }
        int getResult(int round) { return results[round - 1]; }
        void finalResult()
        {
            int i, winCount = 0;
            for(i = 0; i < 5; i++)
            {
                if(results[i] == 2)
                    winCount++;
            }
            if(winCount > 3)
                cout<<"Game Won"<<endl;
            else if(winCount == 3)
                cout<<"Game Draw"<<endl;
            else if(winCount < 3)
                cout<<"Game Lost"<<endl;
        }
    
};

int main()
{
    GameResult g1;
    g1.setScore(1, 45);
    g1.setScore(2, 90);
    g1.setScore(3, 25);
    g1.setScore(4, 50);
    g1.setScore(5, 100);
    cout<<"Game Scores are:"<<endl;
    int i;
    for(i = 0; i < 5; i++)
        cout<<"Round"<<i + 1<<" : "<<g1.getScore(i + 1)<<endl;
    
    g1.setResult(1, 0);
    g1.setResult(2, 2);
    g1.setResult(3, 0);
    g1.setResult(4, 1);
    g1.setResult(5, 2);
    cout<<"Game Results (Points of all rounds): "<<endl;
    for(i = 0; i < 5; i++)
        cout<<"Round"<<i + 1<<" : "<<g1.getResult(i + 1)<<endl;
    g1.finalResult();
    return 0;
}