//using Two pointers + string
bool isPalindrome(string s){
	if(s.size()==0){
		return true;
	}
	
	int i=0;
	int j=s.size()-1;
	
	while(i<j){
		if(isalnum(s[i])==false){
			i++:
			continue;
		}
		
		if(isalnum(s[j])==false){
			j--;
			continue;
		}
		
		if(tolower(s[j])!=tolower(s[i])){
			return false;
		}
		else{
			i++,j--;
		}
	}
	return true;
}