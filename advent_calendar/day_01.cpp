#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
using namespace std;

int main () {
    string line;
    ifstream myfile ("Z:/Prog/CPP/advent_calendar/f_day_01.txt");

    string str_nums[10] = {"zero", "one", "two", "three", "four", 
                         "five", "six", "seven", "eight", "nine"};
    size_t num_index;
    int nums_size;

    string num1, num2;
    int line_val;
    int sum = 0;

    if(myfile.is_open()) {
        while(getline (myfile,line)) {
            num1 = "0";
            num2 = "0";

            nums_size = sizeof(str_nums)/sizeof(str_nums[0]);

            for(int i = 0 ; i < nums_size ; i++) {
                num_index = line.find(str_nums[i]);
                if (num_index != string::npos) {
                    line.replace(num_index + 1, 1, to_string(i));
                }
                while(num_index != string::npos) {
                    num_index = line.find(str_nums[i]);
                    if (num_index != string::npos) {
                        line.replace(num_index + 1, 1, to_string(i));
                    }
                }
            }

            for(int i = 0 ; i < line.length() ; i++) {
                if(isdigit(line[i])) {
                    num1 = line[i];
                    break;
                }
            }
            for(int i = 0 ; i < line.length() ; i++) {
                if(isdigit(line[i])) {
                    num2 = line[i];
                }
            }
            line_val = stoi(num1 + num2);
            sum += line_val;
        }
        cout << sum << '\n';
        myfile.close();
    }
    else {
        cout << "Unable to open file";
    }

  return 0;
}