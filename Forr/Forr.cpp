#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

int findClosestToZero(std::vector<int>& temperatures) {
    if (temperatures.empty()) {
        return 0; // Return 0 if there are no temperatures
    }

    int closestTemp = temperatures[0]; // Assume the first temperature is closest
    for (int temp : temperatures) {
        if (std::abs(temp) < std::abs(closestTemp) || (std::abs(temp) == std::abs(closestTemp) && temp > 0)) {
            closestTemp = temp; // Update closest temperature if current temp is closer
        }
    }

    return closestTemp;
}

void printResult(int closestTemp) {
    std::cout << "Cel mai apropiat de 0: ";
    setColor(FOREGROUND_GREEN);
    std::cout << closestTemp << std::endl;
    setColor(FOREGROUND_GREEN);
}

int main() {
    int n;
    std::cout << "Introduceti numarul de inregistrari cu temperaturi: ";
    std::cin >> n; // Number of temperature readings
    std::vector<int> temperatures(n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Introduceti temperatura " << i + 1 << ": ";
        std::cin >> temperatures[i]; // Read temperature readings
    }

    int closestTemperature = findClosestToZero(temperatures);
    printResult(closestTemperature);

    return 0;
}
