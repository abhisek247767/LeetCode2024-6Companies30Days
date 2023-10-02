//using BFS + Hashtable + string
int ladderLength(string src,string target,vector<string>&wordList){
	unordered_set<string>wset(wordList.begin(),wordList.end());
	
	queue<string>q;
	q.push(src);
	int ans{1};
	
	while(!q.empty()){
		int size = q.size();
		while(size-->0){
			src = q.front();
			q.pop();
			if(src==target){
				return ans;
			}
			
		for(int i=0;i<src.length();i++){
			auto originalChar = src[i];
			for(char c ='a';c<='z';c++){
				src[i] =c;
			if(wset.find(src)!=wset.end()){
				q.push(src);
			wset.erase(wset.find(src));
			}
		}
		src[i] = originalChar;
		}
	}
	ans++;
}
return 0;
}