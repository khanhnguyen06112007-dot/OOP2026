#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <vector>
#include <string>
#include <sstream>
class Tokenizer{
public:
    static std::vector<std::string> Parse(std::string line);
};
#endif