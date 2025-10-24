#include <iostream>
#include <set>

using namespace std;

int main() {

    int N;
    cin >> N;
    multiset<long long> pieces;

    for (int i = 0; i < N; i++) {
        long long len;
        cin >> len;
        pieces.insert(len);
    }

    long long totalCost = 0;

    while (pieces.size() > 1) {

        auto it = pieces.begin();
        long long a = *it;
        it = pieces.erase(it);
        long long b = *it;
        it = pieces.erase(it);

        long long sum = a + b;
        totalCost += sum;
        pieces.insert(sum);
    }

    cout << totalCost << endl;
    return 0;
}