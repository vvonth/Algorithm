#include <iostream>
using namespace std;
int calc[3]={1,0,-1};
int N;
int arr[100000];
int small;
void perm(int cnt,int brr[]){
    if(cnt==2)
    {
        
        bool fail=false;
        int operCnt=0;
        if(brr[0]!=0)
            operCnt++;
        if(brr[1]!=0)
            operCnt++;
        
        int temp0=arr[0];
        int temp1=arr[1];
        arr[1]=arr[1]+brr[1];
        arr[0]=arr[0]+brr[0];
        int d=arr[0]-arr[1];

        int first=arr[1];
        for(int i=2;i<N;i++){
            if(first-arr[i]==d){
                first=arr[i];
            }else if((first-(arr[i]-1)==d)){
                operCnt++;
                first=arr[i]-1;
            }else if(first-(arr[i]+1)==d)
            {
                operCnt++;
                first=arr[i]+1;
            }
            else{
                fail=true;
                break;
            }
        }
        if(!fail){
            small=min(small,operCnt);
        }
        arr[0]=temp0;
        arr[1]=temp1;
        return;
    }
    for(int i=0;i<3;i++){
        brr[cnt]=calc[i];
        perm(cnt+1,brr);
    }
}
int main(void){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int brr[2];
    small=0xfffff;
    perm(0,brr);
    if(small==0xfffff){
        small=-1;
    }
    cout<<small<<'\n';
    return 0;
}
