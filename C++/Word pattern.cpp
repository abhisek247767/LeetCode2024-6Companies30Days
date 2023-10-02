//using hash table + string
bool wordPattern(string pattern,string s){
	unordered_map<char,int>mp1;
	unordered_map<string,int>mp2;
	
	vector<string>v;
	string temp ="";
	for(int i=0;i<s.size();i++){
		temp +=s[i];
		if(s[i+1]==' '){
		v.push_back(temp);
		temp ="";
		i++:
		continue;
		
	}
	if(i==s.size()-1){
		v.push_back(temp);
		break;
	}
}

	int i=0,n = pattern.size();
	if(v=size()!=n)
		return false;

	while(i<n){
	if(i==n || mp1[pattern[i]!=mp2[v[i]])
		return false;
	mp1[pattern][i]]=i+1;
	mp2[v[i]] = i+1;
	i++;
}
	return i==n;
}