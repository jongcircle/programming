#include <iostream>
using namespace std;

typedef pair<int,int> pa;

int main(){
    int N, K, L;
    cin >> N;
    
    int board[100][100] = {0,};
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        int a,b;
        cin >> a >> b;
        board[a-1][b-1] = 1;
    }
    
    cin >> L;
    int time[100];
    char dir[100];
    for (int i = 0; i < L; i++)
    {
        cin >> time[i] >> dir[i];
    }
    
    int x = 0, y = 0;
    int dx = 0, dy = 1;
    int t = 0;
    int cnt = 0;
    pa his[10000];
    int front = 0, rear = 0;

    board[0][0] = 2;
    his[front] = pa(0,0);
    front = (front+1)%10000;

    while (true)
    {
        printf("%d\n", t);
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                printf("%d ",board[i][j]);
            }
            printf("\n");
        }
        if (cnt < L && t == time[cnt]){
            if (dir[cnt] == 'D')
            {
                int temp = dx;
                dx = dy;
                dy = -1*temp;
            } else {
                int temp = dx;
                dx = -1*dy;
                dy = temp;
            }
            cnt++;
        }
        x += dx;
        y += dy;
        t++;
        if (x >= N || y >=N || x<0 || y<0 || board[x][y] == 2)
        {
            cout << t << endl;
            return 0;
        }
        if (board[x][y]==1)
        {
            board[x][y] = 2;
            his[front] = pa(x,y);
            front = (front+1)%10000;
        } else {
            board[x][y] = 2;
            his[front] = pa(x,y);
            pa a = his[rear];
            board[a.first][a.second] = 0;
            front = (front+1)%10000;
            rear = (rear+1)%10000;
        }
        
    }

}