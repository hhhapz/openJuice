#include "subject.hpp"

Subject::Subject() {}

Subject::~Subject() {}

void Subject::attach(Observer* ob) {
    observers.push_back(ob);
}

void Subject::detach(Observer* ob) {
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        if (*it == ob) {
            observers.erase(it);
            break;
        }
    }
}

void Subject::notifyObservers(Event e) const {
    for (Observer* ob: observers) ob->notify(e);
}

void Subject::notifyCards(Event e) const {
    for (Observer* ob: observers) if (ob->subType() == SubscriberType::CardSubscriber) ob->notify(e);
}