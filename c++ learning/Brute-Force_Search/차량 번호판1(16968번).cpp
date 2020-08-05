#include <iostream>
using namespace std;
char num[10]={'0','1','2','3','4','5','6','7','8','9'};
char alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
int cnt=0;
string str;
void brute_force(char c, int len, int N){
    if(len==N){
        cnt++;
        return;
    }
    if(str[len]=='d'){
        for(int i=0;i<10;i++){
            if(c==num[i])
                continue;
            brute_force(num[i], len+1, N);
        }
    }else{
        for(int i=0;i<26;i++){
            if(c==alpha[i])
                continue;
            brute_force(alpha[i], len+1, N);
        }
    }
}
int main(void){
    cin>>str;
    if(str[0]=='d'){
        for(int i=0;i<10;i++){
            brute_force(num[i],1,str.length());
        }
    }else{
        for(int i=0;i<26;i++){
            brute_force(alpha[i],1,str.length());
        }
    }
    cout<<cnt<<'\n';
return 0;

}
