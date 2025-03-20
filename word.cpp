#include <bits/stdc++.h>
using namespace std;

int main(){
	string s=" aa ";
	int c=0;
	int l=s.size();

	

	for(int i=0;i<s.size();i++){
		int j=i;
		if(s[i]==' ' || l==0){
			c=0;
		}
		else if(s[i]==' ' && s[j+1]!=' '){
			c++;
		}
		else if(s[i]==s[l-1] && s[i]!=' '){
			c++;
		}
	}
	cout<<c;
}

