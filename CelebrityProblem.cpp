//BruteForce
/*

Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


// The task is to complete this function
int getId(int M[MAX][MAX], int n)
{
    int i, k = 0;
    int match = 0, pos =0;
    for(i = 0;i < n;i++){
        if (match)
            break;
        for(int j = 0;j < n;j++){
            if(M[i][j] == 1){
                for (k=0; k<n; k++) {
                    if (M[k][j] == 1 & k!=j) {
                        match = 1;
                    }
                }
                if (match ==1 ) {
                    for (k=0; k<n; k++) {
                        if ( k!=j) {
                            if (M[j][k] == 0) {
                                match = 1;
                            } else {
                                match = 0;
                            }
                        }
                    }
                    
                }
            }
            if(match) {
                pos = j;
                break;
            }
               
        }
        
    }
    if (match)
        return pos;
    else 
        return -1;
}
