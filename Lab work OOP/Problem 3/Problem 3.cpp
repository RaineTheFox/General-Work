// Display cat's name and the number of mice he ate. Display if he lives in Craiova or not

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cat {
private:
    string name;
    int miceNo;
    string city;

public:
    Cat(string name, string city) {
        this->name = name;
        this->miceNo = 0;
        this->city = city;
    }

    //  void eatMouse() { this->miceNo++; } - Process is called Overoading!!
    void eatMouse(int count = 1) { this->miceNo += count; }

    string getName() { return this->name; }
    int getMiceNo() { return this->miceNo; }
    bool livesIn(string checkCity) { return this->city == checkCity; }
};

int main() {
    Cat* cat = new Cat("Tomita", "Craiova");
    cat->eatMouse();
    cat->eatMouse();

    cout << cat->getName() << endl;
    cout << cat->getMiceNo() << endl;
    cout << cat->livesIn("Craiova") << endl << endl;

    delete cat;

    //Going further to check for 5 cats
	vector<Cat*> cats = { // updated to use vector instead of array
        new Cat("Lulus", "Craiova"),
        new Cat("Oscar", "Bucuresti"),
        new Cat("Bella", "Craiova"),
        new Cat("Kitty", "Timisoara"),
        new Cat("Simba", "Craiova")
    };

    cats[0]->eatMouse();
    cats[0]->eatMouse();

    cats[1]->eatMouse(7);

    cats[2]->eatMouse();
    cats[2]->eatMouse();
    cats[2]->eatMouse(3);

    cats[4]->eatMouse();

    for (auto cat : cats) {
        cout << cat->getName() << " ate " << cat->getMiceNo() << ((cat->getMiceNo() != 1) ? " mice. " : " mouse. ");
        cout << "Lives in Craiova: " << (cat->livesIn("Craiova") ? "Yes" : "No") << endl;
    }

    auto countCraiovaCats = [&cats]() {
        int count = 0;
        for (auto cat : cats) {
            if (cat->livesIn("Craiova")) {
                count++;
            }
        }
        return count;
        };

    cout << "\nNumber of cats in Craiova: " << countCraiovaCats() << endl;

    for (auto& cat : cats) {
        delete cat;
        cat = NULL;
    }
    cats.clear();

    return 0;
}