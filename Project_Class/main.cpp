#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
private:
    char fullName[50];
    char birthDate[15];
    char phone[15];
    char city[30];
    char country[30];
    char schoolName[50];
    char schoolCity[30];
    char schoolCountry[30];
    int groupNumber;

public:
    void input() {
        cout << "Enter full name: "; cin.getline(fullName, 50);
        cout << "Enter birth date: "; cin.getline(birthDate, 15);
        cout << "Enter phone: "; cin.getline(phone, 15);
        cout << "Enter city: "; cin.getline(city, 30);
        cout << "Enter country: "; cin.getline(country, 30);
        cout << "Enter school name: "; cin.getline(schoolName, 50);
        cout << "Enter school city: "; cin.getline(schoolCity, 30);
        cout << "Enter school country: "; cin.getline(schoolCountry, 30);
        cout << "Enter group number: "; cin >> groupNumber;
        cin.ignore();
    }

    void display() const {
        cout << "Full Name: " << fullName << "\nBirth Date: " << birthDate << "\nPhone: " << phone
            << "\nCity: " << city << "\nCountry: " << country << "\nSchool: " << schoolName
            << "\nSchool City: " << schoolCity << "\nSchool Country: " << schoolCountry
            << "\nGroup Number: " << groupNumber << "\n";
    }

    const char* getFullName() const { return fullName; }
    int getGroupNumber() const { return groupNumber; }
};

class Point {
private:
    double x, y, z;

public:
    void input() {
        cout << "Enter x, y, z coordinates: ";
        cin >> x >> y >> z;
    }

    void display() const {
        cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")\n";
    }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    void saveToFile(const char* filename) const {
        ofstream file(filename);
        if (file) {
            file << x << " " << y << " " << z;
        }
    }

    void loadFromFile(const char* filename) {
        ifstream file(filename);
        if (file) {
            file >> x >> y >> z;
        }
    }
};

int main() {
    Student student;
    student.input();
    student.display();

    Point point;
    point.input();
    point.display();

    point.saveToFile("point.txt");
    Point newPoint;
    newPoint.loadFromFile("point.txt");
    newPoint.display();

    return 0;
}