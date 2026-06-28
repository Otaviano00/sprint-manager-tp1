#ifndef PANEL_HPP
#define PANEL_HPP

#include <string>
#include <vector>
#include <memory>
#include <functional>

/**
 * @brief Representa um painel de navegação interativo no terminal.
 *
 * Um painel pode exibir um título, executar uma ação e/ou apresentar uma lista
 * de sub-painéis como opções numeradas. A navegação entre painéis é gerenciada
 * internamente por `showPanel()`, que percorre a árvore de painéis conforme as
 * escolhas do usuário.
 *
 * @note Todos os atributos são privados e só podem ser configurados por meio de
 * `PanelBuilder`. Instancie painéis exclusivamente através dessa classe.
 *
 * @see PanelBuilder
 */
class Panel
{

private:
    /**
     * @brief Indica se um título foi definido e deve ser exibido ao renderizar o painel.
     * Configurado automaticamente por `PanelBuilder::withTitle()`.
     */
    bool hasTitle = false;

    /**
     * @brief Indica se uma função de ação foi atribuída e deve ser executada ao renderizar o painel.
     * Configurado automaticamente por `PanelBuilder::withAction()`.
     */
    bool hasAction = false;

    /**
     * @brief Indica se o painel possui sub-painéis filhos a serem exibidos como opções numeradas.
     * Pode ser ativado via `PanelBuilder::withOptions()` ou implicitamente por `addOption()`.
     */
    bool hasOptions = false;

    /**
     * @brief Indica se a opção [0] deve ser exibida na lista de opções.
     * Quando `true`, exibe `zeroOptionLabel` como última entrada do menu.
     * Padrão: `true`.
     */
    bool hasZeroOption = true;

    /**
     * @brief Indica se a tela deve ser limpa antes de renderizar o painel.
     * Quando `false`, o conteúdo anterior do terminal é mantido.
     * Padrão: `true`.
     */
    bool cleanScreen = true;

    /**
     * @brief Indica se o painel encerra o fluxo após a execução de `action`.
     * Quando `true`, exibe uma pausa ("Pressione Enter") e retorna ao painel pai
     * em vez de repetir o loop. Em caso de erro na `action`, também retorna ao pai
     * em vez de repetir o painel atual.
     * Padrão: `false`.
     */
    bool hasEnd = false;

    /**
     * @brief Indica se o usuário deve confirmar sua escolha antes de navegar para o sub-painel selecionado.
     * Aplica-se apenas às opções numeradas (não à opção zero).
     * Padrão: `false`.
     */
    bool hasConfirmation = false;

    /**
     * @brief Indica se o usuário deve confirmar antes de executar `zeroOptionAction`.
     * Aplica-se exclusivamente à opção [0].
     * Padrão: `false`.
     */
    bool hasZeroConfirmation = false;

    /** @brief Texto exibido centralizado no topo do painel quando `hasTitle` é `true`. */
    std::string title;

    /** @brief Rótulo exibido ao lado de [0] na lista de opções. Padrão: "Retornar". */
    std::string zeroOptionLabel = "Retornar";

    /** @brief Lista de sub-painéis filhos exibidos como opções numeradas [1..N]. */
    std::vector<Panel *> options;

    /**
     * @brief Função executada durante a renderização do painel, antes de exibir as opções.
     * Pode ser usada para exibir conteúdo, coletar entrada ou realizar operações de negócio.
     */
    std::function<void()> action = nullptr;

    /**
     * @brief Função executada quando o usuário seleciona a opção [0].
     * Se `nullptr`, a opção [0] simplesmente retorna ao painel pai.
     */
    std::function<void()> zeroOptionAction = nullptr;

    /**
     * @brief Condição avaliada no início de cada iteração do painel.
     * Se retornar `true`, o painel encerra imediatamente sem executar ação ou exibir opções.
     * Útil para sair automaticamente de loops após uma condição ser satisfeita
     * (ex.: usuário autenticado).
     */
    std::function<bool()> exitCondition = nullptr;

    /**
     * @brief Ponteiro para o painel pai na árvore de navegação.
     * Definido automaticamente por `addOption()` ao registrar este painel como filho.
     * Usado por `showPanel()` para navegar de volta quando `step()` retorna `nullptr`.
     */
    Panel *parent = nullptr;

    /** @brief Imprime no terminal as opções numeradas e a opção [0], se habilitada. */
    void showOptions();

    /**
     * @brief Lê e valida a entrada do usuário, retornando o índice da opção escolhida.
     * Lança `std::invalid_argument` para entradas não numéricas ou fora do intervalo válido.
     * Retorna -1 quando o usuário seleciona [0] e `zeroOptionAction` é `nullptr`.
     */
    int choseOption();

    /**
     * @brief Executa uma iteração do painel: limpa a tela, exibe o título, executa a ação
     * e/ou exibe as opções. Retorna o próximo painel a ser exibido, `this` para repetir
     * o painel atual (ex.: entrada inválida), ou `nullptr` para indicar que o fluxo
     * deste painel terminou.
     */
    Panel *step();

public:
    Panel() = default;

    virtual ~Panel() = default;

    /**
     * @brief Inicia o loop principal de navegação a partir deste painel.
     *
     * Chama `step()` repetidamente no painel atual. Quando `step()` retorna um
     * sub-painel filho, a navegação avança para ele. Quando retorna `nullptr`,
     * a navegação recua para o `parent`. O loop encerra quando `nullptr` é retornado
     * num painel sem pai (raiz).
     *
     * Este é o único método que deve ser chamado externamente para exibir um painel.
     */
    void showPanel();

    /**
     * @brief Adiciona um sub-painel filho à lista de opções deste painel.
     *
     * Define `option->parent` como `this` e acrescenta `option` ao vetor `options`.
     * Se `hasOptions` ainda era `false`, o habilita automaticamente.
     * As opções são exibidas em ordem de inserção, numeradas a partir de [1].
     *
     * @param option Ponteiro para o painel filho a ser adicionado.
     */
    void addOption(Panel *option);

    friend class PanelBuilder;
};

#endif // PANEL_HPP