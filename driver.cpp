#include "coffeeBreak.hpp"

void displayMenu(vector<coffee>);
void readFile(ifstream &, vector<coffee> &);
coffee findDrink(vector<coffee>, int);
int dueToPay();//returns index for who has largest balance owed for the day

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Invalid command line arguments!" << endl;
        return -1;
    }
    string menu_file = argv[1];
    ifstream in_file(menu_file);
    vector<coffee> drinks; //all available drinks & their prices
    const static int employee_count = 7;
    Person arr[employee_count]; //all coworkers
    if (!in_file.is_open())
    { // cannot open file
        cout << "Unable to open menu file!" << endl;
        return -1;
    }
    else
    { // read menu file & load menu into coffee vector
        readFile(in_file, drinks);
    }

    cout << "Welcome to BertramBucks!" << endl;
    {//TEMP BRACKET TESTING...
        displayMenu(drinks);
        char size = 'S';
        for(int i=0; i<employee_count; i++){
            arr[i] = Person{"person", drinks.at(i), size};
            cout<<arr[i].getDrinkOfChoice().drink<<endl;
            //cout<<arr[i].getDrinkOfChoice().s_price<<endl;
            arr[i].setDrinkPrice(size);
            cout<<arr[i].getDrinkPrice()<<endl;
            //set balance owed to previous amount owed + price of drink
            arr[i].setBalanceOwed(arr[i].getBalanceOwed()+arr[i].getDrinkPrice());
            //double max_debt = arr[0]
        }
        //LEFT OFF HERE...
        return 0;
    }
    for(int i=2; i<employee_count; i++){
            cout<<"Please enter your name: "<<endl;
            string n;
            getline(cin, n);
            arr[i] = Person{n}; //initialize with names
        }

        /*
        WHOEVER HAS LARGEST OUTSTANDING BALANCE FROM THE DRINKS THEY PURCHASE:
        PAYS FOR THAT DAY
        IF TWO PEOPLE HAVE THE SAME OUTSTANDING BALANCE THEN, TIEBREAKER
        */

    coffee temp;
    bool finished = false;
    while (finished == false)
    {
        for (int index = 0; index < employee_count; index++)
        {
            displayMenu(drinks);

        }
        cout << "Another week of coffee?" << endl;
        cout << "Yes | No" << endl;
        string more_coffee;
        getline(cin, more_coffee);
        while (more_coffee != "Yes" || more_coffee != "No")
        {
            cout << "Invalid input. Please enter 'Yes' to continue or 'No' to end the program." << endl;
            getline(cin, more_coffee);
        }
        if (more_coffee == "No")
        {
            cout << "Thanks for playing!" << endl;
            finished = true;
        }
    }

    return 0;
}

void displayMenu(vector<coffee> drinks)
{
    int size = drinks.size();
    int maxsize = drinks.at(0).drink.length();
    for (int x = 0; x < size - 1; x++)
    {
        if (drinks.at(x + 1).drink.length() > maxsize)
        {
            maxsize = drinks.at(x + 1).drink.length();
        }
    }
    cout << left << setw(maxsize + 5) << "Name" << setw(10) << "Small" << setw(10) << "Medium" << setw(10) << "Large" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(maxsize + 5) << drinks.at(i).drink << fixed << setprecision(2) << "$" << setw(9) << drinks.at(i).s_price << "$" << setw(9) << drinks.at(i).m_price << "$" << setw(9) << drinks.at(i).l_price << endl;
    }
    return;
}
void readFile(ifstream &in_file, vector<coffee> &drinks)
{
    string line, drink_name, small, medium, large;
    double small_p, med_p, large_p;
    while (getline(in_file, line))
    {
        stringstream ss(line);
        getline(ss, drink_name, ',');
        getline(ss, small, ',');
        getline(ss, medium, ',');
        getline(ss, large);
        small_p = stod(small);
        med_p = stod(medium);
        large_p = stod(large);
        coffee temp = {small_p, med_p, large_p, drink_name};
        drinks.push_back(temp);
    }
}
coffee findDrink(vector<coffee> drinks, int index)
{
    string drink_order;
    //INCOMPLETE FUNCTION!
    if(index == 0){ //BOB
        drink_order = "Cappuccino";
    }
    else if(index == 1){ //JEREMY
        drink_order = "Black Coffee";
    }
    else{
        cout<<"What would you like to order?"<<endl;
        getline(cin, drink_order);
    }
    return coffee();
}