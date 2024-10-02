//using Two pointers + string
string reverseWords(string s){
	int n = s.length();
	int i=0;
	string res;
	
	while(i<n){
		while(i<n && s[i]==' '){
			i++;
		}
		if(i>=n)
		break;
		int j = i+1;
		
		while(j<n && s[j]!=' '){
			j++;
		}
		
		string sub = s.substr(i,j-i);
		if(res.length()==0)
		res = sub;
		else{
			res = sub+" "+res;
		}
		i = j+1;
	}
	return res;
}