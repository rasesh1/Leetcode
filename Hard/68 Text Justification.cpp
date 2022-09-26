class Solution {
private:
    int maxWidth = 0;
    vector<string> ans;
    
    void addWordsToResult(vector<string>& currentLine, int totalSpaces, bool leftAlign) {
        int n = currentLine.size();
        string line = currentLine[0];
                
        if(leftAlign)   {
            for(int i=1; i<currentLine.size(); i++) {
                line = line + " " + currentLine[i];
            }
            while(line.length() < maxWidth)
                line = line + " ";
            ans.push_back(line);
            return;
        }
        
        int spacePerWord = leftAlign ? 1 : totalSpaces/(currentLine.size()-1);
        int remainder = leftAlign ? 0 : totalSpaces%(currentLine.size()-1);
        
        for(int i=1; i<currentLine.size(); i++) {
            line = line + std::string(spacePerWord, ' ');
            if(i <= remainder) line = line + " ";
            line = line + currentLine[i];
        }
        ans.push_back(line);
        return;
    }
    
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        this->maxWidth = maxWidth;
        
        int n = words.size();
        int i=0;
        
        while(i < n)    {
            vector<string> currentLine = {words[i]};
            int charsRemain = maxWidth - words[i].length();
                        
            int j = i+1;
            int totalSpaces = 0;
            
            while(j < n && charsRemain >= 1 + words[j].length())    {
                currentLine.push_back(words[j]);
                charsRemain = charsRemain - 1 - words[j].length();
                j++;
                totalSpaces++;
            }
            
            totalSpaces = totalSpaces + charsRemain;
            addWordsToResult(currentLine, totalSpaces, (currentLine.size()==1 || j==n));
            i = j;
        }
        return ans;
    }
};