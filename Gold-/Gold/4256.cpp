#include <bits/stdc++.h>
using namespace std;

int preorder[1001], inorder[1001];

void dac(int idx, int l, int r){
    if(l>r) return;
    if(l==r){
        cout << preorder[idx] << ' ';
        return;
    }

    dac(idx+1, l+1, inorder[preorder[idx]]);
    dac(idx+inorder[preorder[idx]]-l+1, inorder[preorder[idx]]+1, r);
    cout << preorder[idx] << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        int n; cin >> n;
        for(int i=1; i<=n; i++) cin >> preorder[i];
        for(int i=1; i<=n; i++){
            int tmp; cin >> tmp;
            inorder[tmp]=i;
        }

        dac(1, 1, n);
        cout << '\n';
    }
    
    return 0;
}