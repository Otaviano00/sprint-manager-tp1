#ifndef STRING_UTILS_HPP_INCLUDED
#define STRING_UTILS_HPP_INCLUDED

using namespace std;
#include <string>
#include <vector>

/**
 * @brief Conjunto de utilitários para manipulação e validação de caracteres e strings.
 */
class StringUtils
{
public:
    /**
     * @brief Informa se um caractere é letra.
     *
     * @param caracter Caractere a ser testado.
     * @param includeCaps Define se letras maiúsculas também são aceitas.
     * @return true quando o caractere é letra válida.
     * @return false quando o caractere não é letra válida.
     */
    static bool isChar(char caracter, bool includeCaps);

    /**
     * @brief Informa se um caractere é dígito decimal.
     *
     * @param caracter Caractere a ser testado.
     * @return true quando o caractere é dígito.
     * @return false quando o caractere não é dígito.
     */
    static bool isDigit(char caracter);

    /**
     * @brief Verifica se um caractere pertence a um conjunto de caracteres.
     *
     * @param caracter Caractere a ser buscado.
     * @param values Conjunto de caracteres válidos.
     * @return true quando o caractere está no conjunto.
     * @return false quando o caractere não está no conjunto.
     */
    static bool isIn(char caracter, string values);

    /**
     * @brief Divide uma string em partes usando um delimitador.
     *
     * @param value Texto de entrada.
     * @param delimiter Delimitador de separação.
     * @return vector<string> Lista com as partes não vazias.
     */
    static vector<string> split(const string value, const string delimiter);
};

#endif // STRING_UTILS_HPP_INCLUDED