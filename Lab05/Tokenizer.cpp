#include "Tokenizer.h"
#include <vector>
#include <string>
std::vector<std::string> Tokenizer::Parse(std::string line){
    std::vector<std::string> res;
    std::string tmp;
    for (char &x : line){
        if ((x >= '0' && x <= '9') || (isalpha(x)) || x == '.') continue;
        else x = ' ';
    }
    std::stringstream ss(line);
    while(ss >> tmp){
        res.push_back(tmp);
    }
    return res;
}