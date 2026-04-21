#include <entidades/PlanoSprint.hpp>

void PlanoSprint::setCodigo(const Codigo &codigo)
{
    this->codigo = codigo;
}

Codigo PlanoSprint::getCodigo() const
{
    return codigo;
}

void PlanoSprint::setNome(const Nome &nome)
{
    this->nome = nome;
}

Nome PlanoSprint::getNome() const
{
    return nome;
}

void PlanoSprint::setDataInicio(const Data &dataInicio)
{
    this->dataInicio = dataInicio;
}

Data PlanoSprint::getDataInicio() const
{
    return dataInicio;
}

void PlanoSprint::setDataFim(const Data &dataFim)
{
    this->dataFim = dataFim;
}

Data PlanoSprint::getDataFim() const
{
    return dataFim;
}