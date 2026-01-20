#include "Zombie.hpp"

int main() {
    std::cout << "--- STACK TEST (randomChump) ---" << std::endl;
    randomChump("StackZombie");     
    std::cout << std::endl;

    // 2. Heap Allocation Testi
    std::cout << "--- HEAP TEST (newZombie) ---" << std::endl;
    Zombie* heapZ = newZombie("HeapZombie");
    heapZ->announce();
    
    // Heap'teki zombi kendiliğinden ölmez! 
    // Bizim onu manuel olarak silmemiz gerekir.
    std::cout << "Deleting heap zombie manually..." << std::endl;
    delete heapZ; // Destructor burada çalışır.

    return 0;
}