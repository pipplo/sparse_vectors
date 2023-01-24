#include <iostream>
#include <list>
#include <vector>
#include <utility>

using namespace std;

class SparseVector {
    public:
    SparseVector(vector<int> vector) {
        for (int i = 0; i<vector.size(); i++) {
            if (vector[i] != 0) {
                elements.push_back(make_pair(i, vector[i]));
            }
        }
    }

    static int DotProduct(SparseVector sv1, SparseVector sv2) {
        auto sv1_itr = sv1.elements.begin();
        auto sv2_itr = sv2.elements.begin();

        int dp = 0;

        while (sv1_itr != sv1.elements.end() && sv2_itr != sv2.elements.end()) {
            if (sv1_itr->first == sv2_itr->first) {
                dp += sv1_itr->second * sv2_itr->second;
                sv1_itr++;
                sv2_itr++;
            } else if ( sv1_itr->first < sv2_itr->first ) {
                sv1_itr++;
            } else {
                sv2_itr++;
            }
        }

        return dp;
    }
    private:
        using SparseElement = pair<int, int>;
        list<SparseElement> elements;
};

int main() {
    vector<int> vec = {1, 0, 0, 2, 0, 5, 3, 4};
    vector<int> vec2 = {4, 5, 3, 2, 0, 5, 3, 4, 0, 0, 0};

    SparseVector sv1 = SparseVector(vec);
    SparseVector sv2 = SparseVector(vec2);

    int dp = SparseVector::DotProduct(sv1, sv2);

    cout << dp << endl;

    return 0;
}