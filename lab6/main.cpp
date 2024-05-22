#define N 100
#include <iostream>
using namespace std;

bool work = true;

struct date{		
	char* name;
	double price;
    int quant;
}; 

void search_by_name(){

}

void search_by_less_quant(){

}

void search_by_decrease_price(){

}

void add_new(char name_n[100], double price_n, int quant_n, date *prostitutka){
    int counter = 0;
    for(int i = 0; i < N; i++){
        // if(prostitutka[i].name == ""){
        //     break;
        // }
        // counter++;
        cout << prostitutka[i].name;
    }
    cout << counter;
}

void print_data(){

}

void exit_prog(){
    work = false;
}

void clear(){
    for(int i = 0; i < 40; i++){cout << "\n";}
}

void fill_m(date* &prostitutka){
    for(int i = 0; i < N; i++){
        prostitutka[i].name = "";
        prostitutka[i].price = -1;
        prostitutka[i].quant = -1;
    }
}

int main(){
    int choise;
    date* prostitutka = (date*)malloc(sizeof(date) * N);
    fill_m(&prostitutka[N]);
    while(work){
        clear();
        cout << "Menu:\n1.Add new\n2.Print data\n3.Search by name\n4.Search by quantity\n5.Search by price\n6.Exit\n";
        cin >> choise;
        switch(choise){
            case 1:
                clear();
                cout << "Firstly enter the name then enter price and finally enter the quantity\n";
                char name_n[100];
                double price_n;
                int quant_n;
                cin.getline(name_n, 100, '\n');
                while (!(cin >> price_n) || (cin.peek() != '\n')){
                    cin.clear();
                    while (cin.get() != '\n');
                }
                while (!(cin >> quant_n) || (cin.peek() != '\n')){
                    cin.clear();
                    while (cin.get() != '\n');
                }
                add_new(name_n, price_n, quant_n, &prostitutka[N]);
                work = false;
                break;
            case 2:
                print_data();
                break;
            case 3:
                search_by_name();
                break;
            case 4:
                search_by_less_quant();
                break;
            case 5:
                search_by_decrease_price();
                break;
            case 6:
                exit_prog();
                break;
            default:
                cout << "Choose anything" << endl;
                break;
        }
    }
}