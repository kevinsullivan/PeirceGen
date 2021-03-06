
#ifndef ROSTFDurationMatcherguard
#define ROSTFDurationMatcherguard
#include "../BaseMatcher.h"
#include "../Interpretation.h"


class ROSTFDurationMatcher : public BaseMatcher {
public:
    ROSTFDurationMatcher(clang::ASTContext* context, interp::Interpretation* interp) : BaseMatcher(context, interp) { }
        virtual void setup();
        virtual void run(const MatchFinder::MatchResult &Result);

};

#endif