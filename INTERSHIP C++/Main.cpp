#include "ComplexNumber.h"
#include <iostream>
#include <fstream>

void printMenu();

int main() {
    int num;
    std::cout << "Enter the number of complex numbers: ";
    std::cin >> num;

    // Dynamic array allocation
    ComplexNumber* numbers = new ComplexNumber[num];

    std::cout << "Enter " << num << " complex numbers (e.g., 3+4i, 2-3i):\n";
    for (int i = 0; i < num; i++) {
        std::cin >> numbers[i];
    }

    // Open file once to store all operations
    std::ofstream file("complexNumbers.txt");
    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    int choice;
    do {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {  // Multiply by a real number
            int index, scalar;
            std::cout << "Enter index and real number: ";
            std::cin >> index >> scalar;

            ComplexNumber before = numbers[index];
            numbers[index] = scalar * numbers[index];

            file << scalar << " × (" << before << ") = " << numbers[index] << "\n";
        }
        else if (choice == 2) {  // Add a complex number
            int index;
            ComplexNumber toAdd;
            std::cout << "Enter index and complex number to add: ";
            std::cin >> index >> toAdd;

            ComplexNumber before = numbers[index];
            numbers[index] = numbers[index] + toAdd;

            file << "(" << before << ") + (" << toAdd << ") = " << numbers[index] << "\n";
        }
        else if (choice == 3) {  // Subtract a complex number
            int index;
            ComplexNumber toSubtract;
            std::cout << "Enter index and complex number to subtract: ";
            std::cin >> index >> toSubtract;

            ComplexNumber before = numbers[index];
            numbers[index] = numbers[index] - toSubtract;

            file << "(" << before << ") - (" << toSubtract << ") = " << numbers[index] << "\n";
        }
        else if (choice == 4) {  // Multiply by another complex number
            int index;
            ComplexNumber toMultiply;
            std::cout << "Enter index and complex number to multiply by: ";
            std::cin >> index >> toMultiply;

            ComplexNumber before = numbers[index];
            numbers[index] = numbers[index] * toMultiply;

            file << "(" << before << ") × (" << toMultiply << ") = " << numbers[index] << "\n";
        }
        else if (choice == 5) {  // Conjugate
            int index;
            std::cout << "Enter index to conjugate: ";
            std::cin >> index;

            ComplexNumber before = numbers[index];
            numbers[index].Conjugate();

            file << "Conjugate of " << before << " = " << numbers[index] << "\n";
        }
        else if (choice == 6) {  // Print magnitude
            int index;
            std::cout << "Enter index: ";
            std::cin >> index;

            double mag = numbers[index].get_Magnitude();
            file << "Mag(" << numbers[index] << ") = √" << mag << " ≈ " << sqrt(mag) << "\n";
        }
        else if (choice == 7) {  // Count numbers with magnitude larger than input
            double threshold;
            int count = 0;
            std::cout << "Enter magnitude threshold: ";
            std::cin >> threshold;

            for (int i = 0; i < num; i++) {
                if (numbers[i].get_Magnitude() > threshold) {
                    count++;
                }
            }

            file << "# Mag > " << threshold << " = " << count << "\n";
        }
        else if (choice == 8) {  // Remove numbers with magnitude larger than input
            double threshold;
            std::cout << "Enter magnitude threshold: ";
            std::cin >> threshold;

            int newSize = 0;
            for (int i = 0; i < num; i++) {
                if (numbers[i].get_Magnitude() <= threshold) {
                    numbers[newSize++] = numbers[i];
                }
            }

            num = newSize;
            file << "Remove Mag > " << threshold << "\n";
        }
        else if (choice == 9) {  // Append a new complex number
            ComplexNumber newNum;
            std::cout << "Enter new complex number: ";
            std::cin >> newNum;

            ComplexNumber* temp = new ComplexNumber[num + 1];

            for (int i = 0; i < num; i++) {
                temp[i] = numbers[i];
            }
            temp[num] = newNum;

            delete[] numbers;
            numbers = temp;
            num++;

            file << "Append " << newNum << "\n";
        }
        else if (choice == 10) {  // Quit and save to file
            file.close();  // Close file before exiting
            std::cout << "Saved and exiting...\n";
            break;
        }
    } while (true);

    delete[] numbers;  // Free allocated memory
    return 0;
}

void printMenu() {
    std::cout << "\nMenu Options:\n";
    std::cout << "1. Multiply a complex number by a real number\n";
    std::cout << "2. Add a complex number\n";
    std::cout << "3. Subtract a complex number\n";
    std::cout << "4. Multiply by another complex number\n";
    std::cout << "5. Conjugate a complex number\n";
    std::cout << "6. Print magnitude of a complex number\n";
    std::cout << "7. Count numbers with magnitude larger than given value\n";
    std::cout << "8. Remove numbers with magnitude larger than given value\n";
    std::cout << "9. Append a new complex number\n";
    std::cout << "10. Quit and save to file\n";
}


