#include <string>
#include <list>
#include <cstdarg>
#include <stdexcept>
#include <modulos/pessoa/PessoaRepository.hpp>
#include <modulos/pessoa/Pessoa.hpp>

PessoaRepository::PessoaRepository() : RepositoryBase<Pessoa>(TABLE_NAME, {{"id", "INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL"},
                                                                           {"email", "TEXT NOT NULL"},
                                                                           {"nome", "TEXT NOT NULL"},
                                                                           {"senha", "TEXT NOT NULL"},
                                                                           {"papel", "TEXT NOT NULL"}})
{
}

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

    Papel papel;
    papel.setValor(query.getColumn("papel").getString());
    pessoa.setPapel(papel);

    return pessoa;
}

bool PessoaRepository::save(Pessoa &pessoa)
{
    SQLite::Statement query(db, "INSERT INTO " + tableName + " (email, nome, senha, papel) VALUES (?, ?, ?, ?)");
    query.bind(1, pessoa.getEmail().getValor());
    query.bind(2, pessoa.getNome().getValor());
    query.bind(3, pessoa.getSenha().getValor());
    query.bind(4, pessoa.getPapel().getValor());

    int rows = query.exec();

    if (rows > 0)
    {
        setEntityId(pessoa, db.getLastInsertRowid());
    }

    return rows > 0;
}

bool PessoaRepository::update(Pessoa &pessoa)
{
    SQLite::Statement query(db, "UPDATE " + tableName + " SET email = ?, nome = ?, senha = ?, papel = ? WHERE id = ?");
    query.bind(1, pessoa.getEmail().getValor());
    query.bind(2, pessoa.getNome().getValor());
    query.bind(3, pessoa.getSenha().getValor());
    query.bind(4, pessoa.getPapel().getValor());
    query.bind(5, static_cast<int>(pessoa.getId()));

    int rows = query.exec();
    return rows > 0;
}

Pessoa *PessoaRepository::findByEmail(Email email)
{
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE email = ? LIMIT 1");
    query.bind(1, email.getValor());

    if (query.executeStep())
    {
        Pessoa pessoa = mapToEntity(query);
        return new Pessoa(pessoa);
    }

    return nullptr;
}

Pessoa *PessoaRepository::findByEmailAndSenha(Email email, Senha senha)
{
    SQLite::Statement query(db, "SELECT * FROM " + tableName + " WHERE email = ? AND senha = ?");
    query.bind(1, email.getValor());
    query.bind(2, senha.getValor());

    if (query.executeStep())
    {
        Pessoa pessoa = mapToEntity(query);
        return new Pessoa(pessoa);
    }

    return nullptr;
}