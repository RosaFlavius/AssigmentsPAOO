#include <iostream>
using namespace std;

class Plane
{
private:
    string engineType;
    string typeOfFuel;
    int enginePower;

public:
    Plane(string engineType, string typeOfFuel, int enginePower) : engineType(engineType),
                                                                   typeOfFuel(typeOfFuel),
                                                                   enginePower(enginePower) {}

    Plane(const Plane &rhs)
    {
        this->engineType = rhs.engineType;
        this->typeOfFuel = rhs.typeOfFuel;
        this->enginePower = rhs.enginePower;
    }

    Plane &operator=(const Plane &rhs)
    {
        if (this != &rhs)
        {
            this->engineType = rhs.engineType;
            this->typeOfFuel = rhs.typeOfFuel;
            this->enginePower = rhs.enginePower;
        }
        return *this;
    }

    void toString()
    {
        cout << "Plane with engine " << engineType << " consume " << typeOfFuel << " type of fuel and has " << enginePower << "hp." << '\n';
    }
};

class MilitaryPlane : Plane
{
private:
    int nrOfWeapons;

public:
    MilitaryPlane(string engineType, string typeOfFuel, int enginePower, int nrOfWeapons) : Plane(engineType, typeOfFuel, enginePower),
                                                                                            nrOfWeapons(nrOfWeapons) {}

    MilitaryPlane(const MilitaryPlane &rhs) : Plane(rhs),
                                              nrOfWeapons(rhs.nrOfWeapons) {}

    MilitaryPlane &operator=(const MilitaryPlane &rhs)
    {
        if (this != &rhs)
        {
            Plane::operator=(rhs);
            nrOfWeapons = rhs.nrOfWeapons;
        }
        return *this;
    }

    void toString()
    {

        Plane::toString();
        cout << "This military plane also has " << nrOfWeapons << " wapons" << '\n'
             << '\n';
    }
};

int main()
{
    Plane plane1 = Plane("reciprocating", "kerosen", 600);
    plane1.toString();

    MilitaryPlane militaryPlane1 = MilitaryPlane("jet", "jet fuel", 400, 4);
    militaryPlane1.toString();

    MilitaryPlane copyMilitaryPlane = MilitaryPlane(militaryPlane1);
    copyMilitaryPlane.toString();

    MilitaryPlane copyMilitaryPlaneOperator = copyMilitaryPlane;
    copyMilitaryPlaneOperator.toString();

    return 0;
}