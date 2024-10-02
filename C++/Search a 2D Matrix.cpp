//using binary search + matrix
bool searchMatrix(vector<vector<int>>&matrix,int target){
	int rows = matrix.size();
	int col = matrix[0].size();
	int i=0,j=col-1;
	
	while(i<rows && j>=0){
		if(matrix[i][j]==target)
		return true;
		else if(matrix[i][j]<target)
		i++;
		else
		j--;
	}
	return false;
}