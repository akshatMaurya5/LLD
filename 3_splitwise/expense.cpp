#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Expense
{
public:
    string paidBy;
    double amount;
    vector<string> participants;
    string type;           // "EQUAL", "EXACT", or "PERCENT".
    vector<double> values; // this holds how expese is split among participants

    // Expense("u4", 1200, {"u1", "u2", "u3", "u4"}, "PERCENT", {40, 20, 20, 20});
    // Expense("u1", 1250, {"u2", "u3"}, "EXACT", {370, 880});

    Expense(string paidBy, double amount, vector<string> participants, string type, vector<double> values) : paidBy(paidBy), amount(amount), participants(participants), type(type), values(values) {}
};