//
//  빙산(2573번).cpp
//  c++ learning
//
//  Created by 원태희 on 2019/10/27.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[300][300];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
vector<pair<int,int>> v;
int visited[300][300];
int n;
int m;
void init(vector<int>&);
void bfs(int,int);
int main(void){
    cin>>n>>m;
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            cin>>map[r][c];
            if(map[r][c]!=0){
                v.push_back(make_pair(r, c));
            }
        }
    }
    vector<int>v2(v.size());
    int cnt2=0;
    int year=0;
    while(true){
        year++;
        init(v2);
        cnt2=0;
        int size=v.size();
        for(int i=0;i<size;i++){
            int x=v[i].first;
            int y=v[i].second;
            if(map[x][y]==0)
                continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(map[nx][ny]==0){
                    v2[i]++;
                    
                }
            }
        }
        for(int i=0;i<size;i++){
            map[v[i].first][v[i].second]-=v2[i];
            if(map[v[i].first][v[i].second]<0)
                map[v[i].first][v[i].second]=0;
        }
        //덩어리 분리 검사
        for(int i=0;i<size;i++){
            if(!visited[v[i].first][v[i].second]&&map[v[i].first][v[i].second]!=0){
                bfs(v[i].first,v[i].second);
                cnt2++;
            }
        }
        
        if(cnt2>1||cnt2==0){
            break;
        }
        
    }
    if(cnt2==0){
        cout<<0<<'\n';
    }else{
    cout<<year<<'\n';
    }
    return 0;
}
void bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(!visited[nx][ny]&&map[nx][ny]!=0){
                visited[nx][ny]=1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}
void init(vector<int> &v2){
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            visited[r][c]=0;
        }
    }
    for(int i=0;i<v2.size();i++){
        v2[i]=0;
    }
}
