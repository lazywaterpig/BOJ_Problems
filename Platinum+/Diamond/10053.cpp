#include <bits/stdc++.h>
using namespace std;

int arr[26][26], before[26][26];
int piv[26]={0}, bound[26]={0};

bool cmp(string a, string b){
    if(a.size()==b.size()) return a<b;
    return a.size()<b.size();
}

void floyd(int n){
    for (int mid=0;mid<n;mid++){
        for (int start=0;start<n;start++){
            for (int end=0;end<n;end++){
                if (arr[start][end] > arr[start][mid] + arr[mid][end]){
                    arr[start][end] = arr[start][mid] + arr[mid][end];
                    before[start][end] = before[mid][end];
                    
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	char c;
    int n;
    cin >> n;
    vector <vector <string>> v;

    for(int i=0; i<n; i++){
    	for(int j=0; j<n; j++){
    		arr[i][j]=123456789;
    	}
    }
    for(int i=0; i<n; i++) arr[i][i]=0;
    
    char cc;
    int tmp, ttmp;
    for(int i=0; i<n; i++){
    	v.push_back(vector <string>());
        cin >> tmp;
        string s;
        c=i+97;
        while(tmp--){
            cin >> s;
			if(s.size()==1){
				cc=s[0];
				ttmp=cc-'a';
            	arr[i][ttmp]=1;
            	piv[i]++;
			}
			v[i].push_back(s);
			bound[i]++;
        }
        sort(v[i].begin(), v[i].end(), cmp);
    }
    
    int maxv;
    int a=6;
    while(a--){
	    memset(piv, 0, sizeof(piv));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                while(v[j].size()!=0 && piv[j]<bound[j] && v[j][piv[j]].size()<=i){
                    for(int k=0; k<n; k++){
                	    maxv=-1;
                    	if(j!=k){
                    		for(int l=0; l<v[j][piv[j]].size(); l++){
        	    				c=v[j][piv[j]][l];
        		    			tmp=c-'a';
        			    		if(arr[tmp][k]>maxv) maxv=arr[tmp][k];
                		    }
    						if(arr[j][k]>maxv+1) arr[j][k]=maxv+1;
                    	}
                    }
                    piv[j]++;
                }
            
        		memset(before, -1, sizeof(before));
		    	for(int l=0; l<n; l++){
			    	for(int k=0; k<n; k++){
				    	if(arr[l][k]!=123456789) before[l][k]=l;
    				}
	    		}
		    	floyd(n);
            }
        }
    }
    
    for(int i=0; i<n; i++) arr[i][i]=0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j]>=123456789) arr[i][j]=-1;
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