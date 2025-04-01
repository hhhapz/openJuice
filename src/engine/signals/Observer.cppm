/**
 * @file Observer.cppm
 * @brief Module file defining the Observer interface and Subject abstract class.
 *
 * This file contains the definitions of the Observer interface and Subject abstract class.
 */

module;

#include <vector>

export module engine.signals.Observer;

#ifdef NO_RESERVED_STD
import std.algorithm;
import std.core;
import std.collections;
#else
import stdlib.algorithm;
import stdlib.core;
import stdlib.collections;
#endif

using namespace stdlib::collections;

/**
 * @interface Observer
 * @brief Interface representing an Observer.
 * @deprecated
 */
export class [[deprecated("There is currently no use for the Observer class, due to the adoption of the ECS system. If a new use is found it will be un-deprecated.")]] Observer {
public:
    virtual ~Observer() {}
    virtual void update(class Subject* subject) = 0;
};

/**
 * @class Subject
 * @brief Abstract class representing a subject.
 * @deprecated
 */
export class [[deprecated("There is currently no use for the Subject class, due to the adoption of the ECS system. If a new use is found it will be un-deprecated.")]] Subject {
private:
    Vector<Observer*> observers;
public:
    virtual ~Subject() {}

    void attach(Observer* observer) {
        observers.push_back(observer);
    }

    void detach(Observer* observer) {
        observers.erase(algorithm::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() {
        for (Observer* observer: observers)
            observer->update(this);
    }
};
