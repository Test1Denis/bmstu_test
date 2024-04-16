#ifndef _linked_list_h_
#define _linked_list_h_

#include <iostream>
#include <string.h>

struct Data {
	char* str_;
	
	Data() {
		str_ = nullptr;
	}
	
	Data(const char* str) {
		str_ = new char [strlen(str)];
		strcpy(str_, str);
	}
	~Data() {
		if (str_ != nullptr) {
			delete [] str_;
		}
	}
};

struct Node {
	int numNode_;
	static int id_node_;
	static int countNodes_;	//weak place
							//if you will create two LinkedList, in every list will contain wrong of count nodes

	Data* data_;

	Node* next_;
	Node* prev_;

	Node();
	Node(Node*);
	Node(const struct Data& data);

	~Node();
};

class LinkedList {
	private :
		Node* Head;
//		Node* Tail;
		Node* CurrNode;
		int countNodes;
	public :
		LinkedList();
		~LinkedList();
		int Push(const Data& data);
		int Pull(Data* data);

		void flush() {
			delete Head;
		}

		int DeleteNode(int numNode);
		int SwapElement(int node1, int node2);
		void ShowElements() const;
};


#endif
