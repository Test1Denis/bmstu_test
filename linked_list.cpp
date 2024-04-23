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
	if (CurrNode == nullptr) {
		return 0;
	}
	if (CurrNode->next_ != nullptr) {
		delete CurrNode->next_;
		CurrNode->next_ = nullptr;
	}
	return 0;
}


void LinkedList::ShowElemFromTail(const Node* curNode) const {
	static int countEl = 0;
	if (curNode->next_ != nullptr) {
		countEl++;
		
		std::cout << countEl-- << " " << curNode->data_->str_ << std::endl;
		ShowElemFromTail(curNode->next_);
	}

}

void LinkedList::ShowElementFromTail_asOneLL() const {
	ShowElemFromTail(Head);	
}


int LinkedList::SwapElement(int node1, int node2) {
	if (node1 < 1 || node2 < 1) {
		std::cout << "check only more than 0" << std::endl;
		return -1;
	}

	Node* nd1 = getNode(node1 - 1);
	Node* nd2 = getNode(node2 - 1);	//bf3 = el3

	Node* nd1_next = nd1->next_;
	Node* nd1_next_next = nd1_next->next_;
	Node* nd2_next = nd2->next_;
	
	nd1->next_ = nd2->next_;

	nd1_next->next_ = nd2->next_->next_;
	nd2->next_ = nd1_next;
	nd2_next->next_ = nd1_next_next;



	return 0;
}


Node* LinkedList::getNode(int numNode) const {
	Node* temp = Head;

	while(--numNode >= 0) {
		temp = temp->next_;
		if (temp == nullptr) {
			return nullptr;
		}
	}
	return temp;
}

void LinkedList::getDataNode(int num_node, char* data) const {
	Node* temp = getNode(num_node);
	if (temp == nullptr) {
		data[0] = '\0';
		return;
	}
	strcpy(data, temp->data_->str_); 
}

