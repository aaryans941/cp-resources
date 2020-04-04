void init(){
	// assumes val[0][i] is set
	for(int j = 1 ; j <= 18 ; ++j){
		for(int i = 1 ; i <= n ; ++i){
			val[j][i] = max(val[j-1][i], val[j-1][jump[j-1][i]]) ;
			jump[j][i] = jump[j-1][jump[j-1][i]] ;
		}
	}	
}
 
int lca(int i, int j){
	if(dep[i] > dep[j])
		swap(i,j) ;
	int k = dep[j] - dep[i] ;
	int ans = 0 ;
	// cout << dep[2] - dep[1] << endl ;
	// cout << k << endl ;
	for(int x = 18 ; x >= 0 ; x--){
		if((1<<x)&k) {
			ans = max(ans, val[x][j]) ;
			j = jump[x][j] ;
		}
	}
	if(i == j) return ans ;
	repD(x,18,0){
		if(jump[x][i] != jump[x][j]){
			ans = max(val[x][i],ans) ;
			ans = max(ans, val[x][j]) ;
			i = jump[x][i] ;
			j = jump[x][j] ;
		}
	}
	ans = max(val[0][i],ans) ;
	ans = max(val[0][j],ans) ;
	return ans ;
}