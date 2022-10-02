#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

	int x,y;
	long int z;
	long long int in, res=0;
	cin>>x;
	for(int i=0; i<x; i++){
		cin>>y;
		for(int j=0; j<y; j++){
			cin>>z;
			for (long int k=0; k<z; k++){
				cin>>in;
				res+=((in-1)/2);
			}
		}
		if(res%2==0) cout<<"Bob"<<endl;
		else cout<<"Alice"<<endl;
		res=0;
	}
    return 0;
}
