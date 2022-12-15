#include <iostream>
#include <memory>
#include <string>

using namespace std;

// item 13

class Pigion
{
private:
    shared_ptr<string> _sound;

public:
    Pigion(shared_ptr<string> sound) : _sound(sound) {} // constructor takes ownership of the string

    void chirps() // chirps method which uses the string resource
    {
        cout << *_sound << endl;
    }
};

class Eagle
{
private:
    auto_ptr<string> _sound;

public:
    Eagle(auto_ptr<string> sound) : _sound(sound) {}

    void peeps() // peeps method which uses the string resource
    {
        cout << *_sound << endl;
    }
};

// item 14

template <typename T>
class Food
{
private:
    T *p;
    int *foodCount;

public:
    Food(T *ptr) : p(ptr), foodCount(new int(1)) {}

    // copy constructor
    Food(const Food &other) : p(other.p), foodCount(other.foodCount)
    {
        ++(*foodCount);
    }

    // assignment operator
    Food &operator=(const Food &other)
    {
        if (this != &other)
        {

            // decrement the food counter
            if (--(*foodCount) == 0)
            {
                delete p;
                delete foodCount;
            }

            p = other.p;
            foodCount = other.foodCount;

            // increment the food counter
            ++(*foodCount);
        }
        return *this;
    }

    ~Food()
    {
        if (--(*foodCount) == 0)
        {
            delete p;
            delete foodCount;
        }
    }

#pragma region getters
    T *get()
    {
        return p;
    }

    int *getFoodCount()
    {
        return foodCount;
    }
#pragma endregion
};

int main(int, char **)
{
    // create a string resource that is shared by multiple Pigion objects
    shared_ptr<string> shared_sound(new string("pruuupruuu"));

    Pigion pigion1(shared_sound);
    Pigion pigion2(shared_sound);

    pigion1.chirps();
    pigion2.chirps();

    // when these Pigion objects go out of use, the sound (string) is automatically freed

    auto_ptr<string> eagle_sound(new string("aaaaaaaa"));

    Eagle eagle1(eagle_sound);

    eagle1.peeps();

    // the string will be automatically freed

    Food<string> food1(new string("Yummy food!"));

    // created with assignment operator
    Food<string> food2 = food1;

    // created with copy constructor
    Food<string> food3(food2);

    food1 = food3;

    cout << *(food1.get()) << endl;
    cout << *(food1.getFoodCount()) << endl;

    return 0;
}
