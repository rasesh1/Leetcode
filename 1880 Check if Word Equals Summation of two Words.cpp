class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1 = 0;
        for(int i=0; i<firstWord.length(); i++) {
            num1 = num1*10 + (int)(firstWord[i]-'a');
        }
        
        int num2 = 0;
        for(int i=0; i<secondWord.length(); i++) {
            num2 = num2*10 + (int)(secondWord[i]-'a');
        }
        
        int target_num = 0;
        for(int i=0; i<targetWord.length(); i++) {
            target_num = target_num*10 + (int)(targetWord[i]-'a');
        }
        
        return (target_num == num1+num2) ? true : false;
        
    }
};