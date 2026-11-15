# Design Patterns

This repository contains C++ factory-pattern examples. These class diagrams are
generated from the source with [clang-uml](https://github.com/bkryza/clang-uml).

## Notification factory

<!-- UML:notification_factory:start -->

```mermaid
classDiagram
    class C_0015070288861779828488["std::string"]
    class C_0015070288861779828488 {
    }
    class C_0000562371626193405134["std::unique_ptr&lt;Notification&gt;"]
    class C_0000562371626193405134 {
    }
    class C_0011059798107567739753["Notification"]
    class C_0011059798107567739753 {
        <<abstract>>
        +~Notification() [default] void
        +send(const string & message) [const] void*
    }
    class C_0016893704426602730684["EmailNotification"]
    class C_0016893704426602730684 {
        +send(const string & message) [const] void
    }
    class C_0007282521114909112944["SMSNotification"]
    class C_0007282521114909112944 {
        +send(const string & message) [const] void
    }
    class C_0016629626733807544515["NotificationFactory"]
    class C_0016629626733807544515 {
        <<abstract>>
        +~NotificationFactory() [default] void
        +createNotification() [const] std::unique_ptr&lt;Notification&gt;*
        +notify(const string & message) [const] void
    }
    class C_0009926197004451764028["EmailNotificationFactory"]
    class C_0009926197004451764028 {
        +createNotification() [const] std::unique_ptr&lt;Notification&gt;
    }
    class C_0006861658365665630179["SMSNotificationFactory"]
    class C_0006861658365665630179 {
        +createNotification() [const] std::unique_ptr&lt;Notification&gt;
    }
    C_0000562371626193405134 ..> C_0011059798107567739753 : 
    C_0011059798107567739753 ..> C_0015070288861779828488 : 
    C_0016893704426602730684 ..> C_0015070288861779828488 : 
    C_0011059798107567739753 <|-- C_0016893704426602730684 : 
    C_0007282521114909112944 ..> C_0015070288861779828488 : 
    C_0011059798107567739753 <|-- C_0007282521114909112944 : 
    C_0016629626733807544515 ..> C_0000562371626193405134 : 
    C_0016629626733807544515 ..> C_0011059798107567739753 : 
    C_0016629626733807544515 ..> C_0015070288861779828488 : 
    C_0009926197004451764028 ..> C_0000562371626193405134 : 
    C_0009926197004451764028 ..> C_0011059798107567739753 : 
    C_0016629626733807544515 <|-- C_0009926197004451764028 : 
    C_0006861658365665630179 ..> C_0000562371626193405134 : 
    C_0006861658365665630179 ..> C_0011059798107567739753 : 
    C_0016629626733807544515 <|-- C_0006861658365665630179 : 

%% Generated with clang-uml, version 0.6.3
%% LLVM version Homebrew clang version 22.1.8
```
<!-- UML:notification_factory:end -->

## Payment factory

<!-- UML:payment_factory:start -->

```mermaid
classDiagram
    class C_0004437079332216935028["std::unique_ptr&lt;Payment&gt;"]
    class C_0004437079332216935028 {
    }
    class C_0009760794342839288652["Payment"]
    class C_0009760794342839288652 {
        <<abstract>>
        +~Payment() [default] void
        +pay(double amount) [const] void*
    }
    class C_0002586015173330893807["UPIPayment"]
    class C_0002586015173330893807 {
        +pay(double amount) [const] void
    }
    class C_0017515195328364720074["CreditCardPayment"]
    class C_0017515195328364720074 {
        +pay(double amount) [const] void
    }
    class C_0006411282814465518445["PayPalPayment"]
    class C_0006411282814465518445 {
        +pay(double amount) [const] void
    }
    class C_0008860022231858625219["PaymentFactory"]
    class C_0008860022231858625219 {
        <<abstract>>
        +~PaymentFactory() [default] void
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;*
        +processPayment(double amount) [const] void
    }
    class C_0002891019806118480022["UPIPaymentFactory"]
    class C_0002891019806118480022 {
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;
    }
    class C_0002334204914400067972["CreditCardPaymentFactory"]
    class C_0002334204914400067972 {
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;
    }
    class C_0017142614624986324678["PayPalPaymentFactory"]
    class C_0017142614624986324678 {
        +createPayment() [const] std::unique_ptr&lt;Payment&gt;
    }
    C_0004437079332216935028 ..> C_0009760794342839288652 : 
    C_0009760794342839288652 <|-- C_0002586015173330893807 : 
    C_0009760794342839288652 <|-- C_0017515195328364720074 : 
    C_0009760794342839288652 <|-- C_0006411282814465518445 : 
    C_0008860022231858625219 ..> C_0004437079332216935028 : 
    C_0008860022231858625219 ..> C_0009760794342839288652 : 
    C_0002891019806118480022 ..> C_0004437079332216935028 : 
    C_0002891019806118480022 ..> C_0009760794342839288652 : 
    C_0008860022231858625219 <|-- C_0002891019806118480022 : 
    C_0002334204914400067972 ..> C_0004437079332216935028 : 
    C_0002334204914400067972 ..> C_0009760794342839288652 : 
    C_0008860022231858625219 <|-- C_0002334204914400067972 : 
    C_0017142614624986324678 ..> C_0004437079332216935028 : 
    C_0017142614624986324678 ..> C_0009760794342839288652 : 
    C_0008860022231858625219 <|-- C_0017142614624986324678 : 

%% Generated with clang-uml, version 0.6.3
%% LLVM version Homebrew clang version 22.1.8
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
