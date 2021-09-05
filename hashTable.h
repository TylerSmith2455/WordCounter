#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

int const TABLESIZE = 100;

class hashTable{
	public:
		hashTable();
		int Hash(string key);
		void insert(string name);
		void print(); 
		vector< pair <string,int> > makeVector();
		void quickSort(vector< pair <string,int> > &myVector, int left, int right, bool compare);
		int partition(vector< pair <string,int> > &myVector, int left, int right, bool compare);
		void swap(string* left, string* right);
		void swap(int* left, int* right);
	private:
		// Node structure to hold word, count, and next node incase of collisions
		struct Node {
        		string word;
        		int count;
        		Node *next;
		};
		
		// Creates a new Node
		struct Node* newNode() {
        		struct Node* temp = new Node;
        		temp->word = "NONE";
        		temp->count = 0;
        		temp->next = NULL;
        		return temp;
		};
		
		// Hash Table: Array of Nodes
		Node* table[TABLESIZE];
};


#endif /* HASHTABLE_H */
