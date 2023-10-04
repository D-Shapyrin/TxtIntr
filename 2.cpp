#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void SupportedOperations(int argc, char* argv[]) {
    // for (int i = 1; i < argc; ++i) {std::cout << "Аргумент " << i << ": " << argv[i] << std::endl;}  // введенные аргументы
    cout << "Поддерживаемые операции:" << endl;
    cout << "  -o exp 'x'   (возведение e в степень x)" << endl;
    cout << "  -o pow 'x' 'y'  (возведение x в степень y)" << endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Калькулятор для возведения 'e' в степень 'x' или возведения 'x' в степень 'y'." << endl;
        SupportedOperations(argc, argv);
        return 1;
    }

    string operation = argv[1];
    // cout << argc << endl; 
    if (operation == "-o" && argc > 3) { //1
        
        string operationType = argv[2]; 
        for (int i = 1; i < argc; ++i) {std::cout << "Аргумент " << i << ": " << argv[i] << std::endl;}
        
        if (operationType == "exp") {
            double operand1 = stod(argv[3]);
            cout << "Результат: " << exp(operand1) << endl;
        } else if (operationType == "pow") {
            double operand1 = stod(argv[3]);
            double operand2 = stod(argv[4]);
            cout << "Результат: " << pow(operand1, operand2) << endl;
        } else {
            cout << "Неподдерживаемая операция! " << operationType << endl;
            SupportedOperations(argc, argv);
            return 1;
        }
    } else {
        cout << "Неправильный формат команды." << endl;
        SupportedOperations(argc, argv);
        return 1;
    } 
    
    return 0;
}
