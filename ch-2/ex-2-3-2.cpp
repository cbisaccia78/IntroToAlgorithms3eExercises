#include <utilities.h>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

void merge(vector<double> &A, int p, int q, int r)
{

    
    vector<double> L(q-p+1, 0);
    vector<double> R(r-q, 0);


    int i;
    for(i = 0; i <= q-p; i++)
        L[i] = A[p + i];
    
    int j;
    int qplus1 = q + 1;
    for(j = 0; j < r-q; j++)
        R[j] = A[qplus1 + j];

    i = j = 0;
    int l_size = L.size();
    int r_size = R.size();
    while (i < l_size && j < r_size)
    {
        int left = L[i];
        int right = R[j];
        if (left <= right)
        {
            A[p + i + j] = left;
            i++;
        }
        else
        {
            A[p + i + j] = right;
            j++;
        }
    }

    if (i == l_size)
    {
        while (j < r_size)
        {
            A[p + l_size + j] = R[j];
            j++;
        }
    }
    else
    {
        while (i < l_size)
        {
            A[p + r_size + i] = R[i];
            i++;
        }
    }
}

void mergeSort(vector<double> &A, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(int argc, char **argv)
{
    vector<double> A = {2,5,8,1,4,9};
    mergeSort(A, 0, 5);
    printIterable(A);
}