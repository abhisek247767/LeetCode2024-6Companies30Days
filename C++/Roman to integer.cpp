//using string + math
int romanToInt(string s){
	vector<int>roman(128);
	
	int ans=0;
	roman['I'] =1;
	roman['V'] =5;
	roman['X'] =10;
	roman['L'] =50;
	roman['C'] =100;
	roman['D'] =500;
	roman['M'] =1000;
	
	for(int i=0;i<s.size();i++){
		if(roman[s[i]]<roman[s[i+1]]){
			ans = ans+roman[s[i+1]]-roman[s[i]]-roman[s[i+1]];
		}
		else{
			ans  = ans+roman[s[i]]+roman[s[i+1]]-roman[s[i+1]];
		}
	}
	return ans;
}