#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int x, y, i;
	long long int t, n_a, n_b, res=0;
	cin>>x;
	long long int ar [x][3];
	for (i=0; i<x; i++){
		cin>>ar[i][1]>>ar[i][2]>>ar[i][3];
	}

	for (i=0; i<x; i++){
		for (y=ar[i][2]; y<=ar[i][3]; y++){

		n_a=ar[i][1];
		n_b=y;

		while (n_b){
          t = n_a % n_b;
          n_a = n_b;
          n_b = t;
        }
        if (n_a<=1) res+=y;
		}

		long int f = res%1000000007;
		cout<<f<<endl;
		res=0;
	}
	return 0;
}