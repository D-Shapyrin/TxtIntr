#include <iostream>
#include <cmath>
#include <string>
#include <unistd.h>

using namespace std;

void SupportedOperations() {
    cout << "Поддерживаемые операции:" << endl;
    cout << "  -o exp 'x'   (возведение e в степень x)" << endl;
    cout << "  -o pow 'x' 'y'  (возведение x в степень y)" << endl;
}

int main(int argc, char* argv[]) {
    int option;
    string operationType;
    double operand1, operand2;

    while ((option = getopt(argc, argv, "o:")) != -1) { // "o" имеет значение
        switch (option) {
            case 'o':
                operationType = optarg;
                break;
            case '?':
                cerr << "Не задан параметр одной из опций" << "\n" << endl;
                break;
            default:
                cerr << "Неправильный параметр: " << char(optopt) << endl; // значения опции, которая не была распознана ("?")
                SupportedOperations();
                return 1;
        }
    }

    if (operationType.empty()) {
        cerr << "Отсутствует обязательный параметр -o." << endl;
        SupportedOperations();
        return 1;
    }

    if (operationType == "exp") {
        if (optind >= argc) {
            cerr << "Отсутствует обязательный аргумент 'x'." << endl;
            SupportedOperations();
            return 1;
        }
        operand1 = stod(argv[optind]);  //optind некст элемент в argv
        cout << "Результат: " << exp(operand1) << endl;
    } else if (operationType == "pow") {
        if (optind + 1 >= argc) {
            cerr << "Отсутствуют обязательные аргументы 'x' и 'y'." << endl;
            SupportedOperations();
            return 1;
        }
        operand1 = stod(argv[optind]);
        operand2 = stod(argv[optind + 1]);
        cout << "Результат: " << pow(operand1, operand2) << endl;
    } else {
        cerr << "Неподдерживаемая операция! " << operationType << endl;
        SupportedOperations();
        return 1;
    }

    return 0;
}
