int roots[1000005];

void MakeSet(int N){
	for(int i=1; i<=N; i++)
		roots[i]=i;
}

int root(int a){
	if(roots[a]==a)
		return a;
	return roots[a] = root(roots[a]);
}

void join(int a,int b){
	int rootA = root(a);
	int rootB = root(b);
	roots[rootA]=rootB;
}

bool SameSet(int a, int b){
	if(root(a)==root(b))
		return true;
	return false;
}