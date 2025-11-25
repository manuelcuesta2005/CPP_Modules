#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n==== ARRAY TEST ====\n";
    const int size = 10;
    Animal *animals[size];

    // Half Dogs, Half Cats
    for (int i = 0; i < size; i++)
    {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Delete all
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << "\n==== DEEP COPY TEST ====\n";

    Dog original;
    original.makeSound();

    Dog copy = original; // copy constructor

    std::cout << "\nModifying original brain...\n";

    // Modify idea 0 of original brain
    original.operator=(original); // for good measure
    original.makeSound();

    std::cout << "\n==== BRAIN DEEP COPY REAL TEST ====\n";

    Dog dog1;
    dog1.makeSound();

    // Ponemos ideas en dog1
    dog1.getBrain()->setIdea(0, "I want food");
    dog1.getBrain()->setIdea(1, "I want to play");

    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog1 idea[1]: " << dog1.getBrain()->getIdea(1) << std::endl;

    // Hacer copia profunda
    Dog dog2 = dog1;

    // Mostrar ideas de dog2
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[1]: " << dog2.getBrain()->getIdea(1) << std::endl;

    // Cambiamos SOLO el dog1
    dog1.getBrain()->setIdea(0, "I want to sleep");

    // Verificar que dog2 NO cambió
    std::cout << "\nDespués de modificar dog1:\n";
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdea(0) << std::endl;

    std::cout << "\nEnd of program\n";

    return 0;
}
