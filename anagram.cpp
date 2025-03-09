// WAP where two strings are anagram or not.

#include <bits/stdc++.h>
using namespace std;


bool anagram(string test1,string test2){
	if(test1.length()!=test2.length()){
		return false;
	}
	sort(test1.begin(),test1.end());
	sort(test2.begin(),test2.end());
	return test1==test2;
}

int main(){
	string s1,s2;
	cin>>s1>>s2;
	if(anagram(s1,s2)){
		cout<<"strings are anagram";
	}
	else{
		cout<<"string are not anagram";
	}
}
 