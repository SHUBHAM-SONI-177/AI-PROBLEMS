#include<bits/stdc++.h>
using namespace std;


struct city
{
	int name;
	int distance;
	int visitedvertexs;
	city* parent;
	vector<int>v;
	city(int name,int distance,int visitedvertexs, vector<int>v){
		this->name = name;
		this->distance = distance;
		this->visitedvertexs = visitedvertexs;
		this->v = v;
	}
	void show(){
		cout<<name<<" ";
	}
};


void print(city* p){
	if(p->parent == NULL){
		p->show();
		return;
	}
	print(p->parent);
	p->show();
}

int main(){
	cout<<"Enter number of vertices"<<endl;

	int n;cin>>n; //I assumed vertices from 1 to n

	int arr[n+1][n+1];memset(arr,-1,sizeof(arr));


	cout<<"Enter edge for all pair"<<endl;
	for(int i=0;i<(n*(n-1))/2;i++){
		int x,y,w;
		cin>>x>>y>>w;
		arr[x][y]=w;
		arr[y][x]=w;
	} 
	vector<int>vv;vv.push_back(1);
	city* root = new city(1,0,1,vv);
	city* myans;
	int minn = INT_MAX;
	queue<city*>q;q.push(root);

	while(!q.empty()){
		city* p = q.front();q.pop();
		for(int i=1;i<=n;i++){
			vector<int>v = p->v;
			if(arr[p->name][i] != -1) 
			{

				if(i==1){
					if(p->visitedvertexs==n){
						if(minn > p->distance){
							//cout<<"I am"<<endl;
							minn = p->distance;
							myans = p;
						}
					}
				}
				else if(find(v.begin(), v.end(), i) == v.end())
				{
					v.push_back(i);
					city* temp = new city(i, p->distance + arr[p->name][i], (p->visitedvertexs)+1, v);
					temp->parent = p;
					q.push(temp);
				}
			}
		}
	}
	print(myans);
	cout<<endl;
}