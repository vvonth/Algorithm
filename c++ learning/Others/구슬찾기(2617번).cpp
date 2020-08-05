#include <iostream>
#include <vector>
using namespace std;
int arr[100];
bool visited[100];
vector<int> heavy[100];
vector<int>light[100];
int heavyCnt=0;
int lightCnt=0;
void heavyRecur(int);
void lightRecur(int);
void init(int);
int result;
int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    int x, y;
    if(N==1){
        cout<<0<<'\n';
    }else{
        for(int i=0;i<M;i++){
            scanf("%d %d",&x,&y);
            heavy[y].push_back(x);//x보다 무거운 번호 저장
            light[x].push_back(y);//y보다 가벼운 번호 저장
        }
        
        for(int i=1;i<=N;i++){
            heavyCnt=lightCnt=0;
            init(N);
            visited[i]=true;
            heavyRecur(i);
            init(N);
            visited[i]=true;
            lightRecur(i);
            if(heavyCnt>=(N+1)/2||lightCnt>=(N+1)/2){
                result++;
            }
        }
        cout<<result<<'\n';
    }
    return 0;
}
void init(int N){
    for(int i=1;i<=N;i++){
        visited[i]=false;
    }
}
void lightRecur(int n){
    for(int i=0;i<light[n].size();i++){
        if(!visited[light[n][i]]){
            visited[light[n][i]]=true;
            //cout<<"가벼운 것:"<<light[n][i]<<'\n';
            lightRecur(light[n][i]);
            lightCnt++;
        }
    }
}
void heavyRecur(int n){
    for(int i=0;i<heavy[n].size();i++){
        if(!visited[heavy[n][i]]){
            visited[heavy[n][i]]=true;
            //cout<<"무거운 것:"<<heavy[n][i]<<'\n';
            heavyRecur(heavy[n][i]);
            heavyCnt++;
        }
    }
}
