//using matrix + backtracking
bool checkWordPresent(vector<vector<char>>&board,string word,int n,int m,int row,int col,int index){
	if(index==word.size()){
		return true;
	}
	if(row<0|| col<0||row>=n ||col>=m ||board[row][col]!=word[index]){
		return false;
	}
	char temp = board[row][col];
	board[row][col] = '*';
	bool ans1 = checkWordPresent(board,word,n,m,row+1,col,index+1);
	bool ans2 = checkWordPresent(board,word,n,m,row,col+1,index+1);
	bool ans3 = checkWordPresent(board,word,n,m,row-1,col,index+1);
	bool ans4 = checkWordPresent(board,word,n,m,row,col-1,index+1);
	board[row][col] = temp;
	return ans1||ans2||ans3||ans4;
}

bool exist(vector<vector<char>>board,string word){
	int n = board.size();
	int m = board[0].size();
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(checkWordPresent(board,word,n,m,i,j,0)){
			return true;
		}
	}
}
return false;
}