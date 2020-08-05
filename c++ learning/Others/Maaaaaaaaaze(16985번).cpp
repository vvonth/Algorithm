//
//  Maaaaaaaaaze(16985번).cpp
//  c++ learning
//
//  Created by 원태희 on 22/08/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void rotate_dfs(int*, int);
void rotate(int select);
int arr[5][5][5];
int krr[5][5][5];
int tmp[5][5][5];
int crr[5];
bool chk;//한번이라도 입구 축구 통과하면 true, 아니면 false;
int m;
int main(void){
    for(int z=0;z<5;z++){
        for(int row=0;row<5;row++){
            for(int col=0;col<5;col++){
                cin>>arr[z][row][col];
                tmp[z][row][col]=arr[z][row][col];
            }
        }
    }
    //입력부분---------------------------
    int brr[4]={0,1,2,3};//회전 경우의 수
    m=126;
    rotate_dfs(brr, 0);
    if(m>=126)
        cout<<-1<<'\n';
    else
        cout<<m<<'\n';
    return 0;
}
//각 판의 순서를 정하는 순열
bool check[5];
bool visited[5][5][5];
int dx[]={0,0,1,-1,0,0};
int dy[]={1,-1,0,0,0,0};
int dz[]={0,0,0,0,1,-1};
int t[5][5][5];
bool bfs(){
    memset(visited, 0, sizeof(visited));
    memset(t, 0, sizeof(t));
    queue<pair<int,pair<int,int>>> q;
    visited[0][0][0]=true;
    q.push(make_pair(0,make_pair(0,0)));
    while(!q.empty()){
        int z=q.front().first;
        int y=q.front().second.first;
        int x=q.front().second.second;
        if(z==4&&y==4&&x==4){
            return true;
        }
        q.pop();
        for(int i=0;i<6;i++){
            int nz=z+dz[i];
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(nx>=0&&nx<5&&ny>=0&&ny<5&&nz>=0&&nz<5&&!visited[nz][ny][nx]&&krr[nz][ny][nx]){
                visited[nz][ny][nx]=true;
                t[nz][ny][nx]=t[z][y][x]+1;
                q.push(make_pair(nz, make_pair(ny, nx)));
            }
        }
    }
    return false;
}

void mix_dfs(int idx){
    if(idx==5){
        if(krr[0][0][0]==1&&krr[4][4][4]==1){
            //bfs 시작..
            chk=true;
            if(bfs()){
                if(m>t[4][4][4])
                    m=t[4][4][4];
            }
        }
        return;
    }
    for(int i=0;i<5;i++){
        if(!check[i])
        {
            check[i]=true;
            for(int row=0;row<5;row++){
                for(int col=0;col<5;col++){
                    krr[i][row][col]=arr[idx][row][col];
                }
            }
            mix_dfs(idx+1);
            check[i]=false;
        }
    }
}


//각 판 회전하는 순열
void rotate_dfs(int *brr, int idx){
    if(idx==5){
        for(int select=0;select<5;select++){
            int cnt=crr[select];
            for(int k=0;k<cnt;k++){
                rotate(select);
            }
        }
        //각 판의 순서를 섞는 순열
        mix_dfs(0);
        
        //배열 회전을 시켯으므로 각 배열 초기화 여기서 꼭 시켜줘야한다.
        for(int z=0;z<5;z++){
            for(int row=0;row<5;row++){
                for(int col=0;col<5;col++){
                    arr[z][row][col]=tmp[z][row][col];
                }
            }
        }
        return;
    }
    
    for(int i=0;i<4;i++){
        crr[idx]=brr[i];
        rotate_dfs(brr,idx+1);
    }
}


//회전 부분..4*4*4*4*4 순열
void rotate(int select){
    int brr[5][5]={0,};
    int m=4;
    for(int row=0;row<5;row++){
        for(int col=0;col<5;col++){
            brr[m-col][row]=arr[select][row][col];
        }
    }
    for(int row=0;row<5;row++){
        for(int col=0;col<5;col++){
            arr[select][row][col]=brr[row][col];
        }
    }
}
