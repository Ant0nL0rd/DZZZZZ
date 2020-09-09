#include <iostream>
#include <vector>

using namespace std;

#define MAX 200001

int visited[MAX], comps[MAX], nex = 1;
vector<vector<int>> gr;
vector<vector<int>> rev_gr;
vector<int> tops;
vector<int> new_gr;

void top_sort(int cur) {
	visited[cur] = true;
	for(auto it : gr[cur]) {
		if(!visited[it]) {
			top_sort(it);
		}
	}
	tops.push_back(cur);
}

void find_comp(int cur) {
	visited[cur] = false;
	comps[cur] = nex;
	for(auto it : rev_gr[cur]) {
		if(visited[it]) {
			find_comp(it);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, i, j, tmp1, tmp2;
	cin >> n >> m;
	gr.resize(n + 1);
	rev_gr.resize(n + 1);
	for(i = 0; i < m; ++i) {
		cin >> tmp1 >> tmp2;
		gr[tmp1].push_back(tmp2);
		rev_gr[tmp2].push_back(tmp1);
	}
	for(i = 1; i <= n; ++i) {
		if(!visited[i]) {
			top_sort(i);
		}
	}
	for(auto it = tops.rbegin(); it != tops.rend(); ++it) {
		if(visited[*it]) {
			find_comp(*it);
			++nex;
		}
	}
	cout << nex - 1 << '\n';
	for(i = 1; i <= n; ++i) {
		cout << comps[i] << ' ';
	}
	cout << endl;
	return 0;
}