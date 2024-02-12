#include "coffeeBreak.hpp"

void displayMenu(vector<coffee>);
void readFile(ifstream &, vector<coffee> &);
coffee findDrink(vector<coffee>, int);
int dueToPay(Person arr[], const int employee_count);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Invalid command line arguments!" << endl;
        return -1;
    }
    string menu_file = argv[1];
    ifstream in_file(menu_file);
    vector<coffee> drinks; // all available drinks & their prices
    const int employee_count = 7;
    Person arr[employee_count]; // all coworkers
    if (!in_file.is_open())
    { // cannot open file
        cout << "Unable to open menu file!" << endl;
        return -1;
    }
    else
    { // read menu file & load menu into coffee vector
        readFile(in_file, drinks);
    }
    double daily_total;
    char size; // drink size (S)mall, (M)edium, (L)arge
    cout << endl;
    cout << "Welcome to BertramBucks!" << endl;
    displayMenu(drinks);

    for (int x = 0; x < employee_count; x++)
    {
        Person temp;
        string emp_name = "";
        if (x == 0)
        {
            temp.setName("Bob"); // output the drink they always get
            temp.setDrinkOfChoice(findDrink(drinks, x));
        }
        else if (x == 1)
        {
            temp.setName("Jeremy"); // output the drink they always get
            temp.setDrinkOfChoice(findDrink(drinks, x));
        }
        else
        {
            displayMenu(drinks);
            temp.setDrinkOfChoice(findDrink(drinks, x));
            cout << "Can I get a name for the order?" << endl;
            getline(cin, emp_name);
            temp.setName(emp_name);
        }
        cout << "What size would you like?" << endl;
        cout << "Enter: (S) for small | (M) for medium | (L) for large." << endl;
        string size_str;
        cin >> size_str;
        while (size_str.length() != 1)
        {
            cout << "Must be a single character input! (S)mall | (M)edium | (L)arge." << endl;
            cin >> size_str;
        }
        size = size_str[0];
        size = toupper(size);
        while (cin.fail() || (size != 'S' && size != 'M' && size != 'L'))
        {
            cout << "Invalid input! (S)mall | (M)edium | (L)arge." << endl;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
            }
            cin >> size;
            size = toupper(size);
        }
        cin.ignore(10000, '\n');
        temp.setDrinkSize(size);
        arr[x] = temp;
    }
    bool loop = true;
    do
    {
        displayMenu(drinks);
        daily_total = 0;
        for (int i = 0; i < employee_count; i++)
        {
            cout << arr[i].getName() << " orders: ";
            cout << arr[i].getDrinkOfChoice().drink;
            cout << " (" << arr[i].getDrinkSize() << ")" << endl;
            arr[i].setDrinkPrice(arr[i].getDrinkSize()); // set person's drink price based on selected size
            cout << "Drink price: $" << arr[i].getDrinkPrice() << endl;
            daily_total += arr[i].getDrinkPrice(); // add person's order to the day's total bill

            // set balance owed to previous amount owed + price of drink
            arr[i].setBalanceOwed(arr[i].getBalanceOwed() + arr[i].getDrinkPrice());
            cout << "Balance owed: $" << arr[i].getBalanceOwed() << endl;
            cout << "=====" << endl;
        }
        int bill_footer = dueToPay(arr, employee_count); // array index corresponding to who will be paying
        cout << "Today's bill will be paid by " << arr[bill_footer].getName() << ", with the largest outstanding debt of: $" << arr[bill_footer].getBalanceOwed() << endl;
        cout << "The bill comes out to: $" << daily_total << endl;
        arr[bill_footer].setBalanceOwed(arr[bill_footer].getBalanceOwed() - daily_total);
        cout << arr[bill_footer].getName() << "'s new debt is: $" << arr[bill_footer].getBalanceOwed() << endl;

        string more_coffee, mc;
        cout << "Another day of coffee?" << endl;
        cout << "Yes/No" << endl;
        getline(cin, mc);
        int more_length = mc.length();
        more_coffee = "";
        for (int k = 0; k < more_length; k++)
        { // convert input to uppercase
            more_coffee += toupper(mc[k]);
        }
        while (more_coffee != "YES" && more_coffee != "NO")
        {
            cout << "Invalid input. Please enter 'Yes' to continue or 'No' to end the program." << endl;
            getline(cin, mc);
            more_length = mc.length();
            more_coffee = "";
            for (int k = 0; k < more_length; k++)
            { // convert input to uppercase
                more_coffee += toupper(mc[k]);
            }
        }
        if (more_coffee == "NO")
        {
            cout << "Thanks for playing!" << endl;
            loop = false;
        }
    } while (loop == true);
    return 0;
}

void displayMenu(vector<coffee> drinks)
{
    int size = drinks.size();
    int msize = drinks.at(0).drink.length();
    unsigned int maxsize = static_cast<unsigned int>(msize);
    for (int x = 0; x < size - 1; x++)
    {
        if (drinks.at(x + 1).drink.length() > maxsize)
        { // DETERMINES THE STRING LENGTH OF THE LONGEST DRINK NAME
            maxsize = drinks.at(x + 1).drink.length();
        }
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << left << setw(maxsize + 5) << "" << setw(10) << "Small" << setw(10) << "Medium" << setw(10) << "Large" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << left << setw(maxsize + 5) << drinks.at(i).drink << fixed << setprecision(2) << "$" << setw(9) << drinks.at(i).s_price << "$" << setw(9) << drinks.at(i).m_price << "$" << setw(9) << drinks.at(i).l_price << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    return;
}
void readFile(ifstream &in_file, vector<coffee> &drinks)
{
    string line, drink_name, small, medium, large;
    double small_p, med_p, large_p;
    while (getline(in_file, line))
    {
        stringstream ss(line);
        getline(ss, drink_name, '|');
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
    string drink_order, drink_found, drink; // customer, menu item, convert to uppercase
    int drink_length, found_length;         // customer order length, menu item length
    if (index == 0)
    { // BOB
        drink = "Cappuccino";
        cout << "Nice to see you Bob! One of your usual " << drink << "s coming right up!" << endl;
    }
    else if (index == 1)
    { // JEREMY
        drink = "Black Coffee";
        cout << "Nice to see you Jeremy! One of your usual " << drink << "s coming right up!" << endl;
    }
    else
    {
        cout << "What would you like to order?" << endl;
        getline(cin, drink);
    }
    int vec_size = drinks.size();
    drink_length = drink.length();
    drink_order = "";
    for (int i = 0; i < drink_length; i++)
    { // convert order into uppercase
        drink_order += (toupper(drink[i]));
    }

    for (int i = 0; i < vec_size; i++)
    { // check coffee vector for drink order
        string drink = drinks.at(i).drink;
        found_length = drink.length();
        drink_found = ""; // reset
        for (int i = 0; i < found_length; i++)
        { // convert drink name on menu to uppercase for comparison
            drink_found += toupper(drink[i]);
        }
        if (drink_found == drink_order)
        { // if order is found
            return drinks.at(i);
        }
        if (i == vec_size - 1)
        { // if every index of the vector has been checked
            cout << "Sorry we don't sell that here! Please enter a valid drink name." << endl;
            getline(cin, drink);
            drink_length = drink.length();
            drink_order = "";
            for (int k = 0; k < drink_length; k++)
            { // convert input to uppercase
                drink_order += toupper(drink[k]);
            }
            i = -1; // restart the for loop; i increments to 0
        }
    }
    return coffee();
}
int dueToPay(Person arr[], const int employee_count)
{
    // returns person with largest debt
    // if multiple people have the same balance owed
    // returns last person to order with the max debt
    double max_due = arr[0].getBalanceOwed();
    int index = 0;
    for (int i = 0; i < employee_count - 1; i++)
    {
        if (max_due <= arr[i + 1].getBalanceOwed())
        {
            max_due = arr[i + 1].getBalanceOwed();
            index = i + 1;
        }
    }
    return index;
}