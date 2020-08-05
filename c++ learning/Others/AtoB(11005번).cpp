#include<iostream>
#include<stack>
using namespace std;
stack<char> s;
char tran(int);
char num(int);
int main(void)
{
    int n,b;
    char k;
    
    cin>>n>>b;
    while(n)
    {
        if(n%b>9)
           k=tran(n%b);
        
        else
            k=num(n%b);
        
        s.push(k);
        n/=b;
    }
    while(!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}
char tran(int a)
{
    char k;
    k=a+55;
    return k;
}
char num(int a)
{
    char k;
    k=a+'0';
    return k;
}
