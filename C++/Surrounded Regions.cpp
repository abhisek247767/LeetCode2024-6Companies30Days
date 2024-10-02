//using DFS appraoch
void dfs(vector<vector<char>>&board,int x,int y,vector<vector<int>>&vis,int dx[],int dy[],int n,int m){
		for(int i=0;i<4;i++){
			int nr = x+dx[i];
			int nc = y+dy[i];
		if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='0'){
			vis[nr][nc] =1;
			dfs(board,nr,nc,vis,dx,dy,n,m);
		}
	}
}

void solve(vector<vector<char>>&board){
	int n = board.size();
	int m = board[0].size();
	
	vector<vector<int>>vis(n,vector<int>(m,0));
	int dx[] = {0,1,0,-1};
	int dy[] = {1,0,-1,0};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0||j==0||i==(n-1)||j==(m-1)){
				if(board[i][j]=='0' && !vis[i][j]){
					vis[i][j] =1;
					dfs(board,i,j,vis,dx,dy,n,m);
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(board[i][j]=='0' && !vis[i][j])
			board[i][j] ='X';
		}
	}
}