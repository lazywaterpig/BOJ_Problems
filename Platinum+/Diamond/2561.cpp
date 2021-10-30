#include <bits/stdc++.h>
using namespace std;

int n; 
int arr[1003];
vector<int> v, tmp, tmp2;

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
    
    int sz=tmp.size();
    for(int i=1; i<=n+1; i++){
        for(int j=0; j<sz; j++){
            if(i && i!=n+1 && i!=tmp[j] && abs(arr[tmp[j]]-arr[i])==1) tmp.push_back(i);
        }
    }
}

void makelist2(){
    int flag=1;
    for(int i=1; i<=n+1; i++){
        if(abs(flag)){
            if(arr[i]-arr[i-1]==flag) continue;

            flag=0;
            tmp2.push_back(i);
        }
        else{
            if(abs(arr[i]-arr[i-1])==1){
                flag=arr[i]-arr[i-1];
            }
            else tmp2.push_back(i);
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
            if(i && i!=n+1 && i!=v[j] && abs(arr[v[j]]-arr[i])==1) v.push_back(i);
        }
    }
    sort(v.begin(), v.end());

    if(v.size()<3){
        cout << "1 1\n1 1\n1 1";
    }
    else{
        flag=0;
        for(int i=0; i<v.size()-1; i++){
            for(int j=i+1; j<v.size(); j++){
            	if(v[i]==v[j]) continue;
            	
                tmp=vector<int> ();
                Swap(v[i], v[j]-1);
                makelist();
                if(tmp.size()<13){
                    if(tmp.size()<1){
                        cout << v[i] << ' ' << v[j]-1 << endl << "1 1\n1 1";
                        flag=1;
                        break;
                    }

                    for(int k=0; k<tmp.size()-1; k++){
                        for(int l=k+1; l<tmp.size(); l++){
            	            if(tmp[k]==tmp[l]) continue;

                            tmp2=vector<int> ();
                            Swap(tmp[k], tmp[l]-1);
                            makelist2();
                            if(tmp2.size()<1){
                                cout << v[i] << ' ' << v[j]-1 << endl << tmp[k] << ' ' << tmp[l]-1 << endl << "1 1";
                                flag=1;
                                break;
                            }
                            else if(tmp2.size()<3){
                                cout << v[i] << ' ' << v[j]-1 << endl << tmp[k] << ' ' << tmp[l]-1 << endl << tmp2[0] << ' ' << tmp2[1]-1;
                                flag=1;
                                break;
                            }
                            Swap(tmp[k], tmp[l]-1);
                        }
                        if(flag) break;
                    }
                }
                if(flag) break;
                Swap(v[i], v[j]-1);
            }
            if(flag) break;
        }
    }

    return 0;
}