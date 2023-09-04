//User function template for C++
class Solution{
public:
	int isDivisible(string s){
	    //complete the function here
	    int oddSum = 0;
	    int evenSum = 0;
	    
	    for(int i = 0; i < s.length(); i++){
	        //even position
	        if((i+1) % 2 == 0){
	            if(s[i] == '1'){
	                evenSum ++;
	            }
	        }
	        //else odd postion
	        else{
	            if(s[i] == '1'){
	                oddSum ++;
	            }
	        }
	    }
	    if(abs(evenSum - oddSum) % 3 == 0){
	        return 1;
	    }
	    return 0;
	}

};