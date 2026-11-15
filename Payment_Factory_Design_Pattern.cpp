// Problem Statement
// You are designing a payment processing system for an e-commerce application.

// The application should support multiple payment methods, such as:
// - Credit Card
// - UPI
// - PayPal
// Each payment method has its own way of processing payments.

// Your task is to design a flexible system that allows the application to process payments without knowing the internal implementation of each payment method.
// Functional Requirements
// 1. The system should support multiple payment methods.
// 2. Each payment method should implement its own processPayment() functionality.
// 3. The application should be able to process payments using different payment methods.
// 4. The payment creation logic should be separated from the client code.
// 5. Adding a new payment method in the future should require minimal changes to existing code.
// Expected Behaviour
// When the application receives a payment request, it should process the payment using the selected payment method.

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Payment {
public:
    virtual void pay(double amount) const = 0; // Pure virtual function
    virtual ~Payment() = default; // Virtual destructor 
};

class UPIPayment : public Payment {
public:
    void pay(double amount) const override {
        cout << "Processing UPI Payment of amount: " << amount << endl;
    }
};

class CreditCardPayment : public Payment {
public:
    void pay(double amount) const override {
        cout << "Processing Credit Card Payment of amount: " << amount << endl;
    }
};

class PayPalPayment : public Payment {
public:
    void pay(double amount) const override {
        cout << "Processing PayPal Payment of amount: " << amount << endl;
    }
};

class PaymentFactory {
public:
    virtual unique_ptr<Payment> createPayment() const = 0; // Pure virtual function
    void processPayment(double amount) const {
        auto payment = createPayment();
        payment->pay(amount);
    }
    virtual ~PaymentFactory() = default; // Virtual destructor
};

class UPIPaymentFactory : public PaymentFactory {
public:
    unique_ptr<Payment> createPayment() const override {
        return make_unique<UPIPayment>();
    }
};

class CreditCardPaymentFactory : public PaymentFactory {
public:
    unique_ptr<Payment> createPayment() const override {
        return make_unique<CreditCardPayment>();
    }
};

class PayPalPaymentFactory : public PaymentFactory {
public:
    unique_ptr<Payment> createPayment() const override {
        return make_unique<PayPalPayment>();
    }
};

void processPayment(const PaymentFactory& factory, double amount) {
    factory.processPayment(amount);
}

int main() {
    UPIPaymentFactory upiFactory;
    CreditCardPaymentFactory creditCardFactory;
    PayPalPaymentFactory paypalFactory;

    processPayment(upiFactory, 100.0);
    processPayment(creditCardFactory, 200.0);
    processPayment(paypalFactory, 300.0);

    return 0;
}