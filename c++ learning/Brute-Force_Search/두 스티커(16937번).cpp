#include <iostream>
#include <vector>
using namespace std;
bool visited[100][100];
vector<pair<int,int>>v;
int H,W,N;
int m;

void brute_force(int idx,int cnt,int brr[]){
    if(cnt==2){
        int x1=v[brr[0]].first;
        int y1=v[brr[0]].second;
        int x2=v[brr[1]].first;
        int y2=v[brr[1]].second;
        int result1=max(x1,y2);
        if(result1<=H){
            if(x2+y1<=W){
                m=max(x1*y1+x2*y2,m);
            }
        }
        if(result1<=W){
            if(x2+y1<=H){
                 m=max(x1*y1+x2*y2,m);
            }
        }
        result1=max(x1,x2);
        if(result1<=H){
            if(y2+y1<=W){
                m=max(x1*y1+x2*y2,m);
            }
        }
        if(result1<=W){
            if(y2+y1<=H){
                 m=max(x1*y1+x2*y2,m);
            }
        }
        result1=max(x2,y1);
        if(result1<=H){
            
            if(x1+y2<=W){
                m=max(x1*y1+x2*y2,m);
            }
        }
        if(result1<=W){
            if(x1+y2<=H){
                 m=max(x1*y1+x2*y2,m);
            }
        }
        result1=max(y1,y2);
        if(result1<=H){
            if(x2+x1<=W){
                m=max(x1*y1+x2*y2,m);
            }
        }
        if(result1<=W){
            if(x2+x1<=H){
                 m=max(x1*y1+x2*y2,m);
            }
        }
        return;
    }
    if(idx==N)
        return;
    brr[cnt]=idx;
    brute_force(idx+1,cnt+1,brr);
    brute_force(idx+1,cnt,brr);
    
}
int main(void){
    cin>>H>>W;
    cin>>N;
    int x,y;
    for(int i=0;i<N;i++){
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    int brr[2];
    brute_force(0,0,brr);
    cout<<m<<'\n';
    return 0;
}
