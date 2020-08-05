#include <iostream>
using namespace std;
int main(void){
    int a1,a2;
    int train=0;
    int m=0;
    for(int i=0;i<4;i++){
        cin>>a1>>a2;
        train+=a2-a1;
        m=max(m,train);
    }
    cout<<m<<'\n';
    return 0;
}
