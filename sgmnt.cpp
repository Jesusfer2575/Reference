#include <cstdio>
using namespace std;
int datos[MAX];
typedef struct Node{
	int lazyFlag;
	int d[3], a, b;
	struct Node *right,*left;
} * Tree;
 
Tree insert(Tree n, int A, int B);
Tree build(int a,int b);
void propagate(Tree n);
int query(Tree n,int a,int b);
int update(Tree n,int a,int b);
int N,Q,x,y,z;

int main(){
	Tree datosbolito = NULL; 
	scanf("%d",&N); 
	for(int i=1;i<=N; i++)
		scanf("%d",&datos[i]);
	datosbolito = build(1,N);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d %d %d",&z,&x,&y );
		if(z){
			printf("%d\n", query(datosbolito, x, y));
		}else{
			update(datosbolito,x, y);
		}
	}
	return 0;
}


Tree insert(Tree n, int A, int B){
	Tree t = new(struct Node);
	t->right = NULL;
	t->left = NULL;
	t->a = A;
	t->b = B;
	return t;
}

Tree build(int a,int b){
	Tree n = new(struct Node);
	n = insert(n, a, b);
	if(a == b)
		n->d[datos[a] % 3]++;
	else{
		int middle = (a + b) / 2;
		n->left = build(a, middle);
		n->right = build(middle+1, b);
		// set the data of the node based on its leaves
		for(int i = 0; i < 3; i++) 
			n->d[i] = n->left->d[i] + n->right->d[i];
	}
	return n;
}

void propagate(Tree n) {
	int ax;
	if(n->lazyFlag){
		// perform all the updates
		for(int ii = 0; ii < n->lazyFlag; ii++){ 
			ax = n->d[2];
			n->d[2] = n->d[1];
			n->d[1] = n->d[0];
			n->d[0] = ax;
		}
		n->lazyFlag = 0;
		// set update flag on the leafs
		if(n->right)
			n->right->lazyFlag++;
		if(n->left)
			n->left->lazyFlag++;
	}
}

int query(Tree n,int a,int b){
	propagate(n); // propagate on query
	if(b<(n->a) || (n->b)<a){ // out of range
		return 0;
	}
	if(a<=(n->a) && (n->b)<=b) { // inside range
		return n->d[0];
	}
	int L = query(n->left,a,b);
	int R = query(n->right,a,b);
	return L + R;
}

int update(Tree n,int a,int b){
	if(n->a==n->b && (n->a==a && n->b==b)){
		n->lazyFlag++; // propagate
		propagate(n);
		return 0;
	}
 
	if(b<(n->a) || (n->b)<a) { // out of range
		return 0;
	}
	if(a<=(n->a) && (n->b)<=b){
		n->lazyFlag++; // propagate
		propagate (n);
		return 0;
	}
	update(n->left,a,b);
	update(n->right,a,b);
	// set the data of the node based on its leaves
	for(int ii = 0; ii < 3; ii++) {
		n->d[ii] = n->right->d[ii] + n->left->d[ii];
	}
	return 0;
 	
}