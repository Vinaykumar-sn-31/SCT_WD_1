#include <iostream>
#include <cstdlib>   
#include <ctime> 

using namespace std;

int main() {
    srand(time(0)); 

    int maxNumber, maxAttempts;
    int choice;

    cout << "============================\n";
    cout << "   Guess the Number Game!\n";
    cout << "============================\n";
    cout << "Choose a difficulty level:\n";
    cout << "1. Easy (1-50, unlimited attempts)\n";
    cout << "2. Medium (1-100, 10 attempts)\n";
    cout << "3. Hard (1-500, 8 attempts)\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            maxNumber = 50;
            maxAttempts = -1; 
            break;
        case 2:
            maxNumber = 100;
            maxAttempts = 10;
            break;
        case 3:
            maxNumber = 500;
            maxAttempts = 8;
            break;
        default:
            cout << "Invalid choice! Defaulting to Medium.\n";
            maxNumber = 100;
            maxAttempts = 10;
    }

    int randomNumber = rand() % maxNumber + 1;
    int guess, attempts = 0;

    cout << "\nI'm thinking of a number between 1 and " << maxNumber << ".\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > randomNumber) {
            cout << "Too high! Try again.\n";
        } else if (guess < randomNumber) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "?? Congratulations! You guessed the number "
                 << randomNumber << " in " << attempts << " attempts.\n";
            break;
        }

        if (maxAttempts != -1 && attempts >= maxAttempts) {
            cout << "? Game Over! You've used all " << maxAttempts 
                 << " attempts. The number was " << randomNumber << ".\n";
            break;
        }

    } while (true);

    return 0;
}




























