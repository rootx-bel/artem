#include <cstring>
#include <stdio.h>
#define N 100

bool work = true;

struct date {
    char name[100];
    double price;
    int quant;
};

void exit_prog() { work = false; }

void clear() {
    for (int i = 0; i < 30; i++) {
        printf("\n");
    }
}

void fill_m(date *prostitutka) {
    for (int i = 0; i < N; i++) {
        strcpy(prostitutka[i].name, "");
        prostitutka[i].price = -1;
        prostitutka[i].quant = -1;
    }
}

void add_new(char name[100], double price, int quant, date *prostitutka) {
    clear();
    for (int i = 0; i < N; i++) {
        if (strlen(prostitutka[i].name) == 0) {
            strcpy(prostitutka[i].name, name);
            prostitutka[i].price = price;
            prostitutka[i].quant = quant;
            break;
        }
    }
}

void print_data(date *prostitutka) {
    clear();
    for (int i = 0; i < N; i++) {
        if (strlen(prostitutka[i].name) != 0) {
            printf("Name: %s\tPrice: %lf\tQuantity: %d\n", prostitutka[i].name,
                   prostitutka[i].price, prostitutka[i].quant);
        }
    }
}

void search_by_name(date *prostitutka) {
    clear();
    char search_name[100];
    printf("Enter name to search: ");
    scanf("%s", search_name);
    for (int i = 0; i < N; i++) {
        if (strcmp(prostitutka[i].name, search_name) == 0) {
            printf("Name: %s\tPrice: %lf\tQuantity: %d\n", prostitutka[i].name,
                   prostitutka[i].price, prostitutka[i].quant);
        }
    }
}

void search_by_less_quant(date *prostitutka) {
    clear();
    int search_quant;
    printf("Enter quantity to search: ");
    scanf("%d", &search_quant);
    for (int i = 0; i < N; i++) {
        if (prostitutka[i].quant < search_quant && prostitutka[i].quant > -1) {
            printf("Name: %s\tPrice: %lf\tQuantity: %d\n", prostitutka[i].name,
                   prostitutka[i].price, prostitutka[i].quant);
        }
    }
}

void search_by_decrease_price(date *prostitutka) {
    clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (prostitutka[j].price < prostitutka[j + 1].price) {
                double b = prostitutka[j].price;
                prostitutka[j].price = prostitutka[j + 1].price;
                prostitutka[j + 1].price = b;
            }
        }
    }
}

int main() {
    int choice;
    date *prostitutka = new date[N];
    fill_m(prostitutka);
    clear();
    while (work) {
        printf("Menu:\n1. Add new\n2. Print data\n3. Search by name\n4. Search "
               "by quantity\n5. Search by price\n6. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            clear();
            printf("Firstly enter the name then enter price and finally enter "
                   "the quantity\n");
            char name_n[100];
            double price_n;
            int quant_n;
            scanf("%s", &name_n);
            scanf("%lf", &price_n);
            scanf("%d", &quant_n);
            add_new(name_n, price_n, quant_n, prostitutka);
            break;
        case 2:
            print_data(prostitutka);
            break;
        case 3:
            search_by_name(prostitutka);
            break;
        case 4:
            search_by_less_quant(prostitutka);
            break;
        case 5:
            search_by_decrease_price(prostitutka);
            break;
        case 6:
            exit_prog();
            break;
        default:
            printf("Choose anything\n");
            break;
        }
    }
    delete[] prostitutka;
    return 0;
}