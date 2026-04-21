#include "SpamDetector.h"
#include <vector>
using namespace std;
bool SpamDetector::isSpam(const string& text){
 set<string> keys = {"win money", "free prize", "click now", "urgent", "lottery", "bitcoin", "verify password"};
 for (auto word : keys)
    if (text.find(word) != string::npos)
        return true;
 int ex=0; for(char c:text) if(c=='!') ex++;
 if(ex>=3) return true;
 return false;
}
