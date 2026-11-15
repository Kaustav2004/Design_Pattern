// UML diagram: Factory_Design_Pattern.svg
// #include <iostream>
// #include <memory>
// #include <string>
// using namespace std;

// class Notification {
// public:
//     virtual void send(const string& message) const = 0; // Pure virtual function
//     virtual ~Notification() {} // Virtual destructor
// };

// class EmailNotification : public Notification {
// public:
//     void send(const string& message) const override {
//         cout << "Sending Email Notification: " << message << endl;
//     }
//     ~EmailNotification() {
//         cout << "Destroying EmailNotification" << endl;
//     }
// };

// class SMSNotification : public Notification {
// public:
//     void send(const string& message) const override {
//         cout << "Sending SMS Notification: " << message << endl;
//     }
//     ~SMSNotification() {
//         cout << "Destroying SMSNotification" << endl;
//     }
// };


// int main() {
//    string type = "email"; // Change this to "sms" to test SMSNotification
   
//     // here is the main problem that client code is directly creating the objects of 
//     // EmailNotification and SMSNotification classes. This violates the Open/Closed 
//     // Principle, as adding new notification types would require modifying the client code.
//     // To adhere to the Open/Closed Principle, we can use a Factory Design Pattern to create 
//     // notification objects without changing the client code.
//    if(type == "email") {
//        unique_ptr<Notification> notification = make_unique<EmailNotification>();
//        notification->send("Hello via Email!");
//    } else if(type == "sms") {
//        unique_ptr<Notification> notification = make_unique<SMSNotification>();
//        notification->send("Hello via SMS!");
//    } else {
//        cout << "Unknown notification type!" << endl;
//    }
// }


#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Notification {
public:
    virtual void send(const string& message) const = 0; // Pure virtual function
    virtual ~Notification() = default; // Virtual destructor
};

class EmailNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "Sending Email Notification: " << message << endl;
    }
};

class SMSNotification : public Notification {
public:
    void send(const string& message) const override {
        cout << "Sending SMS Notification: " << message << endl;
    }
};

class NotificationFactory {
public:
    virtual unique_ptr<Notification> createNotification() const = 0; // Pure virtual function
    // this is the factory interface that defines a method for creating notification objects.
    void notify(const string& message) const {
        auto notification = createNotification();
        notification->send(message);
    }
    
    virtual ~NotificationFactory() = default; // Virtual destructor
};

class EmailNotificationFactory : public NotificationFactory {
public:
    unique_ptr<Notification> createNotification() const override {
        return make_unique<EmailNotification>();
    }
};

class SMSNotificationFactory : public NotificationFactory {
public:
    unique_ptr<Notification> createNotification() const override {
        return make_unique<SMSNotification>();
    }
};

void sendNotification(const NotificationFactory& factory, const string& message) {
    factory.notify(message);
}

int main() {
    EmailNotificationFactory emailFactory;
    SMSNotificationFactory smsFactory;
    
    sendNotification(emailFactory, "Hello via Email!");
    sendNotification(smsFactory, "Hello via SMS!");
    
    return 0;
}