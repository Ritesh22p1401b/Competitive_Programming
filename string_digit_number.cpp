#include <bits/stdc++.h>
using namespace std;

int main(){
	char ch[10];
	int c=0;
	for(int i=0;i<10;i++){
		cin>>ch[i];
	}
	for(int i=0;i<10;i++){
		if(int(ch[i])>=48 && int(ch[i]<=57)){
			c++;
		}
	}
	cout<<c;
	return 0;
}

