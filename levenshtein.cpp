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
 
int levenshtein(const string &s1, const string &s2)
{
   int N1 = s1.size();
   int N2 = s2.size();
   int i, j;
   vector<int> T(N2+1);
 
   for ( i = 0; i <= N2; i++ )
      T[i] = i;
 
   for ( i = 0; i < N1; i++ ) 
   {
      T[0] = i+1;
      int corner = i;
      for ( j = 0; j < N2; j++ ) 
      {
         int upper = T[j+1];
         if ( s1[i] == s2[j] )
            T[j+1] = corner;
         else
            T[j+1] = min(T[j], min(upper, corner)) + 1;
         corner = upper;
      }
   }
   return T[N2];
}
