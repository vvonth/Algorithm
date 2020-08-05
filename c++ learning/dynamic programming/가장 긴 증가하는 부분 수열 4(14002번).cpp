#include <iostream>
using namespace std;
int arr[1001];
int len[1001];
int brr[1001];
int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
    }
    len[1]=1;
    int cnt=0;
    for(int i=2;i<=N;i++){
        for(int j=1;j<i;j++){
            if(arr[i]>arr[j]&&len[i]<len[j]+1){
                len[i]=len[j]+1;
            }
        }
        cnt=0;
    }
    int m=len[1];
    int i;
    for(i=2;i<=N;i++){
        m=max(len[i], m);
    }
    cout<<m<<'\n';
    return 0;
}
