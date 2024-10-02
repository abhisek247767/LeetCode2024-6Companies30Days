//using matrix+math
void rotate(vector<vector<int>>&matrix){
	int n = matrix.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			swap(matrix[i][j],matrix[j][i]);
		}
	}
	for(int i=0;i<n;i++){
	//reverse i-th row
	reverse(matrix[i].begin(),matrix[i].end());
}