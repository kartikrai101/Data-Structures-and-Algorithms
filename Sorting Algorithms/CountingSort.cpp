// Counting Sort:
// This sorting algorithm is applied when the range between the maximum and mininum element is not very large
// It is a stable sorting algorithm, meaning that the relative order of the elements is not changed. Which means that if 1 is there 3 times in the given array, the sequence of the 1s in the final output array will be same
// Time Complexity -> O(n+k)
// Space Complexity -> O(n)
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define loop(i, n) for(int i=0; i<n; i++)

vi countingSort(vi arr, int n){
    // find the maximum element in array
    int maxi = INT_MIN;
    loop(i, n){
        maxi = max(arr[i], maxi);
    }

    // Now create an array of length equal to the max element and populate it with count of each element present in the original array
    vi count_arr(maxi+1, 0);
    loop(i, n){
        int element = arr[i];
        count_arr[element]++;
    }
    
    // For each element, find the cummulative sum of elements before it
    for(int i=1; i<maxi+1; i++){
        count_arr[i] = count_arr[i]+count_arr[i-1];
    }

    // Now we need to shift the elements of the array 1 position to the right
    for(int i=maxi; i>0; i--){
        count_arr[i] = count_arr[i-1];
    }

    // [1, 0, 4, 4]
    // Now that we have shifted the count_arr contents, we can now 
    vi sortedArray(n);
    loop(i, n){
        int element = arr[i];
        // get the position of this element from the count_arr and place it at that positionin the sortedArray
        int position = count_arr[element];
        count_arr[element]++;
        sortedArray[position] = element;
    }

    return sortedArray;
}

int main(){
    int n; cin >> n;
    vi arr(n);

    loop(i, n){
        cin >> arr[i];
    }

    vi sortedArray = countingSort(arr, n);

    loop(i, n){
        cout << sortedArray[i] << " ";
    }cout << endl;

    return 0;
}