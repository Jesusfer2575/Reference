int BIT[1000006];

int query(int a){
	if(a==0)
		return 0;
	return BIT[a] + query(a-(a&-a));
}

int update(int i,int a){
	if(i > n)
		return 0;
	BIT[i] += a;
	return update(i + (i & -i), a);
}