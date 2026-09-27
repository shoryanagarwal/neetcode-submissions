class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> v(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        queue<pair<int, int>> q;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!v[i][j] && grid[i][j] == '1') {
                    v[i][j] = true;

                    ans++;
                    q.push({i, j});

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() ||
                                v[nx][ny] == true || grid[nx][ny] == '0') {
                                continue;
                            }

                            q.push({nx, ny});
                            v[nx][ny] = true;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
