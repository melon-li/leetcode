 //The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

//P   A   H   N
//A P L S I I G
//Y   I   R

//And then read line by line: "PAHNAPLSIIGYIR"

//Write the code that will take a string and make this conversion given a number of rows:

//string convert(string text, int nRows);

//convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
//http://www.cnblogs.com/sanghai/p/3632528.html


//Algorithm1 
//@IMPERFECT
lass Solution {
public:
    string convert(string s, int numRows) {
        string sub[numRows];
        int row = 0,  col = 0;
        if(numRows < 2) return s;
        for(int i=0; i<s.length(); i++){
            if(row < numRows && col%(numRows-1) == 0){
                sub[row++] += s[i];
            }else{
                if(row >= numRows) row = numRows - 2;
                if(row == 0 ){sub[row++] += s[i]; continue;} 
                sub[row--] += s[i];
                col++;
                if(row <= 0) col = 0;
            }
        }

        string r;
        for(int i=0; i<numRows; i++){
            r += sub[i];
        }
        return r;
    }
};

