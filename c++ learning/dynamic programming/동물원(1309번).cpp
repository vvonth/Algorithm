#include <iostream>
using namespace std;
int jail[2][100000];
//문제점: dp[w][h]+=dp[w-1][h-1]+dp[w][h-2]까지 잘 생각했으나 dp[w-1][h-2]이 부분이 어떻게 보면 dp[w-1][h-1]에 들어가 있기 때문에 생각할 필요 없이 *2해야한다.....
int main(void){
    int n;
    cin>>n;
    for(int i=0;i<100000;i++){
        jail[0][i]=1;
        jail[1][i]=1;
    }
    for(int i=1;i<n;i++){
        if(i-2>=0){
            jail[0][i]+=2*jail[1][i-1]+jail[0][i-2];
            jail[0][i]%=9901;
            jail[1][i]+=2*jail[0][i-1]+jail[1][i-2];
            jail[1][i]%=9901;
        }else {
            jail[0][i]+=jail[1][i-1]+1;
            jail[1][i]+=jail[0][i-1]+1;
        }
    }
    cout<<(jail[0][n-1]+jail[1][n-1]+1)%9901<<'\n';
    return 0;
}
