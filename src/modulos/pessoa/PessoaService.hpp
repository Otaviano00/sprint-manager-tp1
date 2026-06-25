#ifndef PESSOASERVICE_HPP
#define PESSOASERVICE_HPP

#include <modulos/pessoa/IPessoaService.hpp>
#include <modulos/autenticacao/IAutenticacaoService.hpp>
#include <modulos/pessoa/PessoaRepository.hpp>

/**
 * @brief Implementa regras de negócio e operações de persistência de Pessoa.
 */
class PessoaService : public IPessoaService
{
private:
    IAutenticacaoService *autenticacao;
    PessoaRepository *repository;

public:
    /**
     * @brief Constrói o serviço e inicializa autenticação e repositório.
     */
    PessoaService();

    /**
     * @brief Destrói o serviço e libera o repositório.
     */
    ~PessoaService();

    /**
     * @brief Verifica autorização do papel logado para o serviço de pessoa.
     * @param servico Identificador do serviço solicitado.
     * @return true quando a operação for permitida.
     */
    bool autenticarPapel(ServicoEnum servico) override;

    /**
     * @brief Cria uma nova pessoa.
     * @param pessoa Entidade a ser persistida.
     */
    void criar(Pessoa &pessoa) override;

    /**
     * @brief Busca uma pessoa pelo identificador.
     * @param id Chave primária da pessoa.
     * @return Pessoa encontrada.
     */
    Pessoa listarPorId(int id) override;

    /**
     * @brief Lista pessoas cadastradas.
     * @return Coleção de pessoas.
     */
    std::list<Pessoa> listar() override;

    /**
     * @brief Atualiza dados de uma pessoa.
     * @param pessoa Entidade com dados atualizados.
     */
    void atualizar(Pessoa &pessoa) override;

    /**
     * @brief Exclui uma pessoa pelo identificador.
     * @param id Chave primária da pessoa.
     */
    void excluir(int id) override;
};

#endif // PESSOASERVICE_HPP
