#include <iostream>
using namespace std;
int N,M;
int flag;
//답 대문자 소문자 판별
char map[50][50];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int visited[50][50];
void cycle(int,int,int,int,int);
int main(void){
    cin>>N>>M;
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            cin>>map[n][m];
        }
    }
    for(int n=0;n<N;n++){
        for(int m=0;m<M;m++){
            visited[n][m]=1;
            cycle(n,m,n,m,0);
            if(flag==1){
                cout<<"Yes"<<'\n';
                return 0;
            }
            visited[n][m]=0;
        }
    }
    
    cout<<"No"<<'\n';
    return 0;
}
void cycle(int r, int c ,int start_x,int start_y,int cnt){
    if(cnt>2){
        for(int k=0;k<4;k++){
            int nr=r+dx[k];
            int nc=c+dy[k];
            if(nr==start_x&&nc==start_y){
                flag=1;
                return;
            }
            
        }
    }
    if(r+1<N&&!visited[r+1][c]&&map[r+1][c]==map[r][c]){
        visited[r+1][c]=true;
        cycle(r+1,c,start_x,start_y,cnt+1);
        visited[r+1][c]=false;
    }
    if(r-1>=0&&!visited[r-1][c]&&map[r-1][c]==map[r][c]){
        visited[r-1][c]=true;
        cycle(r-1,c,start_x,start_y,cnt+1);
        visited[r-1][c]=false;
    }
    if(c+1<M&&!visited[r][c+1]&&map[r][c+1]==map[r][c]){
        visited[r][c+1]=true;
        cycle(r,c+1,start_x,start_y,cnt+1);
        visited[r][c+1]=false;
    }
    if(c-1>=0&&!visited[r][c-1]&&map[r][c-1]==map[r][c]){
        visited[r][c-1]=true;
        cycle(r,c-1,start_x,start_y,cnt+1);
        visited[r][c-1]=false;
    }
}
