#ifndef SCORECARD_H
#define SCORECARD_H

#include <string>
using namespace std;

#define MOTHER_LANG_SUBJECT     1
#define MATH_SUBJECT            2
#define ENGLISH_SUBJECT         3

class ScoreCard {
  public :
    ScoreCard() {
      motherLangScore_ = mathScore_ = englishScore_ = 0;
    }

    string name_;
    int motherLangScore_; // -- ����
    int englishScore_;    // -- ����
    int mathScore_;       // -- ����
};

#endif
