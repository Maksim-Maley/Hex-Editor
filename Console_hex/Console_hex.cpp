#include <iostream>
#include <fstream>
#include <cstdint>
#include <iomanip>
#include <string>
#include <sstream>
//#include <filesystem>

void ShowBytes(std::ifstream& file, std::uint64_t offset)
{
    std::uint8_t buffer[16];

    file.clear();

    file.seekg(offset);

    if (!file)
    {
        std::cout << "Cannot seek to this position\n";
        return;
    }

    file.read(
        reinterpret_cast<char*>(buffer),
        16
    );

    std::streamsize bytesRead = file.gcount();

    if (bytesRead == 0)
    {
        std::cout << "No data at this position\n";
        return;
    }

    //Offset
    std::cout
        << std::hex
        << std::setw(8)
        << std::setfill('0')
        << offset
        << "    ";

    // Hexadecimal
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
            std::cout << "   ";
        }
    }

    std::cout << "   ";

    // ASCII
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
}

void ShowHex(
    std::ifstream& file,
    std::uint64_t offset,
    int lines
)
{
    for (int line = 0; line < lines; line++)
    {
        ShowBytes(file, offset);

        offset += 16;
    }
}

std::string command;
std::ifstream file;

int main()
{
    setlocale(LC_ALL, "");
    
    while (true)
    {
        std::cout << "> ";

        std::getline(std::cin, command);

        std::stringstream ss(command);

        std::string operation;
        std::string argument;

        ss >> operation >> argument;

        if (operation == "open")
        {
            if (argument.empty())
            {
                std::cout << "Укажите имя файла\n";
                continue;
            }

            if (file.is_open())
            {
                file.close();
            }

            file.open(argument, std::ios::binary);

            if (!file)
            {
                std::cout << "Не удалось открыть файл\n";
                continue;
            }

            std::cout << "Файл открыт: " << argument << '\n';

            std::cout << "Offset      Hexadecimal                                        ASCII" << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;

            ShowHex(file, 0, 5);
        }
        else if (operation == "goto")
        {
            if (!file.is_open())
            {
                std::cout << "Сначала откройте файл\n";
                continue;
            }

            if (argument.empty())
            {
                std::cout << "Укажите offset\n";
                continue;
            }

            std::uint64_t offset =
                std::stoull(argument, nullptr, 0);

            std::cout << "Offset      Hexadecimal                                        ASCII" << std::endl;
            std::cout << "------------------------------------------------------------------------------" << std::endl;

            ShowHex(file, offset, 5);
        }
        else if (operation == "close")
        {
            if (file.is_open())
            {
                file.close();
                std::cout << "Файл закрыт\n";
            }
            else
            {
                std::cout << "Файл не открыт\n";
            }
        }
        else if (operation == "exit")
        {
            break;
        }
    }
}