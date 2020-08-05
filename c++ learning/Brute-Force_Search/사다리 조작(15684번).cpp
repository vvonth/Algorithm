#include <iostream>
using namespace std;
int map[40][20];
int N,M,H;
//1이 왼쪽에 있으면 왼쪽으로 이동 1이 자기 자신에 있으면 오른쪽으로 이동
void print(){
    for(int r=0;r<H+2;r++){
        for(int c=0;c<N+1;c++){
            cout<<map[r][c]<<' ';
        }
        cout<<'\n';
    }
}
bool action(){
    for(int c=1;c<=N;c++){
        int x=c;
        int y=0;
        while(true){
            if(y==H+1){
                break;
            }
            if(map[y][x]==1){
                x++;
            }else if(x-1>0&&map[y][x-1]==1){
                x--;
            }
            y++;
        }
       if(x!=c){
            return false;
        }
    //cout<<"c: "<<c<<' '<<"x: "<<x<<'\n';
    }
    return true;
}
//사다리 갯수 놓기
int m=21473822;
void comb(int cnt,int row){
    if(cnt>3){
        return;
    }
    if(m<=2)
        return;
    for(int r=row;r<=H;r++){
        for(int c=1;c<N;c++){
            if(map[r][c]!=1&&map[r][c-1]!=1){
                map[r][c]=1;
                if(action()){
                    m=min(m,cnt);
                }else{
                    comb(cnt+1,r);
                }
                map[r][c]=0;
                
            }
            if(m==1)
                break;
        }
        if(m==1)
            break;
    }
    
}
int main(void){
    cin>>N>>M>>H;
    for(int i=0;i<M;i++){
        int R,C;
        cin>>R>>C;
        map[R][C]=1;
    }
   //print();
    if(action())
        m=0;
    else{
        comb(1,1);
    }
    if(m>3)
        cout<<-1<<'\n';
    else{
        cout<<m<<'\n';
    }
    return 0;
}

