#include "validate.h"
#include <sstream>

void Entitate_Validator::validate(const Entitate &a) {
    vector<string> msgs;
    if(a.get_tip()!="1" && a.get_tip()!="2")
        msgs.emplace_back("Tip invalid!\n");
    if (!msgs.empty())
        throw Validare(msgs);

}
ostream& operator<<(ostream& out, const Validare& ex){
    for(const auto& msg : ex.msg)
        out<< msg<<" ";
    return out;
}