#include <bits/stdc++.h>
using namespace std;

#define MAX 1001

int n, k, mypar, mygpar, cur_par, cnt;
int parent[MAX];
queue <int> next_par;
vector<int> tree[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(1){
        cin >> n >> k;
        if(n==0 && k==0) break;

        int dat[MAX]={0};
        parent[1]=0;
        parent[0]=-1;

        for(int i=1; i<n+1; i++){
            cin >> dat[i];
            if(k==dat[i]) k=i;
        }

        next_par=queue <int>();
        next_par.push(1);
        for(int i=2; i<n+1; i++){
            if(dat[i]!=dat[i-1]+1){
                cur_par=next_par.front();
                next_par.pop();
            }
            next_par.push(i);
            parent[i]=cur_par;
        }
        mypar=parent[k];
        mygpar=parent[mypar];
        
        if(mypar==0 || mypar==1) cout << "0\n";
        else{
            for(int i=0; i<MAX; i++){
                tree[i]=vector<int>();
            }
            for(int i=1; i<n+1; i++){
                tree[i].push_back(parent[i]);
                tree[parent[i]].push_back(i);
            }
            
            cnt=0; int t1, t2;
            for(int i=0; i<tree[mygpar].size(); i++){
            	if(tree[mygpar][i]==mypar) t1=i;
            	if(tree[mygpar][i]==parent[mygpar]) t2=i;
                cnt+=tree[tree[mygpar][i]].size()-1;
            }
			cnt-=tree[tree[mygpar][t1]].size()-1;
			cnt-=tree[tree[mygpar][t2]].size()-1;
            cout << cnt << "\n";
        }
    }

    return 0;
}