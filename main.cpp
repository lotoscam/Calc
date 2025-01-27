#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <thread>
#include <chrono>

using namespace std;

void display_menu() {
    cout << "\033[1;32m----------------------------\n";
    cout << "      Калькулятор\n";
    cout << "----------------------------\n";
    cout << "1. Сложение\n";
    cout << "2. Вычитание\n";
    cout << "3. Умножение\n";
    cout << "4. Деление\n";
    cout << "5. Выход\n";
    cout << "----------------------------\033[0m\n";
    cout << "Выберите операцию: ";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        cout << "\033[1;31mОшибка! Деление на ноль.\033[0m\n";
        return std::numeric_limits<double>::quiet_NaN();
    }
    return a / b;
}

void clear_screen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    double num1, num2;
    int choice;

    while (true) {
        display_menu();
        cin >> choice;

        if (choice == 5) {
            cout << "Выход из программы\n";
            break;
        }

        cout << "Введите первое число: ";
        cin >> num1;

        cout << "Введите второе число: ";
        cin >> num2;

        double result;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                break;
            case 4:
                result = divide(num1, num2);
                if (isnan(result)) {
                    break;
                }
                break;
            default:
                cout << "\033[1;31mНеверный выбор. Пожалуйста, выберите правильную операцию\033[0m\n";
                continue;
        }

        if (!isnan(result)) {
            if (result == static_cast<int>(result)) {
                cout << "\033[1;34mРезультат: " << static_cast<int>(result) << "\033[0m\n";
            } else {
                cout << "\033[1;34mРезультат: " << fixed << setprecision(2) << result << "\033[0m\n";
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(5));
        clear_screen();
    }

    return 0;
}
