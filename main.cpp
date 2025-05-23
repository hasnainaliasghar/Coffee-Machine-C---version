#include <iostream>
#include <string>
#include<fstream>
using namespace std;


struct Drink {
    string name;
    int water;
    int milk;
    int coffee;
    double cash;
    
};


void art(){
    string logo = R"(  
      _____       __  __                            _    _               __  __            _     _            
     / ____|     / _|/ _|                          | |  (_)             |  \/  |          | |   (_)          
    | |     ___ | |_| |_ ___  ___   _ __ ___   __ _| | ___ _ __   __ _  | \  / | __ _  ___| |__  _ _ __   ___
    | |    / _ \|  _|  _/ _ \/ _ \ | '_ ` _ \ / _` | |/ / | '_ \ / _` | | |\/| |/ _` |/ __| '_ \| | '_ \ / _ \
    | |___| (_) | | | ||  __/  __/ | | | | | | (_| |   <| | | | | (_| | | |  | | (_| | (__| | | | | | | |  __/
     \_____\___/|_| |_| \___|\___| |_| |_| |_|\__,_|_|\_\_|_| |_|\__, | |_|  |_|\__,_|\___|_| |_|_|_| |_|\___|
                                                                  __/ |                                      
                                                                 |___/      )";                                              
    cout<<logo<<endl;
}


bool is_resources_sufficient(string choice, int &water, int &milk, int &coffee, Drink menu[]){
    for( int i = 0; i < 3; i++){
        if(choice == menu[i].name){
            if(water >= menu[i].water && milk>=menu[i].milk && coffee >= menu[i].coffee){
                return true;
            }else{
                    if(water <= menu[i].water){
                    cout<<"Not Enough Water..."<<endl;
                }   if(milk<=menu[i].milk){
                    cout<<"Not Enough milk..."<<endl;
                }   if(coffee <= menu[i].coffee){
                    cout<<"Not Enough coffee..."<<endl;
                }
                return false;    
            }
        }
    }


    return false;
}
double process_coins(double cost) {
    double cash_inserted;
    cout << "Insert Money: ";
    cin >> cash_inserted;
    return cash_inserted; 
}


void displaybill(Drink menu[],string choice,int* order, double change){
     for( int i = 0; i < 3; i++){
        if(choice == menu[i].name){
        cout<<endl<<endl;
        cout<<"\t ----------Bill---------- "<<endl;
        cout<<"\t Coffee making Machine"<<endl;
        cout<<"Date: 22-05-2025"<<endl;
        cout<<"Order number: "<<*order<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<"Description"<<"\t\tUnit Price"<<endl;
        cout<<"----------------------------------"<<endl;
        cout<<menu[i].name<<"\t\t\tRs. "<<menu[i].cash<<endl;
        cout<<"Change Given:\t\tRs. "<<change<<endl;
        cout<<"\t---------------------------";
        cout<<endl;
    }
        }
        *order += 1;
    }
    

void deductingredients(int *water, int *coffee, int *milk, string choice,Drink menu[]) {
    for(int i= 0; i<3;i++){
        if(choice == menu[i].name){
            *water -= menu[i].water;
            *coffee -= menu[i].coffee;
            *milk -= menu[i].milk;
        }
    }

    
}

void datafunc(int order,Drink menu[],string choice,double account){
    ifstream checkFile("Today.txt");
    if (!checkFile) {
        ofstream day_sell("Today.txt");
        day_sell <<"Type\t\tprice"<<endl;
        day_sell.close();
    }
    checkFile.close();
    
    ofstream day_sell("Today.txt",ios::app);

    for(int i=0; i<3;i++){
        if(choice== menu[i].name && menu[i].name == "latte"){
            day_sell <<menu[i].name<< "\t\t" <<menu[i].cash <<endl;
        } else if(choice== menu[i].name) {
            day_sell <<menu[i].name<< "\t" <<menu[i].cash <<endl;
        }
    }
    day_sell.close();
    ofstream acc("account.txt");
    acc<<account;
    acc.close();
}

void total_sale(string choice){
    int l=0 , e=0 ,c=0;
    string label;
    int value;
    ifstream sale("TotalSale.txt");
        while (sale >> label >> value) {
            if (label == "Latte") l = value;
            else if (label == "Espresso") e = value;
            else if (label == "Cappuccino") c = value;
        }
        sale.close();

    if(choice == "latte"){
        l++;
    } else if(choice == "espresso"){
        e++;
    } else{
        c++;
    }
    ofstream tsale("TotalSale.txt");
        tsale <<"Latte\t\t"<< l <<endl<<"Espresso\t"<< e<<endl <<"Cappuccino\t"<< c<<endl;
    tsale.close();
}
 
int main() {
    art();
  
    int order_number = 1;
    ifstream acc("account.txt");
    double account;
    if(acc>>account){}else{
        account = 0;
    }

    acc.close();


    Drink menu[] = {
        //{name,water,milk,coffee,cost}
        {"espresso", 50, 0, 18, 150},
        {"latte", 200, 150, 24, 250},
        {"cappuccino", 250, 100, 24, 300}
    };


    // Resources available
    int water = 300;
    int milk = 200;
    int coffee = 100;


    //looping through
    bool is_on = true;
    cout<<"Welcome to Coffee Making Machine!"<<endl;
    while(is_on){
        string choice;
        cout<<endl<<endl;
        cout<<"Espresso\tRs.150\nLatte\t\tRs.250\nCappuccino\tRs.300"<<endl;
        cout<<"What would you like?: ";
        cin>>choice;
            if(choice == "off" || choice == "OFF"){
            cout<<"Thank You for using coffee Machine."<<endl;
            is_on = false;
            break;
        }
       
        if(choice == "report"){
            cout<<"water\t"<<water<<"ml\nmilk\t"<<milk<<"ml\ncoffee\t"<<coffee<<"g\nMoney\t"<<account<<"Rs"<<endl;
        }

        bool found = false;
        for (int i = 0; i < 3; i++) {
            if (choice == menu[i].name || choice == "report") {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Opps Go Again..." << endl;
        }

        if (is_resources_sufficient(choice, water, milk, coffee, menu)) {
            double drink_cost = 0;
            for (int i = 0; i < 3; i++) {
                if (choice == menu[i].name) {
                    drink_cost = menu[i].cash;
                    break;
                }
            }

            if (drink_cost > 0) { 
                double money_received = process_coins(drink_cost);

                if (money_received >= drink_cost) {
                    double change = money_received - drink_cost;
                    account += drink_cost; 

                    //cout << "Here is your change: " << change << endl;
                    
                    bool confirm = true;
                    while(confirm){
                        char confirm_order;
                        cout << "Do you want to confirm this Order?(Y/N): ";
                        cin >> confirm_order;
                        
                        
                        if (confirm_order == 'y' || confirm_order == 'Y') {
                            deductingredients(&water, &coffee, &milk, choice,menu);
                            displaybill(menu, choice, &order_number, change); 
                            cout<<endl;
                            cout << "Here is your " << choice << " ☕. Enjoy!" << endl;
                            datafunc(order_number,menu,choice,account);
                            total_sale(choice);
                            confirm = false;
                            break;
                            
                        } else if(confirm_order == 'n' || confirm_order == 'N') {
                            cout << "Dear Customer! Your order is cancelled. Here is your refund: " << money_received<<"Rs." << endl;
                            confirm = false;
                            break;
                        } else {
                            cout<<"Incorrect input try again"<<endl;
                        }
                    }
                } else if (money_received < drink_cost) {
                    cout << "Payment is insufficient. Refunded!!"  << endl;
                } 
            }
        }
        
    }  
        
        return 0;
}