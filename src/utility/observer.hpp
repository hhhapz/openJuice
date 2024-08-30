#pragma once

enum class Event { };

enum class SubscriberType { CardSubscriber };

class Observer {
  public:
    virtual void notify(Event e) = 0;
    virtual SubscriberType subType() = 0;
    virtual ~Observer();
};