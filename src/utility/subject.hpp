#pragma once

#include <vector>

#include "observer.hpp"

class Subject {
  private:
    std::vector<Observer*> observers;
  public:
    Subject();
    void attach(Observer* ob);
    void detach(Observer* ob);
    void notifyObservers(Event e) const;
    void notifyCards(Event e) const;
    virtual ~Subject() = 0;
};