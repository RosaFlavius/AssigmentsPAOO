#include <iostream>
using namespace std;

class Engine
{
private:
    int horsePower;

public:
    Engine(int horsePower) : horsePower(horsePower) {}
    static Engine *getEngine(int horsePower)
    {
        return new Engine(horsePower);
    }
    void toString()
    {
        cout << horsePower << " hp" << '\n';
    }
};

class Plane
{
private:
    string typeOfPlane;
    string typeOfFuel;
    string enginePower;
    Engine *engine;

public:
    Plane(string typeOfPlane, string typeOfFuel, int enginePower) : typeOfPlane(typeOfPlane),
                                                                    typeOfFuel(typeOfFuel)
    {
        this->engine = Engine::getEngine(enginePower);
    }
    ~Plane()
    {
        delete engine;
    }
    void toString()
    {
        cout << typeOfPlane << " plane consume " << typeOfFuel << " type of fuel and has ";
        this->engine->toString();
        cout << '\n';
    }
};

class Uncopyable
{
protected:           // allow construction
    Uncopyable() {}  // and destruction of
    ~Uncopyable() {} // derived objects...
private:
    Uncopyable(const Uncopyable &); // ...but prevent copying
    Uncopyable &operator=(const Uncopyable &);
};

class Pilot : private Uncopyable
{
private:
    string name;
    int yearsOfExperience;

public:
    Pilot(string name, int yearsOfExperience) : name(name),
                                                yearsOfExperience(yearsOfExperience) {}
    void toString()
    {
        cout << "The pilot called " << name << " has " << yearsOfExperience << " years of experience" << '\n';
    }
};

int main()
{

    Engine engine(125);
    engine.toString();

    Plane plane1("Military", "Jet fuel", 400);
    plane1.toString();

    Plane copyPlane1("Vacation", "Kerosen", 600);
    copyPlane1 = plane1;
    copyPlane1.toString();

    Plane copyPlane2(copyPlane1);
    copyPlane2.toString();

    Plane plane2("Cargo", "Kerosen", 500);
    plane2.toString();

    Pilot pilot("Rosa Flavius", 20);
    pilot.toString();
    // Pilot copyPilot(pilot);

    return 0;
}