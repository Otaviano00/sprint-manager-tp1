#ifndef PROJETOSERVICE_HPP
#define PROJETOSERVICE_HPP

#include <modulos/projeto/IProjetoService.hpp>
#include <modulos/autenticacao/IAutenticacaoService.hpp>
#include <modulos/projeto/ProjetoRepository.hpp>

/**
 * @brief Implementa regras de negócio e operações de persistência de Projeto.
 */
class ProjetoService : public IProjetoService
{
private:
    IAutenticacaoService *autenticacao;
    ProjetoRepository *repository;

public:
    /**
     * @brief Constrói o serviço e inicializa autenticação e repositório.
     */
    ProjetoService();
    ~ProjetoService();

    /**
     * @brief Verifica autorização do papel logado para o serviço de projeto.
     * @param servico Identificador do serviço solicitado.
     * @return true quando a operação for permitida.
     */
    bool autenticarPapel(ServicoEnum servico) override;

    /**
     * @brief Cria um novo projeto.
     * @param projeto Entidade a ser persistida.
     */
    void criar(Projeto &projeto) override;

    /**
     * @brief Busca um projeto pelo identificador.
     * @param id Chave primária do projeto.
     * @return Projeto encontrado.
     */
    Projeto listarPorId(int id) override;

    /**
     * @brief Lista projetos cadastrados.
     * @return Coleção de projetos.
     */
    std::list<Projeto> listar() override;

    /**
     * @brief Atualiza dados de um projeto.
     * @param projeto Entidade com dados atualizados.
     */
    void atualizar(Projeto &projeto) override;

    /**
     * @brief Exclui um projeto pelo identificador.
     * @param id Chave primária do projeto.
     */
    void excluir(int id) override;

    /**
     * @brief Lista projetos associados a uma pessoa.
     * @param pessoa Pessoa usada como filtro.
     * @return Coleção de projetos associados.
     */
    std::list<Projeto> listarPorPessoa(Pessoa &pessoa) override;
};

#endif // PROJETOSERVICE_HPP
