#pragma once
#include <iostream>

template<typename T>
class List {
	template<typename T>
	struct Node {
		
		
			T data;
			Node<T>* nextPtr;
		public:
			Node(const T& info) {
				data = info;
				nextPtr = nullptr;
			}
			T getData() const {
				return data;
			}
	};
private:
	Node<T>* firstPtr;
	Node<T>* lastPtr;
	Node<T>* getNewNode(const T& value) {
		return new Node<T>(value);
	}


public:
	List() {
		std::cout << "Default Constructor" << std::endl;
		firstPtr = nullptr;
		lastPtr = nullptr;

	}
	
	~List() {
		std::cout << "Destructor" << std::endl;
		if (!isEmpty()) {
			std::cout << "Destroying nodes..." << std::endl;

			Node<T>* currentPtr = firstPtr;

			while (currentPtr != nullptr) {
				currentPtr = currentPtr->nextPtr;
			}
		}
	}
	/*
	List(const List& src) {
		std::cout << "Copy Constructor" << std::endl;
		this->firstPtr = src.firstPtr;
		this->lastPtr = src.lastPtr;

	}*/

	List& operator=(const List& src) {						//In order to work properly, lists should have same sizes.
															//Otherwise, the new list will be comprised of the first k elements of the other list, where k=size of our list
		if (&src == this)return *this;
		Node<T>* currentPtr = firstPtr;
		Node<T>* currentPtr_src = src.firstPtr;
		while (currentPtr != nullptr) {
			currentPtr->data = currentPtr_src->data;
			currentPtr = currentPtr->nextPtr;
			currentPtr_src = currentPtr_src->nextPtr;
		}
		
		
	}

	T operator[] (int subscript){
		if (subscript >= 0 || subscript < this->size()) {
			Node<T>* currentPtr = firstPtr;
			int i = 0;
			while (currentPtr != nullptr && i != subscript ) {
				currentPtr = currentPtr->nextPtr;
				i++;
			}
			return currentPtr->data;					//We have reached  i=subscript-1
		}
	}

	void taks() const {							//Ascending order
		
		Node<T>* currentPtr = firstPtr;
		T* temp = new T[this->size()];
		int k = 0;
		while (currentPtr != nullptr) {
			temp[k] = currentPtr->data;
			k++;
			currentPtr = currentPtr->nextPtr;
		}
		for (int i = 0; i < k-1; i++) {
			int min = i;
			for (int j = i + 1; j < k; j++) {
				if (temp[j] < temp[i]) {
					min = j;
					T t = temp[i];
					temp[i] = temp[min];
					temp[min] = t;
				}
			}
		}
		currentPtr = firstPtr;
		int j = 0;
		while (currentPtr != nullptr) {
			currentPtr->data = temp[j];
			j++;
			currentPtr = currentPtr->nextPtr;
		}
	}
				
	void flip() {								
		Node<T>* currentPtr = firstPtr;
		T* temp = new T[this->size()];
		int i = 0;
		while (currentPtr != nullptr) {
			temp[this->size()-i-1] = currentPtr->data;
			i++;
			currentPtr = currentPtr->nextPtr;
		}
		currentPtr = firstPtr;
		int j = 0;
		while (currentPtr != nullptr) {
			currentPtr->data = temp[j];
			j++;
			currentPtr=currentPtr->nextPtr;
		}

	}

	T begin() const {
		return this->firstPtr->data;
	}
	T end()const {
		return this->lastPtr->data;
	}
	int size() const {
		int size = 0;
		if (isEmpty()) {
			return 0;
		}
		else {
			Node<T>* currentPtr = firstPtr;
			while (currentPtr != nullptr) {
				size++;
				currentPtr = currentPtr->nextPtr;
			}
		}
		return size;
	}

	bool find(const T& value) {
		if (isEmpty()) {
			std::cout << "The list is empty" << std::endl;
			return false;
		}
		else {
			Node<T>* currentPtr = firstPtr;
			while (currentPtr != nullptr) {
				
				if (currentPtr->data == value) {
					return true;
				}
				currentPtr = currentPtr->nextPtr;			
			}
			
		}
		return false;
	}

	void replace(int pos, const T& value){
		if (pos < 0) {
			std::cout << "Position index should be greater than 0." << std::endl;
			
		}
		else if (pos > this->size()) {
			std::cout << "Position index exceeds the list's bounds" << std::endl;
			
		}
		else {
			Node<T>* currentPtr = firstPtr;
			int i = 0;
			while (currentPtr != nullptr && i != pos - 1) {
				currentPtr = currentPtr->nextPtr;
				i++;
			}
			currentPtr->data = value;				//because i=pos-1 we can replace the data at this index
		}
		

	}


	void insert_front(const T& value) {
		Node<T>* newPtr = getNewNode(value);
		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			newPtr->nextPtr = firstPtr;
			firstPtr = newPtr;
		}
	}

	void insert_back(const T& value) {
		Node<T>* newPtr = getNewNode(value);
		if (isEmpty()) {
			firstPtr = lastPtr = newPtr;
		}
		else {
			lastPtr->nextPtr = newPtr;
			lastPtr = newPtr;
		}
	}
	void remove_front() {
		if (isEmpty()) {
			std::cout << "The list is empty, so i can't remove anything" << std::endl;
		}
		else {
			

			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;
			}
			else {
				firstPtr = firstPtr->nextPtr;
			}
		}
	}

	void remove_back() {
		if (isEmpty()) {
			std::cout << "The list is empty, so i can't remove anything" << std::endl;
		}
		else {
			if (firstPtr == lastPtr) {
				firstPtr = lastPtr = nullptr;
			}
			else {
				Node<T>* currentPtr = firstPtr;
				while (currentPtr->nextPtr != lastPtr) {
					currentPtr = currentPtr->nextPtr;						//find the protelefteo element
				}
				lastPtr = currentPtr;
				currentPtr->nextPtr = nullptr;
			}
		}
	}

	

	bool isEmpty() const {
		return firstPtr == nullptr;
	}

	void print() const {
		if (isEmpty()) {
			std::cout << "The list is empty" << std::endl;

		}
		Node<T>* currentPtr = firstPtr;
		while (currentPtr != nullptr) {
			std::cout << currentPtr->data << std::endl;
			currentPtr = currentPtr->nextPtr;
		}
	}





};