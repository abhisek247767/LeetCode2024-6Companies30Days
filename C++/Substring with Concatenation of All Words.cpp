//using hashmap + sliding window
vector<find>findSubstring(string s,vector<string>&words){
	vector<int>ans;
	
	int n= words.size();
	int m = words[0].size();
	int total = n*m;
	
	if(s.size()<total){
		return ans;
	}
	
	for(int i=0;i<s.size()-total;i++){
		unordered_map<string,int>mp;
		
		for(int j=0;j<words.size();j++){
		mp[words[j]]++;
	}
	
	int k;
	for(k=0;k<=n;k++){
		string temp = s.substr(i+k*m);
		if(mp.count(temp)==0){
			break;
		}
		else{
			if(mp[temp]!=0){
				mp[temp]--;
			}
			else{
				break;
			}
		}
	}
	if(k==n){
		ans.push_back(i);
	}
}
return ans;
	
}