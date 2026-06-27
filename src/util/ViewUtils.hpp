
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#ifndef _WIN32
#define CLEAR "clear"
#else
#define CLEAR "cls"
#endif

#define IMAGE_PATH "src/util/images/"

class ViewUtils
{
public:
    static bool printTextFile(const std::string &filePath)
    {
        std::ifstream file(IMAGE_PATH + filePath);
        if (!file.is_open())
        {
            return false;
        }

        std::ostringstream buffer;
        buffer << file.rdbuf();

        std::cout << buffer.str();

        file.close();

        return true;
    }

    static void clear()
    {
        system(CLEAR);
    }

    static void waitForEnter(const std::string &message = "[Pressione Enter para prosseguir]")
    {
        std::cout << message << std::endl;
        std::string enter;
        std::getline(std::cin, enter);
    }

    static void showError(const std::string &errorMessage)
    {
        std::cout << std::endl
                  << "Erro: " << errorMessage << std::endl;
    }

    static void showErrorAndWait(
        const std::string &errorMessage,
        const std::string &enterMessage = "[Pressione Enter para tentar novamente]")
    {
        showError(errorMessage);
        waitForEnter(enterMessage);
    }

    static bool confirmAction(const std::string &message = "Tem certeza que deseja continuar? (S/n): ")
    {
        std::cout << std::endl
                  << message;
        std::string confirmation;
        std::getline(std::cin, confirmation);

        if (confirmation != "" && confirmation != "s" && confirmation != "S")
        {
            return false;
        }

        return true;
    }
};