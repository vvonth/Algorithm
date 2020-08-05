#include <iostream>
using namespace std;
string str[50];
int cnt[50];
bool chk[50];
int main(void){
    int R,C,K;
    cin>>R>>C;
    
    for(int r=0;r<R;r++){
        cin>>str[r];
    }
    cin>>K;
    
    for(int r=0;r<R;r++){
        cnt[r]++;
        for(int r2=r+1;r2<R;r2++){
            if(str[r].compare(str[r2])==0){
                cnt[r]++;
                cnt[r2]++;
            }
        }
    }
    //최대 개수를 찾고 0의 개수를 찾는다.
    bool flag=false;
    if(K%2==0){
        flag=true;
    }
    int result;
    while(true){
        int m=0;
        int idx=0;
        for(int r=0;r<R;r++){
            if(chk[r]==true)
                continue;
            if(cnt[r]>m){
                m=cnt[r];
                idx=r;
            }
        }
        chk[idx]=true;
        int count=0;
        for(int i=0;i<str[idx].size();i++){
            if(str[idx][i]=='0'){
                count++;
            }
        }
        cout<<"idx: "<<idx<<' '<<str[idx]<<' '<<count<<'\n';
        if(flag&&count%2==0){
            if(K>=count){
                result=m;
                break;
            }
        }else if(!flag&&count%2==1){
            if(K>=count){
                result=m;
                break;
            }
        }
        bool chk2=true;
        for(int i=0;i<R;i++){
            if(!chk[i]){
               chk2=false;
                break;
            }
        }
        if(chk2){
            result=0;
            break;
        }
    }
    cout<<result<<'\n';
    return 0;
}
