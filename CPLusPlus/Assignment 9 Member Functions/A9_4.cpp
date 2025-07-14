#include<iostream>
using namespace std;

/*
A9.4 Write a driver function main() to use TestResult class (Question 3).
Create an array to 5 TestResult objects, set values to all the objects
and display the results in sorted order (by net_score).
(Completed)
*/
class TestResult
{
    private:
        int roll_no, right, wrong, net_score;
        static int right_weightage, wrong_weightage;
    public:
        void setRollNumber(int r)
        {
            roll_no = r;
        }
        void setRight(int r)
        {
            right = r;
        }
        void setWrong(int w)
        {
            wrong = w;
        }
        void setNetScore(int score)
        {
            net_score = score;
        }
        static void setRightWeightage(int rw)
        {
            right_weightage = rw;
        }
        static void setWrongWeightage(int ww)
        {
            wrong_weightage = ww;
        }
        int getRollNumber()
        {
            return roll_no;
        }
        int getRight()
        {
            return right;
        }
        int getWrong()
        {
            return wrong;
        }
        int getNetScore()
        {
            return net_score;
        }
        static int getRightWeightage()
        {
            return right_weightage;
        }
        static int getWrongWeightage()
        {
            return wrong_weightage;
        }
        void setAllproperties(int r, int ri, int w, int score)
        {
            roll_no = r;
            right = ri;
            wrong = w;
            net_score = score;
        }
        void showAllResult()
        {
            cout<<"Roll Number: "<<getRollNumber()<<endl;
            cout<<"Right: "<<getRight()<<endl;
            cout<<"Wrong: "<<getWrong()<<endl;
            cout<<"Net Score: "<<getNetScore()<<endl;
        }
};

void swapResultObjects(TestResult &r1, TestResult &r2)
{
    TestResult temp;
    temp = r1;
    r1 = r2;
    r2 = temp;
}
void sortArrayOfTestResultObjectsOnBasisOfNetScore(TestResult arr[], int size)
{
   int i,j;
   for(i=0;i<size-1;i++)
        for(j=i+1;j<size;j++)
            if(arr[j].getNetScore() < arr[i].getNetScore())
                swapResultObjects(arr[j], arr[i]);
}

int main()
{
    TestResult r1[5];
    r1[0].setAllproperties(1, 6, 4, 10);
    r1[1].setAllproperties(2, 16, 18, 5);
    r1[2].setAllproperties(3, 32, 64, 3);
    r1[3].setAllproperties(4, 80, 40, 40);
    r1[4].setAllproperties(5, 55, 45, 35);
    sortArrayOfTestResultObjectsOnBasisOfNetScore(r1, 5);
    cout<<"Test Results after swapping on the basis of net score:"<<endl;
    int i;
    for(i = 0; i < 5; i++)
    {
        r1[i].showAllResult();
    }

    // test code to test swap objects function
    // TestResult r1, r2;
    // r1.setAllproperties(1, 40, 8, 32);
    // r2.setAllproperties(2, 50, 60, -10);
    // r1.showAllResult();
    // r2.showAllResult();
    // swapResultObjects(r1, r2);
    // cout<<"results output after swapping objects:"<<endl;
    // r1.showAllResult();
    // r2.showAllResult();
    // TestResult::setRightWeightage(60);
    // TestResult::setWrongWeightage(40);
    // cout<<"Right Weightage: "<<TestResult::getRightWeightage()<<endl;
    // cout<<"Wrong Weightage: "<<TestResult::getWrongWeightage()<<endl;
    return 0;
}