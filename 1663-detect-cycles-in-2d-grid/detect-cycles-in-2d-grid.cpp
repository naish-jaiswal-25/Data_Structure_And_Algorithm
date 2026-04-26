class Solution {
public:
    int rows, cols;
    
    bool dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited,
             int r, int c, int pr, int pc, char ch) {
        
        if (visited[r][c]) return true;
        
        visited[r][c] = true;
        
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];
            
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols 
                && grid[nr][nc] == ch) {
                
                if (nr == pr && nc == pc) continue;
                
                if (dfs(grid, visited, nr, nc, r, c, ch))
                    return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, visited, i, j, -1, -1, grid[i][j]))
                        return true;
                }
            }
        }
        
        return false;
    }
};