class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        // MMMCXLV
        //1000 + 1000 + 1000 + 100 + 10 + 50 + 5
        int sum = 0;
        for(int i = 0; i<str.size(); i++){
            //               and str[i+1] present
            if(i != str.size()-1 ){
                if(str[i] == 'I' and str[i+1] == 'V'){
                    sum += 4;
                    ++i;
                    continue;
                }
                if(str[i] == 'I' and str[i+1] == 'X'){
                    sum += 9;
                    ++i;
                    continue;
                }
                else if(str[i] == 'X' and str[i+1] == 'L'){
                    sum += 40;
                    ++i;
                    continue;
                }
                else if(str[i] == 'X' and str[i+1] == 'C'){
                    sum += 90;
                    ++i;
                    continue;
                }
                else if(str[i] == 'C' and str[i+1] == 'D'){
                    sum += 400;
                    ++i;
                    continue;
                }
                else if(str[i] == 'C' and str[i+1] == 'M'){
                    sum += 900;
                    ++i;
                    continue;
                }
 
            }   
            switch(str[i]){
                case 'I':
                    sum += 1;
                    break;
                    
                case 'V':
                    sum += 5;
                    break;
                    
                case 'X':
                    sum += 10;
                    break;
                    
                case 'L':
                    sum += 50;
                    break;
                    
                case 'C':
                    sum += 100;
                    break;
                    
                case 'D':
                    sum += 500;
                    break;
                    
                case 'M':
                    sum += 1000;
                    break;
                default:
                    break;
                    
            }//switch case terminated
        }//loop body terminated
        return sum;
// 1 - I
// 57 - LVII
// 112 - CXII
// 370 - CCCLXX
// 999 - CMXCIX
// 2000 - MM
// 2563 - MMDLXIII
// 3145 - MMMCXLV
// 4000 - MMMM
    }
};