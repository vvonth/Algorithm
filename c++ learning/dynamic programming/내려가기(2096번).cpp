#include <iostream>
using namespace std;
int main(void)
{
    int n;
    cin>> n;
    int a1,a2,a3;
    int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
    cin>>a1>>a2>>a3;
    int min_left,max_left,min_mid,max_mid,min_right,max_right;
    min_left=max_left=a1;
    min_mid=max_mid=a2;
    min_right=max_right=a3;
    for(int r=1;r<n;r++){
        cin>>a1>>a2>>a3;
        tmp1=max_left;
        tmp2=max_mid;
        tmp3=max_right;
        tmp4=min_left;
        tmp5=min_mid;
        tmp6=min_right;
        max_left=max(tmp1,tmp2)+a1;
        min_left=min(tmp4,tmp5)+a1;
        max_mid=max(tmp1,max(tmp2,tmp3))+a2;
        min_mid=min(tmp4,min(tmp5,tmp6))+a2;
        max_right=max(tmp2,tmp3)+a3;
        min_right=min(tmp5,tmp6)+a3;

    }
    int m1=max(max_left,max(max_mid,max_right));
    int m2=min(min_left,min(min_mid,min_right));
    cout<<m1<<' '<<m2<<'\n';
    return 0;
}

