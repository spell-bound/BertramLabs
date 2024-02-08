#include "coffeeBreak.hpp"

void displayMenu(vector<coffee>);
void readFile(ifstream&, vector<coffee>&);

int main(int argc, char *argv[]){
    if(argc != 2){
        cout<<"Invalid command line arguments!"<<endl;
        return -1;
    }
    string menu_file = argv[1];
    ifstream in_file(menu_file);
    vector<coffee> drinks;
    if(!in_file.is_open()){//cannot open file
        cout<<"Unable to open menu file!"<<endl;
        return -1;
    }
    else{
        readFile(in_file, drinks);
    }
    cout<<"Welcome to BertramBucks!"<<endl;
    displayMenu(drinks);

    return 0;
}

void displayMenu(vector<coffee> drinks){
    int size = drinks.size();
    int maxsize = drinks.at(0).drink.length();
    for(int x = 0; x<size-1; x++){
        if(drinks.at(x+1).drink.length()>maxsize){
            maxsize = drinks.at(x+1).drink.length();
        }
    }
    cout<<left<<setw(maxsize+5)<<"Name"<<setw(10)<<"Small"<<setw(10)<<"Medium"<<setw(10)<<"Large"<<endl;
    for(int i=0; i<size; i++){
        cout<<left<<setw(maxsize+5)<<drinks.at(i).drink<<fixed<<setprecision(2)<<"$"<<setw(9)<<drinks.at(i).s_price<<"$"<<setw(9)<<drinks.at(i).m_price<<"$"<<setw(9)<<drinks.at(i).l_price<<endl;
    }
    return;
}
void readFile(ifstream& in_file, vector<coffee>& drinks){
        string line, drink_name, small, medium, large;
        double small_p, med_p, large_p;
        while(getline(in_file, line)){
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