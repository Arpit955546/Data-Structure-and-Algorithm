class Solution {
public:

    bool dfs(int row, int col, int m, int n, int index,
             vector<vector<char>> &mat, string &word) {
        if(index == word.size())
            return true;
        if(row < 0 || col < 0 || row >= m || col >= n 
           || mat[row][col] != word[index])
            return false;
        
        char temp = mat[row][col];
        mat[row][col] = '#';  
        
        int dr[4] = {-1,0,1,0};
        int dc[4] = {0,-1,0,1};
        
        for(int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            
           
            if(dfs(nr, nc, m, n, index+1, mat, word))
                return true;
        }
        
        
        mat[row][col] = temp;  // backtrack
        return false;
    }

    bool exist(vector<vector<char>> &mat, string &word) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == word[0]) {
                    if(dfs(i, j, m, n, 0, mat, word))
                        return true;
                }
            }
        }
        
        return false;
    }
};