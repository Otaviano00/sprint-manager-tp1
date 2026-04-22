#ifndef PROJETO_HPP_INCLUDED
#define PROJETO_HPP_INCLUDED

#include "../dominios/dominios.hpp"

//**Classe que representa um projeto de desenvolvimento de software gerenciado pelo framework scrum*/

class Projeto{
    private:
        Codigo codigo; //código no formato válido que representa o projeto
        Nome nome; // nome do projeto
        Data inicio; // começo do projeto
        Data termino; // fim do projeto
    
    public:
        Codigo getCodigo() const; // retorna o código do projeto
        bool setCodigo(const Codigo & codigo); // checa se o código é válido e então o define como código do projeto
        Nome getNome() const; // retorna o nome do projeto
        bool setNome(const Nome & nome); //checa se o nome é válido e então o define como nome do projeto
        Data getInicio() const; //retorna a data de início do projeto;
        bool setInicio(const Data & inicio); //checa se a data de início é válida e então a define como data de início do projeto
        Data getTermino() const; //retorna a data de término do projeto
        bool setTermino(const Data & termino); // checa se a data de término é válida e então a define como data de término do projeto       
} 




