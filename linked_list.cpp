#include "linked_list.h"

int Node::countNodes_ = 0;
int Node::id_node_ = 0;

Node::Node() {
	next_ = nullptr;
	prev_ = nullptr;
	countNodes_++;
	numNode_ = ++id_node_;
}

Node::Node(const struct Data& data) : Node() {
	data_ = new Data(data.str_);
}

Node::Node(Node* prev) : Node() {
	prev_ = prev;
}

Node::~Node() {
	countNodes_--;
	delete data_;

	if (next_ != nullptr) {
		delete next_;
	}
}

LinkedList::LinkedList() {
	Head = nullptr;
	CurrNode = nullptr;
	countNodes = 0;
}

LinkedList::~LinkedList() {
	delete Head;
}

int LinkedList::Push(const Data& data) {
	Node* temp = new Node(data);
	++countNodes;
	
	if (Head == nullptr) {
		Head = temp;
		CurrNode = temp;
		return 0;
	}

	temp->prev_ = CurrNode;
	CurrNode->next_ = temp;
	CurrNode = temp;

	return 0;
}

void LinkedList::ShowElements() const {
	Node* tempHead = Head;

	std::cout << "count nodes = " << tempHead->countNodes_ << std::endl;
	
	while(tempHead != nullptr) {
		std::cout << tempHead->numNode_ << ": " << tempHead->data_->str_ << std::endl;
		tempHead = tempHead->next_;
	}
}

int LinkedList::Pull(Data* data) {
	if (CurrNode == nullptr) {
		return -1;	
	}

	if (data->str_ != nullptr) {
		delete [] data->str_;
	}
	data->str_ = new char [strlen(CurrNode->data_->str_) + 1];
	strcpy(data->str_, CurrNode->data_->str_);

	CurrNode = CurrNode->prev_;
	if (CurrNode->next_ != nullptr) {
		delete CurrNode->next_;
	}
	return 0;
}



