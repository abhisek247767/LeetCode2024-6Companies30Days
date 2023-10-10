// C++ code to implement the approach

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
