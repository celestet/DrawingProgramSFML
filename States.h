//
// Created by Celeste Tan on 11/18/21.
//

#ifndef VERSION1_STATES_H
#define VERSION1_STATES_H


#include <map>

class States {
public:
    enum ObjectState {
        HIDDEN, HIGHLIGHTED, DISABLED, CURSORBLINKING, BGCOLOR, ITEMAPPEARED,
        DISPLAYON, LIMITED, BLINKING, DRAG,LASTSTATE
    };

    States();
    bool checkState(ObjectState state) const;

    static bool stateEnabled(ObjectState state);
    static void enableState(ObjectState state);
    static void disableState(ObjectState state);

private:
    static std::map<ObjectState, bool> statesMap;
};



#endif //VERSION1_STATES_H
