#include <utilities.h>
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

void merge(vector<double> &A, int p, int q, int r)
{

    
    vector<double> L(q-p+2, 0);
    vector<double> R(r-q, 0);

    // sentinals
    double infinity = numeric_limits<double>::infinity();
    L[q-p+1] = infinity;
    R[r-q] = infinity;

    int i;
    for(i = 0; i <= q-p; i++)
        L[i] = A[i];
    
    int j;
    int qplus1 = q + 1;
    for(j = 0; j < r-q; j++)
        R[j] = A[j+qplus1];

    i = j = 0;
    for (int k = p; k < r; k++)
    {
        double l = L[i], r = R[j];
        if (l <= r)
        {
            A[k] = l;
            i++;
        }
        else
        {
            A[k] = r;
            j++;
        }
    }
}

void mergeSort(vector<double> &A, int p, int r)
{
    if (p < r - 1)
    {
        int q = (p + r - 1) / 2;
        mergeSort(A, p, q+1);
        mergeSort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main(int argc, char **argv)
{
    vector<double> A = {2,5,8,1,4,9};
    mergeSort(A, 0, 6);
    printIterable(A);
}