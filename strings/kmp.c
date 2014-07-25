/* Algoritmo para la construcciòn de la tabla de fallos
algorithm kmp_table:
    input:
        an array of characters, W (the word to be analyzed)
        an array of integers, T (the table to be filled)
    output:
        nothing (but during operation, it populates the table)

    define variables:
        an integer, pos ← 2 (the current position we are computing in T)
        an integer, cnd ← 0 (the zero-based index in W of the next 
character of the current candidate substring)

    (the first few values are fixed but different from what the algorithm 
might suggest)
    let T[0] ← -1, T[1] ← 0

    while pos < length(W) do
        (first case: the substring continues)
        if W[pos - 1] = W[cnd] then
            let cnd ← cnd + 1, T[pos] ← cnd, pos ← pos + 1

        (second case: it doesn't, but we can fall back)
        else if cnd > 0 then
            let cnd ← T[cnd]

        (third case: we have run out of candidates.  Note cnd = 0)
        else
            let T[pos] ← 0, pos ← pos + 1
*/
