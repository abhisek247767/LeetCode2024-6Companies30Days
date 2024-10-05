// C++ program to find all unique triplets that sum to zero

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all unique triplets that sum to zero
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > result;

    // Sort the array to allow two-pointer technique
    sort(nums.begin(), nums.end());

    // Traverse the array
    for (int i = 0; i < nums.size(); i++) {
        // Skip duplicate elements for the first number
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        // Use two pointers to find pairs that sum to -nums[i]
        int left = i + 1, right = nums.size() - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Found a triplet
                vector<int> triplet;
                triplet.push_back(nums[i]);
                triplet.push_back(nums[left]);
                triplet.push_back(nums[right]);
                result.push_back(triplet);

                // Skip duplicates for the second and third numbers
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                // Move the pointers
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

/* Driver program to test the function */
int main() {
    // Test case 1
    int arr1[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<vector<int> > result1 = threeSum(nums1);
    cout << "Triplets that sum to zero in [-1, 0, 1, 2, -1, -4] are:\n";
    for (int i = 0; i < result1.size(); i++) {
        cout << "[" << result1[i][0] << ", " << result1[i][1] << ", " << result1[i][2] << "]\n";
    }

    // Test case 2
    int arr2[] = {0, 1, 1};
    vector<int> nums2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<vector<int> > result2 = threeSum(nums2);
    cout << "Triplets that sum to zero in [0, 1, 1] are:\n";
    for (int i = 0; i < result2.size(); i++) {
        cout << "[" << result2[i][0] << ", " << result2[i][1] << ", " << result2[i][2] << "]\n";
    }

    // Test case 3
    int arr3[] = {0, 0, 0};
    vector<int> nums3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<vector<int> > result3 = threeSum(nums3);
    cout << "Triplets that sum to zero in [0, 0, 0] are:\n";
    for (int i = 0; i < result3.size(); i++) {
        cout << "[" << result3[i][0] << ", " << result3[i][1] << ", " << result3[i][2] << "]\n";
    }

    return 0;
}
