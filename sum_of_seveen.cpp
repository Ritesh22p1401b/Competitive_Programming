#include <bits/stdc++.h>

using namespace std;

bool three(int n){
	while(n){
		if(n%7>1) return false;
		n/=7;
	}
	return true;
}

int main()
{
	int x;
	int n;
	cin>>n;
	x=three(n);
	if(x==0)cout<<"false";
	else cout<<"true";
	return 0;
}
 
