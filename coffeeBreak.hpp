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
    string drink;//item name
};

class Person{
    private:
        string _name;
        coffee _drink_of_choice;
        char _drink_size;
        double _drink_price;
        double _balance_paid; //how much they paid on their designated day
        double _balance_owed; //total cost of the drinks they have purchased
    public:
        Person();
        Person(string);
        Person(string, coffee, char);

        coffee getDrinkOfChoice() const;
        void setDrinkOfChoice(coffee);

        char getDrinkSize() const;
        void setDrinkSize(char);

        double getDrinkPrice() const;
        void setDrinkPrice(char);

        double getBalancePaid() const;
        void setBalancePaid(double);

        double getBalanceOwed() const;
        void setBalanceOwed(double);

        //double calculate

};

#endif