#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

int x, n, m, count=0, br=0;
cin>>x;
vector<int> inp[x];
vector<int> assoc[x][20];

for (int i=0; i<x; i++){
	cin>>n;
	for(int j=0; j<n; j++){
		cin>>m;
		inp[i].push_back(m);
		assoc[i][m].push_back(j);
	}
}

int t_a, t_b, c_a, c_b;

for (int i=0; i<x; i++){
	if(!inp[i].empty()){
	t_a=inp[i].front();
	inp[i].erase(inp[i].begin());
	assoc[i][t_a].erase(assoc[i][t_a].begin());
	count++;

	if(!inp[i].empty()){
	do{
		if(t_a==inp[i].front()){
			inp[i].erase(inp[i].begin());
			assoc[i][t_a].erase(assoc[i][t_a].begin());
		}
		else{
			t_b=inp[i].front();
			inp[i].erase(inp[i].begin());
			assoc[i][t_b].erase(assoc[i][t_b].begin());
			count++;
			br=1;
		}
	}while(br!=1);

	while(!inp[i].empty()){
		if(t_a==inp[i].front()){
			inp[i].erase(inp[i].begin());
			assoc[i][t_a].erase(assoc[i][t_a].begin());
		}
		else if(t_b==inp[i].front()){
			inp[i].erase(inp[i].begin());
			assoc[i][t_b].erase(assoc[i][t_b].begin());
		}
		else{
			if (assoc[i][t_a].empty()){
				t_a=inp[i].front();
				inp[i].erase(inp[i].begin());
				assoc[i][t_a].erase(assoc[i][t_a].begin());
				count++;
			}
			else if (assoc[i][t_b].empty()){
				t_b=inp[i].front();
				inp[i].erase(inp[i].begin());
				assoc[i][t_b].erase(assoc[i][t_b].begin());
				count++;
				}
			else{
				c_a=assoc[i][t_a].front();
				c_b=assoc[i][t_b].front();

				if (c_a<c_b){
					t_b=inp[i].front();
					inp[i].erase(inp[i].begin());
					assoc[i][t_b].erase(assoc[i][t_b].begin());
					count++;
				}
				else{
					t_a=inp[i].front();
					inp[i].erase(inp[i].begin());
					assoc[i][t_a].erase(assoc[i][t_a].begin());
					count++;
				}
			}
		}
	}
	cout<<count<<endl;
	count=0;
}}}



    return 0;
}

