#include <iostream>
using namespace std;
int board[200][105];
int sum;
void shape5(int x, int y, int C){
    int flag=false;
    if(y+2<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x+1][y+2]==1&&board[x][y+1]==0&&board[x][y+2]==0)
            {
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x][y+2]==0)
            {
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+2<200){
            if(board[x+1][y]==1&&board[x+2][y+1]==1&&board[x+1][y+1]==0&&board[x][y+1]==0){
                flag=true;
            }
        }
        if(x==198){
            if(board[x+1][y]==1&&board[x+1][y+1]==0&&board[x][y+1]==0)
                flag=true;
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+2<C){
        if(x+2<200){
            if(board[x+1][y]==1&&board[x+2][y+1]==1&&board[x+1][y+2]==1&&board[x][y+1]==0&&board[x][y+2]==0&&board[x+1][y+1]==0){
                flag=true;
            }
        }
        if(x==198){
            if(board[x+1][y]==1&&board[x+1][y+2]==1&&board[x][y+1]==0&&board[x][y+2]==0&&board[x+1][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x][y+1]==1&&board[x-1][y+1]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==1&&board[x-1][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    
}
void shape1(int x, int y, int C){
    int flag=false;
    if(x+1<200){
        if(board[x+1][y]==1){
            flag=true;
        }
    }
    if(x==199){
        flag=true;
    }
    if(flag)
        sum++;
    flag=false;
    if(y+3<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x+1][y+2]==1&&board[x+1][y+3]==1&&board[x][y+1]==0&&board[x][y+2]==0&&board[x][y+3]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x][y+2]==0&&board[x][y+3]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;

}
void shape2(int x, int y, int C){
    int flag=false;
    if(y+1<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x][y+1]==0&&board[x-1][y+1]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x-1][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
}
void shape3(int x, int y, int C){
    int flag=false;
    if(y+2<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x][y+2]==1&&board[x][y+1]==0&&board[x-1][y+1]==0&&board[x-1][y+2]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x-1][y+1]==0&&board[x-1][y+2]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+2<200){
            if(board[x+1][y]==1&&board[x+2][y+1]==1&&board[x][y+1]==0&&board[x+1][y+1]==0){
                flag=true;
            }
        }
        if(x==198){
            if(board[x+1][y]==1&&board[x][y+1]==0&&board[x+1][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
}
void shape4(int x, int y, int C){
    int flag=false;
    if(y+2<C){
        if(x+2<200){
            if(board[x+1][y]==1&&board[x+2][y+1]==1&&board[x+2][y+2]==1&&board[x][y+1]==0&&board[x+1][y+1]==0&&board[x+1][y+2]==0){
                flag=true;
            }
        }
        if(x==198){
            if(board[x+1][y]==1&&board[x][y+1]==0&&board[x+1][y+1]==0&&board[x+1][y+2]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x][y+1]==1&&board[x-1][y+1]==0&&board[x-2][y+1]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==1&&board[x-1][y+1]==0&&board[x-2][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
}
void shape6(int x, int y, int C){
    int flag=false;
    if(y+2<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x+1][y+2]==1&&board[x][y+1]==0&&board[x][y+2]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x][y+2]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x][y+1]==1&&board[x-1][y+1]==1&&board[x-2][y+1]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==1&&board[x-1][y+1]==1&&board[x-2][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+2<C){
        if(x+2<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x+2][y+2]==1&&board[x][y+1]==0&&board[x][y+2]==0&&board[x+1][y+2]==0){
                flag=true;
            }
        }
        if(x==198){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x][y+1]==0&&board[x][y+2]==0&&board[x+1][y+2]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x][y+1]==0&&board[x-1][y+1]==0&&board[x-2][y+1]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x-1][y+1]==0&&board[x-2][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
}
void shape7(int x, int y, int C){
    int flag=false;
    if(y+2<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x+1][y+2]==1&&board[x][y+1]==0&&board[x][y+2]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0&&board[x][y+2]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    
    if(y+1<C){
        if(x+3<200){
            if(board[x+1][y]==1&&board[x+2][y]==1&&board[x+3][y+1]==1&&board[x+2][y+1]==0){
                flag=true;
            }
        }
        if(x==197){
            if(board[x+1][y]==1&&board[x+2][y]==1&&board[x+2][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+2<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x][y+1]==1&&board[x][y+2]==1&&board[x-1][y+1]==0&&board[x-1][y+2]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==1&&board[x][y+2]==1&&board[x-1][y+1]==0&&board[x-1][y+2]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
    flag=false;
    if(y+1<C){
        if(x+1<200){
            if(board[x+1][y]==1&&board[x+1][y+1]==1&&board[x][y+1]==0){
                flag=true;
            }
        }
        if(x==199){
            if(board[x][y+1]==0){
                flag=true;
            }
        }
    }
    if(flag)
        sum++;
}
int main(void){
    int C,P,R;
    cin>>C>>P;
    for(int i=0;i<C;i++){
        cin>>R;
        for(int j=199;j>199-R;j--){
            board[j][i]=1;
        }
    }
//    for(int r=0;r<200;r++){
//        for(int c=0;c<C;c++){
//            cout<<board[r][c]<<' ';
//        }
//        cout<<'\n';
//    }
    sum=0;
    for(int c=0;c<C;c++){
        for(int r=199;r>=0;r--){
            if(board[r][c]==0){
                if(P==5){
                    shape5(r,c,C);
                }else if(P==1){
                    shape1(r,c,C);
                }else if(P==2){
                    shape2(r,c,C);
                }else if(P==3){
                    shape3(r,c,C);
                }else if(P==4){
                    shape4(r,c,C);
                }else if(P==6){
                    shape7(r,c,C);
                }else{
                    shape6(r,c,C);
                }
                break;
            }
        }
    }
    cout<<sum<<'\n';
    
    return 0;
}
