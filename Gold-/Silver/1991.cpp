#include <bits/stdc++.h>
using namespace std;

#define MAX 27

int n;
int tree[MAX][2]={0,};

void F_dfs(int node){
    cout << char('A'-1+node);
    for(int i=0; i<2; i++){
        int next=tree[node][i];
        if(next!=0) F_dfs(next);
    }
}

void M_dfs(int node){
    for(int i=0; i<2; i++){
        int next=tree[node][i];
        if(next!=0) M_dfs(next);
        if(i==0) cout << char('A'-1+node);
    }
}

void L_dfs(int node){
    for(int i=0; i<2; i++){
        int next=tree[node][i];
        if(next!=0) L_dfs(next);
    }
    cout << char('A'-1+node);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        char par, child_l, child_r;
        cin >> par >> child_l >> child_r;
        par-=64;
        if(!(child_l=='.')){
            child_l=child_l-64;
            tree[par][0]=child_l;
        }
        if(!(child_r=='.')){
            child_r=child_r-64;
            tree[par][1]=child_r;
        }
    }

    F_dfs(1);
    cout << "\n";

    M_dfs(1);
    cout << "\n";

    L_dfs(1);
    
    return 0;
}