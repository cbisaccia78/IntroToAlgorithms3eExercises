#include <vector>
#include <iostream>

#include <utilities.h>

using namespace std;

void _insertionSortNonDecreasing(vector<int> &A)
{
    for(int i = 1; i < A.size(); i++)
    {
        int key = A[i];
        int j = i - 1;
        int curr;
        while (j >= 0 && key < (curr = A[j]))
        {
                A[j+1] = curr;
                j--;
        }
        A[j+1] = key;
    }
}

void _insertionSortNonIncreasing(vector<int> &A)
{
    size_t A_size = A.size();
    for(int i = A_size - 2; i >= 0; i--)
    {
        int key = A[i];
        int j = i + 1;
        int curr;
        while (j < A_size && key < (curr = A[j]))
        {
                A[j-1] = curr;
                j++;
        }
        A[j-1] = key;
    }
}

void insertionSort(vector<int> &A, bool reverse = false)
{
    size_t A_size = A.size();
    if (A_size < 2)
        return;

    if (reverse)
    {
        _insertionSortNonIncreasing(A);
    }
    else
    {
        _insertionSortNonDecreasing(A);
    }
    
}

int main(int argc, char **argv)
{
    vector<int> v {4,2,7,2, 2, 1,3};
    insertionSort(v);
    printIterable(v);
    insertionSort(v, true);
    printIterable(v);
}