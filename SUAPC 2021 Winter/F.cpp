#include <bits/stdc++.h>
using namespace std;

int piv;
string s, ss;
vector<string> arr;
// This function generates all n bit Gray codes and prints the
// generated codes
void GreyCode(int n)
{
    
     // power of 2
    for (int i = 0; i < (1 << n); i++)
    {
        // Generating the decimal
        // values of gray code then using
        // bitset to convert them to binary form
        int val = (i ^ (i >> 1));
         
        // Using bitset
        bitset<32> r(val);
         
        // Converting to string
        string s = r.to_string();
        arr.push_back(s.substr(32 - n));
    }
}

// Driver program to test above function
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n; cin >> n;
	cin >> s;
	ss = s.substr(1, n-1);
	if(n==1){
		if(s=="1") cout << "1\n0\n";
		else cout << "0\n1\n";
	}
    else{
        
        char fbit = s[0];
        char nfbit = (s[0]=='0'?'1':'0');
        //cout << fbit << nfbit << endl;
    	GreyCode(n-1);
        while(arr[piv]==ss) piv++;
    	for(int i=piv; i<arr.size(); i++){
    		cout << fbit << arr[i] << '\n';
    		cout << nfbit;
    		for(int j=0; j<n-1; j++) cout << (arr[i][j]=='0'?'1':'0');
    		cout << endl;
    	}
    	for(int i=0; i<piv; i++){
    		cout << fbit << arr[i] << '\n';
    		cout << nfbit;
    		for(int j=0; j<n-1; j++) cout << (arr[i][j]=='0'?'1':'0');
    		cout << endl;
    	}
    }
    return 0;
}