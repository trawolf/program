#include<iostream>
#include"Database.h"
#include"Info.h"
using namespace std;

int  main() {
    int  capacity, total_data_number, id, delete_data_number; //容量，增量，id，减量
    char  username[10];
    char  password[10];
    cin >> capacity >> total_data_number;
    Database  d(capacity);
    int* id_array = new  int[total_data_number];
    for (int p = 0; p < total_data_number; p++) {
        cin >> id >> username >> password;
        id_array[p] = id;
        d.push_info(Info(id, username, password));
    }
    cin >> delete_data_number;
    for (int q = 0; q < delete_data_number; q++) {
        cin >> id;
        d.delete_info(id);
    }
    for (int k = 0; k < total_data_number; k++)
        d.get_info(id_array[k]);
    return  0;
}