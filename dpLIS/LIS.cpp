#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

o
// foo
// test

int LIS(vector<int>& v){
    int maxAns = 0;
    vector<int> cache(v.size(), -1);

    int n = v.size();
    
    for(int i = n-1 ; i >= 0; i--){
 
        int max =0; 
        int ans =0;  
        //if(cache[i] == -1){
            for(int j = i+1; j < n; j++){
                //cout<< i<<","<<j<<" : " << v[i] <<"," << v[j] << endl;
                if(v[j] > v[i]){
                    if(cache[j] > max){
                        max = cache[j];
                    }
                }
            }
           
           cache[i] = 1 + max;
           if(cache[i] > maxAns){
               maxAns = cache[i];
           }
        // cout<<"cache["<<i<<"]:"<< cache[i]<<endl;
        //}
    }

    
/*
    int maxAns = 0;
    int ans;

for(int i=0; i< n; i++ ){
        ans = cache[i];
        if(ans > maxAns){
            maxAns = ans;
        }
    }
    
*/
    return maxAns;
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    copy_n(istream_iterator<int>(cin), n, back_inserter(v));
    /*cout<<"n:"<<n<<endl;
    for(int i =0; i< n; i++)
        cout<<v[i]<<",";
    cout<<endl;
    */
    if(n>0)
        cout<<LIS(v)<<endl;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

