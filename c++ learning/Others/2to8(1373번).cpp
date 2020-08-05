#include<iostream>
#include<algorithm>
using namespace std;
char nu[400001];
int main(void)
{
    string s;
    cin>>s;
    int a=0;
    int m=s.size();
    for(int j=m-1;j>=0;j-=3)
    {
        if(j-1<0)
            nu[a++]=(s[j]-'0');
        else if(j-2<0)
            nu[a++]=(s[j-1]-'0')*2+(s[j]-'0');
        else
            nu[a++]=(s[j-2]-'0')*4+(s[j-1]-'0')*2+(s[j]-'0');
    }
    for(int i=a-1;i>=0;i--)
        printf("%d",nu[i]);
    printf("\n");
}
