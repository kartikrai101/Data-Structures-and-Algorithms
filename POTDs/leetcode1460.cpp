#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(target.size() != arr.size()) return false;
        // hanlde the case to check if all the elements in target are present in arr
        unordered_map<int, int> arr_elements;
        for(int i=0; i<arr.size(); i++){
            int element = arr[i];
            arr_elements[element]++;
        }

        for(int i=0; i<target.size(); i++){
            int element = target[i];
            if(arr_elements[element] == 0)
                return false;
            arr_elements[element]--;
        }
        return true;
    }
};