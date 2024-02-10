#include "coffeeBreak.hpp"

Person::Person(){ //default construct
    _name = "";
    _drink_of_choice = coffee();
    _drink_size = '0';
    _drink_price = 0;
    _balance_owed = 0;
}
Person::Person(string name){//paramaterized w/ name
    _name = name;
    _drink_of_choice = coffee();
    _drink_size = '0';
    _drink_price = 0;
    _balance_owed = 0;
}
Person::Person(string name, coffee drink_of_choice, char drink_size){//with name & drink pref
    _name = name;
    _drink_of_choice = drink_of_choice;
    _drink_size = drink_size;
    if(drink_size == 'S'){
        _drink_price = drink_of_choice.s_price;
    }
    else if(drink_size == 'M'){
        _drink_price = drink_of_choice.m_price;
    }
    else if(drink_size == 'L'){
        _drink_price = drink_of_choice.l_price;
    }
    else{
        _drink_price = 0;
    }
    _balance_owed = 0;
}

string Person::getName() const{
    return _name;
}
void Person::setName(string name){
    _name = name;
}

coffee Person::getDrinkOfChoice() const{
    return _drink_of_choice;
}
void Person::setDrinkOfChoice(coffee drink_of_choice){
    _drink_of_choice = drink_of_choice;
}

char Person::getDrinkSize() const{
    return _drink_size;
}
void Person::setDrinkSize(char drink_size){
    _drink_size = drink_size;
}

double Person::getDrinkPrice() const{
    return _drink_price;
}
void Person::setDrinkPrice(char drink_size){
    if(drink_size == 'S'){
        _drink_price = _drink_of_choice.s_price;
    }
    else if(drink_size == 'M'){
        _drink_price = _drink_of_choice.m_price;
    }
    else if(drink_size == 'L'){
        _drink_price = _drink_of_choice.l_price;
    }
}

double Person::getBalanceOwed() const{
    return _balance_owed;
}
void Person::setBalanceOwed(double balance_owed){
    _balance_owed = balance_owed;
}
