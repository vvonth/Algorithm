#include <iostream>
#include <queue>
#include <utility>
//priority 큐의 구조체 사용법, 쇄설물이 화산을 타고 갈 수 있으므로 방문 배열 조심히 쓸 것 미리 화산을 방문 해놓으면 통과를 못함..
//문제에서는 재상이가 도달할 수 있는 곳 중에서 가장 큰 산이므로 따로 저장해놔야한다.
using namespace std;
struct node{
    int x;
    int y;
};
bool operator<(node a1,node a2){
    if(a1.x==a2.x){
        return a2.y<a1.y;
    }
    return a1.x<a2.x;
}
int M,N,V,X,Y;
int arr[101][101];
bool visited[101][101];
bool check[101][101];
queue<pair<pair<int,int>,int>> q;
queue<pair<int,int>> js;
priority_queue<node> pq;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

void print(){
    for(int r=1;r<=M;r++){
        for(int c=1;c<=N;c++){
            cout<<arr[r][c]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(void){
    cin>>M>>N>>V>>X>>Y;
    for(int r=1;r<=M;r++){
        for(int c=1;c<=N;c++){
            cin>>arr[r][c];
        }
    }
    js.push(make_pair(X, Y));
    check[X][Y]=true;
    node p;
    p.x=arr[X][Y];
    p.y=0;
    pq.push(p);
    for(int i=0;i<V;i++){
        int a,b,c;
        cin>>a>>b>>c;
        q.push(make_pair(make_pair(a,b),c));
        arr[a][b]=-1;
    }
    int clock=1;
    while(true){
        int size=q.size();
        for(int i=0;i<size;i++){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            if(clock-time>0){
                visited[x][y]=true;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=1&&nx<=M&&ny>=1&&ny<=N&&!visited[nx][ny]){
                        visited[nx][ny]=true;
                        arr[nx][ny]=-1;
                        q.push(make_pair(make_pair(nx, ny),time));
                    }
                }
            }else{
                q.push(make_pair(make_pair(x, y), time));
            }
        }
       // cout<<"clock: "<<clock<<'\n';
        //print();
        size=js.size();
        for(int i=0;i<size;i++){
            int x=js.front().first;
            int y=js.front().second;
            js.pop();
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx>=1&&nx<=M&&ny>=1&&ny<=N&&arr[nx][ny]!=-1&&!check[nx][ny]){
                    check[nx][ny]=true;
                    js.push(make_pair(nx, ny));
                    p.x=arr[nx][ny];
                    p.y=clock;
                    pq.push(p);
                    js.push(make_pair(nx, ny));
                }
            }
        }
        if(js.size()==0)
            break;
        clock++;
    }
    cout<<pq.top().x<<' '<<pq.top().y<<'\n';
    return 0;
}
