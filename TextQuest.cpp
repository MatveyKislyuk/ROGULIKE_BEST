#include <iostream>
#include <string.h>
#include <cstdio>
#include <fstream>
#include <sstream>
#include "Utility.h"
#include "TextQuest.h"

bool isNum(char n){ //проверка является ли числом
    if ((n == '0') or (n == '1') or (n == '2') or(n == '3')
    or (n == '4') or (n == '5') or (n == '6') or (n == '7')
    or (n == '8') or (n == '9') or (n == '10') or (n=='11')
    or (n == '12') or (n == '13') or (n == '14') or (n=='15')
    or (n == '16') or (n == '17') or (n == '18') or (n=='19') or (n=='20')){
        return true;
    }
    else{
        return false;
    }
}

void quest()
{
    gotoxy(0, 30);
    bool game = true;
    int n = -1, inp = 0, i = 0, j = 0;
    int a[2] = {0,0};
    string vr[256], choice[256], str[256];
    int num[256];
    ifstream in;


    in.open("..\\quest.txt");
    while(!in.eof()){ //закидывает строчки из текстового файла
        getline(in, str[i]);
        vr[i]=str[i][0]; vr[i] += str[i][1];
        num[i]=stoi(vr[i]);
        str[i].erase(0,2);
        string last_five = str[i].substr(str[i].length() - 5, 5);


        while(j < str[i].length()){
            istringstream iss(last_five);
            vector<int> arr;
            int numer;
            while (iss >> numer) {
                arr.push_back(numer);
            }
            for (int d : arr) {
                choice[i][j] = d;
            }
            j++;
            cout << choice[i][j] << " ";
        }


        str[i].erase(str[i].length() - 5, 5);


        i++;
    }

    /*i = 0;
    while(game){
        cout << str[i] << "\n";
        while(!kbhit()){
            auto Key = _getch();
            if (KeyCheck(Key) == 1) {

            }
            if (KeyCheck(Key) == 2) {

            }
        }

        i++;
    }*/

    /*while(game){

    }
    while(game){
        i = 0; n++;
        while(i < str[n].length()){ //разделение текста от чисел
            if ((!isNum(str[n][i])) and (str[n][i] != ' ')){
                a[0]=i;
                i=str[n].length();
            }
            i++;
        }
        i = i - 2;
        while(i > 0){ //конкретное выделение текста
            if ((!isNum(str[n][i])) and (str[n][i] != ' ')){
                a[1] = i+1;
                i=-1;
            }
            i--;
        }
        choice = str[n].substr(a[1]+1,str[n].length()-a[1]);
        j = 0; i = 0;
        for(j = 0; j < 10; j++){
            num[j]="0"; //все остальные варианты выбора пустые
        }
        j = 0; i = 0;
        if (a[1] > (str[n].length()-2)){ //условие выхода из квеста
            for(j = 0; j < 10; j++){
                num[j] = "777";
            }
        }
        else{
            j = 0; i = 0;
            while((i < choice.length()) and (j < 10)){
                if (choice[i] == ' '){
                    num[j] = choice.substr(0,i);
                    j++;
                    choice = choice.substr(i+1, choice.length()-1-i );
                    i = 0;
                }
                else{
                    i++;
                }
            }
        }
        cout << str[n].substr(a[0],a[1]-a[0]) << endl;

        cin >> inp;
        n = stoi(num[inp-1]);
        if (n == 777){
            game = false;
        }
    }*/
    in.close();
    wait();
}
