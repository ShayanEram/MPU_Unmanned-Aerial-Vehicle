#ifndef MESSAGE_QUEUE_HPP
#define MESSAGE_QUEUE_HPP

#include <queue>
#include <mutex>
#include <condition_variable>

class MessageQueue {
public:
    void pushCommand(std::string command) {
        std::lock_guard<std::mutex> lock(queueMutex);
        commands.push(command);
        condition.notify_one();
    }

    std::string popCommand() {
        std::unique_lock<std::mutex> lock(queueMutex);
        condition.wait(lock, [this]{ return !commands.empty(); });
        std::string command = commands.front();
        commands.pop();
        return command;
    }

private:
    std::queue<std::string> commands;
    std::mutex queueMutex;
    std::condition_variable condition;
};

#endif // MESSAGE_QUEUE_HPP
