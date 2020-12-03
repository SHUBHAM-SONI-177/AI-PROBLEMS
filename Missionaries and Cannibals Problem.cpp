#include<bits/stdc++.h>
using namespace std;





struct state
{
	int nhuman_side1;
	int ncanibels_side1;

	int boat_state;

	int nhuman_side2;
	int ncanibels_side2;

	state* parent;

	state(int h1,int c1,int b, int h2,int c2){
		nhuman_side1 = h1;
		ncanibels_side1 = c1;
		boat_state = b;
		nhuman_side2 = h2;
		ncanibels_side2 = c2;
	}

	void show(){
		cout<<"Humans on left "<<nhuman_side1<<endl;
		cout<<"Canibels on left"<<ncanibels_side1<<endl;

		if(boat_state==1){
			cout<<"Boat on left"<<endl;
		}else{
			cout<<"Boat on right"<<endl;
		}

		cout<<"Humans on right "<<nhuman_side2<<endl;
		cout<<"Canibels on right"<<ncanibels_side2<<endl;

		cout<<endl;
	}
};






bool isSafe(int h1,int c1,int h2,int c2){
	if(h1>=0 && h2>=0 && c1>=0 && c2>=0 && (h1 >= c1 || h1 == 0) && (h2 >= c2 || h2 == 0)){
		return true;
	}
	return false;
}





bool isSame(state* a,state* b){
	if(a->nhuman_side1 == b->nhuman_side1 && a->ncanibels_side1 == b->ncanibels_side1 && a->nhuman_side2 == b->nhuman_side2 && a->ncanibels_side2 == b->ncanibels_side2){
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


int main()
{
	cout<<"Enter the number of humans and canibels"<<endl;
	int nhuman,ncanibels;cin>>nhuman>>ncanibels;
	if(ncanibels>nhuman){
		cout<<"Cannot solve"<<endl;
		return 0;
	}

	state* root = new state(nhuman,ncanibels,1,0,0);
	root->parent = NULL;
	state* goal = new state(0,0,2,nhuman,ncanibels);
	queue<state*>q;
	q.push(root);

	while(!q.empty())
	{
		state* p = q.front();q.pop();
		if(isSame(p,goal)){
			print(p);
			break;
		}
		if(p->boat_state==1)
		{
			if(isSafe(p->nhuman_side1-1,p->ncanibels_side1,p->nhuman_side2+1,p->ncanibels_side2)){
				state* temp = new state(p->nhuman_side1-1,p->ncanibels_side1,2,p->nhuman_side2+1,p->ncanibels_side2);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1,p->ncanibels_side1-1,p->nhuman_side2,p->ncanibels_side2+1)){
				state* temp = new state(p->nhuman_side1,p->ncanibels_side1-1,2,p->nhuman_side2,p->ncanibels_side2+1);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1-1,p->ncanibels_side1-1,p->nhuman_side2+1,p->ncanibels_side2+1)){
				state* temp = new state(p->nhuman_side1-1,p->ncanibels_side1-1,2,p->nhuman_side2+1,p->ncanibels_side2+1);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1,p->ncanibels_side1-2,p->nhuman_side2,p->ncanibels_side2+2)){
				state* temp = new state(p->nhuman_side1,p->ncanibels_side1-2,2,p->nhuman_side2,p->ncanibels_side2+2);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1-2,p->ncanibels_side1,p->nhuman_side2+2,p->ncanibels_side2)){
				state* temp = new state(p->nhuman_side1-2,p->ncanibels_side1,2,p->nhuman_side2+2,p->ncanibels_side2);
				temp->parent = p;
				q.push(temp);
			}
		}
		else
		{
			if(isSafe(p->nhuman_side1+1,p->ncanibels_side1,p->nhuman_side2-1,p->ncanibels_side2)){
				state* temp = new state(p->nhuman_side1+1,p->ncanibels_side1,1,p->nhuman_side2-1,p->ncanibels_side2);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1,p->ncanibels_side1+1,p->nhuman_side2,p->ncanibels_side2-1)){
				state* temp = new state(p->nhuman_side1,p->ncanibels_side1+1,1,p->nhuman_side2,p->ncanibels_side2-1);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1+1,p->ncanibels_side1+1,p->nhuman_side2-1,p->ncanibels_side2-1)){
				state* temp = new state(p->nhuman_side1+1,p->ncanibels_side1+1,1,p->nhuman_side2-1,p->ncanibels_side2-1);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1,p->ncanibels_side1+2,p->nhuman_side2,p->ncanibels_side2-2)){
				state* temp = new state(p->nhuman_side1,p->ncanibels_side1+2,1,p->nhuman_side2,p->ncanibels_side2-2);
				temp->parent = p;
				q.push(temp);
			}
			if(isSafe(p->nhuman_side1+2,p->ncanibels_side1,p->nhuman_side2-2,p->ncanibels_side2)){
				state* temp = new state(p->nhuman_side1+2,p->ncanibels_side1,1,p->nhuman_side2-2,p->ncanibels_side2);
				temp->parent = p;
				q.push(temp);
			}
		}
	}
}