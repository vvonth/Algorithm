#include <iostream>
#include<algorithm>
using namespace std;
int arr[15];
bool check[15];
int N,L,R,X;
int result;
void brute_force(int idx,int sum,int cnt){
    if(sum>R){
        return;
    }
    if(idx==N){
        if(cnt<2){
            return;
        }
        if(sum<L)
            return;
        int m2=10000000;
        int m1=0;
        for(int i=0;i<N;i++){
            if(check[i]==true){
                m2=min(m2,arr[i]);
                m1=max(m1,arr[i]);
            }
        }
        if(m1-m2<X)
            return;
        result++;
        return;
        
    }
    
    check[idx]=true;
    brute_force(idx+1,sum+arr[idx],cnt+1);
    check[idx]=false;
    brute_force(idx+1,sum,cnt);
    
}
int main(void){
   
    cin>>N>>L>>R>>X;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    brute_force(0,0,0);
    cout<<result<<'\n';
    return 0;
}
