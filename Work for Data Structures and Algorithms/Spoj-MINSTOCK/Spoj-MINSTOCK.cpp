#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    cin.ignore();

    map<string, int> nameToPrice;
    set<pair<int, string>> priceName;

    for (int day = 1; day <= N; day++) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        int type;
        ss >> type;

        if (type == 1) {
            string X;
            int Y;
            ss >> X >> Y;

            if (nameToPrice.find(X) != nameToPrice.end()) {
                int oldPrice = nameToPrice[X];
                priceName.erase({ oldPrice, X });
            }
            nameToPrice[X] = Y;
            priceName.insert({ Y, X });

        }

        else if (type == 2) {
            string X;
            int Z;
            ss >> X >> Z;

            if (nameToPrice.find(X) != nameToPrice.end()) {
                int oldPrice = nameToPrice[X];
                priceName.erase({ oldPrice, X });
                nameToPrice[X] = Z;
                priceName.insert({ Z, X });
            }

        }

        else if (type == 3) {
            auto it = priceName.begin();
            string name = it->second;
            cout << name << " " << day << "\n";

            priceName.erase(it);
            nameToPrice.erase(name);
        }
    }

    return 0;
}