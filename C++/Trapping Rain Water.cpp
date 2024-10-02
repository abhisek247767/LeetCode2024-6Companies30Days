//using Two pointer+dynamic programming
int trap(vector<int>&nums){
	int n = nums.size();
	int a[n],b[n];
	a[0] = nums[0];
	b[0] = nums[n-1];
	
	//Moving left 
	for(int i=1;i<n;i++){
		a[i] = max(a[i-1,nums[i]]);
	}
	
	//Moving right
	for(int i= n-2;i>=0;i--){
		b[i] = max(b[i+1],nums[i]);
	}
	
	int res =0;
	for(int i=0;i<n;i++){
		res += (min(a[i],b[i]))-nums[i];
	}
	return res;
}
