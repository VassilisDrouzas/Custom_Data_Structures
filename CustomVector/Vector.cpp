#include "Vector.h"

	//////////////////////////////  TEST  1  //////////////////////////

//Feel free to edit the main() function in order to play around with the vector :)
int main()
{
	std::cout << "Test 1 : " << std::endl << std::endl;

	MyVec<int> y;


	y.push_back(20); //push back san tou vector
	y.push_back(30);
	y.push_back(40);
	y.push_back(50);
	y.push_back(60);
	y.push_back(70);
	y.push_back(80);

	y.print();

	y.push_front(10); // push front antistoixa

	y.pop_back(); // diagrafi tou teleutaiou keliou

	y.pop_front();//diagrafi tou protou keliou (array[0])

	y.pushAt(90, 4); // eisagwgi tou 90 sti thesi 4

	y.popAt(2); // diagrafei tou keliou 2

	MyVec <int> y2;
	y2.push_back(200);
	y2.push_back(300);

	y = y + y2; // operator +

	MyVec <int> y3 = y2; // copy constructor
	y3 = y;  // operator =


	y.taks(); // taksinomisi auksousa i fthinousa oti thes

	y.flip(); // anapodogirisma tou vector

	y.print(); // cout olwn twn keliwn tou vector

//////////////////////////////  TEST  2  //////////////////////////

	std::cout << std::endl << "Test 2 :" << std::endl << std::endl;

	if (y.Empty())std::cout << "I am empty " << std::endl;  // na ektipwnei an o vector einai adeios i oxi
	else
	{
		std::cout << "My size is : " << y.mySize() << " bytes" << std::endl;  //size tou vector se bytes

		std::cout << "I have " << y.HowLong() << " elements" << std::endl;  //arithmos keliwn tou vector

		std::cout << "My first element is : " << y.begin() //array[0]
			<< " and my last one is : " << y.end() << std::endl; // array[last]
	}

	std::cout << "Do you have a '30' in your elements ?          ";
	if (y.find(30))std::cout << "Yes i Do!!" << std::endl;  // epistrefei an iparxei i timh 30 ston vector
	else std::cout << "Sorry but NO" << std::endl;

	std::cout << "My third element is : " << y[2] << std::endl;  // epistrefei to array[i]

	y.Erase();                      // na adeiasei o pinakas
	y.print();
	if (y.Empty())std::cout << "I am empty " << std::endl;
	y.off();                       // na apenergopoihthei o pinakas
	if (y.Empty())std::cout << "I am empty " << std::endl;


}
