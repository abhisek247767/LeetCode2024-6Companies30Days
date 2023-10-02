//using ordered map
int removeDuplicates(vector<int>&nums){
	map<int,int>mp;
	for(int i=0;i<nums.size();i++){
		mp[nums[i]]++;
	}
	
	int idx =0;
	for(auto x= mp.begin();x!=mp.end();x++){
		int cnt = (x->second<=2)?x->second:2;
		while(cnt){
			nums[idx++] = it->first;
			cnt--;
		}
	}
	return idx;
}