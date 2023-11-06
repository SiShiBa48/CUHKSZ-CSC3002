/* Q2: 
 * File: FindDNAMatch.cpp
 * ----------------------
 * This file solves the DNA matching exercise from the text.
 */
// header file for OJ system
// #include <iostream>
// #include <string>

// using namespace std;

#include <iostream>
#include <string>
//#include "CSC3002OJActive/assignment1/FindDNAMatch.h" //for OJ
//#include "FindDNAMatch.h" //for local test
using namespace std;


/*
 * Function: findDNAMatch
 * Usage: int pos = findDNAMatch(s1, s2);
 *        int pos = findDNAMatch(s1, s2, start);
 * ---------------------------------------------
 * Returns the first index position at which strand s1 would bind to
 * the strand s2, or -1 if no such position exists.  If the start
 * parameter is supplied, the search begins at that index position.
 */

int findDNAMatch(string s1, string s2, int start) {
   // TODO
   string s3 = matchingStrand(s1);
   int pos = -1;
   bool find = true;
   for (int i = start;i < (start+s1.length());i++){
      if (s3[i-start]!=s2[i]){
         find = false;
      }
   }
   if (find){
      pos = start;
   }
   return pos;
}

/*
 * Function: matchingStrand
 * Usage: string match = matchingStrand(strand);
 * ---------------------------------------------
 * Returns a string in which each base has been replaced by its
 * counterpart base (C <-> G and A <-> T).  Any other characters
 * are replaced by an X.
 */

string matchingStrand(string strand) {
   // TODO
   string re;
   for (int i =0;i<strand.length();i++){
      switch (strand[i]){
         case 'T': re.append("A");break;
         case 'A': re.append("T");break;
         case 'G': re.append("C");break;
         case 'C': re.append("G");break;
      }
      //cout << re << endl;
   }
   
   return re;
   
}

/*
 * Function: findAllMatches
 * Usage: findAllMatches(s1, s2);
 * ------------------------------
 * Finds all positions at which s1 can bind to s2.
 */

void findAllMatches(string s1, string s2) {
   // TODO
   bool find;
   find = false;
   for (int i =0;i<=(s2.length()-s1.length());i++){
      int ans;
      ans = findDNAMatch(s1,s2,i);
      if (ans != -1){
         find = true;
         cout << s1 << " matches " << s2 << " at position " << ans << endl;
      }
   }
   if (not find){
      cout << s1 << " has no matches in " << s2 << endl;
   }
}

// DO NOT modify the main() function
/*
 * sample output:
 * input:  TTGCC TAACGGTACGTC
 * output: TTGCC matches TAACGGTACGTC at position 1
*/
int main(int argc, char* argv[]) {
    string s1, s2;
    cin >> s1 >> s2; 
    findAllMatches(s1, s2);
    return 0;
}
