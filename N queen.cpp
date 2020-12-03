#include<bits/stdc++.h>
using namespace std;



//state space is considered as 1D array

struct state{
	vector<int>arr;
	vector<vector<int>>possible_value;
	int nval;
	int minvalue;
};



struct mycompare
{
    bool operator()(state a, state b){
        return a.nval > b.nval;
    }
};


vector<vector<int>> calculate(vector<vector<int>>v,   int val,   int f,   bool &check,   int &minn,   int &heuristic)
{
	v[f].clear();
	int mini = INT_MAX;
	for(int i=0;i<v.size();i++){
		if(v[i].size()>0){


			vector<int>temp;
			for(auto j : v[i]){
				if(abs(f-i)!=abs(val-j) && j!=val){
					temp.push_back(j);
				}
			}


			if(temp.size()==0){
				check=false;
				return v;
			}


			if(temp.size()<mini){
				mini = temp.size();
				minn = i;
			}


			heuristic += temp.size();
			v[i] = temp;
		}
	}
	return v;
}


bool Isgoal(vector<int>p){
	for(int i=0;i<p.size();i++){
		if(p[i]==-1){
			return false;
		}
	}
	return true;
}


void print(vector<int>p){
	for(int i=0;i<p.size();i++){
		for(int j=0;j<p.size();j++){
			if(p[j]==i){
				cout<<"X ";
			}
			else{
				cout<<". ";
			}
		}
		cout<<endl;
	}
}

int findsum(vector<vector<int>> v){
	int count =0;
	for(int i=0;i<v.size();i++){
		count+=v[i].size();
	}
	return count;
}

void pprint(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}


void MRV(int n){
	vector<int>v(n,-1);
	priority_queue<state,vector<state>,mycompare>q;
	vector<vector<int>>vv;
	for(int i=0;i<n;i++){
		vector<int>te;
		for(int j=0;j<n;j++){
			te.push_back(j);
		}
		vv.push_back(te);
	}
	state root = {v,vv,n*n,0};
	q.push(root);

	//cout<<"Reached to root push"<<endl;

	map<vector<int>,bool>visit;
	while(!q.empty()){
		state p = q.top();q.pop();
		//pprint(p.arr);
		if(Isgoal(p.arr)){
			print(p.arr);
			break;
		}

		if(visit.find(p.arr) == visit.end()){
			visit[p.arr]=true;
		}
		else{
			continue;
		}

		vector<int>temp_vector = p.possible_value[p.minvalue];
		for(auto i : temp_vector)
		{
			bool check = true;int next_minvalue = INT_MAX;int heuristic_cost = 0;
			vector<vector<int>>tempvv = calculate(p.possible_value,i,p.minvalue,check,next_minvalue,heuristic_cost);
			if(check){
				vector<int>tempv = p.arr;
				tempv[p.minvalue] = i;
				state temp = {tempv,tempvv,heuristic_cost,next_minvalue};
				q.push(temp);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;cout<<"Enter board size"<<endl;
	cin>>n;
	MRV(n);
	return 0;
}