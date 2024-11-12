#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <Windows.h>

using namespace std;

// Структура для зберігання коефіцієнтів прямої
struct Line {
    double A;
    double B;
    double C;
};

// Функція для перевірки, чи є дві прямі паралельними
bool areParallel(const Line& line1, const Line& line2) {
    return (line1.A * line2.B == line2.A * line1.B);
}

// Функція для перевірки, чи є дві прямі перпендикулярними
bool arePerpendicular(const Line& line1, const Line& line2) {
    return (line1.A * line2.A + line1.B * line2.B == 0);
}

// Функція для запису результату в файл
void writeResult(ofstream& outFile, const Line& line1, const Line& line2, const string& relation) {
    outFile << line1.A << " " << line1.B << " " << line1.C << " "
        << line2.A << " " << line2.B << " " << line2.C << " "
        << relation << endl;
}

// Функція для обробки пар ліній та визначення їх взаємного розташування
void processLines(ifstream& inFile, ofstream& outFile) {
    Line line1, line2;
    while (inFile >> line1.A >> line1.B >> line1.C) {
        inFile.clear();
        inFile.seekg(0); // Повертаємося на початок файлу
        while (inFile >> line2.A >> line2.B >> line2.C) {
            if (line1.A == line2.A && line1.B == line2.B && line1.C == line2.C)
                continue; // Пропускаємо однакові прямі

            if (areParallel(line1, line2)) {
                writeResult(outFile, line1, line2, "Паралельні");
            }
            else if (arePerpendicular(line1, line2)) {
                writeResult(outFile, line1, line2, "Перпендикулярні");
            }
            else {
                writeResult(outFile, line1, line2, "Перетинаються");
            }
        }
    }
}

// Меню для користувача
void menu() {
    string inputFileName, outputFileName;
    cout << "Введіть ім'я вхідного файлу: ";
    cin >> inputFileName;
    cout << "Введіть ім'я вихідного файлу: ";
    cin >> outputFileName;

    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);

    if (!inFile || !outFile) {
        cerr << "Помилка відкриття файлу!" << endl;
        return;
    }

    processLines(inFile, outFile);

    inFile.close();
    outFile.close();
    cout << "Обробка завершена. Результати записані у файл " << outputFileName << endl;
}

// Головна функція
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        int choice;
        cout << "\n--- Меню ---\n";
        cout << "1. Обробити файли\n";
        cout << "0. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            menu();
        }
        else if (choice == 0) {
            break;
        }
        else {
            cout << "Невірний вибір. Спробуйте ще раз.\n";
        }
    }
    return 0;
}
