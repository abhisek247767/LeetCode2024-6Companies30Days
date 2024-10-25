#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to swap elements if the element in arr1 is greater than the element in arr2
    void swapIfGreater(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2) {
        if (arr1[ind1] > arr2[ind2]) {
            swap(arr1[ind1], arr2[ind2]); //mno loop so no increment and decrement
        }
    }

    // Function to merge two sorted arrays
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        int len = n + m;

        // Initial gap
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                // Case 1: left in arr1 and right in arr2
                if (left < n && right >= n) {
                    swapIfGreater(arr1, arr2, left, right - n);
                }
                // Case 2: both pointers in arr2
                else if (left >= n) {
                    swapIfGreater(arr2, arr2, left - n, right - n); //you know why right - n
                }
                // Case 3: both pointers in arr1
                else {
                    swapIfGreater(arr1, arr1, left, right);
                }
                left++;
                right++;
            }

            // Break if iteration gap=1 is completed
            if (gap == 1) break;

            // Otherwise, calculate new gap
            gap = (gap / 2) + (gap % 2);
        }

        // Copy remaining elements of arr2 to arr1 if any
        for (int i = 0; i < m; i++) {
            arr1[n + i] = arr2[i]; //arr1 taking additional elements from array 2 to store
        }
    }
};
