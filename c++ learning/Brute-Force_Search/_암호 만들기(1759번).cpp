//
//  암호 만들기(1759번).cpp
//  c++ learning
//
//  Created by 원태희 on 28/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
int visited(string &password)
{
    int a=0,b=0;
    for(int i=0;i<password.size();i++)
    {
        if(password[i]=='a'||password[i]=='e'||password[i]=='i'||password[i]=='o'||password[i]=='u')
            a++;
        else
            b++;
    }
    if(a>=1&&b>=2)
    {
        return 1;
    }
    else
        return 0;
}


void check(int L, vector<char>&alpha,string password, int index)
{
    
    if(index>alpha.size())
        return ;
    if(password.length()==L)
    {
        if(visited(password))
            cout<<password<<'\n';
        return;
    }
    check(L,alpha,password+alpha[index],index+1);
    check(L,alpha,password,index+1);
}
int main(void)
{
    string password="";
    vector<char> alpha;
    char k;
    int L,C;
    cin>>L>>C;
    for(int i=0;i<C;i++)
    {
        cin>>k;
        if(k!=' ')
            alpha.push_back(k);
    }
    sort(alpha.begin(),alpha.end());
    check(L,alpha,password,0);
    return 0;
}*/

void go(int L,int C, int *visited, char *alpha,int index,int count)
{
    if(index>C)
        return;
    if(L==count)
    {
        int a=0,b=0;
        for(int i=0;i<C;i++)
        {
            
            if(visited[i])
            {
                if(alpha[i]=='a'||alpha[i]=='e'||alpha[i]=='i'||alpha[i]=='o'||alpha[i]=='u')
                    a++;
                else
                    b++;
            }
        }
        if(a>=1&&b>=2)
        {
            for(int i=0;i<C;i++)
            {
                if(visited[i])
                    cout<<alpha[i];
            }
            cout<<'\n';
        }
        
        return;
    }

        visited[index]=1;
        //printf("%d",index);
        go(L,C,visited,alpha,index+1,count+1);
        visited[index]=0;
        go(L,C,visited,alpha,index+1,count);
}

int main(void)
{
    int L,C;
    cin>>L>>C;
    char alpha[16]={0,};
    int visited[16]={0,};
    char k;
    for(int i=0;i<C;)
    {
        scanf(" %c",&k);
        
        if(k!=' ')
        {
            alpha[i]=k;
            i++;
        }
    }
    sort(alpha,alpha+C);
    go(L,C,visited,alpha,0,0);
    return 0;
}


/*if(L==index)
 {
 for(int i=0;i<C;i++)
 {
 if(visited[i])
 cout<<alpha[i];
 }
 cout<<'\n';
 return ;
 }
 if(L>index)
 {
 visited[index]=1;
 check(L,C,alpha,index+1);
 visited[index]=0;
 index--;
 }*/
