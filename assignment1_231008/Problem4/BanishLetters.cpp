/*
 * File: BanishLetters.cpp
 * -----------------------
 * This program removes all instances of a set of letters from
 * an input file.
 */

#include <iostream>
//#include <fstream>
#include "CSC3002OJActive/assignment1/lib.h"
using namespace std;

int banishLetters() {
    string list;
    cin >> list;

    string text;
    string s;
    while(getline(cin,s)){
        text+=s;
        text+="\n";
    }
    for(int i = 0; i< list.size();i++){
        char com = list.at(i);
        char s;
        if ((com>=97)&&(com<=122))
            s = com-32;
        else if ((com>=65)&&(com<=90))
            s = com+32;
        for(int j = 0;j<text.size();j++){
            if(text.at(j)==s||text.at(j)==com){
                text.erase(j,1);
                j--;
            }
        }
    }
    cout<<text<<endl;
}


/* DO NOT modify this main() part */
/*
 sample output:
 input: S
        this is a testing 1
        this is a testing 2
 output:
        thi i a teting 1
        thi i a teting 2
*/
int main(int argc, char* argv[]) {
    banishLetters();
    return 0;
}
