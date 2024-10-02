Problem Statement :

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Output:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]


Input: nums = [2,0,1]
Output: [0,1,2]


#include<iostream>
using namespace std;


// Function to sort the colors
vector<int> sortColors(vector<int>& nums) {
        int high=nums.size()-1, low = 0 , mid =0;
        while(mid<=high)
        {
            if( nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++; mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[high],nums[mid]);
                high--;
            }
        } 
	return nums;
    }


int main()
{
	vector <int> nums=[2,0,1,1,1,0,2];
	sorted=sortColors(nums);
	for(int i=0;i<sorted.size();i++)
		print(sorted[i]);
 	return 0 ; 	
}