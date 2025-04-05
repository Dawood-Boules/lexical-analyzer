#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isKeyword(string word) {
    return word == "int" || word == "float" || word == "if" || word == "return" || word == "for";
}

void tokenize(string code) {
    string token = "";
    for (int i = 0; i < code.length(); i++) {
        char ch = code[i];

        if (isspace(ch)) continue;

        if (isalpha(ch)) {
            token = "";
            while (isalnum(code[i]) || code[i] == '_') {
                token += code[i];
                i++;
            }
            i--;
            if (isKeyword(token))
                cout << "<" << token << ", KEYWORD>" << endl;
            else
                cout << "<" << token << ", IDENTIFIER>" << endl;
        }

        else if (isdigit(ch)) {
            token = "";
            while (isdigit(code[i])) {
                token += code[i];
                i++;
            }
            i--;
            cout << "<" << token << ", NUMBER>" << endl;
        }

        else if (ch == '=' || ch == '+' || ch == '-') {
            cout << "<" << ch << ", OPERATOR>" << endl;
        }

        else if (ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}') {
            cout << "<" << ch << ", SEPARATOR>" << endl;
        }

        else {
            cout << "<" << ch << ", UNKNOWN>" << endl;
        }
    }
}

int main() {
    string code = "int x = 5; float y = x + 2;";
    tokenize(code);
    return 0;
}
