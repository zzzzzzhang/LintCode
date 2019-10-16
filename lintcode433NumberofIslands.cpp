#include<vector>
#include<typeinfo>
#include<iostream>
using namespace std;
class Solution {
public:
    /**
     * @param grid: a boolean 2D matrix
     * @return: an integer
     */
    int numIslands(vector<vector<bool>> &grid) {
        // write your code here
        if ( grid.empty() || grid[0].empty() ) return 0;
        int row = grid.size();
        int col = grid[0].size();
//        cout<<row<<" "<<col<<endl;
        int cnt = 0;
//        cout<<typeid(grid[0][0]).name()<<endl;
        for(int r=0; r < row; r++){
        	for(int c=0; c < col; c++){
//        		cout<<grid[r][c]<<endl;
        		if(grid[r][c]){
        			dfs(grid, r, c);
        			cnt++;
				}
			}
		}
		return cnt;
    }
private:
	void dfs(vector<vector<bool>> &grid, int i, int j){
		int row = grid.size();
		int col = grid[0].size();
		if (i<0||j<0||row<=i||col<=j) return;
		if (!grid[i][j]) return;
		grid[i][j] = false;
		dfs(grid, i-1, j);
		dfs(grid, i+1, j);
		dfs(grid, i, j-1);
		dfs(grid, i, j+1);
	}
};
int main(){
	Solution solve;
	int out = 0;
	vector<vector<bool>> grid = {{1,1,0,0,0},{0,1,0,0,1},{0,0,0,1,1},{0,0,0,0,0},{0,0,0,0,1}};
	out = solve.numIslands(grid);
	cout<<out<<endl;
}
