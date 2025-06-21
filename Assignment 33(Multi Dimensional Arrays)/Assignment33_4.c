/* A33.4 Four players are playing a tournament of Chess with round robin 
method (each player will play with every other player). Each win has 2 points,
draw has 1 point and loose has 0 points. Declare a score_board two dimensional 
array to store the scores of the players against each player. (Completed)
5. For que-4, define a function to update score_board after each match result.
(Completed) 
6. For que-4, define a function to display score_board.
(Completed)
7. For que-4, define a function which returns the score of a specific player.
(Completed)
8. For que-4, define a function to find the winner of the tournament.
(Completed)
9. For que-4, define a function to display rank of the players.
(Completed)
10. For que-4, define a function to run tournament, in which user has to enter result of
each game and update score board using score_board function.
(Completed)
*/

#include<stdio.h>

void updateScoreBoard(int p1Num, int p1Match, int p2Num, int p2Match, int score_board[4][3], int result)
{
    /*
    Function parameters meanings:-
    p1Num : player number of first player
    p1Match : match number of first player
    p2Num : player number of second player
    p2Match : match number of second player
    score_board[4][3] : current score board of all match results of all players
    
    result: result of the match
    Possible values that can be passed in this function parameter:-
    p1Num : if first player wins
    p2Num : if second player wins
    (any other value (try to pass negative value for better clarity)) : if match draw
    */
    
    if(result == p1Num)
        score_board[p1Num - 1][p1Match - 1] += 2;
    else if(result == p2Num)
        score_board[p2Num - 1][p2Match - 1] += 2;
    else
    {
        score_board[p1Num - 1][p1Match - 1]++;
        score_board[p2Num - 1][p2Match - 1]++;
    }
}

void displayScoreBoard(int score_board[4][3])
{
    int totalScores[4] = {0}, i, j;
    for(i = 0; i < 4; i++)
        for(j = 0; j < 3; j++)
            totalScores[i] += score_board[i][j];
    printf("\nCurrent Score Board is:\n");
    for(i = 0; i < 4; i++)
        printf("Player %d:\t%d\n", i + 1, totalScores[i]);
}

int PlayerScore(int score_board[4][3], int playerNumber)
{
    int i, playerTotalScore = 0;
    for(i = 0; i < 3; i++)
        playerTotalScore += score_board[playerNumber - 1][i];
    return playerTotalScore;
}

void displayTournamentWinner(int score_board[4][3])
{
    int winnerScore = PlayerScore(score_board, 1), i;
    for(i = 1; i < 4; i++)
    {
        if(PlayerScore(score_board, i + 1) > winnerScore)
            winnerScore = PlayerScore(score_board, i + 1);
    }
    printf("Tournament Winner:\n");
    for(i = 0; i < 4; i++)
    {
        if(PlayerScore(score_board, i + 1) == winnerScore)
        {
            printf("Player %d, ", i + 1);
        }
    }
    printf("\b\b  ");
}

int findWinnerScore(int score_board[4][3])
{
    int winnerScore = PlayerScore(score_board, 1), i;
    for(i = 1; i < 4; i++)
    {
        if(PlayerScore(score_board, i + 1) > winnerScore)
            winnerScore = PlayerScore(score_board, i + 1);
    }
    return winnerScore;
}

void SortArrayinDescending(int arr[], int size)
{
    int i, j;
    for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
            if(arr[j] > arr[i])
            {
                arr[j] = arr[j] + arr[i];
                arr[i] = arr[j] - arr[i];
                arr[j] = arr[j] - arr[i];
            }
}

int firstElementIndexOfArray(int arr[], int size, int element)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(arr[i] == element)
            return i;
    }
    return -1;
}

void displayPlayerNamesWithScore(int score_board[4][3], int score)
{
    int j;
    for(j = 0; j < 4; j++)
    {
        if(score == PlayerScore(score_board, j + 1))
        {
            printf("Player %d, ", j + 1);
        }
    }
    printf("\b\b  ");

}

void displayPlayerRanks(int score_board[4][3])
{
    int i, j, distinctScores[4] = {-1, -1, -1, -1}, distinctLastIndex = -1;
    for(j = 0; j < 4; j++)
    {
        for(i = 0; i <= distinctLastIndex; i++)
        {
            if(PlayerScore(score_board, j + 1) == distinctScores[i])
                break;
        }
        if(i > distinctLastIndex)
        {
            distinctLastIndex++;
            distinctScores[distinctLastIndex] = PlayerScore(score_board, j + 1);
        }
    }
    SortArrayinDescending(distinctScores, distinctLastIndex + 1);
    // printf("Distinct Scores in descending order are:\n");
    // for(i = 0; i <= distinctLastIndex; i++)
    // {
    //     printf("%d, ", distinctScores[i]);
    // }
    // printf("\b\b  ");
    printf("\nRank of all players in Chess Tournament:\n");
    for(i = 0; i <= distinctLastIndex; i++)
    {
        printf("Rank %d : ", i + 1);
        displayPlayerNamesWithScore(score_board, distinctScores[i]);
        printf("\n");
    }
}

void runTournament(int score_board[4][3])
{
    int result[6] = {0}, i;
    printf("\nMatch 1-> 1 Vs 2:\n");
    printf("\nMatch 2-> 1 Vs 3:\n");
    printf("\nMatch 3-> 1 Vs 4:\n");
    printf("\nMatch 4-> 2 Vs 3:\n");
    printf("\nMatch 5-> 2 Vs 4:\n");
    printf("\nMatch 6-> 3 Vs 4:\n");
    for(i = 0; i < 6; i++)
    {
        printf("Enter result of match %d: ", i + 1);
        scanf("%d", &result[i]);
    }
    updateScoreBoard(1, 1, 2, 1, score_board, result[0]);
    updateScoreBoard(1, 2, 3, 1, score_board, result[1]);
    updateScoreBoard(1, 3, 4, 1, score_board, result[2]);
    updateScoreBoard(2, 2, 3, 2, score_board, result[3]);
    updateScoreBoard(2, 3, 4, 2, score_board, result[4]);
    updateScoreBoard(3, 3, 4, 3, score_board, result[5]);
    
}

int main()
{
    int score_board[4][3] = {0};
    /*
    updateScoreBoard(1, 1, 2, 1, score_board, 2);
    updateScoreBoard(1, 2, 3, 1, score_board, -1);
    updateScoreBoard(1, 3, 4, 1, score_board, 4);
    updateScoreBoard(2, 2, 3, 2, score_board, 2);
    updateScoreBoard(2, 3, 4, 2, score_board, 2);
    updateScoreBoard(3, 3, 4, 3, score_board, 4);
    */
    runTournament(score_board);
    //displayScoreBoard(score_board);
    int playerNumber = 2;
    // printf("Player %d score : %d\n", playerNumber, PlayerScore(score_board, 2));
    //displayTournamentWinner(score_board);
    displayPlayerRanks(score_board);
    return 0;
}