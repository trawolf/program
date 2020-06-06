/*
��һ����myfile���ļ��������ļ�������������ѧϰ�Ŀ�Ŀ�����֣���������һ�Ž�Ҫ���ԵĿ�Ŀ���֣�
�����׷��һ�ſ�Ŀ�����֡�д����Ϻ����ζ�ȡmyfile�����ݲ���ʾ����Ļ�ϡ�����Ҫ�����������Ŀ�ȱ���֡�
*/
/*
�������롿Math
                    English
                    C++
                    Network
�����������
                    Writng file->
                    Please input subjects:
                    Please input the 1 subject:
                    --->
                    Please input the 2 subject:
                    --->
                    Please input testing subject(only one):
                    --->
                    Write the appended content(only one):
                    --->
                    Read the content of the file:
                    --->Math
                    --->English
                    --->C++
                    --->Network
*/

#include<iostream>
#include<string>
#include<fstream>
using  namespace  std;

class  fileoperate
{
public:
    fileoperate();
};

fileoperate::fileoperate()
{
    char  letter[20];
    ofstream  outfile;
    outfile.open("myfile", ios::out);
    cout << "Writng  file->" << endl;
    cout << "Please  input  subjects:  " << endl;
    //enter your code here
    cout << "Please input the 1 subject:" << endl << "--->" << endl;
    cin >> letter;
    cout << "\n";
    outfile << letter << endl;      //���ļ�д������
    cout << "Please input the 2 subject:" << endl << "--->" << endl;
    cin >> letter;
    cout << "\n";
    outfile << letter << endl;      //���ļ�д������

    cout << "Please  input  testing  subject(only  one):  " << endl;
    cout << "--->";
    cin >> letter;
    cout << "\n";
    outfile << letter << endl;      //���ļ�д������
    outfile.close();                        //�ر��ļ�
    outfile.open("myfile", ios::app);
    cout << "Write  the  appended  content(only  one):  " << endl;
    cout << "--->";
    cout << "\n";
    //enter your code here
    cin >> letter;
    outfile << letter << endl;      //���ļ�д������
    outfile.close();                        //�ر��ļ�
    cout << endl << "Read the content of the file:" << endl;
    ifstream infile("myfile");
    infile.getline(letter, 19);
    while (!infile.eof()) {
        cout <<"--->"<< letter << endl;
        infile.getline(letter, 19);
    }
    infile.close();

}

int  main()
{
    fileoperate  fiop;
    system("pause");
    return  0;
}