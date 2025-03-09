#include <bits/stdc++.h>

using namespace std;

bool three(int n){
	while(n){
		if(n%3>1) return false;
		n/=3;
	}
	return true;
}

int main()
{
	int n;
	int x;
	cin>>n;
	x=three(n);
	if(x==0)cout<<"false";
	else cout<<"true";
	return 0;
}
 
