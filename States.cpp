//
// Created by Celeste Tan on 11/18/21.
//

#include "States.h"

std::map<States::ObjectState, bool> States::statesMap;

States::States() {
    for (int i = HIDDEN; i < LASTSTATE; ++i) {
        statesMap[static_cast<ObjectState>(i)] = false;
    }
}

bool States::stateEnabled(ObjectState state) {
    if (statesMap.count(state) > 0) {
        return statesMap[state];
    }
    return false;
}

void States::enableState(ObjectState state) {
    statesMap[state] = true;
}

void States::disableState(ObjectState state) {
    statesMap[state] = false;
}

bool States::checkState(States::ObjectState state) const {
    return statesMap.at(state);
}
