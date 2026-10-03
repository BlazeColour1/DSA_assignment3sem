#include <string>
#include <algorithm>

class TextEditor {
private:
    std::string prefix;
    std::string suffix;

public:
    TextEditor() {
        prefix.reserve(200000);
        suffix.reserve(200000);
    }
    
    void addText(std::string text) {
        prefix += text;
    }
    
    int deleteText(int k) {
        int count = 0;
        while (k-- > 0 && !prefix.empty()) {
            prefix.pop_back();
            count++;
        }
        return count;
    }
    
    std::string cursorLeft(int k) {
        while (k-- > 0 && !prefix.empty()) {
            suffix.push_back(prefix.back());
            prefix.pop_back();
        }
        int sz = prefix.size();
        int len = (sz < 10) ? sz : 10;
        return prefix.substr(sz - len);
    }
    
    std::string cursorRight(int k) {
        while (k-- > 0 && !suffix.empty()) {
            prefix.push_back(suffix.back());
            suffix.pop_back();
        }
        int sz = prefix.size();
        int len = (sz < 10) ? sz : 10;
        return prefix.substr(sz - len);
    }
};


/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */