//-1은 트리의 끝이다.
//전위순회는 Root,Left,Right 순이다. 따라서 root를 제일 먼저 방문한 후 리프노드 끝까지 간 뒤 자식들은 -1이 2개가 나온다.
//전위순회 트리를 배열로 나타내면 root를 제일먼저 그다음 left, right순으로 이루어져있다.반드시 리프노드로 인해 끝에가 -1이어야한다.
//문제풀이=> 트리가 끝까지 도달하면 성공/항상 왼쪽 트리 오른쪽 트리 검사 배열 인덱스를 ++ 해주므로 자동으로 검사가 된다.
//만약 트리를 검사해서 1을 반환할경우(트리가 끝에 도달),트리가 끝에 도달 X-> 틀렸음/0을 반환->맞았음
#include<iostream>
#include<vector>
using namespace std;
bool solution(vector<int>);
int isBT(vector<int>);
int i;
int main(void)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    solution(v)==true ? cout<<"It is a tree"<<'\n':cout<<"no tree"<<'\n';
}
/*
bool solution(vector<int> serialization)
{
    
    if(isBT(serialization)||i!=serialization.size())
    {
        return false;
    }
    return true;
}
int isBT(vector<int> serialization)
{
    if(i==serialization.size())
        return 1;
    if(serialization[i++]==-1)
        return 0;
    if(isBT(serialization)||isBT(serialization))
        return 1;
    return 0;
    
}*/
/*
 #include<cstdio>
 #include<vector>
 
 using namespace std;
 
 vector<int> serialization;
 
 bool solution(vector<int> serialization);
 int isBT(vector<int>::iterator &iter,vector<int>&serial);
 
 int main(void){
 int n,num;
 scanf("%d",&n);
 for(int i=0;i<n;i++){
 scanf("%d",&num);
 serialization.push_back(num);
 }
 puts(solution(serialization)==true ? "It is a tree":"It is not a tree");
 return 0;
 }
 
 bool solution(vector<int> serialization){
 vector<int>::iterator iter=serialization.begin();
 if(isBT(iter,serialization)||iter!=serialization.end())
 return false;
 return true;
 }
 
 int isBT(vector<int>::iterator &iter,vector<int>&serial){
 if(iter==serial.end())
 return -1;
 if(*iter++==-1)
 return 0;
 if(isBT(iter,serial)||isBT(iter,serial))
 return 1;
 return 0;
 }
 */
//-1을 만나면 끝에 도달했다는 뜻
