/**
 * @file  main.cpp
 * @brief A few short examples in a row.
 *
 *  Demonstrates how-to use the SQLite++ wrapper
 *
 * Copyright (c) 2012-2020 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <unistd.h>

#include <SQLiteCpp/SQLiteCpp.h>

#ifdef SQLITECPP_ENABLE_ASSERT_HANDLER
namespace SQLite
{
    /// definition of the assertion handler enabled when SQLITECPP_ENABLE_ASSERT_HANDLER is defined in the project (CMakeList.txt)
    void assertion_failed(const char *apFile, const long apLine, const char *apFunc, const char *apExpr, const char *apMsg)
    {
        // Print a message to the standard error output stream, and abort the program.
        std::cerr << apFile << ":" << apLine << ":" << " error: assertion failed (" << apExpr << ") in " << apFunc << "() with message \"" << apMsg << "\"\n";
        std::abort();
    }
}
#endif

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <SQLiteCpp/SQLiteCpp.h>

#include <entidades/Pessoa.hpp>
#include <repository/PessoaRepository.hpp>

int main()
{
    std::cout << "=== Testando o RepositoryBase e PessoaRepository ===" << std::endl;

    try
    {
        // Instancia classe de persistência de entidade Pessoa
        // Cria tabela "pessoa" uma única vez e com as configurações setadas na classe.
        PessoaRepository repo;

        // Instancia entidade Pessoa. Não há id atrelado ainda
        Pessoa novaPessoa;

        Email email;
        email.setValor("te@ste.com");
        novaPessoa.setEmail(email);

        Nome nome;
        nome.setValor("Joao");
        novaPessoa.setNome(nome);

        Senha senha;
        senha.setValor("A1b2C3");
        novaPessoa.setSenha(senha);

        // Salva a instancia de Pessoa no banco de dados. Atrela novo ID no ssave
        if (repo.save(novaPessoa))
        {
            std::cout << "Nova pessoa salva com sucesso no banco de dados, com ID gerado = " << novaPessoa.getId() << std::endl;
        }

        std::cout << "\nLista de pessoas no banco de dados:" << std::endl;
        std::vector<Pessoa> pessoas = repo.findAll();
        for (const Pessoa &p : pessoas)
        {
            std::cout << "- [" << p.getEmail().getValor() << "] "
                      << p.getNome().getValor() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "Exceção do SQLite: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "tudo ok!\n";
    return EXIT_SUCCESS;
}
