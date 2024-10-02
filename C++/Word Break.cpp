//using string + DP(tabulation) + hashtable
bool wordBreak(string s,vector<string>&wordDict){
	vector<bool>dp(s.size()+1,0);
	dp[0] = true;
	unordered_set<string>st(wordDict.begin(),wordDict.end());
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<i;j++){
			if(dp[j] && st.count(s.substr(j,i-j))){
				dp[i] = true;
				break;
			}
		}
	}
	return dp[s.size()];
}