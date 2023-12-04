#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;

int main () {
    string line;
    string game;

    int r_max, g_max, b_max;

    string str_num_balls = ""; 
    int num_balls; 
    string color; 

    int index = 0;
    int column;

    int result;
    int sum = 0;

    ifstream myfile ("./f_day_02.txt");

    if(myfile.is_open()) {
        while(getline (myfile,line)) {
            // cout << "SUM =" << sum << '\n';
            r_max = 0;
            g_max = 0;
            b_max = 0;

            column = line.find(':');
            if(column != string::npos) {
                index++;
                line.erase(0, column+2);
            }

            // cout << "INDEX =" << index << '\n';

            for(int i = 0 ; i < line.length() ; i++) {
                if(isdigit(line[i])) {
                    str_num_balls.append(line, i, 1);
                }
                else if((line[i] == 'r' && line[i-1] != 'g') || line[i] == 'g' || line[i] == 'b') {
                    // cout << "str_num = " << str_num_balls << '\n';
                    // cout << "l[i] = " << line[i] << '\n';
                    num_balls = stoi(str_num_balls);
                    str_num_balls = "";

                    if(line[i] == 'r' && num_balls > r_max) {
                        r_max = num_balls;
                    }
                    else if(line[i] == 'g' && num_balls > g_max) {
                        g_max = num_balls;
                    }
                    else if(line[i] == 'b' && num_balls > b_max) {
                        b_max = num_balls;
                    }
                }
            }
            result = r_max * g_max * b_max;
            // cout << result << "\n\n";
            sum += result;
        }
        cout << sum << "\n\n";
    } 
    else {
        cout << "Unable to open file";
    }

  return 0;
}
