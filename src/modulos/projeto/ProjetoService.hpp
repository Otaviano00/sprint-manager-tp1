#ifndef PROJETOSERVICE_HPP
#define PROJETOSERVICE_HPP

#include <modulos/projeto/IProjetoService.hpp>
#include <modulos/autenticacao/IAutenticacaoService.hpp>
#include <modulos/projeto/ProjetoRepository.hpp>

/**
 * @brief Implementa regras de negócio e operações de persistência de Projeto.
 *
 * Responsável por orquestrar a criação, leitura, atualização e exclusão de projetos,
 * garantindo que as operações respeitem as regras de negócio e as restrições de
 * autorização baseadas no papel do usuário autenticado.
 */
class ProjetoService : public IProjetoService
{
private:
    IAutenticacaoService *autenticacao; /**< Serviço de autenticação para verificar papel. */
    ProjetoRepository *repository;      /**< Repositório para persistência de Projeto. */

public:
    /**
     * @brief Constrói o serviço e inicializa autenticação e repositório.
     */
    ProjetoService();

    /**
     * @brief Verifica autorização do papel logado para o serviço de projeto.
     * 
     * Define as permissões por papel:
     * - Criar, Atualizar, Excluir: Proprietário de Produto
     * - Ler e Listar: Todos os papéis
     * 
     * @param servico Identificador do serviço solicitado.
     * @return true quando a operação for permitida para o papel do usuário logado.
     * @throws std::invalid_argument quando o serviço é desconhecido.
     */
    bool autenticarPapel(ServicoEnum servico) override;

    /**
     * @brief Cria um novo projeto no banco de dados.
     * 
     * Persiste um projeto contendo código, nome, data de início e data de término.
     * 
     * @param projeto Entidade Projeto a ser persistida com dados validados.
     * @throws std::runtime_error em caso de erro na persistência.
     */
    void criar(Projeto &projeto) override;

    /**
     * @brief Busca um projeto pelo identificador no banco de dados.
     * 
     * @param id Chave primária do projeto.
     * @return Projeto encontrado.
     * @throws std::invalid_argument quando o projeto não é encontrado.
     */
    Projeto listarPorId(int id) override;

    /**
     * @brief Lista todos os projetos cadastrados no banco de dados.
     * 
     * @return Coleção de projetos cadastrados.
     */
    std::list<Projeto> listar() override;

    /**
     * @brief Atualiza dados de um projeto existente.
     * 
     * Permite atualizar nome e datas de um projeto.
     * Não é permitida a alteração do código (chave primária).
     * 
     * @param projeto Entidade com dados atualizados.
     * @throws std::runtime_error quando o projeto não é encontrado ou erro na atualização.
     */
    void atualizar(Projeto &projeto) override;

    /**
     * @brief Exclui um projeto pelo identificador.
     * 
     * Remove completamente o projeto do banco de dados.
     * 
     * @param id Chave primária do projeto.
     * @throws std::runtime_error quando o projeto não é encontrado ou erro na exclusão.
     */
    void excluir(int id) override;

    /**
     * @brief Lista projetos associados a uma pessoa (Mestre Scrum).
     * 
     * @param pessoa Pessoa usada como filtro.
     * @return Coleção de projetos associados à pessoa.
     */
    std::list<Projeto> listarPorPessoa(Pessoa &pessoa) override;
};

#endif // PROJETOSERVICE_HPP
