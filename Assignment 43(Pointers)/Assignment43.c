#include<stdio.h>
#include<string.h>

/*
A43.1 Write a function to swap strings of two char arrays.
(Completed)
*/

void swapStrings(char* str1, char* str2)
{
    char temp[100] = "\0";
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

/*
A43.2 Write a function to sort an array of int type values. [void sort(int* ptr, int size);]
(Completed)
*/
void sort(int* ptr, int size)
{
   int i, j;
   for(i = 0; i < size - 1; i++)
        for(j = i + 1; j < size; j++)
            if(ptr[j] < ptr[i])
            {
                ptr[j] = ptr[j] + ptr[i];
                ptr[i] = ptr[j] - ptr[i];
                ptr[j] = ptr[j] - ptr[i];
            }
}

/*
A43.3 Write a function to merge two arrays in a given array. [void merge(int* arr1, int 
size1, int* arr2, int size2, int* arr3);]
(Completed)
*/
void merge(int* arr1, int size1, int* arr2, int size2, int* arr3)
{
    int i;
    for(i = 0; i < size1; i++)
        arr3[i] = arr1[i];
    for(i = 0; i < size2; i++)
        arr3[i + size1] = arr2[i];    
}

/*
A43.4 Write a function to move first value of the array to the position where all smaller
values will be in the left and greater values will be in the right.
(Completed)
*/
// this question can be solved by using this function which is defined in A43.2
// void sort(int* ptr, int size) 

/*
A43.5 There are five classes with different number of students in them. Five arrays
containing marks of students of each class. Write a function to receive an address
of an array of pointers to access marks of all the students. The job of function is to
find the highest marks among all the classes.

(Completed)
*/
int highestMarksAmongAllClasses(int** allClassMarks, int* studentsCount)
{
    int maxMarks = -1, i, j;
    for(i = 0; i < 5; i++) // iterating through all classes
    {
        for(j = 0; j < studentsCount[i]; j++) // iterating through all marks of every class
        {
            if(allClassMarks[i][j] > maxMarks)
                maxMarks = allClassMarks[i][j];
        }
    }
    return maxMarks;
}

int main()
{
    // char str[100] = "\0", str2[100] = "\0";
    // printf("Enter string1: ");
    // fgets(str, sizeof(str), stdin);
    // str[strcspn(str, "\r\n")] = 0;
    // printf("Enter string2: ");
    // fgets(str2, sizeof(str2), stdin);
    // str2[strcspn(str2, "\r\n")] = 0;
    // printf("Before Swapping:\n");
    // printf("String1: \"%s\"\n", str);
    // printf("String2: \"%s\"\n", str2);
    // swapStrings(str, str2);
    // printf("After Swapping:\n");
    // printf("String1: \"%s\"\n", str);
    // printf("String2: \"%s\"\n", str2);

    // int a[10] = {31, 67, 18, 15, 78, 24, 9, 3, 2, 17}, i;
    // printf("Array before sorting is:\n");
    // for(i = 0; i < 10; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    // sort(a, 10);
    // printf("\nArray after sorting is:\n");
    // for(i = 0; i < 10; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    // int i, a1[5] = {2, 4, 6, 8, 10}, a2[7] = {11, 22, 33, 44, 55, 66, 77}, a3[100] = {0};
    // merge(a1, 5, a2, 7, a3);
    // printf("Merged array is:\n");
    // for(i = 0; i < 12; i++)
    // {
    //     printf("%d ", a3[i]);
    // }

    int m1[3] = {36, 29, 11}, m2[5] = {76, 74, 82, 40, 53};
    int m3[7] = {7, 14, 21, 28, 35, 42, 49};
    int m4[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int m5[11] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 46, 89};
    int *allMarks[5] = {m1, m2, m3, m4, m5};
    int studentsCount[5] = {3, 5, 7, 9, 11};
    int maxMarks = highestMarksAmongAllClasses(allMarks, studentsCount);
    printf("Maximum marks among all classes is %d", maxMarks);
    return 0;
}
