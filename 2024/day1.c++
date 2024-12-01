#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <limits.h>
#include <fstream>
using namespace std;
 
typedef long long ll;

int part_1(vector<int> &l1, vector<int> &l2){
    int ans = 0;
    
    for(int i=0; i<l1.size(); i++){
        ans += abs(l1[i] - l2[i]);
    }
    return ans;
}

int part_2(vector<int> &l1, vector<int> &l2){
    int similarity_score = 0;
    
    unordered_map<int,int> m;
    for(int &i: l2){
        m[i]++;
    }

    for(int &i: l1){
        similarity_score += i*m[i];
    }

    return similarity_score;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ifstream inFile;
    string fileName = "ip1.txt";
    inFile.open(fileName);

    int a, b;
    vector<int> l1, l2;
    
    while (inFile >> a >> b) {
        l1.push_back(a);
        l2.push_back(b);
    }        
    inFile.close();
    
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    
    cout << "part 1 output: " << part_1(l1,l2) << "\n";
    cout << "part 2 output: " << part_2(l1,l2) << "\n";

    return 0;
}