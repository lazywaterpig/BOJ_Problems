#include <bits/stdc++.h>
#define MAX 102
#define endl "\n"
using namespace std;

int n;
int g[MAX][MAX];

void floyd(){
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(g[i][k] && g[k][j]) g[i][j] = 1;
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> g[i][j];
    }

    floyd();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cout << g[i][j] << " ";
        cout << endl;
    }

    return 0;
}