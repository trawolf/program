#pragma once
#include<iostream>

const int length = 10;
class Info
{
private:
	int id;
	char* username;   //字符串长度<10
	char* password;   //字符串长度<10
public:
	friend class Database;
	bool operator ==( Info b) {
		if (id == b.id)
			return true;
		else return false;
	}
	Info() {}
	Info(int num, char* name, char* word) {
		this->id = num;
		username = new char[length];
		password = new char[length];
		for (unsigned int i = 0; i < strlen(name); i++)
		{
			username[i] = name[i];
			username[i + 1] = '\0';
		}
		for (unsigned int i = 0; i < strlen(word); i++)
		{
			password[i] = word[i];
			password[i + 1] = '\0';
		}
	}
};

