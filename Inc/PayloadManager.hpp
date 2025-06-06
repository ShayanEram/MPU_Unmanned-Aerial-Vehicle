#ifndef PAYLOADMANAGER_HPP
#define PAYLOADMANAGER_HPP

class PayloadManager {
public:
    PayloadManager();
    ~PayloadManager();

    void loadPayload();
    void unloadPayload();
    void getPayloadStatus() const;

private:
    // Add private member variables here
};

#endif // PAYLOADMANAGER_HPP