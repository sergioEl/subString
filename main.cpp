/******************************************************************************

Seokho Danny Han | seokhoh@mun.ca

                  ** Amazon code test 1 - Part 2**
               
Question: 
    Michelle has created a word game for her students. 
    The word game begins with Michelle writing a string and a number, K, on the board. 
    The students have to ﬁnd the substrings of size K with K distinct characters.
    
    Write an algorithm to help the students ﬁnd the correct answer. 
    If the given string does not have K distinct characters then output an empty list.
    Input
    
    The input to the function/method consists of two arguments -
    inputStr, representing the string written by the teacher;
    num , an integer representing the number, K, written by the teacher on the board.
    
    Output
    Return distinct substrings of input string of size K with K distinct characters.
    
    Constraints
    0 ≤ num ≤ 26
    
    Note
    
    The input string consists of only lowercase letters of the English alphabet. 
    Substrings are not necessarily distinct.
    
    Examples
    Input:
    inputStr = awaglknagawunagwkwagl
    num = 4
    
    Output:
    {wagl, aglk, glkn, lkna, knag, gawu, awun, wuna, unag, nagw, agwk, kwag}
    
    Explanation:
    Substrings in order are: wagl, aglk, glkn, lkna, knag, gawu, awun, wuna, unag, nagw, agwk, kwag, wagl
    "wagl" is repeated twice, but is included in the output once.


*******************************************************************************/

#include <iostream>
#include <vector> 

using namespace std;

int main()
{
    string a = "awaglknagawunagwkwagl";
    int subStringLen = 4;
    
    cout << "string given: " << a << "\nLength of the sub string: " << subStringLen << "\n";
    
    vector<string> v = {};// result vector
    // loop over the string
    for (int i = 0; i < a.size(); i++){
        // cout << i << "\n";
        bool flag = true; // flag for checking same character within the substring
        int j = i; // for comparison of characters
        string s = ""; // tmp string
        s.push_back(a[i]); // push the first character
        // when the expected substring's length exceeds the original string's length, it's done.
        while (i + subStringLen <= a.size() && flag){
            // check every permutation of the substring
            for (int k = j+1; k < i + subStringLen; k++){
                // if any character repeats, it proceeds to the next substring
                if (a[j] == a[k]){
                    flag = false;
                    break;
                }
                // cout << a[j] << " " << a[k] << "\n";
                bool notInString = true; // checking if the character is not in the tmpString
                for (auto t : s){
                    if (t == a[k]) 
                    { 
                        notInString = false; 
                        break;
                    }
                }
                // if the character is not in the tmpString, insert it to the tmpString
                if (notInString){
                    s.push_back(a[k]);
                }
            }
            // if we check the all possible permutation, we stop.
            if (j == i + subStringLen) {
                flag = false;
            }
            j ++; // increase to the next character within the substring
        }
        // cout << "st: " << s << "...\n";
        // check for the last time, if the tmpString's length is the same as the requested length.
        if (s.size() == subStringLen){
            v.push_back(s);
        }
    }
    // print the result vector
    for (auto a : v){
        cout << a << "\n";
    }
    return 0;
}
