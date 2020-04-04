int MX_PRIME=5e5+5;
int spf[MX_PRIME];
bitset<MX_PRIME> isprime;
void sieve(int n){
	isprime.set(); isprime[0]=isprime[1]=0; spf[2]=2;
	for(int i = 4 ; i < n ; i += 2) isprime[i]=0 , spf[i] = 2;
	for(int i = 3 ; i < n ; i++)if(isprime[i]){
		spf[i]=i;
		for(int j = i * 2; j < n ; j += i){
			if(isprime[j]) spf[j] = i;
			isprime[j] = false;
		}
	}
	/*
		vi primes;
		repA(i,2,n-1)if(isprime[i])primes.pb(i);
	*/
}