#include<iostream>
#include"CBox.h"
#include"CBox2.h"
#include"CCandyBox.h"
using namespace std;

int main() {
	CCandyBox chocBox{ 2.0, 3.0, 4.0, "Chockies" };  // Declare and initialize
	CCandyBox chocolateBox{ chocBox };               // Use copy constructor
	std::cout << "Volume of chocBox is " << chocBox.volume() << std::endl
		<< "Volume of chocolateBox is " << chocolateBox.volume() << std::endl;
	std::cout << "====================Display====================" << std::endl;
	chocBox.Display();
	chocolateBox.Display();
	{ // Caution
		std::cout << "====================CBox related====================" << std::endl;
		CBox& box = chocBox;
		box.Display();
		CBox* pBox = &chocolateBox;
		pBox->Display();
	} { // Caution
		std::cout << "====================CBox2 related====================" << std::endl;
		CBox2& box = chocBox;
		box.Display();
		CBox2* pBox = &chocolateBox;
		pBox->Display();
	}
	return 0;
}