#include<bits/stdc++.h>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    int fresh = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }else if(grid[i][j]==1){
                fresh++;
            }
        }
    }
    if(fresh==0){
        return 0;
    }
    int time = 0;
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            pair<int,int> p = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x = p.first+dx[i];
                int y = p.second+dy[i];
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1){
                    grid[x][y] = 2;
                    q.push({x,y});
                    fresh--;
                }
            }
        }
        time++;
    }
    if(fresh>0){
        return -1;
    }
    return time-1;
}

int main(){
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout<<orangesRotting(grid)<<endl;
    return 0;
}