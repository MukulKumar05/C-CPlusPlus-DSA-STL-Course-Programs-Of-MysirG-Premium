#include<iostream>
using namespace std;

/*
A9.5 Define a class Matrix to represent a 3X3 order matrix. Provide appropriate
methods and properties to the class. Also define following methods in the
class:
1. Matrix add(Matrix)
2. Matrix sub(Matrix)
3. Matrix multiply(Matrix)
4. Matrix transpose()
5. bool is_singular()
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
        Matrix add(Matrix m2)
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
        Matrix sub(Matrix m2)
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
        Matrix multiply(Matrix m2)
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
        Matrix transpose()
        {
            Matrix trans;
            int i, j;
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    trans.m[i][j] = m[j][i];
                }
            }
            return trans;
        }
        int determinant()
        {
            return m[0][0]*(m[1][1]*m[2][2]-m[2][1]*m[1][2])-m[0][1]*(m[2][2]*m[1][0]-m[2][0]*m[1][2])+m[0][2]*(m[2][1]*m[1][0]-m[2][0]*m[1][1]);
        }
        bool is_singular()
        {
            if(determinant())
                return false;
            return true;
        }
};


int main()
{
    Matrix m1, m2, sum, difference, product, m2Transposed;
    int arr1[3][3] = {4, -3, 5, 1, 0, 3, -1, 5, 2};
    int arr2[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    m1.setMatrixValues(arr1);
    m2.setMatrixValues(arr2);
    sum = m1.add(m2);
    difference = m1.sub(m2);
    product = m1.multiply(m2);
    m2Transposed = m2.transpose();
    product.printMatrix();
    // cout<<"Determinant of matrix m1 is "<<m1.determinant()<<endl;
    // if(m2.is_singular())
    //     cout<<"Matrix is singular matrix"<<endl;
    // else
    //     cout<<"Matrix is non-singular matrix"<<endl;
    return 0;
}