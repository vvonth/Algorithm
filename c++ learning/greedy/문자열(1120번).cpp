#include <iostream>
using namespace std;
int diff;
int main(void){
    string a,b;
    cin>>a>>b;
        int m=9999;
        diff=b.length()-a.length();
        for(int start=0;start<=diff;start++){
            int cnt=0;
            for(int j=0;j<a.length();j++){
                if(a[j]!=b[start+j]){
                    cnt++;
                }
            }
            m=min(cnt, m);
        }
    cout<<m<<'\n';
    return 0;
}
