#include <iostream>
using namespace std;


double celsiusToFahrenheit(double c);
double celsiusToKelvin(double c);
double fahrenheitToCelsius(double f);
double fahrenheitToKelvin(double f);
double kelvinToCelsius(double k);
double kelvinToFahrenheit(double k);

int main() {
    int choice;
    double temp, converted;

    cout << "Temperature Conversion Program\n";
    cout << "--------------------------------\n";
    cout << "Choose a conversion:\n";
    cout << "1. Celsius to Fahrenheit\n";
    cout << "2. Celsius to Kelvin\n";
    cout << "3. Fahrenheit to Celsius\n";
    cout << "4. Fahrenheit to Kelvin\n";
    cout << "5. Kelvin to Celsius\n";
    cout << "6. Kelvin to Fahrenheit\n";
    cout << "Enter your choice (1-6): ";
    cin >> choice;

    cout << "Enter temperature value: ";
    cin >> temp;

    switch (choice) {
        case 1:
            converted = celsiusToFahrenheit(temp);
            cout << temp << " °C = " << converted << " °F\n";
            break;
        case 2:
            converted = celsiusToKelvin(temp);
            cout << temp << " °C = " << converted << " K\n";
            break;
        case 3:
            converted = fahrenheitToCelsius(temp);
            cout << temp << " °F = " << converted << " °C\n";
            break;
        case 4:
            converted = fahrenheitToKelvin(temp);
            cout << temp << " °F = " << converted << " K\n";
            break;
        case 5:
            converted = kelvinToCelsius(temp);
            cout << temp << " K = " << converted << " °C\n";
            break;
        case 6:
            converted = kelvinToFahrenheit(temp);
            cout << temp << " K = " << converted << " °F\n";
            break;
        default:
            cout << "Invalid choice!\n";
    }

    return 0;
}


double celsiusToFahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double c) {
    return c + 273.15;
}

double fahrenheitToCelsius(double f) {
    return (f - 32.0) * 5.0 / 9.0;
}

double fahrenheitToKelvin(double f) {
    return (f - 32.0) * 5.0 / 9.0 + 273.15;
}

double kelvinToCelsius(double k) {
    return k - 273.15;
}

double kelvinToFahrenheit(double k) {
    return (k - 273.15) * 9.0 / 5.0 + 32.0;
}








