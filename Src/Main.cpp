#include "main.hpp"
#include "ThreadManager.hpp"

int main() 
{
    ThreadManager manager;
    manager.startAll();

    std::this_thread::sleep_for(std::chrono::seconds(10)); // Let threads run

    manager.stopAll();
    return 0;
}
