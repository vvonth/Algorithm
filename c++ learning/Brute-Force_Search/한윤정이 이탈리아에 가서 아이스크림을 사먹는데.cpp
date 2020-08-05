#include <iostream>
#include <vector>
using namespace std;
vector<int>adj[10000];
int result;
bool check(int ice[]){
    for(auto x: adj[ice[0]]){
        if(x==ice[1]){
            return false;
        }
    }
    return true;
}

void comb(int value,int cnt,int ice[], int N){
    if(cnt==3){
        bool flag=true;
        for(auto x: adj[ice[0]]){
            if(x==ice[2]){
                flag=false;
            }
        }
        for(auto x: adj[ice[1]]){
            if(x==ice[2]){
                flag=false;
            }
        }
        if(flag){
//            for(int i=0;i<3;i++){
//                cout<<ice[i]<<' ';
//            }
//            cout<<'\n';
            result++;
        }
        return;
    }
    if(cnt==2&&!check(ice)){
        return;
    }
    for(int i=value;i<=N;i++){
        ice[cnt]=i;
        comb(i+1,cnt+1,ice,N);
    }
}

int main(void){
    
    int N,M,a,b;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ice[3];
    comb(1,0,ice,N);
    cout<<result<<'\n';
    return 0;
}
