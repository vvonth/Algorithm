#include<iostream>
#include<stack>
using namespace std;
bool check[1000001];
int main(void){
    string sang,bomb;
    cin>>sang>>bomb;
    if(bomb.size()!=1){
        stack<pair<int,int>>s;//sang 인덱스, bomb 인덱스
        for(int i=0;i<sang.size();i++){//문자열의 길이
            if(sang[i]==bomb[0]){//첫째 문자가 같으면
                s.push(make_pair(i,0));
            }
            else{
                if(!s.empty()){//**
                    if(sang[i]==bomb[s.top().second+1]){
                        s.push(make_pair(i,s.top().second+1));
                        if(s.top().second==bomb.size()-1){//폭발 문자열이 끝이면
                            for(int i=0;i<bomb.size();i++){
                                check[s.top().first]=true;
                                s.pop();
                            }
                        }
                    }
                    else{
                        while(!s.empty()){
                            s.pop();
                        }
                    }
                }
            }
        }
        bool chk=false;
        for(int i=0;i<sang.size();i++){
            if(check[i]==false){
                cout<<sang[i];
                chk=true;
            }
        }
        if(!chk)
            cout<<"FRULA"<<'\n';
    }
    else{
        bool chk=false;
        for(int i=0;i<sang.size();i++){
            if(bomb[0]!=sang[i]){
                cout<<sang[i];
                chk=true;
            }
        }
        if(!chk){
            cout<<"FRULA"<<'\n';
        }
    }
    return 0;
}
