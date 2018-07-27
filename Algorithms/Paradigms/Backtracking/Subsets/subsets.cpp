/*
 * Find all subsets of an array
 */

#include <iostream>
#include <vector>

using namespace std;

void printVectorInt(vector<int> A) {
    for (int i = 0; i < A.size(); ++i)
        cout<<A[i]<<" ";
    cout<<endl;
}

void printVectorVectorInt(vector<vector<int> > A) {
    for (int i = 0; i < A.size(); ++i)
    {
        printVectorInt(A[i]);
    }
}

void subsetUtil(vector<int>& A, vector<vector<int>>& result, vector<int>& subset, int index) {
    for (int i = index; i < A.size(); ++i)
    {
        subset.push_back(A[i]);
        result.push_back(subset);

        subsetUtil(A, result, subset, i+1);
        subset.pop_back();
    }

    return;
}

vector<vector<int>> allSubsets(vector<int> A) {
    vector<vector<int>> result;
    vector<int> subset;
    result.push_back(subset); // for null element
    subsetUtil(A, result, subset, 0);

    return result;
}

int main() {
    printVectorVectorInt(allSubsets({1,2,3,4}));
    return 0;
}
