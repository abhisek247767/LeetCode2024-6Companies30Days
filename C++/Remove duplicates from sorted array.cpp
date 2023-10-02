//using Two pointers
int removeDuplicates(vector<int>&nums){
	for(int i=0;i<nums.size();i++){
		for(int j=i+1;j<nums.size();j++){
			if(nums[i]==nums[j]){
				nums.erase(nums.begin()+j);
				j--;
			}
		}
	}
	return nums.size();
}