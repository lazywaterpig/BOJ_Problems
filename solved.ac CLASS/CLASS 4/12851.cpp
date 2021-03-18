#include <bits/stdc++.h>
using namespace std;

int arr[100001][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(arr, 0, sizeof(arr));
    int n, k, bound;
    cin >> n >> k;
    if(n==k){
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }
    queue <int> q;
    q.push(n);
    arr[n][1]=1;
    while(!q.empty()){
        int tmp=q.front();
        int cnt=arr[tmp][1];
        q.pop();
        if(tmp==k){
            bound=arr[k][1];
            continue;
        }
        if(arr[k][0]!=0 && arr[tmp][0]>=arr[k][0]){
            break;
        }
        int move[3];
        move[0]=tmp-1;
        move[1]=tmp+1;
        move[2]=tmp*2;

        for(int i=0; i<3; i++){
            if(move[i]==k){
                arr[k][0]=arr[tmp][0]+1;
                arr[k][1]+=arr[tmp][1];
            }
            else if(move[i]>=0 && move[i]<=100000){
                if(n!=move[i] && (arr[move[i]][0]==0 || arr[move[i]][0]==arr[tmp][0]+1)){
                    if(arr[move[i]][0]==0) q.push(move[i]);
                    arr[move[i]][0]=arr[tmp][0]+1;
                    arr[move[i]][1]+=arr[tmp][1];
                }
            }
        }
    }
    cout << arr[k][0] << endl;
    cout << arr[k][1] << endl;
    return 0;
}