#include <iostream>
using namespace std;
string s;
int s1;
int big;
bool chk[10];
void perm(int cnt, char a[]){
    if(a[0]=='0')
        return;
    if(cnt==s.length()){
        int num=0;
        int mul=1;
        for(int i=cnt-1;i>=0;i--){
            num+=mul*(a[i]-'0');
            
            mul*=10;
        }
        if(num<s1){
            big=max(big,num);
        }
        return;
    }
    for(int i=0;i<s.length();i++){
        if(!chk[i]){
            chk[i]=true;
            a[cnt]=s[i];
            perm(cnt+1,a);
            chk[i]=false;
        }
    }
}
int main(void){
    
    cin>>s>>s1;
    char a[10];
    perm(0,a);
    if(big==0){
        big=-1;
    }
    cout<<big<<'\n';
    return 0;
}

