
#include <iostream> // std::cout ve std::endl kullanmak yerine printf() kullanmak yasak 
#include <cctype>  // std::toupper kullanabilmek icin 

int main (int argc, char **argv) {
    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            for(int j = 0; argv[i][j] != '\0'; j++)
            {
                   std::cout << static_cast<char>(std::toupper(argv[i][j]));
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}