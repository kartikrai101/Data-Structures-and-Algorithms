// Let's write a code to perform quick sort on an array
#include<bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define loop(i, n) for(int i=0; i<n; i++)

int partition(vi &arr, int start, int end){
    int pivot_element = arr[start];
    int left=start, right=end;

    while(left < right){
        while(arr[left] <= pivot_element){
            left++;
        }

        while(arr[right] > pivot_element){
            right--;
        }

        if(left < right){
            swap(arr[left], arr[right]);
        }
    }

    // swap the pivot element with the element at the right pointer
    arr[start] = arr[right];
    arr[right] = pivot_element;

    return right;
}

void quickSort(vi &arr, int s, int e){
    // get the pivot element and place it to it's corrected sorted position
    int pivot;
    if(s < e){
        pivot = partition(arr, s, e);
        quickSort(arr, s, pivot-1);
        quickSort(arr, pivot+1, e);
    }
}

int main(){
    int n; cin >> n; vi arr(n);
    loop(i, n){
        cin >> arr[i];
    }
    
    int start = 0, end = n-1;
    quickSort(arr, start, end);

    loop(i, n){
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}