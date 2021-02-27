#include <bits/stdc++.h>
using namespace std;

vector <int> linked[1001];
int visit[1001]={0};

void bfs(int n){
    int cnt=0, tmp;
    for(int i=1; i<=n; i++){
        if(visit[i]==0){
            queue <int> q;
            q.push(i);
            visit[i]=1;
            cout << i << " ! ";
            while(!q.empty()){
                tmp=q.front();
                q.pop();
                for(int j=0; j<linked[i].size(); j++){
                    if(visit[linked[i][j]]==0){
                		visit[linked[i][j]]=1;
                        q.push(linked[i][j]);
                        
            			cout << linked[i][j] << " ! ";
                    }
                }
            }
            cnt++;
            cout << i << " ? ";
        }
    }
    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int i, n, m, parent, child;
    cin >> n >> m;
    for(i=0; i<m; i++){
        cin >> parent >> child;
        linked[parent].push_back(child);
        linked[child].push_back(parent);
    }
    for(i=1; i<=n; i++){
        for(int j=0; j<linked[i].size(); j++){
        	cout << linked[i][j] << ' ';
        }
        cout << endl;
    }
    bfs(n);
    return 0;
}