//using matrix + simulation
vector<int>spiralOrder(vector<vector<int>>&matrix){
	int sRow =0,sCol =0;
	int eRow = matrix.size()-1;
	int eCol = matrix[0].size()-1;
	
	vector<int>ans;
	
	while(sRow<=eRow && sCol<=eCol){
		//left to right
		for(int i=sCol;i<eCol;i++){
			ans.push_back(matrix[sRow][i]);
		}
		sRow++;
		
		//from top to bottom
		for(int i=sRow;i<=eRow;i++){
			ans.push_back(matrix[i][eCol]);
		}
		eCol--;
		
		if((sRow>eRow) || (sCol>eCol)){
			break;
		}
		
		//from right to left
		for(int i=eCol;i>=sCol;i--){
			ans.push_back(matrix[eRow][i]);
		}
		eRow--;
		
		//from bottom to top
		for(int i=eRow;i>=sRow;i--){
			ans.push_back(matrix[i][sCol]);
		}
		sCol++;
	}
	return ans;
}