#include <vector>
#include <utilities.h>
#include <iostream>

using namespace std;

/**
 * worst case is O(log(n))
 * 
 * justification:
 *       ^
 *   1   |   c         
 *       |   |
 *   2   |   c
 *       .
 *       .
 *       |   |
 * log(n)|   c
 * 
 * 
 *  constant steps per level, log(n) + 1 total levels = c*(log(n) + 1) = O(log(n))
 *      
 */
int binarySearch(vector<double> &A, double key)
{
    int high = A.size() - 1;
    int low = 0;

    while (low <= high)
    {
        int half_index = (low + high) / 2;
        int half_val = A[half_index];

        if (key == half_val)
            return half_index;
        else if (key < half_val)
            high = half_index - 1;
        else
            low = half_index + 1;
    }
    return -1;
    
}

int main(int argc, char **argv)
{
    vector<double> A = {1.0, 4.0, 8.0, 12.0, 15.0, 19.0};
    cout << binarySearch(A, 22.0) << '\n';
}