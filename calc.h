#ifndef CALC_H
#define CALC_H

#include <vector>
#include <string>
#include <unordered_map>

class ExprSolver
{
private:
    std::unordered_map<std::string, int> m_op_presedence = {{"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}, {"%", 1}, {"(", 2}};

private:
    void makeCalc(std::vector<std::string>& expr, std::vector<std::string>::iterator it);

    std::vector<std::string>::iterator firstOperatorIndex(std::vector<std::string>& expr);
    bool isOperator(const std::string& op) const;

public:
    void exprSolver(std::vector<std::string>& expr);
};

#endif