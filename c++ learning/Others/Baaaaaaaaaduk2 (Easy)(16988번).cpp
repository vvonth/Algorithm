#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int arr[20][20];
bool visited[20][20];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int result;
bool chk;
int cnt;
void bfs(int row, int col,int N,int M){
    queue<pair<int,int>>q;
    cnt=1;
    chk=false;
    q.push(make_pair(row, col));
    visited[row][col]=true;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nx=x+dx[k];
            int ny=y+dy[k];
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&arr[nx][ny]==0){
                chk=true;
            }
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&!visited[nx][ny]&&arr[nx][ny]==2){
                    visited[nx][ny]=true;
                    q.push(make_pair(nx, ny));
                    cnt++;
               // printf("nx:%d ny:%d cnt:%d\n" , nx, ny,cnt);
              //  cout<<chk<<'\n';
            }
        }
    }
}
void recur(int N,int M,int R,int idx){
    if(idx==2){
        //bfs로 2의 돌을 세면서 주변에 0을 발견
        int m=0;
        memset(visited,0,sizeof(visited));
        for(int row=0;row<N;row++){
            for(int col=0;col<M;col++){
                if(!visited[row][col]&&arr[row][col]==2){
                    bfs(row,col,N,M);
                    if(!chk){
                        m+=cnt;
                       // printf("m: %d\n",m);
                    }
                }
            }
        }
        if(result<m)
            result=m;
        return;
    }
    for(int row=R;row<N;row++){
        for(int col=0;col<M;col++){
            if(arr[row][col]==0){
                arr[row][col]=1;
                for(int k=0;k<4;k++){
                    int nr=row+dx[k];
                    int nc=col+dy[k];
                    if(arr[nr][nc]==2){
                        recur(N,M,row,idx+1);
                        break;
                    }
                }
                arr[row][col]=0;
            }
        }
    }
}

int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    for(int row=0;row<N;row++){
        for(int col=0;col<M;col++){
            scanf("%d",&arr[row][col]);
        }
    }
    //---------------------------------
    recur(N,M,0,0);
    printf("%d\n",result);
}
