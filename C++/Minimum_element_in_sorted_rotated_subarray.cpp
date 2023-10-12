Problem statement:

Given a sorted array arr[] (may be distinct or may contain duplicates) of size N that is rotated at some unknown point, the task is to find the minimum element in it. 

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum value
int findMin(int arr[], int n)
{
	int min_ele = arr[0];

	// Traversing over array to
	// find minimum element
	for (int i = 0; i < n; i++) {
		if (arr[i] < min_ele) {
			min_ele = arr[i];
		}
	}

	return min_ele;
}

// Driver code
int main()
{
	int arr[] = { 5, 6, 1, 2, 3, 4 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	cout << findMin(arr, N) << endl;
	return 0;
}
