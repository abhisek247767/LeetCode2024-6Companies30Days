//using array + prefixsum
vector<int>productExceptSelf(vector<int>&nums){
	int n = nums.size();
	int p = nums[0];
	
	vector<int>ans(n,1);
	for(int i=1;i<n;i++){
		ans[i] =p;
		p = p*nums[i];
	}
	p = nums[n-1];
	for(int i=n-2;i>=0;i--){
		ans[i] = ans[i]*p;
		p = p*nums[i];
	}
	return ans;
}