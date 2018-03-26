#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findmingates(vector<int> arrQ, vector<int> depQ, int nflights) {
    
    //Sort departure ;
	sort(depQ.begin(), depQ.end());	
	
	int ar=0, dp=0, count=0, curr=0;
	
	while(ar<nflights) 
	{
		if(arrQ[ar] < depQ[dp]) 
		{ 
			curr++; 
			ar++;
		}
		else 
		{
			curr=max(curr-1,0);
			dp++;
		}
		count=max(curr,count);			
	}
	return count;
}

int main() {
    int n, temp_value;
    cin>>n;
    
    vector<int> arrQ;
    vector<int> depQ;
    
    for (int i=0;i<n;i++) {
        
        cin>>temp_value;
        arrQ.push_back(temp_value);
        
    }
    
    for (int i=0;i<n;i++) {
        cin>>temp_value;
        depQ.push_back(temp_value);
    }
    
    int mingates = findmingates(arrQ,depQ,n);
    
	cout<<"Minimumgates: "<<mingates;
	return 0;
}
