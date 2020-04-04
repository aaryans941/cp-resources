 	
struct matrix
{ 
	int arr[SZ][SZ];

	void reset()
	{
		memset(arr, 0, sizeof(arr));
	}

	void makeiden()
	{
		reset();
		for(int i=0;i<SZ;i++)
		{
			arr[i][i] = 1;
		}
	}

	matrix operator + (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = (arr[i][j] + o.arr[i][j])%mod;
			}
		}
		return res;
	}

	matrix operator * (const matrix &o) const 
	{
		matrix res;
		for(int i=0;i<SZ;i++)
		{
			for(int j=0;j<SZ;j++)
			{
				res.arr[i][j] = 0;
				for(int k=0;k<SZ;k++)
				{
					res.arr[i][j] = (res.arr[i][j] + (arr[i][k]*o.arr[k][j])%mod)%mod;
				}
			}
		}
		return res;
	}
};
  	
matrix matrix_expo(matrix a, int pw)
{
	matrix res ;
	res.makeiden() ;
	while(pw)
	{
		if(pw&1)
			res = res * a ;
		pw /= 2;
		a = a * a ;
	}
	return res ;
}