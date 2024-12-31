/*
 Write code for selection sort. 
 
 What loop invariant does this algorithm maintain? 
    - At each iteration start of the while loop, A[1..i-1] contains the i-1th smallest 
    elements of the array, sorted. 
 Why does it need to run for only the first n-1 elements, rather than for all n elements? 
     - because once it hits n-1, it swaps the n-1th element with the last element, which is 
     vaccuously the smallest element. so after n-1th iteration the entire array is sorted. 
 Give the best-case and worst-case running times of selection sort in O notation.
    - best case = worst case = O(n)
 */

#include <utilities.h>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

int minElement(vector<int> &A, int start, int end)
{
    int smallestIndexSoFar = -1;
    int smallestSoFar = numeric_limits<int>::max();
    int i = start;
    while (i < end)
    {
        const auto& num = A[i];
        if (num < smallestSoFar)
        {
            smallestSoFar = num;
            smallestIndexSoFar = i;
        }
        i++;
    }
    return smallestIndexSoFar;
}
/*
find the smallest element
of A and exchange it with the element in A[1] . Then find the second smallest
element of A, and exchange it with A[2] . Continue in this manner for the first n-1
elements of A.
*/
void selectionSort(vector<int> &A)
{// [4,12,1,9,3] - [1], [1,12]
    size_t size = A.size();
    int smallest_idx, smallest, i = 0;
    while (i < size - 1)
    {
        smallest_idx = minElement(A, i, size);// 
        smallest = A[smallest_idx];
        A[smallest_idx] = A[i];
        A[i] = smallest;
        i++;
    }
}

int main(int argc, char **argv)
{
    vector<int> v {4,2,7,2, 2, 1,3};
    printIterable(v);
    selectionSort(v);
    printIterable(v);
}