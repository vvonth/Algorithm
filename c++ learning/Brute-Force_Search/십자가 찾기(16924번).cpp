#include <iostream>
using namespace std;
char map[100][100];
bool visited[100][100];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int R,C;
int cross_cnt;
int answer[10000][3];
void print(){
    cout<<"----출력-------"<<'\n';
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            cout<<map[r][c];
        }
        cout<<'\n';
    }
    cout<<"----END-------"<<'\n';
}

bool cross(int r, int c,int size){
    for(int k=0;k<4;k++){
        int nr=r;
        int nc=c;
        for(int s=0;s<size;s++){
            nr+=dx[k];
            nc+=dy[k];
            if(nr<0||nr>=R||nc<0||nc>=C||map[nr][nc]=='.')
                return false;
        }
    }
    return true;
}
void check(int r, int c, int size){
    visited[r][c]=true;
    for(int k=0;k<4;k++){
        int nr=r;
        int nc=c;
        for(int s=0;s<size;s++){
            nr+=dx[k];
            nc+=dy[k];
            if(nr>=0&&nr<R&&nc>=0&&nc<C&&map[nr][nc]=='*'){
                visited[nr][nc]=true;
            }
        }
    }
}

int main(void)
{
    cin>>R>>C;
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            cin>>map[r][c];
        }
    }
    int q=0;
    for(int r=1;r<R-1;r++){
        for(int c=1;c<C-1;c++){
            if(map[r][c]=='*'){
                int cnt;
                for(cnt=1;;cnt++){
                    if(!cross(r,c,cnt)){
                        break;
                    }
                }
                if(cnt>1){
                    check(r,c,cnt-1);
                    cross_cnt++;
                    answer[q][0]=r+1;
                    answer[q][1]=c+1;
                    answer[q][2]=cnt-1;
                    q++;
                }
            }
        }
    }
    if(cross_cnt>R*C){
        cout<<-1<<'\n';
        return 0;
    }
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(map[r][c]=='*'&&!visited[r][c]){
                cout<<-1<<'\n';
                return 0;
            }
        }
    }
    
    cout<<cross_cnt<<'\n';
    for(int i=0;i<q;i++){
        cout<<answer[i][0]<<' '<<answer[i][1]<<' '<<answer[i][2];
        cout<<'\n';
    }
    
    return 0;
}
