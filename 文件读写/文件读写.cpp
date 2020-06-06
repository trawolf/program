#include<iostream>
#include<fstream>
#include<algorithm>
#include<sstream>

struct stu {
	int id;
	char name[10];
	unsigned int score;
};
bool operator<(stu s1, stu s2)
{
	return s1.score < s2.score;
}
bool operator>(stu s1, stu s2)
{
	return s1.score > s2.score;
}
int main()
{
	stu* ones = new stu[1000];
	std::ifstream infile("data.txt",std::ios::binary);
	std::string str;
	std::stringstream strfile;
	int i = 0;
	while (getline(infile, str))
	{
		strfile << str;
		strfile >> ones[i].name >> ones[i].id >> ones[i].score;
		i++;
	}
	int count = i;
	infile.close();
	std::sort(ones, ones + count);
	std::ofstream outfile("data.dat", std::ios::binary);
	for (int j = count- 1; j >= 0; j--)
	{
		outfile.write((char*)(&ones[j]), sizeof(ones[j]));
	}
	outfile.close();
	return 0;
}