#include <iostream>
#include <queue>
#include <map>
#include<set>
using namespace std;
int arr[5][5];
queue<pair<pair<int,int>,string>> q;
set<string> se;
int main(void){
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            cin>>arr[r][c];
        }
    }
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            
            string s=""+to_string(arr[r][c]);
            q.push({{r,c},s});
            while(!q.empty()){
                int x=q.front().first.first;
                int y=q.front().first.second;
                string s=q.front().second;
                q.pop();
                if(s.length()<6){
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        string ns=s;
                        if(nx>=0&&nx<5&&ny>=0&&ny<5){
                            ns+=to_string(arr[nx][ny]);
                            q.push({{nx,ny},ns});
                        }
                    }
                }else{
                    se.insert(s);
                    
                }
            }
        }
    }
    cout<<se.size()<<'\n';
    return 0;
}
