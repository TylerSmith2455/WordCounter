#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<ctype.h>
#include"hashTable.h"

using namespace std;

int main(int argc, char *argv[]) {
	// Create hashTable Object
	hashTable myTable;
	string tmpString, line;

	// Receive input from text file
	while(getline(cin, tmpString)) {
		std::stringstream ss(tmpString); // Take one line of text at time
		while(getline(ss,tmpString, ' ')) { // Break words up when white space is found
			int i = 0;
			while (tmpString[i]) { // Check each character for punctuation
				if (ispunct(tmpString[i]) && (tmpString[i] != '_')) { // If punctuation is found, and it isn't an underscore split the word
					string leftString, rightString;
					for (int j = 0; j < i; j++) 
						leftString = leftString + tmpString[j];
					for (unsigned long j = i+1; j < tmpString.length(); j++)
						rightString = rightString + tmpString[j];
					
					// If the string isn't empty insert into hash table
					if (!leftString.empty()) 
						myTable.insert(leftString);
					tmpString = rightString;
					i = 0;
				}
				else i++;
			}
			
			// If the string isn't empty insert into hash table
			if (!tmpString.empty()) 
				myTable.insert(tmpString);
		}
	}
	myTable.print(); // Print the hash table
	return 0;
}
