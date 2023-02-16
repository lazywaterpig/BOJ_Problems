#include <bits/stdc++.h>
using namespace std;

int postorder[100100], inorder[100100];

void preorder(int idx, int l, int r){
    if(l>r) return;
    if(l==r){
    	cout << postorder[idx] << ' ';
    	return;
    }

    cout << postorder[idx] << ' ';
    /*cout << endl;
    cout << l << ' ' << inorder[postorder[idx]]-1 << endl;
    cout << inorder[postorder[idx]] << ' ' << r-1 << endl;*/
    preorder(idx-1+inorder[postorder[idx]]-r, l, inorder[postorder[idx]]-1);
    preorder(idx-1, inorder[postorder[idx]]+1, r);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    for(int i=1; i<=n; i++){
        int tmp; cin >> tmp;
        inorder[tmp]=i;
    }
    for(int i=1; i<=n; i++) cin >> postorder[i];


    preorder(n, 1, n);

    return 0;
}