# Game of Life :-

[Problem Link] :--- (https://leetcode.com/problems/game-of-life/description/)

<h3>
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.<br><br>

Example 1:<br>
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]<br>
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]<br><br>
Example 2:<br>
Input: board = [[1,1],[1,0]]<br>
Output: [[1,1],[1,1]]<br>


Constraints:<br>
m == board.length<br>
n == board[i].length<br>
1 <= m, n <= 25<br>
board[i][j] is 0 or 1.<br>
  
</h3>

***Solution***

```

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        for(int a=0;a<n;a++){
            for(int b=0;b<m;b++){
                int count=0;
                for(int c=a-1;c<=a+1;++c){
                    for(int d=b-1;d<=b+1;++d){
                        if(c==a && d==b) continue;
                        if(c>=0 && c<n && d>=0 && d<m && (board[c][d]==1 || board[c][d]==3)){
                            count++;
                        }
                    }
                }

                if(board[a][b]==1 && (count<2 || count>3)){
                    board[a][b]=3;
                }
                if(board[a][b]==0 && count==3){
                    board[a][b]=2;
                }
            }
        }
        for(int a=0;a<n;++a){
            for(int b=0;b<m;++b){
                if(board[a][b]==3){
                    board[a][b]=0;
                }
                if(board[a][b]==2){
                    board[a][b]=1;
                }
            }
        }
    }
};

```
