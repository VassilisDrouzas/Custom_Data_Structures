#include "List.h"


//Feel free to change the main() function to play around with the list functions! :)
int main()
{
	std::cout << "Test 1 : " << std::endl << std::endl;

	List <int> y; //dimiourgia custom "vector" me 5 kelia-theseis


	y.insert_back(20); //push back san tou vector
	y.insert_back(30);
	y.insert_back(40);
	y.insert_back(50);
	y.insert_back(60);
	y.insert_back(70);
	y.insert_back(80);

	y.print();

	y.insert_front(10); // push front antistoixa
	std::cout << "---------" << std::endl;
	y.print();
	y.remove_back(); // diagrafi tou teleutaiou keliou

	y.remove_front();//diagrafi tou protou keliou 


	List <int> y2;
	y2.insert_back(200);
	y2.insert_back(300);
	
	//y = y + y2; // operator + (can't happen because list size is fixed. When going to add the first item of the new list, the old list points to null)
	//std::cout<<"OPERATOR+" << std::endl;
	y.print();
	List <int> y3 = y2; // copy constructor
	y3 = y;  // operator =

	std::cout << "y3 print" << std::endl;
	y3.print();

	
	

	y.flip(); // anapodogirisma tou list
	std::cout<<"Flip"<<std::endl;

	y.print(); 



	std::cout << "TAKS" << std::endl;
	y.taks();
	y.print();

	
	

//////////////////////////////  TEST  2  //////////////////////////

	std::cout << std::endl << "Test 2 :" << std::endl << std::endl;

	if (y.isEmpty())std::cout << "I am empty " << std::endl;  
	else
	{
		std::cout << "My size is : " << y.size() << " elements" << std::endl;  //arithmos thesewn tou list
		

		

		std::cout << "My first element is : " << y.begin() 
			<< " and my last one is : " << y.end() << std::endl; 
	}

	std::cout << "Do you have a '30' in your elements ?          ";
	if (y.find(30))std::cout << "Yes i Do!!" << std::endl;  // epistrefei an iparxei i timh 30 ston vector
	else std::cout << "Sorry but NO" << std::endl;

	std::cout << "My third element is : " << y[2] << std::endl;  // epistrefei to array[i]
	y.print();
	y.replace(3, 45);
	
	std::cout << "---------" << std::endl;
	y.print();
	if (y.isEmpty())std::cout << "I am empty " << std::endl;


}
