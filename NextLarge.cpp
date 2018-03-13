#include<iostream>

using namespace std;

void next_larger(int arr[], int num) {
    
    int next, i, j;
    for (i=0; i<num; i++)
    {
        
        next = -1;
        for (j = i+1; j<num; j++)
        {
            if (arr[i] < arr[j])
            {
                next = arr[j];
                break;
            }
        }
        cout<<next<<" ";
        
    }
}


         
int main() {
    int num, test;
    
    int arr[1000];
    cin>>test;

 
    for (int t=0; t< test; t++) {
            cin>>num;
        for (int i = 0; i < num; i++) {
            cin>>arr[i];
        }
        next_larger(arr, num);
        if (t < test) {
            cout << "\n";
        }
    }
    cout<<"\n";
       
    return 0;
}
