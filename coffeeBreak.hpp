#ifndef COFFEEBREAK_HPP__
#define COFFEEBREAK_HPP__
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct coffee{
    double s_price;//small
    double m_price;//medium
    double l_price;//large
    string drink;
};

class Person{
    private:
        string _name;
        double _balance_paid; //how much they paid on their designated day
        double _balance_owed; //total cost of the drinks they have purchased
    public:
        Person();
        Person(string);

        double getBalancePaid() const;
        void setBalancePaid();

        double getBalanceOwed() const;
        void setBalanceOwed();

};

#endif