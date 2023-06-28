#include <bits/stdc++.h> 
class three{
	public:
	int val,idx,jdx;
};
struct comparator{
	bool operator()(three a,three b){
		return a.val<b.val;
	}
};
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	priority_queue<three,vector<three>,comparator> pq;
	vector<int> ans;
	set<pair<int,int>> s;
	pq.push({a[n-1]+b[n-1],n-1,n-1});
	s.insert({n-1,n-1});
	while(ans.size()!=k){
		three obj = pq.top();
		pq.pop();

		int vl = obj.val,i = obj.idx,j = obj.jdx;
		ans.push_back(vl);
		if(i>0 && s.count({i-1,j}) ==0 ){
			s.insert({i-1,j});
			pq.push({a[i-1]+b[j],i-1,j});
		}
		if(j>0 && s.count({i,j-1}) == 0){
			s.insert({i,j-1});
			pq.push({a[i]+b[j-1],i,j-1});
		}
		
	}
	return ans;
}