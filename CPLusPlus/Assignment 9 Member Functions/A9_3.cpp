#include<iostream>
using namespace std;

/*
A9.3 Define a class TestResult with properties roll_no, right, wrong,
net_score. Also define class properties right_weightage, wrong_weightage.
Provide methods to set and get all the properties.
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
};
int TestResult:: right_weightage, TestResult:: wrong_weightage;

int main()
{
    TestResult r1;
    r1.setRollNumber(1);
    r1.setRight(6);
    r1.setWrong(4);
    r1.setNetScore(10);
    TestResult::setRightWeightage(60);
    TestResult::setWrongWeightage(40);
    cout<<"Roll Number: "<<r1.getRollNumber()<<endl;
    cout<<"Right: "<<r1.getRight()<<endl;
    cout<<"Wrong: "<<r1.getWrong()<<endl;
    cout<<"Net Score: "<<r1.getNetScore()<<endl;
    cout<<"Right Weightage: "<<TestResult::getRightWeightage()<<endl;
    cout<<"Wrong Weightage: "<<TestResult::getWrongWeightage()<<endl;
    return 0;
}