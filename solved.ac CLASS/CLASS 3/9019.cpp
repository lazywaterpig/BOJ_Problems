#include <bits/stdc++.h>
using namespace std;

int visited[10000][2], cnt;

void bfs(int A, int B){
    queue <int> q;
    q.push(A);
    visited[A][0]=-2;
    int nval, tmp;
    while(1){
        tmp=q.front();
        q.pop();
        nval=(tmp*2)%10000;
        if(visited[nval][0]==-1){
            visited[nval][0]=tmp;
            visited[nval][1]='D';
            q.push(nval);
        }
        nval=(tmp+9999)%10000;
        if(visited[nval][0]==-1){
            visited[nval][0]=tmp;
            visited[nval][1]='S';
            q.push(nval);
        }
        nval=(tmp%1000)*10+(tmp/1000);
        if(visited[nval][0]==-1){
            visited[nval][0]=tmp;
            visited[nval][1]='L';
            q.push(nval);
        }
        nval=(tmp%10)*1000+tmp/10;
        if(visited[nval][0]==-1){
            visited[nval][0]=tmp;
            visited[nval][1]='R';
            q.push(nval);
        }
        if(visited[B][0]!=-1){
            stack <char> s;
            while(visited[B][0]!=-2){
                s.push(visited[B][1]);
                B=visited[B][0];
            }
            while(!s.empty()){
                cout << s.top();
                s.pop();
            }
            cout << '\n';
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int aa, bb;
        cin >> aa >> bb;
        
        memset(visited, -1, sizeof(visited));
        cnt=0;

        bfs(aa, bb);
    }
}