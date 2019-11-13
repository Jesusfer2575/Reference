// Número mínimo de operaciones requeridas para transformar una cadena de caracteres en otra
// Algoritmo de tipo bottom-up, común en programación dinámica. 
// Se apoya en el uso de una matriz (n + 1) × (m + 1), donde n y m son las longitudes de los cadenas.
/*
int LevenshteinDistance(char str1[1..lenStr1], char str2[1..lenStr2])
   // d is a table with lenStr1+1 rows and lenStr2+1 columns
   declare int d[0..lenStr1, 0..lenStr2]
   // i and j are used to iterate over str1 and str2
   declare int i, j, cost
 
   for i from 0 to lenStr1
       d[i, 0] := i
   for j from 0 to lenStr2
       d[0, j] := j
 
   for i from 1 to lenStr1
       for j from 1 to lenStr2
           if str1[i] = str2[j] then cost := 0
                                else cost := 1
           d[i, j] := minimum(
                                d[i-1, j] + 1,     // deletion
                                d[i, j-1] + 1,     // insertion
                                d[i-1, j-1] + cost   // substitution
                            )
   return d[lenStr1, lenStr2]
*/

// Implementation: 
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int Levenshtein(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();
	
	for (int i = 0; i <= n; i++)
		dp[i][0] = i;
	for (int i = 0; i <= m; i++)
		dp[0][i] = i;

	int cost = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cost = (s1[j - 1] == s2[i - 1]) ? 0 : 1;
			
			dp[i][j] = min(dp[i][j - 1]+1, //Deletion
					   min(dp[i - 1][j]+1, //Insertion
						   dp[i - 1][j - 1] + cost)); //Substitution
		}
	}
	return dp[n][m];
}
