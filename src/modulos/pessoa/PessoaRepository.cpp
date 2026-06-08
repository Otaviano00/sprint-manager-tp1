#include <string>
#include <list>
#include <cstdarg>
#include <stdexcept>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/pessoa/Pessoa.hpp>

Pessoa PessoaRepository::mapToEntity(SQLite::Statement &query)
{
    long id = query.getColumn("id").getInt();
    Pessoa pessoa(id);

    Email email;
    email.setValor(query.getColumn("email").getString());
    pessoa.setEmail(email);

    Nome nome;
    nome.setValor(query.getColumn("nome").getString());
    pessoa.setNome(nome);

    Senha senha;
    senha.setValor(query.getColumn("senha").getString());
    pessoa.setSenha(senha);

    return pessoa;
}

bool PessoaRepository::save(Pessoa &pessoa)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (email, nome, senha) VALUES (?, ?, ?)");
    query.bind(1, pessoa.getEmail().getValor());
    query.bind(2, pessoa.getNome().getValor());
    query.bind(3, pessoa.getSenha().getValor());

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(pessoa, db.getLastInsertRowid());
    }

    return rows > 0;
}