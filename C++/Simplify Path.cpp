//using stack+string
string simplifyPath(string path){
	stack<string>st;
	string ans;
	
	for(int i=0;i<path.size();i++){
		if(path[i]=='/')
		continue;
		
		string temp;
		
		while(i<path.size() && path[i]!='/'){
			temp +=path[i];
			i++;
		}
		
		if(temp=='.'){
			continue;
		else if(temp =".."){
			if(!st.empty))
			st.pop();
		}
		else
			st.push(temp);
	}
	
	while(!st.empty()){
		ans ="/"+st.top()+ans;
		st.pop();
	}
	
	if(ans.size()==0)
	return "/";
	
	return ans;
}