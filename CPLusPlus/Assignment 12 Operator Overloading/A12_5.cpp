#include<iostream>
using namespace std;

/*
A12.5 Define a class Matrix to represent 3X3 matrix. Provide appropriate
instance methods. Also define operator+, operator-, operator* to perform
addition, subtraction and multiplication operations respectively.
(Completed)
*/
class Matrix
{
    private:
        int m[3][3];
    public:
        void setMatrixValues(int mat[3][3])
        {
            int i, j;
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    m[i][j] = mat[i][j];
                }
            }
        }
        void printMatrix()
        {
            int i, j;
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    cout<<m[i][j]<<"\t";
                }
                cout<<endl;
            }
        }
        Matrix operator+(Matrix m2)
        {
            Matrix sum;
            int i, j;
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    sum.m[i][j] = m[i][j] + m2.m[i][j];
                }
            }
            return sum;
        }
        Matrix operator-(Matrix m2)
        {
            Matrix difference;
            int i, j;
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    difference.m[i][j] = m[i][j] - m2.m[i][j];
                }
            }
            return difference;
        }
        Matrix operator*(Matrix m2)
        {     
            Matrix product;
            int arr[3][3] = {0}, i, j, k;
            product.setMatrixValues(arr);
            for(i = 0; i < 3; i++)
                for(j = 0; j < 3; j++)
                    for(k = 0; k < 3; k++)
                        product.m[i][j] += m[i][k] * m2.m[k][j];
            return product;
        }
};


int main()
{
    
    return 0;
}