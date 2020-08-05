#include <iostream>
using namespace std;
int arr[500][500];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int memo[500][500];
int isvisited[500][500];
int M,N;
int func(int x, int y){
    if(x==0&&y==0){
        
        return 1;
    }
    if(isvisited[x][y]){
        return memo[x][y];
    }
    for(int k=0;k<4;k++){
        int nx=dx[k]+x;
        int ny=dy[k]+y;
        if(nx>=0&&nx<M&&ny>=0&&ny<N&&arr[nx][ny]>arr[x][y]){
            memo[x][y]+=func(nx,ny);
        }
    }
    isvisited[x][y]=1;
    return memo[x][y];
}
int main(void){
    cin>>M>>N;
    for(int r=0;r<M;r++){
        for(int c=0;c<N;c++){
            cin>>arr[r][c];
        }
    }
    cout<<func(M-1,N-1)<<'\n';
    return 0;
}

