#include <iostream>
#include <fstream>
#include <cstdint>
#include <iomanip>
#include <string>
//#include <filesystem>


int main()
{
    setlocale(LC_ALL, "");

    std::string filename;

    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    std::ifstream file(
        filename,
        std::ios::binary
    );

    if (!file)
    {
        std::cout << "Cannot open file\n";
        return 1;
    }

    std::uint8_t buffer[16];
    std::uint64_t offset = 0;

    std::cout << "Offset      Hexadecimal                                     ASCII" << std::endl;
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    
    while (true)
    {
        file.read(
            reinterpret_cast<char*>(buffer),
            16
        );

        std::streamsize bytesRead = file.gcount();

        if (bytesRead == 0)
        {
            break;
        }

        //Offset
        std::cout
            << std::hex
            << std::setw(8)
            << std::setfill('0')
            << offset
            << "    ";

        //Hexadecimal
        for (int i = 0; i < 16; i++)
        {
            if (i < bytesRead)
            {
                std::cout
                    << std::hex
                    << std::setw(2)
                    << std::setfill('0')
                    << static_cast<int>(buffer[i])
                    << ' ';
            }
            else
            {
                std::cout << "** ";
            }
            
        }

        //ASCII
        for (int i = 0; i < bytesRead; i++)
        {
            if (buffer[i] >= 32 && buffer[i] <= 126)
            {
                std::cout << static_cast<char>(buffer[i]);
            }
            else
            {
                std::cout << '.';
            }
        }

        std::cout << '\n';

        offset += bytesRead;
    }
}