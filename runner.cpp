class Solution {
public:

    vector<vector<int>> combinationSum3(int k, int n)
    /**
    * Main driver function to check if there exists combinations of
    * digits from 1-9 that add up to n
    * params: k the size of set, n the number to sum up to 
    * return the set
    **/
    {
        
    int sum = 0;
        
    vector<vector<int> > ans = makeCombi(n, k); 
    vector<vector<int> > set; 

    for (int i = 0; i < ans.size(); i++) { 
        for (int j = 0; j < ans[i].size(); j++) { 
                cout << ans.at(i).at(j) << " "; 
                sum+=ans.at(i).at(j);
        }
        cout<<"sum is "<<sum<<endl;
        if(sum == n){
            set.push_back(ans[i]);
            
        }
        sum = 0;
        cout << endl; 
    }
        
    return set;
        
    }
        
    void makeCombiUtil(vector<vector<int> >& ans, vector<int>& tmp, int n, int left, int k)
    /**
    * helper function to build the set of all possible numbers from 1 - 9 size k
    * params: ans the set of all combos, tmp temp vector, n the size of sum, left left digit, k set size
    * return none
    **/
    { 
        // Pushing this vector to a vector of vector 
        if (k == 0) { 
            ans.push_back(tmp); 
            return; 
        } 
  
        // i iterates from left to n. First time 
        // left will be 1 
        for (int i = left; i <= 9; ++i) 
        { 
            tmp.push_back(i); 
            makeCombiUtil(ans, tmp, n, i + 1, k - 1); 
  
            // Popping out last inserted element 
            // from the vector 
            tmp.pop_back(); 
        } 
    } 
  
    // Prints all combinations of size k of numbers 
    // from 1 to n. 
    vector<vector<int> > makeCombi(int n, int k) 
    { 
        vector<vector<int> > ans; 
        vector<int> tmp; 
        makeCombiUtil(ans, tmp, n, 1, k); 
        return ans; 
    } 
        
        // given number 
};
