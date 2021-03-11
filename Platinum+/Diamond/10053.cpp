#include <bits/stdc++.h>
using namespace std;

int arr[26][26];
int piv[26]={0}, bound[26]={0};

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	char c;
    int n;
    cin >> n;
    vector <vector <string>> v;

    memset(arr, 1234567890, sizeof(arr));
    for(int i=0; i<n; i++) arr[i][i]=0;

    int tmp;
    for(int i=0; i<n; i++){
    	v.push_back(vector <string>());
        cin >> tmp;
        string s;
        c=i+97;
        while(tmp--){
            cin >> s;
			if(s.find(c) == string::npos){
				v[i].push_back(s);
				bound[i]++;
			}
        }
        sort(v[i].begin(), v[i].end(), cmp);
    }

    for(int j=0; j<n; j++){
        while(v[j][piv[j]].size()<=1){
        	c=v[j][piv[j]][0];
            arr[j][(int)c-97]=1;
            piv[j]++;
        }
    }

    int maxv;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            while(piv[j]<bound[j] && v[j][piv[j]].size()<=i){
                for(int k=0; k<n; k++){
                	maxv=-1;
                	if(j!=k){
                		for(int l=0; l<v[j][piv[j]].size(); l++){
        					c=v[j][piv[j]][l];
        					if(arr[(int)c-97][k]>maxv) maxv=arr[(int)c-97][k];
                		}
						arr[j][(int)c-97]=min(1234567890, maxv+1);
                	}
                }
                piv[j]++;
            }
        }
    }

/*
    for(int i=0; i<n; i++){
    	for(int j=0; j<v[i].size(); j++) cout << v[i][j] << ' ';
    	cout << endl;
    }
*/

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]>=1234567890) arr[i][j]=-1;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}