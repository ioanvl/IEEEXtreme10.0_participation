#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int hello(int*cell, int x, int y, int n){

	if(x==(n-1)){
		return 1;
	}
	else{

		int*m_cell=(cell+(x*n)+y);

		if(*m_cell==0){
			*m_cell=2;
		}
		else if (*m_cell==1){
			*m_cell=3;
			if (x+1<n) if(hello(cell, (x+1), y, n)==1) return 1;
			if (x-1>=0) if(hello(cell, (x-1), y, n)==1) return 1;
			if (y+1<n) if(hello(cell, (x), (y+1), n)==1) return 1;
			if (y-1>=0) if(hello(cell, (x), (y-1), n)==1) return 1;
		}
	}
	return 0;
}



int main() {
	int n;
	cin>>n;
	int map[n][n]; 
	int lvl[n]={0};
	int lvl_c=0, count, x, y;

	for (int i=0; i<n; i++){
		lvl[i]=0;
		for(int j=0; j<n; j++){
			map[i][j]=0;
		}
	}

	for (count=0; count<n; count++){
		cin>>x;
		if (x!=(-1)){
			x--;
			cin>>y;
			y--;

			map[x][y]=1;
			if(lvl[x]!=1){
				lvl[x]=1;
				lvl_c++;
			}
		}
		else{
			cout<<"-1";
			return 0;	
		}
	}

	for (int i=0; i<n; i++){
		if(map[0][i]==0) map[0][i]=2;
		else if (map[0][i]==1) if(hello((int*)map, 0, i, n)==1) {cout<<(count); return 0;} ;
	}

	int run=true;

	do{
		cin>>x;
		if(x==(-1)){
			cout<<"-1"; return 0;
		}
		else{
			x--;
			cin>>y;
			y--;
			count++;

			lvl[x]=1;

			if(map[x][y]==0) map[x][y]=1;
			else if (map[x][y]==2){
				map[x][y]=1;
				if(hello((int*)map, x, y, n)==1){
					cout<<(count);
					return 0;
				}
			}
		}
	}while (true);
    return 0;
}
