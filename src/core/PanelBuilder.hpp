#ifndef PANEL_BUILDER_HPP
#define PANEL_BUILDER_HPP

#include <core/Panel.hpp>

/**
 * @brief Construtor fluente (Builder) para a classe `Panel`.
 *
 * ## Por que esta classe existe?
 *
 * `Panel` possui todos os seus atributos privados. A única forma de configurá-los
 * externamente é via `PanelBuilder`, que é declarado como `friend class` de `Panel`.
 * Essa restrição é intencional: garante que painéis só sejam criados em estados
 * consistentes (ex.: `hasTitle` nunca fica `true` sem que `title` tenha sido definido)
 * e centraliza a lógica de construção em um único lugar.
 *
 * ## Por que usar em vez de instanciar `Panel` diretamente?
 *
 * - O construtor de `Panel` é público, mas seus atributos são todos privados, tornando
 *   uma instância criada diretamente inútil — nenhum atributo pode ser configurado.
 * - `PanelBuilder` é um Singleton: a mesma instância é reutilizada para construir
 *   múltiplos painéis. Após cada chamada a `build()`, o builder reseta seu estado
 *   interno com um novo `Panel` vazio, pronto para a próxima configuração.
 * - A interface fluente (`->withX()->withY()->build()`) torna a construção de painéis
 *   legível e menos sujeita a erros de ordem de inicialização.
 *
 * ## Uso típico
 * @code
 * Panel *p = PanelBuilder::builder()
 *                ->withTitle("Menu Principal")
 *                ->withOptions(true)
 *                ->withZeroAction(true, "Sair")
 *                ->build();
 * @endcode
 *
 * @see Panel
 */
class PanelBuilder
{
private:
    /** @brief Painel em construção. Resetado para um novo `Panel` a cada `build()`. */
    Panel *panel = nullptr;

    /** @brief Instância única do builder (padrão Singleton). */
    static PanelBuilder *instance;

    PanelBuilder() : panel(new Panel()) {}

public:
    /**
     * @brief Define o título exibido no topo do painel.
     *
     * Ativa `Panel::hasTitle` e armazena o texto em `Panel::title`.
     * O título é renderizado centralizado com bordas de `=` a cada chamada de `step()`.
     *
     * @param title Texto do título.
     */
    PanelBuilder *withTitle(const std::string &title);

    /**
     * @brief Controla se a tela é limpa antes de renderizar o painel.
     *
     * Define `Panel::cleanScreen`. Quando `false`, o conteúdo anterior do terminal
     * é preservado, útil para painéis de entrada que devem ser exibidos logo abaixo
     * de conteúdo já impresso (ex.: logo do sistema).
     *
     * @param cleanScreen Padrão: `true`.
     */
    PanelBuilder *withInitialCleanScreen(bool cleanScreen = true);

    /**
     * @brief Define a função executada durante a renderização do painel.
     *
     * Ativa `Panel::hasAction` e armazena o callable em `Panel::action`.
     * A ação é chamada a cada iteração de `step()`, antes de exibir as opções.
     * Se a ação lançar uma exceção e `Panel::hasEnd` for `false`, o painel se
     * repete; se `hasEnd` for `true`, o erro é exibido e o fluxo retorna ao pai.
     *
     * @param action Função sem retorno e sem parâmetros (`std::function<void()>`).
     */
    PanelBuilder *withAction(std::function<void()> action);

    /**
     * @brief Habilita o modo de menu e, opcionalmente, pré-carrega sub-painéis.
     *
     * Define `Panel::hasOptions` e `Panel::options`. Sub-painéis também podem ser
     * adicionados individualmente após o `build()` via `Panel::addOption()`.
     *
     * @param hasOptions `true` para ativar o modo de menu com opções numeradas.
     * @param options    Lista inicial de sub-painéis filhos. Padrão: `{}` (vazia).
     */
    PanelBuilder *withOptions(bool hasOptions, std::vector<Panel *> options = {});

    /**
     * @brief Configura a opção [0] do menu.
     *
     * Define `Panel::hasZeroOption`, `Panel::zeroOptionLabel`, `Panel::zeroOptionAction`
     * e `Panel::hasZeroConfirmation`. A opção [0] é convencionalmente usada para
     * "Retornar", "Sair" ou ações destrutivas que requerem confirmação.
     * Se `action` for `nullptr`, selecionar [0] simplesmente retorna ao painel pai.
     *
     * @param hasZeroOption     `true` para exibir a opção [0]. Padrão do painel: `true`.
     * @param label             Rótulo exibido ao lado de [0]. Padrão: `"Retornar"`.
     * @param action            Função executada ao selecionar [0]. Padrão: `nullptr`.
     * @param hasZeroConfirmation `true` para exigir confirmação antes de executar `action`. Padrão: `false`.
     */
    PanelBuilder *withZeroAction(bool hasZeroOption, const std::string &label = "Retornar", std::function<void()> action = nullptr, bool hasZeroConfirmation = false);

    /**
     * @brief Define se o painel encerra o fluxo após a execução da ação.
     *
     * Quando `Panel::hasEnd` é `true`, após `action` executar com sucesso, o painel
     * exibe uma pausa ("Pressione Enter") e retorna ao pai. Em caso de erro na ação,
     * exibe a mensagem de erro e também retorna ao pai, em vez de repetir o painel.
     *
     * @param hasEnd `true` para encerrar o fluxo após a ação. Padrão do painel: `false`.
     */
    PanelBuilder *withEnd(bool hasEnd);

    /**
     * @brief Exige confirmação do usuário antes de navegar para o sub-painel escolhido.
     *
     * Define `Panel::hasConfirmation`. Aplica-se às opções numeradas [1..N];
     * para confirmação da opção [0], use o parâmetro `hasZeroConfirmation` em
     * `withZeroAction()`.
     *
     * @param hasConfirmation Padrão: `true`.
     */
    PanelBuilder *withConfirmation(bool hasConfirmation = true);

    /**
     * @brief Define uma condição de saída automática para o painel.
     *
     * Define `Panel::exitCondition`. A condição é avaliada no início de cada
     * iteração de `step()`: se retornar `true`, o painel encerra imediatamente
     * sem executar ação ou exibir opções. Útil para loops que devem terminar
     * automaticamente quando um estado externo muda (ex.: usuário faz login).
     *
     * @param condition Função predicado sem parâmetros (`std::function<bool()>`).
     */
    PanelBuilder *withExitCondition(std::function<bool()> condition);

    /**
     * @brief Retorna a instância única do `PanelBuilder` (padrão Singleton).
     *
     * Cria a instância na primeira chamada. O estado interno é automaticamente
     * resetado após cada `build()`, portanto a mesma instância pode ser reutilizada
     * para construir múltiplos painéis sequencialmente.
     */
    static PanelBuilder *builder()
    {
        if (instance == nullptr)
        {
            instance = new PanelBuilder();
        }

        return instance;
    }

    /**
     * @brief Finaliza a construção e retorna o `Panel` configurado.
     *
     * Retorna o ponteiro para o `Panel` montado e reseta o estado interno do builder
     * com um novo `Panel` vazio, deixando-o pronto para a próxima construção.
     *
     * @return Ponteiro para o `Panel` configurado. A responsabilidade de liberar
     *         a memória é do chamador.
     */
    Panel *build();
};

#endif // PANEL_BUILDER_HPP