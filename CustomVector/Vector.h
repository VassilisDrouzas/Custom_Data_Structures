#pragma once
#include <iostream>



	template<typename T>
	class MyVec {
	private:
		T* data;
		int size = 0;

	public:
		MyVec() {														//Default Constructor
			std::cout << "Default Constructor" << std::endl;
			//this->size = 0;
			data = new T[0];
			//data = nullptr;

		}
		
		MyVec(const MyVec& src) {										//Copy constructor
			std::cout << "Copy Constructor" << std::endl;
			this->size = src.size;
			this->data = new T[this->size];
			for (unsigned int i = 0; i < size; i++) {
				this->data[i] = src.data[i];
			}
		}

		MyVec& operator=(const MyVec& src) {
			std::cout << "Operator=" << std::endl;
			if (&src == this) return *this;
			this->size = src.size;
			if (this->data != nullptr) delete[] data;
			this->data = new T[this->size];
			for (unsigned int i = 0; i < size; i++) {
				this->data[i] = src.data[i];
			}
		}

		MyVec& operator+(MyVec & right) {
			std::cout << "Operator+" << std::endl;
			int oldSize = size;
			this->size += right.size;
			T* temp = new T[oldSize];
			for (int i = 0; i < oldSize; i++) {
				temp[i] = data[i];
			}
			if (this->data != nullptr) delete[] data;
			this->data = new T[size];
			for (int i = 0; i < oldSize; i++) {
				this->data[i] = temp[i];

			}
			for (int i = oldSize; i < size; i++) {

				this->data[i] = right.data[size - i - 1];
			}
			return *this;


		}
		/*
		friend std::ostream& operator<<(std::ostream& os, MyVec& right) {
			
				os << *(right.data) << std::endl;
				return os;
			
		}
		*/

		T operator[](int subscript) {
			if (subscript >= 0 || subscript < size) {
				return data[subscript];
			}
		}
		/*
		bool operator<(const MyVec& right) {					//Sort for class objects
			return data < right.data;
		}
		*/
		void taks() {
			std::cout << "Sorting using selection sort-Ascending order" << std::endl;
			for (int i = 0; i < size - 1; i++) {
				int min = i;
				for (int j = i + 1; j < size; j++) {
					if (data[j] < data[i]) {
						min = j;
						T temp = data[i];
						data[i] = data[min];
						data[min] = temp;
					}
				}
			}

		}

		bool Empty() const{
			//std::cout << "size: " << size << std::endl;
			if (data != nullptr) {
				return false;
			}
			return true;

		}
		void print()const {
			std::cout << "size: " << size << std::endl;
			if (data != nullptr) {
				for (unsigned int i = 0; i < size; i++) {
					std::cout << data[i] << std::endl;
				}
			}

		}
		void push_back(T element) {
			size++;
			T* temp = new T[size];


			for (int i = 0; i < size; i++) {
				temp[i] = data[i];

			}

			temp[size - 1] = element;
			data = temp;
			//delete[] temp;

		}

		void pop_back() {
			size--;
			T* temp = new T[size];

			for (int i = 0; i < size; i++) {
				temp[i] = data[i];
			}
			delete[] data;

			data = temp;
			temp = nullptr;
			//delete[] temp;												//Debug Error? Why doesn't happen below too?
		}
		void push_front(T element) {
			size++;
			T* temp = new T[size];
			temp[0] = element;
			for (int i = 0; i < size; i++) {
				temp[i + 1] = data[i];
			}

			data = temp;
			//delete[] temp;

		}
		void pop_front() {

			T* temp = new T[size];
			for (int i = 0; i < size; i++) {
				temp[i] = data[i + 1];
			}
			size--;
			data = temp;
			//delete[] temp;
		}

		void flip() {
			std::cout << "Flip" << std::endl;
			T* temp = new T[size];
			for (int i = 0; i < size; i++) {
				temp[i] = data[size - 1 - i];
			}
			data = temp;
			//delete[] temp;
		}
		T begin() const {
			if (Empty()) {
				std::cout << "The vector is empty" << std::endl;
			}
			else {
				return data[0];
			}

		}
		T end() const {
			if (Empty()) {
				std::cout << "The vector is empty" << std::endl;
			}
			else {
				return data[size - 1];
			}
		}
		int HowLong() {
			return size;
		}

		int mySize() {
			return sizeof(data);
		}
		void off() {
			if (!data) {
				delete[] data;
				data = nullptr;
			}
		}
		void Erase() {

			data = nullptr;

		}
		void pushAt(T element, int pos) {
			size++;
			T* temp = new T[size];


			for (int i = 0; i < pos; i++) {

				temp[i] = data[i];

			}
			temp[pos] = element;
			for (int i = pos + 1; i < size; i++) {
				temp[i] = data[i - 1];
			}
			data = temp;
			//delete[] temp;
		}

		void popAt(int pos) {
			size--;
			T* temp = new T[size];

			for (int i = 0; i < pos; i++) {
				temp[i] = data[i];
			}
			for (int i = pos; i < size; i++) {
				temp[i] = data[i + 1];
			}
			data = temp;
		}
		T find(T element) {
			for (int i = 0; i < size; i++) {
				if (data[i] == element) return true;
			}
			return false;
		}
		~MyVec() {
			std::cout << "Destructor" << std::endl;
			off();
		}

	};
	
	
	

