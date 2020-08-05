#include <iostream>
using namespace std;
int chess[10][10];
bool chk[10][10];
bool visited[10][10];
int result;
int origin;
int N;
void show(){
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            cout<<chk[r][c]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
void uncheck(int r, int c){
    int row=r;
    int col=c;
    while(row>=0&&col>=0){
        row--;
        col--;
        chk[row][col]=false;
        visited[row][col]=false;
    }
        row=r;
        col=c;
        while(row>=0&&col<N){
            row--;
            col++;
            chk[row][col]=false;
            visited[row][col]=false;
        }
        row=r;
        col=c;
        while(row<N&&col>=0){
            row++;
            col--;
            chk[row][col]=false;
            visited[row][col]=false;
        }
        row=r;
        col=c;
        while(row<N&&col<N){
            row++;
            col++;
            chk[row][col]=false;
            visited[row][col]=false;
        }

}
void check(int r, int c){
    int row=r;
    int col=c;
    while(row>=0&&col>=0){
        row--;
        col--;
        chk[row][col]=true;
        visited[row][col]=true;
    }
        row=r;
        col=c;
        while(row>=0&&col<N){
            row--;
            col++;
            chk[row][col]=true;
            visited[row][col]=true;
        }
        row=r;
        col=c;
        while(row<N&&col>=0){
            row++;
            col--;
            chk[row][col]=true;
            visited[row][col]=true;
        }
        row=r;
        col=c;
        while(row<N&&col<N){
            row++;
            col++;
            chk[row][col]=true;
            visited[row][col]=true;
        }
}
void recur(){
    
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            if(!visited[row][col]&&!chk[row][col]&&chess[row][col]==1){
                visited[row][col]=true;
                chk[row][col]=true;
                check(row,col);
                result+=1;
                show();
                recur();
                uncheck(row,col);
                result-=1;
                chk[row][col]=false;
                visited[row][col]=false;
            }
        }
    }
    if(origin<result)
        origin=result;
}

int main(void){
    cin>>N;
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            cin>>chess[r][c];
            if(r==0&&chess[r][c]==1){
               // chk[r][c]=true;
               // result+=1;
            }
        }
    }
    origin=0;
    recur();
    cout<<origin<<'\n';
}
