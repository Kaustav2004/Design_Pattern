# Design Patterns

This repository contains C++ factory-pattern examples. These class diagrams are
generated from the source with [clang-uml](https://github.com/bkryza/clang-uml).

## Notification factory

<!-- UML:notification_factory:start -->

```mermaid
classDiagram
    class C_0001275076681856179721["std::string"]
    class C_0001275076681856179721 {
    }
    class C_0018138725717688678615["std::unique_ptr&lt;Notification&gt;"]
    class C_0018138725717688678615 {
    }
    class C_0000065107195742535227["Notification"]
    class C_0000065107195742535227 {
        <<abstract>>
        +~Notification() [default] void
        +send(const string & message) [const] void*
    }
    class C_0009571795672658047204["EmailNotification"]
    class C_0009571795672658047204 {
        +send(const string & message) [const] void
    }
    class C_0003776505871401580153["SMSNotification"]
    class C_0003776505871401580153 {
        +send(const string & message) [const] void
    }
    class C_0010304378484534008865["NotificationFactory"]
    class C_0010304378484534008865 {
        <<abstract>>
        +~NotificationFactory() [default] void
        +createNotification() [const] std::unique_ptr&lt;Notification&gt;*
        +notify(const string & message) [const] void
    }
    class C_0011038165129306852938["EmailNotificationFactory"]
    class C_0011038165129306852938 {
        +createNotification() [const] std::unique_ptr&lt;Notification&gt;
    }
    class C_0000443153978548955419["SMSNotificationFactory"]
    class C_0000443153978548955419 {
        +createNotification() [const] std::unique_ptr&lt;Notification&gt;
    }
    C_0018138725717688678615 ..> C_0000065107195742535227 : 
    C_0000065107195742535227 ..> C_0001275076681856179721 : 
    C_0009571795672658047204 ..> C_0001275076681856179721 : 
    C_0000065107195742535227 <|-- C_0009571795672658047204 : 
    C_0003776505871401580153 ..> C_0001275076681856179721 : 
    C_0000065107195742535227 <|-- C_0003776505871401580153 : 
    C_0010304378484534008865 ..> C_0018138725717688678615 : 
    C_0010304378484534008865 ..> C_0000065107195742535227 : 
    C_0010304378484534008865 ..> C_0001275076681856179721 : 
    C_0011038165129306852938 ..> C_0018138725717688678615 : 
    C_0011038165129306852938 ..> C_0000065107195742535227 : 
    C_0010304378484534008865 <|-- C_0011038165129306852938 : 
    C_0000443153978548955419 ..> C_0018138725717688678615 : 
    C_0000443153978548955419 ..> C_0000065107195742535227 : 
    C_0010304378484534008865 <|-- C_0000443153978548955419 : 

%% Generated with clang-uml, version 0.6.3
%% LLVM version Ubuntu clang version 18.1.3 (1ubuntu1)
```
<!-- UML:notification_factory:end -->

## Payment factory

<!-- UML:payment_factory:start -->

```mermaid
classDiagram
    class C_0008703728454312397085["std::unique_ptr&lt;Payment&gt;"]
    class C_0008703728454312397085 {
    }
    class C_0015398629302490077741["Payment"]
    class C_0015398629302490077741 {
        <<abstract>>
        +~Payment() [default] void
        +pay(double amount) [const] void*
    }
    class C_0014372867184526014403["UPIPayment"]
    class C_0014372867184526014403 {
        +pay(double amount) [const] void
    }
    class C_0011825729577383634659["CreditCardPayment"]
    class C_0011825729577383634659 {
        +pay(double amount) [const] void
    }
    class C_0001914535175163676746["PayPalPayment"]
    class C_0001914535175163676746 {
        +pay(double amount) [const] void
    }
    class C_0017996786056422422736["PaymentFactory"]
    class C_0017996786056422422736 {
        <<abstract>>
        +~PaymentFactory() [default] void
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;*
        +processPayment(double amount) [const] void
    }
    class C_0000675268977554222996["UPIPaymentFactory"]
    class C_0000675268977554222996 {
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;
    }
    class C_0017571377031642784068["CreditCardPaymentFactory"]
    class C_0017571377031642784068 {
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;
    }
    class C_0017829665219736894171["PayPalPaymentFactory"]
    class C_0017829665219736894171 {
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;
    }
    C_0008703728454312397085 ..> C_0015398629302490077741 : 
    C_0015398629302490077741 <|-- C_0014372867184526014403 : 
    C_0015398629302490077741 <|-- C_0011825729577383634659 : 
    C_0015398629302490077741 <|-- C_0001914535175163676746 : 
    C_0017996786056422422736 ..> C_0008703728454312397085 : 
    C_0017996786056422422736 ..> C_0015398629302490077741 : 
    C_0000675268977554222996 ..> C_0008703728454312397085 : 
    C_0000675268977554222996 ..> C_0015398629302490077741 : 
    C_0017996786056422422736 <|-- C_0000675268977554222996 : 
    C_0017571377031642784068 ..> C_0008703728454312397085 : 
    C_0017571377031642784068 ..> C_0015398629302490077741 : 
    C_0017996786056422422736 <|-- C_0017571377031642784068 : 
    C_0017829665219736894171 ..> C_0008703728454312397085 : 
    C_0017829665219736894171 ..> C_0015398629302490077741 : 
    C_0017996786056422422736 <|-- C_0017829665219736894171 : 

%% Generated with clang-uml, version 0.6.3
%% LLVM version Ubuntu clang version 18.1.3 (1ubuntu1)
```
<!-- UML:payment_factory:end -->

## Generate diagrams locally

Install `clang-uml`, CMake, and a C++ compiler, then run:

```sh
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
cmake --build build
clang-uml --progress --query-driver /usr/bin/c++
clang-uml -g mermaid --query-driver /usr/bin/c++
python3 scripts/embed_diagrams.py
```

GitHub Actions regenerates the source diagrams and updates this README when C++
source or diagram configuration changes are pushed to `main`. PlantUML source
files are also saved in [`docs/diagrams`](docs/diagrams). You can run the
workflow manually from the repository's **Actions** tab.
