// A house can have:
// - Number of floors (required)
// - Number of bedrooms (required)
// - Garage (optional)
// - Swimming pool (optional)
// - Garden (optional)
// - Roof type (optional)
// Requirements:
// 1. Create a House class.
// 2. Create a HouseBuilder class.
// 3. Provide separate setter methods.
// 4. Support method chaining.
// 5. Implement build() to return a House.
// 6. Validate required properties.
// 7. Give sensible defaults to optional properties.

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class House {
private:
    int floors;
    int bedrooms;
    int garage;
    int swimmingPool;
    int garden;
    string roofType;
public:
    House(int floors, int bedrooms, int garage, int swimmingPool, int garden, string roofType){
        this->floors = floors;
        this->bedrooms = bedrooms;
        this->garage = garage;
        this->swimmingPool = swimmingPool;
        this->garden = garden;
        this->roofType = roofType;
    }

    void displayDetails(){
        cout << "House Details:" << endl;
        cout << "Floors: " << floors << endl;
        cout << "Bedrooms: " << bedrooms << endl;
        cout << "Garage: " << garage << endl;
        cout << "Swimming Pool: " << swimmingPool << endl;
        cout << "Garden: " << garden << endl;
        cout << "Roof Type: " << roofType << endl;
    }
};

class HouseBuilder {
private:
    int floors = 0;
    int bedrooms = 0;
    int garage = 0;
    int swimmingPool = 0;
    int garden = 0;
    string roofType = "Flat";
public:
    HouseBuilder& setFloors(int floors){
        this->floors = floors;
        return *this;
    }

    HouseBuilder& setBedrooms(int bedrooms){
        this->bedrooms = bedrooms;
        return *this;
    }

    HouseBuilder& setGarage(int garage){
        this->garage = garage;
        return *this;
    }

    HouseBuilder& setSwimmingPool(int swimmingPool){
        this->swimmingPool = swimmingPool;
        return *this;
    }

    HouseBuilder& setGarden(int garden){
        this->garden = garden;
        return *this;
    }

    HouseBuilder& setRoofType(string roofType){
        this->roofType = roofType;
        return *this;
    }

    House build(){
        if(floors <= 0 || bedrooms <= 0){
            throw invalid_argument("Floors and Bedrooms must be greater than 0");
        }
        return House(floors, bedrooms, garage, swimmingPool, garden, roofType);
    }
};

class HouseDirector {
public:
    House constructSimpleHouse(HouseBuilder& builder){
        return builder.setFloors(1)
                      .setBedrooms(2)
                      .build();
    }

    House constructLuxuryHouse(HouseBuilder& builder){
        return builder.setFloors(2)
                      .setBedrooms(4)
                      .setGarage(2)
                      .setSwimmingPool(1)
                      .setGarden(1)
                      .setRoofType("Gabled")
                      .build();
    }
};

int main(){
    House house1 = HouseBuilder().setFloors(2)
                        .setBedrooms(3)
                        .setGarage(1)
                        .setSwimmingPool(1)
                        .setGarden(1)
                        .setRoofType("Gabled")
                        .build();
    house1.displayDetails();

    House house2 = HouseBuilder().setFloors(1)
                        .setBedrooms(2)
                        .build();
    house2.displayDetails();

    HouseBuilder builder;
    House house3 = HouseDirector().constructLuxuryHouse(builder);
    house3.displayDetails();
}