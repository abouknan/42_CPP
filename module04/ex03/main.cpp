#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== Additional Tests ===" << std::endl;

    // Test 1: Test unequip and floor handling
    std::cout << "\n--- Test 1: Unequip and floor handling ---" << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    
    ICharacter* player = new Character("player");
    AMateria* ice = src2->createMateria("ice");
    AMateria* cure = src2->createMateria("cure");
    
    player->equip(ice);
    player->equip(cure);
    
    // Save addresses before unequipping to prevent memory leaks
    AMateria* floor[2];
    floor[0] = ice;
    floor[1] = cure;
    
    player->unequip(0);
    player->unequip(1);
    
    // Clean up floor
    delete floor[0];
    delete floor[1];
    
    delete player;
    delete src2;

    // Test 2: Full inventory
    std::cout << "\n--- Test 2: Full inventory (4 slots) ---" << std::endl;
    IMateriaSource* src3 = new MateriaSource();
    src3->learnMateria(new Ice());
    src3->learnMateria(new Cure());
    
    ICharacter* wizard = new Character("wizard");
    ICharacter* target = new Character("target");
    
    for (int i = 0; i < 5; i++) // Try to add 5 materias (only 4 will fit)
    {
        AMateria* mat = src3->createMateria(i % 2 == 0 ? "ice" : "cure");
        wizard->equip(mat);
    }
    
    // Use all 4 equipped materias
    for (int i = 0; i < 4; i++)
        wizard->use(i, *target);
    
    delete wizard;
    delete target;
    delete src3;

    // Test 3: Deep copy of Character
    std::cout << "\n--- Test 3: Deep copy of Character ---" << std::endl;
    IMateriaSource* src4 = new MateriaSource();
    src4->learnMateria(new Ice());
    src4->learnMateria(new Cure());
    
    Character* original = new Character("original");
    AMateria* mat1 = src4->createMateria("ice");
    AMateria* mat2 = src4->createMateria("cure");
    original->equip(mat1);
    original->equip(mat2);
    
    Character* copy = new Character(*original);
    ICharacter* dummy = new Character("dummy");
    
    std::cout << "Original uses materias:" << std::endl;
    original->use(0, *dummy);
    original->use(1, *dummy);
    
    std::cout << "Copy uses materias:" << std::endl;
    copy->use(0, *dummy);
    copy->use(1, *dummy);
    
    delete original;
    delete copy;
    delete dummy;
    delete src4;

    // Test 4: Unknown materia type
    std::cout << "\n--- Test 4: Unknown materia type ---" << std::endl;
    IMateriaSource* src5 = new MateriaSource();
    src5->learnMateria(new Ice());
    
    AMateria* unknown = src5->createMateria("fire"); // Unknown type
    if (!unknown)
        std::cout << "Unknown materia type returned NULL (correct)" << std::endl;
    
    delete src5;

    // Test 5: Using invalid inventory slots
    std::cout << "\n--- Test 5: Invalid inventory operations ---" << std::endl;
    ICharacter* testChar = new Character("test");
    ICharacter* testTarget = new Character("target");
    
    testChar->use(-1, *testTarget);  // Invalid index
    testChar->use(4, *testTarget);   // Out of bounds
    testChar->use(0, *testTarget);   // Empty slot
    
    testChar->unequip(-1);  // Invalid index
    testChar->unequip(4);   // Out of bounds
    
    delete testChar;
    delete testTarget;

    std::cout << "\n=== All tests completed ===" << std::endl;

    return 0;
}
