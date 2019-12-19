#include <iostream>
#include <string>

using namespace std;

int main() {
    int age;
    string name, city, college, career, animal, petName;

    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "Please enter your age: ";
    cin >> age;
    cout << "What city do you live in? ";
    cin.ignore();
    getline(cin, city);
    cout << "What college do you attend? ";
    getline(cin, college);
    cout << "What is your ideal career? ";
    getline(cin, career);
    cout << "What is your favorite type of animal? ";
    getline(cin, animal);
    cout << "What would you name your pet? ";
    getline(cin, petName);

    cout << "There once was a person named " << name << " who lived in " << city << ". At the age of "
         << age << ", " << name << " went to college at " << college << ". " << name
         << " graduated and went to work as a " << career << ". Then, " << name << " adopted a(n) "
         << animal << " named " << petName << ". They both lived happily every after!\n";

    return 0;
}
