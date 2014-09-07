// initialize with a big value
// be careful with overflows!
for(int i = 0; i < vertices; i++)
	for(int j = 0; j < vertices; j++)
		a[i][j] = 1 << 15;
// initialize diagonal
for(int i = 0; i < vertices; i++)
	a[i][i] = 0;

// initialize distances between nodes
// Sample distances
a[0][1]=20;
a[0][2]=10;
a[0][4]=5;

// Floyd-Warshall
// add nodes between (first 1 then 2, 3 till n) and look if
// distance is shorter
for(int k = 0; k < vertices; k++)
	for(int i = 0; i < vertices; i++)
		for(int j = 0; j < vertices; j++)
			if(a[i][j]>a[i][k]+a[k][j])
				a[i][j]=a[i][k]+a[k][j];
