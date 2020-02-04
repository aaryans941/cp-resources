set<int> adj[N];
int nodes; 
void dfs(int u , int p = 0){
	nodes++;
	sub[u] = 1;
	trav(v , adj[u]) if(v != p){
		dfs(v , u);
	}
}

int cent(int u , int p = 0){
	trav(v , adj[u]) if(v != p)
		if(sub[v] > (nodes/2))
			return cent(v, u);
	return u;
}

void dcmp(int u , int p = 0){
	nodes = 0;
	dfs(u);
	int node = cent(u);
	// set parent : 
	centpar[node][0]= p;
	trav(v , adj[node]){
		adj[v].erase(node);
		dcmp(v, node);
	}
}

// question : https://codeforces.com/contest/342/problem/E
// usage : https://codeforces.com/contest/342/submission/69488485
