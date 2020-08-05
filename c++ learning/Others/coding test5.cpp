#include<iostream>
#include<vector>
using namespace std;
char str[500];
char str2[500];
typedef struct info{
    int id;
    vector<string> v;
}info;
info in[1000];
info in2[1000];
bool cmp(info &u,info&v)
{
    return u.id<v.id;
}
int main(void){
    int r;
    int count=0;
    string s;
    scanf("%d",&r);//행의 수
    scanf(" %[^\n]s",str);

    char* t=strtok(str," ");
    while(t!=NULL)
    {
        t=strtok(NULL," ");
        count++;
    }
    for(int i=1;i<r;i++)
    {
        scanf("%d",&in[i].id);
        for(int j=1;j<count;j++)
        {
            cin>>s;
            in[i].v.push_back(s);
        }
    }
    
    int r2;
    int count2=0;
    string s2;
    scanf("%d",&r2);
    scanf(" %[^\n]s",str2);
    
    char* t2=strtok(str2," ");
    while(t2!=NULL)
    {
        t2=strtok(NULL," ");
        count2++;
    }
    for(int i=1;i<r;i++)
    {
        scanf("%d",&in2[i].id);
        for(int j=1;j<count2;j++)
        {
            cin>>s2;
            in2[i].v.push_back(s2);
        }
    }
    sort(in,in+1000,cmp);
    sort(in2,in2+1000,cmp);
    int j=0;
    printf("%s",str);
    printf("%s",str2+3);
    for(int i=0;i<r;i++)
    {
        
        for(;j<r2;j++)
        {
            if(in[i].id==in2[j].id)
            {
                cout<<in[i].id;
                for(auto x : in[i].v)
                    cout<<x;
                for(auto x: in[j].v)
                    cout<<x<<'\n';
            }
            else if(in[i].id<in2[j].id)
            {
                break;
            }
                
        }
    }
    
    
}




