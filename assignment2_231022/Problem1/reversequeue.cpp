
/* P1:
 * File: reversequeue.cpp
 * ----------------------
 * This file tests the ReverseQueue function.
 */

#include <iostream>
//#include "CSC3002OJActive/assignment2/reversequeue.h" // For OJ test
#include "reversequeue.h" // For local test
#include <stack>
#include <deque>
using namespace std;

/* TODO PART:
 * Function: reverseQueue
 * Usage: reverseQueue(queue);
 * ---------------------------
 * Reverses the order of the elements in a queue.  This
 * implementation does so by using a stack to hold the
 * values as they are being reversed.
 */

void reverseQueue(queue<string> & queue) {
   // TODO
    stack<string> reverse;
    while (!queue.empty()){
        string s;
        s = queue.front();
        queue.pop();
        reverse.push(s);
       // cout << "e";
    }
    while (!reverse.empty()){
        string s;
        s = reverse.top();
        
        reverse.pop();
        queue.push(s);
    }
}

/* TODO PART:
 * Function: listQueue
 * Usage: listQueue(queue);
 * ------------------------
 * Lists the contents of the queue on the standard output stream.
 */

void listQueue(queue<string> & queue) {
   // TODO
    std::queue<string> lis;
    cout << "The queue contains: ";
    lis = queue;
    while (!lis.empty()){
        cout << lis.front() << " ";
        lis.pop();
    }
    cout << endl;
}


/* DO NOT modify this main() part*/

int main() {
    string str;
    queue<string> line;

    while(cin>>str){
        line.push(str);
    }
    listQueue(line);
    reverseQueue(line);
    listQueue(line);
    return 0;
}
