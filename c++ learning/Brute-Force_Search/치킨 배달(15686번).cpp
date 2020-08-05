//시간초과 해결...
//1.combination에서 map 복사하는 것 삭제
//2. best보다 s합이 클경우 바로 리턴
//3. bfs사용안하고 바로 거리 계산
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int map[50][50];
int copyMap[50][50];
vector<pair<int,int>> v;
vector<pair<int,int>>tmp;

int N,M;
int best;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int bfs(int R, int C){
    int result=0xfffff;
    for(auto x:tmp){
       result=min(result,abs(x.first-R)+abs(x.second-C));
    }
    return result;
}
void comb(int cnt, int size){
    if(tmp.size()==M){
        for(auto x:tmp){
            int r=x.first;
            int c=x.second;
            copyMap[r][c]=1;
        }
        //cout<<"끝"<<'\n';
        int s=0;
        for(int r=0;r<N;r++){
            for(int c=0;c<N;c++){
                if(map[r][c]==1){
                    s+=bfs(r,c);
                    if(best<s)
                        break;
                }
            }
            if(best<s)
                break;
        }
        for(auto x:tmp)
            copyMap[x.first][x.second]=0;
        best=min(best,s);
        return;
    }
    if(cnt==size)
    {
        return;
    }
    tmp.push_back(v[cnt]);
    comb(cnt+1,size);
    tmp.pop_back();
    comb(cnt+1,size);
}
int main(void){
    cin>>N>>M;
    best=0xfffff;
    for(int r=0;r<N;r++){
        for(int c=0;c<N;c++){
            cin>>map[r][c];
            if(map[r][c]==2){
                v.push_back({r,c});
            }
        }
    }
    int size=v.size();
    comb(0,size);
    cout<<best<<'\n';
    return 0;
}
