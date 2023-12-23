/* P1:
 * File: WildcardMatch.cpp
 * -----------------------
 * This program tests the wildcardMatch method, which
 * matches a filename against a pattern containing the wildcard
 * characters * and ?.
 */

#include <iostream>
#include <string>
#include <string.h>
// #include "CSC3002OJActive/assignment4/WildcardMatch.h" //for OJ test
#include "WildcardMatch.h" // for local test
using namespace std;

/*
 * Method: wildcardMatch
 * Usage: if (wildcardMatch(filename, pattern)) . . .
 * --------------------------------------------------
 * This method checks to see whether filename matches the pattern,
 * which consists of three types of characters:
 *
 * 1. The character ?, which matches any single character
 * 2. The character *, which matches any string of characters
 * 3. Any other character, which matches only that character
 */

bool wildcardMatch(string filename, string pattern)
{
	// TODO
	string head = "", tail = "", mathead = "", mattail = "";
	bool boo = false, matboo = false, re = true;
	for (int i = 0; i < filename.length(); i++)
	{
		if (filename[i] == '.')
		{
			boo = true;
		}
		else
		{
			if (not boo)
			{
				head = head + filename[i];
			}
			else
			{
				tail = tail + filename[i];
			}
		}
	}
//	cout << head << tail << boo<< endl;
	if (boo)
	{
		for (int i = 0; i < pattern.length(); i++)
		{
			if (pattern[i] == '.')
			{
				matboo = true;
			}
			else
			{
				if (not matboo)
				{
					mathead = mathead + pattern[i];
				}
				else
				{
					mattail = mattail + pattern[i];
				}
			}
		}
	//	cout << mathead << mattail << matboo << endl;
		for (int i = 0;i<mattail.length();i++){
			if (mattail[i]=='?'){
				mattail.erase(i,1);
				if (tail.length()==0){
					re = false;
					//cout << "411" << endl;
					break;
				}
				tail.erase(0,1);
			}else if (mattail[i]!='*'){
				int pos = tail.find(mattail[i]);
				if (pos == -1){
					re = false;
					//cout << "511" << endl;
					break;
				}
				tail = tail.erase(pos,1);
			}
		}
		if ((tail.length()>0)&&(mattail.find('*')==-1)){
			re = false;
		//	cout << "611" << endl;
		}

		for (int i = 0;i<mathead.length();i++){
			if (mathead[i]=='?'){
				mathead.erase(i,1);
				if (head.length()==0){ 
					
					re = false;
				//	cout << "311" << endl;
					break;
				}
				head.erase(0,1);
			}else if (mathead[i]!='*'){
				int pos = head.find(mathead[i]);
				if (pos == -1){
					re = false;
				//	cout << "211" << endl;
					break;
				}
				head = head.erase(pos,1);
			}
		}
		if (pattern.find('.') == std::string::npos){
			re = false;
		}
		if ((head.length()>0)&&(mathead.find('*')==-1)){
			re = false;
			//cout << "111" << endl;
		}
	}
	if (not boo)
	{
		int count = 0;
		for (int i = 0; i < pattern.length(); i++)
		{
			if (pattern[i] == '?')
			{
				count++;
			}
		}
		if (pattern.find('.') != std::string::npos){
			re = false;
		}

		for (int i = 0;i<pattern.length();i++){
			if (pattern[i]=='?'){
				pattern.erase(i,1);
				if (head.length()==0){
					re = false;
				//	cout << "311" << endl;
					break;
				}
				head.erase(0,1);
			}else if (pattern[i]!='*'){
				int pos = head.find(pattern[i]);
				if (pos == -1){
					re = false;
				//	cout << "211" << endl;
					break;
				}
				head = head.erase(pos,1);
			}
		}
		if ((head.length()>0)&&(pattern.find('*')==-1)){
			re = false;
			//cout << "111" << endl;
		}
	}
	return re;
}
/* DO NOT modify the main() part */

int main()
{
	string in_pair, filename, pattern;
	bool matchResult;
	while (getline(cin, in_pair))
	{
		int sp = in_pair.find(' ');
		filename = in_pair.substr(0, sp);
		pattern = in_pair.substr(sp + 1, in_pair.size());
		matchResult = wildcardMatch(filename, pattern);
		cout << boolalpha << matchResult << endl;
	}
	return 0;
}
