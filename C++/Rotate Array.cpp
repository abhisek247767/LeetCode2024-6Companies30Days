//using two pointers
void rotate(vector<int>&nums,int k){
	vector<int>vec;
	int n= nums.size();
	if(k>nums.size()){
		k = k%n;
	}
	
	for(int i=0;i<n;i++){
		vec.push_back(nums[i]);
	}
	for(int i=0;i<k;i++){
		nums[i] = vec[n-k+i];
	}
	
	for(int i=0;i<n-k;i++){
		nums[k+i] = vec[i];
	}
	return;
}