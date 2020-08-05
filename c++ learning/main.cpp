#include<iostream>
using namespace std;

int solution(int n,int x, int weight[]){
    int result=0xfffff;
    pair<int,int> best[1<<n];
    best[0]={1,0};
    for(int s=1;s<(1<<n);s++){
        best[s]={n+1,0};
        for(int p=0;p<n;p++){
            if(s&(1<<p)){
                auto option=best[s^(1<<p)];
                int n1=s^(1<<p);
                cout<<"s: "<<s<<' '<<"p: "<<p<<'\n';
                cout<<"s^(1<<p): "<<n1<<'\n';
                cout<<"weight["<<p<<"]: "<<weight[p]<<'\n';
                if(option.second+weight[p]<=x){
                    option.second+=weight[p];
                }else{
                    option.first++;
                    option.second=weight[p];
                }
                cout<<"best["<<n1<<"]: "<<option.first<<' '<<option.second<<'\n';
                cout<<"best["<<s<<"]: "<<best[s].first<<' '<<best[s].second<<'\n';
                best[s]=min(best[s],option);
                cout<<"best["<<s<<"]: "<<best[s].first<<' '<<best[s].second<<'\n';
            }
        }
        cout<<"---------------count: "<<s<<"---------------"<<'\n';
        result=best[s].first;
    }
    return result;
}
int main(void){
    int weight[5]={2,3,4,5,9};
   cout<< solution(5,12,weight)<<'\n';
    return 0;
}


