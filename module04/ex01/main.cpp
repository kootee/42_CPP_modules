/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktoivola <ktoivola@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:51:37 by ktoivola          #+#    #+#             */
/*   Updated: 2024/10/30 10:39:45 by ktoivola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int numAnimals = 4;
    const Animal* animals[numAnimals];

    // Fill half the array with Dogs and half with Cats
    for (int i = 0; i < numAnimals / 2; i++)
        animals[i] = new Dog();
    for (int i = numAnimals / 2; i < numAnimals; i++)
        animals[i] = new Cat();
    
    // Add ideas
    for (int i = 0; i < numAnimals; i++) {
        if (auto dog = dynamic_cast<const Dog*>(animals[i])) {
            const_cast<Dog*>(dog)->setIdea("I'm a good boy");
            const_cast<Dog*>(dog)->setIdea("Poop is tasty");
            const_cast<Dog*>(dog)->setIdea("Is that a bird?!");
            const_cast<Dog*>(dog)->setIdea("Where's my pack?");
        } 
        else if (auto cat = dynamic_cast<const Cat*>(animals[i])) {
            const_cast<Cat*>(cat)->setIdea("What's behind the door?");
            const_cast<Cat*>(cat)->setIdea("Don't touch me");
            const_cast<Cat*>(cat)->setIdea("Can I go outside?");
            const_cast<Cat*>(cat)->setIdea("Can I come inside?");
        }
    }
    
    // Checks last animal and fills its brains with a hundred ideas
    std::cout << "Adding lots of ideas to the last animal...\n";
    if (auto dog = dynamic_cast<const Dog*>(animals[numAnimals - 1])) {
            for (int i = 0; i < 50; i++)
                const_cast<Dog*>(dog)->setIdea("Woof!");
    }
    else
        std::cout << "Not a dog, \"dog\" points to " << dog << std::endl;
    if (auto cat = dynamic_cast<const Cat*>(animals[numAnimals - 1])) {
        for (int i = 0; i < 50; i++)
            const_cast<Cat*>(cat)->setIdea("Purrrrr....");
    }
    else
        std::cout << "Not a cat, \"cat\" points to " << cat << std::endl;
    // Read mind of all animals
    std::cout << "Reading minds of all animals...\n";
    for (int i = 0; i < numAnimals; i++) {
        if (auto dog = dynamic_cast<const Dog*>(animals[i]))
            const_cast<Dog*>(dog)->readMind();
        else if (auto cat = dynamic_cast<const Cat*>(animals[i]))
            const_cast<Cat*>(cat)->readMind();
    }
    
    // Delete all elements in the array
    std::cout << "Deleting all animals in array...\n";
    for (int i = 0; i < numAnimals; i++) {
        std::cout << "Deleting animal " << i << std::endl;
        delete animals[i]; // Deletes each Dog or Cat as an Animal
    }
    
    std::cout << "A few more tests...\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;
    delete i;

    std::cout << "\n------- Testing deep copying -------" << std::endl;
    // Create an original Dog and add ideas to its Brain
    Dog originalDog;
    originalDog.setIdea("Chase the ball");
    originalDog.setIdea("Dig a hole");
    
    // Copy-assign originalDog to a newDog
    Dog newDog;
    newDog = originalDog;

    std::cout << "Ideas in originalDog's Brain before modification:\n";
    originalDog.readMind();

    std::cout << "\nIdeas in newDog's Brain (copied from originalDog):\n";
    newDog.readMind();

    // Modify ideas in originalDog to see if newDog's ideas are unaffected
    originalDog.setIdea("Chew on the slipper");

    std::cout << "\nIdeas in originalDog's Brain after modification:\n";
    originalDog.readMind();

    std::cout << "\nIdeas in newDog's Brain after originalDog's modification (should remain unchanged):\n";
    newDog.readMind();
    
    std::cout << std::endl;
    return (0);
}
