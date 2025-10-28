#include<bits/stdc++.h>
using namespace std;

long long c;
long long binpow(long long a,long long b) {
    if (b==0) return 1;
    long long x=binpow(a,b/2);
    x=(x*x)%c;
    if (b%2!=0) {
        x=(x*x)%c;
    }
    return x;
}

int main() {
    string s;
    cin>>s;
    int k;
    cin>> k;
    long long p=31,c=1e9+7;
    long long hash=0;
    for (int i = k-1;i>=0;i--) {
        hash+=(s[i]-'a'+1)*binpow(p,k-i-1);
        hash%c;
    }
    cout<<hash<<" ";
    for (int i=k;i<s.size();i++) {
        hash=(hash+(s[i-k]-'a'+1)*binpow(p,k-1)+c)%c;
        hash=(hash*p)%c;
        hash=(hash+s[i]-'a'+1)%c;
        cout<<hash<<" ";
    }
}
