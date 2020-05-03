#pragma once
#include"Info.h"
#include<iostream>
using namespace std;

class Database
{
private:
	Info* info;
	int count;  //现有账号数量
	int capacity;  //数据库总容量
public:
	Database(int cap) {
		this->capacity = cap;
		this->count = 0; 
		this->info = new Info[capacity];
}
	//向info添加f，count加一(如果id重复或超出数据库容量则取消添加)
	bool push_info(Info f) {
		if (count >= capacity) return false;
		else {
			bool yesorno=0;
			for (int i = 0; i < count; i++) {
				if (f == info[i]) {
					yesorno = 1;
					break;
				}
			}
			if (yesorno == 0) {
				info[count] = f;
				count++;
				return true;
			}
			else return false;
		}
	}
	//获取id为m的账号信息，如果存在则打印成为一行
	void get_info(int m) {
		for (int i = 0; i < count; i++) {
			if (info[i].id == m) {
				cout << info[i].id <<" "<< info[i].username <<" "<< info[i].password<<endl;
				break;
			}
		}
	}
	//删除id为m的账号信息，并将m之后的数据前移，如果删除成功返回true，如果不存在id为m的，则返回false
	bool delete_info(int m) {
		 for(int i=0;i<count;i++){
			if (info[i].id == m) {
				for (int j = i; j < count-1; j++) {
					info[j] = info[j + 1];
				}
				count--;
				return true;
				break;
			}
		}
		return false;
	}
};

