#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[10003];
vector<int> v, tmp;

void Swap(int a, int b){
    for(int i=0; i<(b-a+1)/2; i++){
        int tmp=arr[a+i];
        arr[a+i]=arr[b-i];
        arr[b-i]=tmp;
    }
}

void makelist(){
    int flag=1;
    for(int i=1; i<=n+1; i++){
        if(abs(flag)){
            if(arr[i]-arr[i-1]==flag) continue;

            flag=0;
            tmp.push_back(i);
        }
        else{
            if(abs(arr[i]-arr[i-1])==1){
                flag=arr[i]-arr[i-1];
            }
            else tmp.push_back(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    arr[0]=0;
    for(int i=1; i<=n; i++) cin >> arr[i];
    arr[n+1]=n+1;

    int flag=1;
    for(int i=1; i<=n+1; i++){
        if(abs(flag)){
            if(arr[i]-arr[i-1]==flag) continue;

            flag=0;
            v.push_back(i);
        }
        else{
            if(abs(arr[i]-arr[i-1])==1){
                flag=arr[i]-arr[i-1];
            }
            else v.push_back(i);
        }
    }

    
    int sz=v.size();
    for(int i=1; i<=n+1; i++){
        for(int j=0; j<sz; j++){
            if(i!=v[j] && abs(arr[v[j]]-arr[i])==1) v.push_back(i);
        }
    }
    sort(v.begin(), v.end());

    if(v.size()<3){
        cout << "1 1\n1 1";
    }
    else{
        flag=0;
        for(int i=0; i<v.size()-1; i++){
            for(int j=i+1; j<v.size(); j++){
            	if(v[i]==v[j]) continue;
            	
                tmp=vector<int> ();
                Swap(v[i], v[j]-1);
                makelist();
                if(tmp.size()<3){
                    cout << v[i] << ' ' << v[j]-1 << endl << tmp[0] << ' ' << tmp[1]-1;
                    flag=1;
                    break;
                }
                Swap(v[i], v[j]-1);
            }
            if(flag) break;
        }
    }

    return 0;
}