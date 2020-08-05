#include<iostream>
using namespace std;
int tran(char n)
{
    int k;
    if(n>='A'&&n<='Z')
        k=n-55;
    else
        k=n-'0';
    
    return k;
}

int main(void)
{
    int b;
    string n;
    int k=1;
    int sum=0;
    cin>>n>>b;
    for(int i=n.size()-1;i>=0;i--)
    {  sum+=tran(n[i])*k;
        k*=b;
    }
    cout<<sum<<'\n';
    
}
//ans = ans * b + (s[i] - '0'); !!!!특이 배열 앞에서부터 계산할때 계속 더해나감 역으로
