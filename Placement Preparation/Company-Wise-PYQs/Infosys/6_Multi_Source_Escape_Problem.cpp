// Problem:
// Given an N x M grid containing:
// '.' = empty cell
// '#' = wall
// 'F' = fire source
// 'H' = human
//
// Fire spreads to adjacent cells every minute.
// The human can also move to adjacent cells every minute.
// Determine whether the human can reach any boundary cell
// before the fire reaches that cell.
//
// Approach:
// 1. Multi-Source BFS from all fire cells to compute fire arrival times.
// 2. BFS from the human, moving only if the human reaches a cell
//    strictly before the fire.
// 3. If the human reaches any boundary cell, return "YES"; otherwise "NO".
#include<bits/stdc++.h>
using namespace std;

string canEscape(vector<string>& grid, int n, int m){
    vector<vector<int>>fireTime(n,vector<int>(m,INT_MAX));
    vector<vector<int>>humanTime(n,vector<int>(m,-1));
    queue<pair<int,int>>fireQueue;
    queue<pair<int,int>>humanQueue;vector<pair<int,int>>dir={
        {1,0}, {-1,0}, {0,-1}, {0,1}
    };
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='F'){
                fireTime[i][j]=0;
                fireQueue.push({i,j});
            }
            else if(grid[i][j]=='H'){
                humanTime[i][j]=0;
                humanQueue.push({i,j});
            }
        }
    }

    // FIRE BFS
    while(!fireQueue.empty()){
        auto [x,y]=fireQueue.front();
        fireQueue.pop();
        for(auto [dx,dy]:dir){
            int nx=x+dx;
            int ny=y+dy;
            if((nx>=0 && nx<n)&&
            (ny>=0 && ny<m) &&
            (grid[nx][ny]!='#')&&
            (fireTime[nx][ny]==INT_MAX)){
                fireTime[nx][ny]=fireTime[x][y]+1;
                fireQueue.push({nx,ny});
            }
        }
    }
    // Human BFS
    while(!humanQueue.empty()){
        auto [x,y]=humanQueue.front();
        humanQueue.pop();
        // Escape if boundary is reached
        if((x==0 || x==n-1 || y==0 || y==m-1) && humanTime[x][y]<fireTime[x][y]){
            return "YES";
        }
        for(auto [dx,dy]:dir){
            int nx=x+dx;
            int ny=y+dy;
            if((nx>=0 && nx<n) && (ny>=0 && ny<m) && (grid[nx][ny]!='#' && (humanTime[nx][ny]==-1))){
                int nextTime=humanTime[x][y]+1;
                if(nextTime < fireTime[nx][ny]){
                    humanTime[nx][ny]=nextTime;
                    humanQueue.push({nx,ny});
                }
            }
        }
    }
    return "NO";
}

int main(){
    int n,m; cin>>n>>m;
    vector<string>grid(n);
    for(int i=0;i<n;i++) cin>>grid[i];
    cout<< canEscape(grid,n,m);
}