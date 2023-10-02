//using string
string convert(string s,int numRows){
	if(numRows==1)
	return s;
	
	bool down = true;
	string arr[numRows];
	int row =0;
	for(int i=0;i<s.size();i++){
		arr[row].push_back(s[i]);
		if(row==numsRows-1)
		down = false;
		else if(row==0)
		down = true;
		if(down)
		row++;
		else
		row--;
	}
	
	string res ="";
	for(int i=0;i<numRows;i++){
		res +=arr[i];
	}
	return res;
}
