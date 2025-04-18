#include <iostream>
#include <map>
#include <functional>
#include <string>
using namespace std;

double sideA = 0, sideB = 0, sideC = 0;

bool UserInput(string input) {
    if (input.empty()) return false;
    try {
        double number = stod(input);
        if (number <= 0) return false;
    }
    catch (...) { return false; }
    return true;
}

void enterNumber(double& varLink, string label) {
    string str_input;
    cout << label << " = ";
    getline(cin, str_input);
    while (!UserInput(str_input)) {
        cout << "Ошибка ввода! " << label << " = ";
        getline(cin, str_input);
    }
    varLink = stoi(str_input);
}
  

void enterSideA() {
    enterNumber(sideA, "Введите длину стороны A");
    cout << "Сторона A: " << sideA << endl;
}

void enterSideB() {  
    enterNumber(sideB, "Введите длину стороны B");  
    cout << "Сторона B: " << sideB << endl;  
}
 
void enterSideC() {  
    enterNumber(sideC, "Введите длину стороны C");  
    cout << "Сторона C: " << sideC << endl;  
}  

void checkExistence() {
    if (sideA + sideB > sideC && sideA + sideC > sideB && sideB + sideC > sideA) {  
        cout << "Треугольник существует." << endl;  
    } else {  
        cout << "Треугольник не существует." << endl;  
    } 
}

void calculatePerimeter() {
    if (sideA == 0 || sideB == 0 || sideC == 0) {  
        cout << "Ошибка: не все стороны введены." << endl;  
        return;  
    }  
    double perimeter = sideA + sideB + sideC;  
    cout << "Периметр треугольника: " << perimeter << endl; 
}

struct MenuItem {
    string title;
    function<void()> action;
};

int main() {
    map<int, MenuItem> menu = {
        {1, {"Ввод стороны A", [](){ enterNumber(sideA, "Сторона A"); }}},
        {2, {"Ввод стороны B", [](){ enterNumber(sideB, "Сторона B"); }}},
        {3, {"Ввод стороны C", [](){ enterNumber(sideC, "Сторона C"); }}},
        {4, {"Проверить существование треугольника", checkExistence}},
        {5, {"Вычислить периметр", calculatePerimeter}}
    };

    int choice = 0;
    while (true) {
        cout << "\nМеню:" << endl;
        for (const auto& item : menu) {
            cout << item.first << ". " << item.second.title << endl;
        }
        cout << "0. Выход" << endl;
        
        string str_choice;
        cout << "Выберите пункт: ";
        getline(cin, str_choice);
        
        if (!UserInput(str_choice)) {
            cout << "Неверный ввод!" << endl;
            continue;
        }
        
        choice = stoi(str_choice);
        if (choice == 0) break;
        
        if (menu.find(choice) != menu.end()) {
            menu[choice].action();
        } else {
            cout << "Неверный выбор!" << endl;
        }
    }
    cout << "Программа завершена." << endl;
    return 0;
}