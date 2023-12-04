#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> copyFile(std::string file_name);


int main() {
    std::string file_name = "./f_day_04.txt";
    std::vector<std::string> puzzle_input;

    std::vector<std::string> card;
    std::vector<std::string> tmp;
    std::size_t index_delimiter;
    std::vector<int> winning_nums;
    std::vector<int> card_nums;

    std::vector<int> card_cpy;

    int result_card;
    int points = 0;

    puzzle_input = copyFile(file_name);

    for(int i = 0 ; i < puzzle_input.size() ; i++) {
        card_cpy.push_back(1);
    }

    for(int i = 0 ; i < puzzle_input.size() ; i++) {
        tmp.clear();
        winning_nums.clear();
        card_nums.clear();
        result_card = 0;

        index_delimiter = puzzle_input[i].find(":") + 2;
        if(index_delimiter == std::string::npos) {
            std::cout << "Error, no column found.\n";
            return 1;
        }
        puzzle_input[i].erase(0, index_delimiter);

        index_delimiter = puzzle_input[i].find("|");
        if(index_delimiter == std::string::npos) {
            std::cout << "Error, no vertical bar found.\n";
            return 1;
        }
        
        tmp.push_back(puzzle_input[i].substr(0, index_delimiter-1) + " ");
        tmp.push_back(puzzle_input[i].substr(index_delimiter+2, puzzle_input[i].size()) + " ");

        index_delimiter = tmp[0].find(" ");
        while(index_delimiter < tmp[0].size()){
            if(!isdigit(tmp[0][index_delimiter-1])) {
                tmp[0].erase(0,index_delimiter+1);
                index_delimiter = tmp[0].find(" ");
                if(index_delimiter == std::string::npos) {
                    break;
                }
                continue;
            }
            winning_nums.push_back(stoi(tmp[0].substr(0,index_delimiter)));
            tmp[0].erase(0,index_delimiter+1);
            index_delimiter = tmp[0].find(" ");
            if(index_delimiter == std::string::npos) {
                break;
            }
        }

        index_delimiter = tmp[1].find(" ");
        while(index_delimiter < tmp[1].size()){
            if(!isdigit(tmp[1][index_delimiter-1])) {
                tmp[1].erase(0,index_delimiter+1);
                index_delimiter = tmp[1].find(" ");
                if(index_delimiter == std::string::npos) {
                    break;
                }
                continue;
            }
            card_nums.push_back(stoi(tmp[1].substr(0,index_delimiter)));
            tmp[1].erase(0,index_delimiter+1);
            index_delimiter = tmp[1].find(" ");
            if(index_delimiter == std::string::npos) {
                break;
            }
        }

        /** PART ONE
        for(int num : card_nums) {
            if(std::find(winning_nums.begin(), winning_nums.end(), num) != winning_nums.end()) {
                if(result_card == 0) {
                    result_card++;
                } else {
                    result_card *= 2;
                }
            }
        }
        points += result_card;
        */

        /** PART TWO */
        int num_cpy = card_cpy[i];
        do {
            int num_cards;
            num_cards = 0;
            for(int num : card_nums) {
                
                if(std::find(winning_nums.begin(), winning_nums.end(), num) != winning_nums.end()) {
                    num_cards++;
                }
            }
            for(int x = 1 ; x <= num_cards ; x++) {
                card_cpy[i+x]++;
            }

            num_cpy--;
        } while(num_cpy > 0);
    }

    for(int n : card_cpy) {
        points += n;
    }

    std::cout << points << '\n';


    return 0;
}

std::vector<std::string> copyFile(std::string file_name) {
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

