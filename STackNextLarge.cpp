#include<iostream>
#include <stack>

using namespace std;

void next_larger(int arr[], int num) {
    
    int next, i, j, element;
    stack<int> s;
    
    //push the first element to the stack
    s.push(arr[0]);
    
    for (i=1; i<num; i++)
    {
        next = arr[i];
        if(s.empty() == false){
            element = s.top();
            s.pop();
            while(next > element) {
                cout<<element<<"--"<<next<<" ";
                if (s.empty() == true) 
                    break;
                element = s.top();
                s.pop();
                
            }
            if (element > next) {
                s.push(element);
            }
        }
        s.push(next);
    }
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
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
