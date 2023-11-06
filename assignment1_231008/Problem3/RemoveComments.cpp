/*
 * File: RemoveComments.cpp
 * ------------------------
 * Prints out a file after removing comments.
 */
// header file for local test
#include <iostream>
#include <iomanip>
//#include "CSC3002OJActive/assignment1/RemoveComments.h" //for OJ
//#include "RemoveComments.h" //for local test
using namespace std;


/*
 * Function: removeComments
 * Usage: removeComments(is, os);
 * ------------------------------
 * Copies characters from the input stream is to the output stream os,
 * removing any comments it finds.  This program eliminates both the
 * /* and // comment forms but does not check to see if those characters
 * are embedded within strings.
 */

void removeComments(istream & is, ostream & os) {
    string text;
    string s;
    while(getline(is,s)){
        text+=s;
        text+="\n";
    }
    int shortcom[500][2];
    int shortpos = 0;                    
    for(int i = 0;i<text.size();i++){
        int slash = text.find("//",i),end = text.find("\n",slash);
        if(slash == -1)
            break;
        shortcom[shortpos][0] = slash;
        shortcom[shortpos][1] = end;
        shortpos++;
        i = slash;
    }

    for(int i = shortpos-1;i>=0;i--){
        int pos = shortcom[i][0]; 
        int length = shortcom[i][1]-shortcom[i][0];
        text.erase(pos,length);
    }
    int longcom[500][2];
    int longpos = 0;                
    for(int i = 0;i<text.size();i++){
        int leftcom = text.find("/*",i),rightcom = text.find("*/",leftcom);
        if(leftcom == -1)
            break;
        longcom[longpos][0] = leftcom;
        longcom[longpos][1] = rightcom;
        longpos++;
        i = rightcom;
    }
    for(int i = longpos-1;i>=0;i--){
        int pos = longcom[i][0]; 
        int length = longcom[i][1]-longcom[i][0]+2;
        text.erase(pos,length);
    }
    
    cout << text<<endl;

}


void TestRemoveComments(){
    removeComments(cin, cout);
}

// DO NOT modify the main() function
/*
 * sample output format:
 * input:  test file // this is a comment
           test file /* this is also a comment*/
/* output: test file
           test file
 */
int main(int argc, char* argv[]) {
    TestRemoveComments();
    return 0;
}

