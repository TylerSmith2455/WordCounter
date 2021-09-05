#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<string>
#include"hashTable.h"

using namespace std;

// Hash Table constructor, adds new node to each element in the table array
hashTable::hashTable() {
	for (int i = 0; i < TABLESIZE; i++) {
		table[i] = newNode();
	}
}

// Hash function
int hashTable::Hash(string key) {
	int index = 0;

	// Finds int value of the string
	for (unsigned long i = 0; i < key.length(); i++)
		index = index + (int)key[i];

	// If the index is too large take the ramainder of the index divided by the table size
	if (index > TABLESIZE - 1) 
		index = index % TABLESIZE;
	return index;
}

// Insert word into Hash Table
void hashTable::insert(string name) {
	int var = 1;
	int index = Hash(name);              // Find the index number for that word
	
	if (table[index]->word == "NONE") {  // If a word hasnt been put in the Node at the index, add the new word to it
		table[index]->word = name;
		table[index]->count = 1;
	}
	else if (table[index]->word == name) {   // If there is a word in the Node and its the same as the new word, increase word count
		table[index]->count = table[index]->count + 1;
	}
	else {            // Traverse down the Nodes until either a word match is found or the Node is NULL,                  
		Node* temp = table[index];
		while (temp->next != NULL) {
			temp = temp->next;
			if (temp->word == name) {
				temp->count = temp->count + 1;
				var = 0;
				break;
			}
		}
		if (var == 1) {   // If the Node is NULL and a match wasn't found, create new Node
			 Node* add = newNode();
                         add->word = name;
                         add->count = 1;
			 temp->next = add;
		}
	}
}

// Print both alphabetically and numerically
void hashTable::print() {
	bool compare = 0;  // bool variable to tell which way to sort
	vector< pair <string,int> > myVector = makeVector();  // Make a vector pair of string and int
	quickSort(myVector, 0, myVector.size(), compare);     // Sort alphabetically
	for (unsigned long i = 1; i < myVector.size() + 1; i++) {
		cout << myVector[i].first << " " << myVector[i].second << endl;  // Print each word and its count
	}
	cout << endl;
	compare = 1;
	quickSort(myVector, 0, myVector.size(), compare);     // Sort numerically
	for (unsigned long i = 0; i < myVector.size(); i++) {
                cout << myVector[i].first << " " << myVector[i].second << endl;  // Print each word and its count
        }
}

// Make a vector pair to easily sort and print
vector< pair <string,int> > hashTable::makeVector() {
	vector< pair <string,int> > myVector;    // Vector pair of string and int
	for (int i = 0; i < TABLESIZE; i++) {    // Add each word and its count to the vector
                if (table[i]->word != "NONE") {
                        myVector.push_back(make_pair(table[i]->word,table[i]->count));
                        Node* temp = table[i];
                        while (temp->next != NULL) {  // Make sure there isn't more words down linked list's
                                temp = temp->next;
                                myVector.push_back(make_pair(temp->word,temp->count));
                        }
                }
        }
	return myVector;
}

// Swap two ints
void hashTable::swap(int* left, int* right) {
        int temp = *left;
        *left = *right;
        *right = temp;
}

// Swap two strings
void hashTable::swap(string* left, string* right) {
	string temp = *left;
	*left = *right;
	*right = temp;
}

int hashTable::partition(vector< pair <string,int> > &myVector, int left, int right, bool compare) {
	if (compare == 0) {  // If sorting Alphabetically: based on the word
		string pivot = myVector[right].first;    // Make pivot the last word
		int index = (left - 1);
	
		for (int i = left; i <= right - 1; i++) {
			if (myVector[i].first < pivot) {  // If a word is less than the pivot word
				index++;
				swap(&myVector[index].first,&myVector[i].first);  // Swap the string words
				swap(&myVector[index].second,&myVector[i].second); // Swap theint count values
			}
		}
		swap(&myVector[index+1].first, &myVector[right].first);   // Swap the string words
		swap(&myVector[index+1].second, &myVector[right].second);  // Swap the int count values
		return (index + 1);
	}
	else {              // Else sorting Numerically: based on the count
		int pivot = myVector[right].second;      // Make pivot the last count
                int index = (left - 1);

                for (int i = left; i <= right - 1; i++) {
                        if (myVector[i].second > pivot) {  // If a count is greater than the pivot count
                                index++;
                                swap(&myVector[index].first,&myVector[i].first);   // Swap the string words
                                swap(&myVector[index].second,&myVector[i].second);  // Swap the int count values
                        }
                }
                swap(&myVector[index+1].first, &myVector[right].first);    // Swap the string words
                swap(&myVector[index+1].second, &myVector[right].second);   // Swap the int count values
                return (index + 1);
	}
}

// Quick sort method
void hashTable::quickSort(vector< pair <string,int> > &myVector, int left, int right, bool compare) {
	if (left < right) {
		int part = partition(myVector, left, right, compare);
		quickSort(myVector, left, part - 1, compare);
		quickSort(myVector, part + 1, right, compare);
	}		

}





