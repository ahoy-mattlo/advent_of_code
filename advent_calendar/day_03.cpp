#include <iostream>
#include <fstream>
#include <vector>

std::vector<std::string> copyFile (std::string file_name);
std::vector<int> checkAround(std::vector<std::string> datas, int i, int j);
std::string checkLeft(std::vector<std::string> datas, std::string str_num, int i, int j);
std::string checkRight(std::vector<std::string> datas, std::string str_num, int i, int j, int size_j);
int calculateGear(std::vector<int> nums);

int main() {
    std::string file_name = "./f_day_03.txt";
    std::vector<std::string> puzzle_input;
    std::vector<int> nums;
    int sum = 0;

    puzzle_input = copyFile(file_name);

    for(int i = 0 ; i < puzzle_input.size() ; i++) {
        //std::cout << "line number: " << i+1 << '\n';
        for(int j = 0 ; j < puzzle_input[0].size() ; j++) {
            char c = puzzle_input[i][j];
            /** PART ONE
             *  -------
             * if(!(c == '.' || isdigit(c))) {
             *      for(int num : checkAround(puzzle_input, i, j)) {
             *        nums.push_back(num);
             *      }
             *  }
            */
            /** PART TWO */
            if(c == '*') {
                nums.clear();
                for(int num : checkAround(puzzle_input, i, j)) {
                    nums.push_back(num);
                }
                sum += calculateGear(nums);
                // std::cout << "SUM = " << sum << '\n';
            }
            
        }
    }

    std::cout << sum << '\n';

    return 0;
}


std::vector<std::string> copyFile (std::string file_name) {
    std::string line;
    std::vector<std::string> lines;

    std::ifstream file(file_name);
    if(file.is_open()) {
        while(getline(file, line)) {
            lines.push_back(line);
        }
    }
    else {
        std::cout << "Error, file couldn't open.\n";
    }

    return lines;
}

std::vector<int> checkAround(std::vector<std::string> datas, int i, int j) {
    std::vector<int> nums;
    std::string str_num;
    int size_i = datas.size();
    int size_j = datas[0].size();
    char tmp_c;
    std::string tmp_s;

    // check left
    tmp_c = datas[i][j-1];
    if(j != 0 && isdigit(tmp_c)) {
        str_num = tmp_c;
        // check for other digits to the left
        str_num = checkLeft(datas, str_num, i, j-2);
        nums.push_back(stoi(str_num));
    }
    
    // check right
    tmp_c = datas[i][j+1];
    if(j != size_j-1 && isdigit(tmp_c)) {
        
        str_num = tmp_c;
        // check for other digits to the right
        str_num = checkRight(datas, str_num, i, j+2, size_j);
        nums.push_back(stoi(str_num));
    }
    
    // check top
    tmp_c = datas[i-1][j];
    if(i != 0) {
        str_num.clear();
        if(isdigit(tmp_c)) {
            str_num = tmp_c;
        }
        // check for other digits to the left
        str_num = checkLeft(datas, str_num, i-1, j-1);
        if(!str_num.empty() && !isdigit(tmp_c)) {
            nums.push_back(stoi(str_num));
            str_num.clear();
        }
        // check for other digits to the right
        str_num = checkRight(datas, str_num, i-1, j+1, size_j);
        if(!str_num.empty()) {
            nums.push_back(stoi(str_num));
        }
    }
    
    // check buttom
    tmp_c = datas[i+1][j];
    if(i != size_i-1) {
        str_num.clear();
        if(isdigit(tmp_c)) {
            str_num = tmp_c;
        }
        // check for other digits to the left
        str_num = checkLeft(datas, str_num, i+1, j-1);
        if(!str_num.empty() && !isdigit(tmp_c)) {
            nums.push_back(stoi(str_num));
            str_num.clear();
        }
        // check for other digits to the right
        str_num = checkRight(datas, str_num, i+1, j+1, size_j);
        if(!str_num.empty()) {
            nums.push_back(stoi(str_num));
        }
    }


    return nums;
}

std::string checkLeft(std::vector<std::string> datas, std::string str_num, int i, int j) { 
    char tmp_c;
    std::string tmp_s;

    for(int n = j ; n >=0 ; n--) {
        tmp_c = datas[i][n];
        if(isdigit(tmp_c)) {
            tmp_s = tmp_c;
            str_num.insert(0, tmp_s);
        }
        else {
            break;
        }
    }

    return str_num;
}

std::string checkRight(std::vector<std::string> datas, std::string str_num, int i, int j, int size_j) {
    char tmp_c;
    std::string tmp_s;

    for(int n = j ; n < size_j ; n++) {
        tmp_c = datas[i][n];
        if(isdigit(tmp_c)) {
            tmp_s = tmp_c;
            str_num.append(tmp_s);
        }
        else {
            break;
        }
    }

    return str_num;
}

int calculateGear(std::vector<int> nums) {
    /** PART TWO*/
    int result;
    if(nums.size() > 1) {
        result = nums[0] * nums[1];
    }
    // std::cout << nums[0] << " * " << nums[1] << " = " << result << '\n';
    return result;
}