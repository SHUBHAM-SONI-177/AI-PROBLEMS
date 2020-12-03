#include<bits/stdc++.h>
using namespace std;

struct state
{
	int p,q;
	int x,y;
	state* parent;
	state(int x,int y,int p,int q){
		this->x = x;
		this->y = y;
		this->p = p;
		this->q = q;
	}
	void show(){
		cout<<x<<" "<<y<<endl;
	}
};


bool isSafe(int x,int y,int p,int q){
	if(x==p || y==q || x==0 || y==0){
		return true;
	}
	return false;
}


bool isSame(state* a,int x){
	if(a->x == x || a->y == x){
		return true;
	}
	return false;
}

void print(state* p){
	if(p->parent == NULL){
		p->show();
		return;
	}
	print(p->parent);
	p->show();
}

int main(){
	cout<<"Enter p and q"<<endl;
	int pp,qq;
	cin>>pp>>qq;
	queue<state*>q;
	int ans = max(pp,qq);

	cout<<"Enter what weight you want"<<endl;
	int x;cin>>x;

	if(ans<x){
		cout<<"Cannot weight"<<endl;
		return 0;
	}

	state* root = new state(0,0,pp,qq);
	q.push(root);
	root->parent = NULL;
	while(!q.empty()){
		state* p = q.front();q.pop();
		if(isSame(p,x)){
			print(p);
			break;
		}
		state* te = new state(p->x,qq,pp,qq);
		te->parent = p;
		q.push(te);
		te = new state(pp,p->y,pp,qq);
		te->parent = p;
		q.push(te);
		for(int i=0;i<=ans;i++){
			if(isSafe(p->x-i,p->y+i,pp,qq)){
				state* temp = new state(p->x-i,p->y+i,pp,qq);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->x+i,p->y-i,pp,qq)){
				state* temp = new state(p->x+i,p->y-i,pp,qq);
				temp->parent = p;
				q.push(temp);
			}
		}
		te = new state(p->x,0,pp,qq);
		te->parent = p;
		q.push(te);
		te = new state(0,p->y,pp,qq);
		te->parent = p;
		q.push(te);
	}
}