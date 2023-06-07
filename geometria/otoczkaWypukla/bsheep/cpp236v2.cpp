//zadanie convex hull
//link do konta na SPOJ'u: https://www.spoj.com/users/hinski2/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> para;

class punkt{
public:
	int x, y, idx;

	punkt(){};
	punkt(int a, int b, int c){x = a, y = b, idx = c;}

	double distance(punkt &a){
		int dx = a.x - x;
		int dy = a.y - y;

		return sqrt(dx * dx + dy * dy);
	}

	bool operator != (punkt &a){
		if(a.x != x || a.y != y) return true;
		return false;
	}
};

bool cmp(const punkt &a, const punkt &b){
	return a.y == b.y ? (a.x  == b.x ? a.idx < b.idx : a.x < b.x) : a.y < b.y;
}

int cross(punkt a, punkt b, punkt c){
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}

void make_otoczka(vector<punkt> &v, vector<punkt> &upper, vector<punkt> &lower){
	sort(v.begin(), v.end(), cmp);

	int k = 1;
	for(int i = 1; i < v.size(); i++)
		if(v[i - 1] != v[i])
			v[k++] = v[i];

	v.resize(k);

	int sajz = 2 * k;
	upper.resize(sajz);
	lower.resize(sajz);

	int j = 0;
	k = 0;

	for(int i = 0; i < v.size(); i++){
		while(j > 1 && cross(lower[j - 2], lower[j - 1], v[i]) <= 0)
			j--;
		while(k > 1 && cross(upper[k - 2], upper[k - 1], v[i]) >= 0)
			k--;

		lower[j++] = v[i];
		upper[k++] = v[i];
	}

	lower.resize(j);
	upper.resize(k);
}

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		vector<punkt> v;

		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d%d", &x, &y);

			v.push_back(punkt(x, y, i + 1));
		}

		vector<punkt>lower, upper;
		make_otoczka(v, upper, lower);

		for(int i = upper.size() - 2; i > 0; i--)
			lower.push_back(upper[i]);

		double dist = 0.0;
		for(int i = 1; i < lower.size(); i++)
			dist += lower[i - 1].distance(lower[i]);
		dist += lower[lower.size() - 1].distance(lower[0]);

		printf("%.2lf\n", dist);
		for(int i = 0; i < lower.size(); i++)
			printf("%d ", lower[i].idx);
		printf("\n");
	}
}
