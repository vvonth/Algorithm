#include <iostream>
#include <vector>
using namespace std;
char map[30][30];
bool visited[30][30];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int n,m;
int answer;
void dfs(int r, int c,int cnt,int allCnt,int dir){
    vector<pair<int,int>> v;
    if(allCnt==0){
        answer=min(answer,cnt);
        return;
    }
    for(int k=0;k<4;k++){
        int nr=r;
        int nc=c;
        //끝까지 이동하는 곳.....
        if(k==dir){
            continue;
        }
        bool flag=false;
        int count=0;
        while(true){
            nr+=dx[k];
            nc+=dy[k];
            if(nr<0||nr>=n||nc<0||nc>=m||visited[nr][nc]||map[nr][nc]=='*')
                break;
            flag=true;
            visited[nr][nc]=true;
            v.push_back({nr,nc});
            map[nr][nc]='B';
            count++;
            //cout<<"nr: "<<nr<<"nc: "<<nc<<'\n';
        }
        
        //끝까지 이동 했어.. 그러면 어케해야돼? 다음 이동할 곳을 찾아야돼;
        nr-=dx[k];
        nc-=dy[k];
        /*for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                cout<<map[r][c];
            }
            cout<<'\n';
        }
        cout<<"allCnt: "<<allCnt<<'\n';
        cout<<"!nr: "<<nr<<"!nc: "<<nc<<'\n';*/
        if(flag)
            dfs(nr,nc,cnt+1,allCnt-count,k);
        for(auto x: v){
            visited[x.first][x.second]=false;
            map[x.first][x.second]='.';
        }
    }
}

int main(void){
    int cnt=1;
    while(cin>>n>>m){
    int allCnt=0;
    answer=0xffffff;
    
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            cin>>map[r][c];
            if(map[r][c]=='.'){
                allCnt++;
            }
        }
    }
    for(int r=0;r<n;r++){
        for(int c=0;c<m;c++){
            if(map[r][c]=='.'){
                visited[r][c]=true;
                map[r][c]='B';
                dfs(r,c,0,allCnt-1,-1);
                visited[r][c]=false;
                    map[r][c]='.';
            }
        }
    }
        if(answer==0xffffff){
            cout<<"Case "<<cnt++<<": "<< -1<<'\n';
        }else{
            cout<<"Case "<<cnt++<<": "<< answer<<'\n';
        }
    }
    return 0;
}
