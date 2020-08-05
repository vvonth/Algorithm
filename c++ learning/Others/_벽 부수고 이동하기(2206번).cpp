//
//  벽 부수고 이동하기(2206번).cpp
//  c++ learning
//
//  Created by 원태희 on 25/08/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int arr[1000][1000];
int visited[2][1000][1000];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int t[1000][1000];
void print(int N, int M){
    for(int row=0;row<N;row++){
        for(int col=0;col<M;col++){
            printf("arr[%d][%d]: %d",row,col, arr[row][col]);
        }
    }
}

void bfs(int row, int col,int N, int M){
    queue<pair<int,pair<int,int>>> q;
    q.push(make_pair(1,make_pair(row, col)));
    visited[1][row][col]=1;
    while(!q.empty()){
        int x=q.front().second.first;
        int y=q.front().second.second;
        int possible=q.front().first;
        if(x==N-1&&y==M-1){
            return;
        }
        q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                //기회가 있고 벽이 1 일경우 부순다.
                if(possible&&arr[nx][ny]==1){
                    q.push(make_pair(0, make_pair(nx, ny)));
                    t[nx][ny]=t[x][y]+1;
                }
                //벽이 0일 경우 큐에 넣는다.
                if(arr[nx][ny]==0&&!visited[possible][nx][ny]){
                    visited[possible][nx][ny]=1;
                    q.push(make_pair(possible,make_pair(nx, ny)));
                    t[nx][ny]=t[x][y]+1;
                }
            }
        }
    }
}
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int row=0;row<N;row++){
        for(int col=0;col<M;col++){
            scanf("%1d",&arr[row][col]);
        }
    }
    //---------------------------
    bfs(0,0,N,M);
    if(N==1&&M==1){
        printf("%d\n",1);
    }
    else if(!t[N-1][M-1]){
        printf("%d\n",-1);
    }
    else{
        printf("%d\n",t[N-1][M-1]+1);
    }
    return 0;
}
