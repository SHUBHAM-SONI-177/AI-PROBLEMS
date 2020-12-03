#include<bits/stdc++.h>
using namespace std;

struct Puzzle
{
	int arr[3][3];
	Puzzle* parent;
	pair<int,int>blankposition;
	Puzzle(int arrr[3][3]){
		parent = NULL;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				arr[i][j]=arrr[i][j];
				if(arr[i][j]==-1){
					blankposition={i,j};
				}
			}
		}
	}
	void show(){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};


bool isSame(Puzzle* p1,Puzzle* p2){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(p1->arr[i][j] != p2->arr[i][j])
				return false;
		}
	}
	return true;
}

void print(Puzzle* p,Puzzle* root){
	if(isSame(p,root)){
		p->show();
		return;
	}
	//cout<<"I am still here"<<endl;
	print(p->parent,root);
	p->show();
}



bool isValid(int i,int j){
	if(i>=0 && i<3 && j>=0 && j<3)
		return true;
	return false;
}


bool checking(int arr[3][3]){
	vector<int>v;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			v.push_back(arr[i][j]);
		}
	}
	int inversions = 0;
	for(int i=0;i<9;i++){
		for(int j=i+1;j<9;j++){
			if(v[i]!=-1 && v[j] != -1 && v[i]>v[j]){
				inversions++;
			}
		}
	}
	if(inversions&1 == 1){
		return false;
	}
	else{
		return true;
	}
}



int main(){
	cout<<"Please enter entries(between 1 to 8 and -1 at blank place) of start of the 8-puzzle"<<endl;
	int array[3][3];for(int i=0;i<3;i++){for(int j=0;j<3;j++){int x;cin>>x;array[i][j]=x;}}
	Puzzle* root = new Puzzle(array);
	/* Assuming goal puzzle to be 1 2 3 4 5 6 7 8 -1*/
	bool check = checking(array);
	if(!check){
		cout<<"Cannot be solved"<<endl;
		return 0;
	}
	int inte = 1;
	for(int i=0;i<3;i++){for(int j=0;j<3;j++){array[i][j]=inte++;if(i==2 && j==2){array[i][j]=-1;}}}
	Puzzle* goal = new Puzzle(array);

	queue<Puzzle*>q;q.push(root);
	//cout<<"Reached"<<endl;
	while(!q.empty()){
		Puzzle* p = q.front();q.pop();
		if(isSame(p,goal)){
			print(p,root);
			break;
		}
		pair<int,int>pp = p->blankposition;
		int i=pp.first,j = pp.second;
		int a[3][3];

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a[i][j]=p->arr[i][j];
			}
		}

		if(isValid(i,j-1)){
			swap(a[i][j-1],a[i][j]);
			Puzzle* temp = new Puzzle(a);
			temp->parent = p;
			q.push(temp);
		}

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a[i][j]=p->arr[i][j];
			}
		}

		if(isValid(i-1,j)){
			swap(a[i-1][j],a[i][j]);
			Puzzle* temp = new Puzzle(a);
			temp->parent = p;
			q.push(temp);
		}

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a[i][j]=p->arr[i][j];
			}
		}

		if(isValid(i,j+1)){
			swap(a[i][j+1],a[i][j]);
			Puzzle* temp = new Puzzle(a);
			temp->parent = p;
			q.push(temp);
		}

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a[i][j]=p->arr[i][j];
			}
		}

		if(isValid(i+1,j)){
			swap(a[i+1][j],a[i][j]);
			Puzzle* temp = new Puzzle(a);
			temp->parent = p;
			q.push(temp);
		}
	}
}

