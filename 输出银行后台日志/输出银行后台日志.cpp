#include<fstream>
#include<iostream>
#include<ctime>
#include<algorithm>
#include<string.h>
//#include<iomanip>
#pragma warning(disable : 4996)

struct data {
	time_t time;
	char url[50];
	char username[20];
};
bool operator<(data d1, data d2)
{
	return (int)d1.time < (int)d2.time;
}
bool operator>(data d1, data d2)
{
	return (int)d1.time > (int)d2.time;
}
int main()
{
	int lines;
	std::cin >> lines;
	data* ones = new data[lines];
	for (int i = 0; i < lines; i++) {
		std::cin >> ones[i].time >> ones[i].url >> ones[i].username;
	}
	std::sort(ones, ones + lines);
	std::ofstream outfile("log.txt", std::ios::out);
	for (int i = 0; i < lines; i++) {
		outfile << ctime(&ones[i].time) ;
		outfile.width(20);
		outfile.setf(std::ios::left);
		outfile << ones[i].username;
		int length = strlen(ones[i].url);
		if (ones[i].url[length - 1] == 'n') {
			outfile << "login" << std::endl;
		}
		else if (ones[i].url[length-1] == 't') {
			outfile << "logout" << std::endl;
		}
		else if (ones[i].url[length-1] == 'y') {
			outfile << "pay" << std::endl;
		}
	}
	outfile.close();
	return 0;
}
