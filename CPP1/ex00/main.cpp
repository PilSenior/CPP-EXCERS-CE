#include "Zombie.hpp"

int main() {
    std::cout << "--- STACK TEST (randomChump) ---" << std::endl;
    randomChump("StackZombie");     
    std::cout << std::endl;
    std::cout << "--- HEAP TEST (newZombie) ---" << std::endl;
    Zombie* heapZ = newZombie("HeapZombie");
    heapZ->announce();
    std::cout << "Deleting heap zombie manually..." << std::endl;
    delete heapZ;

    return 0;
}