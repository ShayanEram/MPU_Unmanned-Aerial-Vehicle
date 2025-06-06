#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <vector>
#include <string>
#include <functional>

class Observer {
public:
    void addListener(std::function<void(std::string)> callback) {
        listeners.push_back(callback);
    }

    void triggerEvent(std::string eventMessage) {
        for (auto& listener : listeners) {
            listener(eventMessage);
        }
    }

private:
    std::vector<std::function<void(std::string)>> listeners;
};

#endif // OBSERVER_HPP
