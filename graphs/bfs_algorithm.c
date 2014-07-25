/*
// Breadth-first search algorithm
// O(|V| + |E|)
procedure BFS(G,v) is
	create a queue Q
	create a vector set V // V visited nodes, could be made using a boolean array
	enqueue v onto Q 
	add v to V // Mark as visited
	while Q is not empty loop
		t ← Q.dequeue()
		if t is what we are looking for then // If we are searching for something
			return t
		end if
		for all edges e in G.adjacentEdges(t) loop
			u ← G.adjacentVertex(t,e)
			if u is not in V then // If not visited
				add u to V // Mark as visited
				enqueue u onto Q
			end if
		end loop
	end loop
	return none
end BFS
*/
