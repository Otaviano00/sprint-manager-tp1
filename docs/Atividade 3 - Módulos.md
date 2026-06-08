## Diagrama de módulos em UML

![[diagrama_modulos_tp1.png]]
### 0. Requisitos para a implementação dos módulos
- Cada módulo tem que ser feito na linguagem C++

- A interface visual será feita via linha de comando. Toda interface visual deve passar pelos padrões da classe Panel para o projeto seguir com a mesma implementação.

- A persistência dos dados ocorrerá via SQLite utilizando o wrapper SQLiteCpp. Esses códigos devem estar na camada Repository;

- Cada módulo pode contar mais que uma classe em sua composição.

- A listagem de qualquer entidade (projeto, plano de sprint, história de usuário, etc.) deve resultar na apresentação apenas do código identificador da entidade.
    
- A leitura de qualquer entidade deve resultar na apresentação completa de todos os dados da entidade.
    
- Não é permitida a edição de nenhum dado que atue como identificador da entidade (chave primária).
    
- O sistema deve assegurar todas as multiplicidades e não possibilitar que exclusões de registros resultem em inconsistências na base de dados.
### 1. Descrição dos Módulos

A arquitetura do sistema segue um modelo em camadas, dividido em Apresentação e Serviço. A nomenclatura dos módulos foi padronizada em siglas para facilitar a rastreabilidade estrutural: a letra inicial **M** indica Módulo, o núcleo (ex: **Pe**) indica a entidade (Pessoa), e o sufixo (**A** ou **S**) indica a camada (Apresentação ou Serviço).

#### 1.1 Controlador Principal

- **MVC (Módulo View Controller):** É o controlador principal da aplicação. Seu propósito é instanciar os módulos de apresentação e orquestrar a navegação de alto nível do usuário. Ele atua como o menu raiz do sistema, transferindo o controle de tela para os submódulos específicos sem conhecer as regras de negócio.

#### 1.2 Camada de Apresentação

O propósito destes módulos é gerenciar a interface com o usuário (CLI). Eles são responsáveis por exibir menus estáticos e dinâmicos, capturar as entradas do teclado, realizar a validação sintática primária (utilizando as classes de Domínio) e formatar a saída na tela. Estes módulos não acessam dados persistentes; eles apenas consomem os serviços da camada inferior.

- **MAuA (Módulo Autenticação Apresentação):** 

	- **Propósito:** Gerenciar o fluxo visual de entrada e saída do sistema. Captura credenciais e exibe mensagens de sucesso ou falha de sessão.
    
- **MPeA (Módulo Pessoa Apresentação):** 

	- **Propósito:** Prover a interface para a manipulação dos dados de usuários do sistema, listando, criando e removendo Perfis.
    
- **MPrA (Módulo Projeto Apresentação):**  

	- **Propósito:** Prover a interface para a manipulação dos dados dos Projetos geridos pelo sistema.
    
- **MPsA (Módulo Plano de Sprint Apresentação):** 

	- **Propósito:** Prover a interface para a manipulação dos dados dos Planos de Sprint gerenciados pelo sistema.
    
- **MHuA (Módulo História de Usuário Apresentação):** 

	- **Propósito:** Prover a interface para a manipulação dos dados relacionados as Histórias de Usuário.
    
#### 1.3 Camada de Serviço

O propósito genérico destes módulos é encapsular a lógica de negócio e gerenciar o armazenamento de dados. Eles implementam as regras do framework Scrum, validam as permissões de acesso baseadas no Papel do usuário logado (Proprietário de Produto, Mestre Scrum ou Desenvolvedor) e orquestram as operações de CRUD junto à infraestrutura de persistência (banco de dados SQLite).

As restrições de autenticação por Papel estão na tabela 3 mais ao final do documento.

- **MAuS (Módulo Autenticação Serviço)**
	
	- **Propósito:** Centralizar o estado da sessão atual, verificando a autenticidade das credenciais contra o banco de dados e distribuindo o papel do usuário logado.
	    
	- **Regras e Restrições de Negócio:** 
		- Para ser autenticado, o usuário deve informar obrigatoriamente o Email e a Senha correspondentes. 
			- Verificar tabela de domínios no final do documento.
		- Apenas após a autenticação validada, o usuário deve ser guardado para que possa ser recuperado em outros momentos de autenticação de Papel.
	    

- **MPeS (Módulo Pessoa Serviço)**
	
	- **Propósito:** Gerenciar o ciclo de vida da entidade Pessoa, garantindo a unicidade e integridade dos dados dos colaboradores.
	    
	- **Regras e Restrições de Negócio:** 
		- Para utilizar o sistema, cada usuário deve ter uma conta criada contendo Email, Nome, Senha e Papel no projeto. 
			- Verificar tabela de domínios no final do documento.
		- Verificar relacionamento da entidade Pessoa com as outras entidades do Diagrama Entidade Relacionamento no final do documento.
	    

- **MPrS (Módulo Projeto Serviço)**
	
	- **Propósito:** Administrar a criação e manutenção de Projetos, estabelecendo as fronteiras de escopo do sistema.
	    
	- **Regras e Restrições de Negócio:** 
		- No exato momento de criação de um projeto, o Proprietário de Produto deve obrigatoriamente associar o novo projeto a um Mestre Scrum.
			- Verificar tabela de domínios no final do documento.
		- Verificar relacionamento da entidade Projeto com as outras entidades do Diagrama Entidade Relacionamento no final do documento.
	    

- **MPsS (Módulo Plano de Sprint Serviço)**
	
	- **Propósito:** Orquestrar o planejamento de tempo e capacidade de cada ciclo ágil (Sprint).
	    
	- **Regras e Restrições de Negócio:** 
		- Ao criar um Plano de Sprint, o Mestre Scrum deve obrigatoriamente associá-lo a um projeto. 
		- Existe uma restrição de validação temporal matemática: a soma das capacidades de todos os planos de sprint de um projeto deve ser menor ou igual ao número de dias totais calculados entre as datas de início e término do respectivo projeto.
		- Verificar relacionamento da entidade Plano de Sprint com as outras entidades do Diagrama Entidade Relacionamento no final do documento.
	    

- **MHuS (Módulo História de Usuário Serviço)**
	
	- **Propósito:** Controlar os requisitos funcionais, seus estados e o esforço estimado para a entrega.
	    
	- **Regras e Restrições de Negócio:** 
		- A descrição da História de Usuário deve seguir estritamente o formato contendo o papel ("como..."), a ação ("eu quero...") e o valor ("para...").
		- Ao criar uma História de Usuário, o Proprietário de Produto deve associá-la a um projeto e o estado da história deve ser fixado como "A FAZER". Adicionalmente, existe uma restrição de dimensionamento: a soma de todas as estimativas das Histórias de Usuário associadas a um Plano de Sprint não pode ultrapassar a capacidade total daquele Plano de Sprint.
		- Verificar relacionamento da entidade Pessoa com as outras entidades do Diagrama Entidade Relacionamento no final do documento.
        

### 2. Descrição das Interfaces

Para garantir o baixo acoplamento, a comunicação entre o MVC e a Apresentação, bem como entre a Apresentação e o Serviço, é feita exclusivamente através de interfaces. Elas são classes virtuais e já existem.

#### 2.1 Interfaces de Apresentação

Consumidas pelo MVC e implementadas pelos Módulos de Apresentação. Estas interfaces declaram estritamente o contrato de execução visual de cada submódulo.

- **IAuA (Interface Autenticação Apresentação):** Declara o serviço primário de interface gráfica para inicialização de sessão (login) e encerramento (logout)
    
- **IPeA (Interface Pessoa Apresentação):** Declara o ponto de entrada para a exibição do painel de gerenciamento Pessoas.
    
- **IPrA (Interface Projeto Apresentação):** Declara o ponto de entrada para a exibição do painel de gerenciamento de Projetos.
    
- **IPsA (Interface Plano de Sprint Apresentação):** Declara o ponto de entrada para a exibição do painel de gerenciamento de Planos de Sprints.
    
- **IHuA (Interface História de Usuário Apresentação):** Declara o ponto de entrada para a exibição do painel de gerenciamento de Histórias de Usuário.
    

#### 2.2 Interfaces de Serviço

Consumidas pelos Módulos de Apresentação e implementadas pelos Módulos de Serviço. Estas interfaces declaram os contratos de negócio que mascaram as operações de banco de dados.

A autenticação para verificar se uma Pessoa pode executar uma determinada ação é presente em cada módulo de serviço e exposta aqui pelo método `autenticarPapel`. Esse mapeamento está presente na tabela 3 mais para o final do documento.

- **IAuS (Interface Autenticação Serviço):** Declara os serviços globais de validação de credenciais (`autenticarLogin`) e identificação de privilégios (`getPapel`).
    
- **IPeS (Interface Pessoa Serviço):** Declara as operações de CRUD de Pessoa e as verificações de papéis autorizados.

- **IPrS (Interface Projeto Serviço):** Declara as operações de CRUD, a consulta de projetos por colaborador e as verificações de papéis autorizados.
    
- **IPsS (Interface Plano de Sprint Serviço):** Declara as operações de CRUD, o agrupamento de Sprints por projeto pai e as verificações de papéis autorizados.
    
- **IHuS (Interface História de Usuário Serviço):** Declara as operações de CRUD, métodos de transição de estado, associação e desassociação a Pessoas/Sprints e listagens cruzadas.

### 3. Restrições de autorização
| ID     | Serviço                                                   | Entidades                                         | Papéis Permitidos                                    |
| :----- | :-------------------------------------------------------- | :------------------------------------------------ | :--------------------------------------------------- |
| **1**  | CRIAR                                                     | PESSOA                                            | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **2**  | LER                                                       | PESSOA                                            | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **3**  | ATUALIZAR                                                 | PESSOA                                            | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **4**  | EXCLUIR                                                   | PESSOA                                            | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **5**  | CRIAR                                                     | PROJETO                                           | PROPRIETÁRIO DE PRODUTO                              |
| **6**  | LER                                                       | PROJETO                                           | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **7**  | ATUALIZAR                                                 | PROJETO                                           | PROPRIETÁRIO DE PRODUTO                              |
| **8**  | EXCLUIR                                                   | PROJETO                                           | PROPRIETÁRIO DE PRODUTO                              |
| **9**  | CRIAR                                                     | PLANO DE SPRINT                                   | MESTRE SCRUM                                         |
| **10** | LER                                                       | PLANO DE SPRINT                                   | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **11** | ATUALIZAR                                                 | PLANO DE SPRINT                                   | MESTRE SCRUM                                         |
| **12** | EXCLUIR                                                   | PLANO DE SPRINT                                   | MESTRE SCRUM                                         |
| **13** | CRIAR                                                     | HISTÓRIA DE USUÁRIO                               | PROPRIETÁRIO DE PRODUTO                              |
| **14** | LER                                                       | HISTÓRIA DE USUÁRIO                               | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **15** | ATUALIZAR                                                 | HISTÓRIA DE USUÁRIO                               | PROPRIETÁRIO DE PRODUTO                              |
| **16** | EXCLUIR                                                   | HISTÓRIA DE USUÁRIO                               | PROPRIETÁRIO DE PRODUTO                              |
| **17** | ESTABELECER ASSOCIAÇÃO ENTRE HISTÓRIA DE USUÁRIO E PESSOA | HISTÓRIA DE USUÁRIO<br>PESSOA                     | MESTRE SCRUM                                         |
| **18** | REMOVER ASSOCIAÇÃO ENTRE HISTÓRIA DE USUÁRIO E PESSOA     | HISTÓRIA DE USUÁRIO<br>PESSOA                     | MESTRE SCRUM                                         |
| **19** | LISTAR PROJETOS ASSOCIADOS A PESSOA                       | PROJETO<br>PESSOA                                 | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **20** | LISTAR HISTÓRIAS DE USUÁRIO ASSOCIADAS A PROJETO          | HISTÓRIA DE USUÁRIO<br>PROJETO                    | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **21** | LISTAR PLANOS DE SPRINT ASSOCIADOS A PROJETO              | PLANO DE SPRINT<br>PROJETO                        | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **22** | LISTAR HISTÓRIAS DE USUÁRIO ASSOCIADAS A PLANO DE SPRINT  | HISTÓRIA DE USUÁRIO<br>PLANO DE SPRINT            | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **23** | LISTAR HISTÓRIAS DE USUÁRIO ASSOCIADAS A PESSOA           | HISTÓRIA DE USUÁRIO<br>PESSOA                     | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM, DESENVOLVEDOR |
| **24** | MOVER HISTÓRIA DE USUÁRIO DE PROJETO PARA PLANO DE SPRINT | HISTÓRIA DE USUÁRIO<br>PROJETO<br>PLANO DE SPRINT | MESTRE SCRUM                                         |
| **25** | ALTERAR ESTADO DE HISTÓRIA DE USUÁRIO                     | HISTÓRIA DE USUÁRIO                               | PROPRIETÁRIO DE PRODUTO, MESTRE SCRUM                |

### 3. Retrições nos domínios

| Nome           | Formato Válido                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| :------------- | :------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Código**     | 5 caracteres.<br>Sendo letras maiúsculas (A-Z) os dois primeiros caracteres.<br>Sendo dígitos (0-9) os três últimos caracteres.                                                                                                                                                                                                                                                                                                                                      |
| **Data**       | DIA/MÊS/ANO.<br>DIA é número de 1 a 31.<br>MÊS é número 01, 02, 03, 04, 05, 06, 07, 08, 09, 10, 11 ou 12.<br>ANO é número de 2000 a 2999.<br>Data deve ser válida considerando anos bissextos.                                                                                                                                                                                                                                                                       |
| **EMAIL**      | parte-local@domínio<br>Parte local pode conter letra (a-z), dígito (0-9) ou ponto(.) ou hífen (-); não pode iniciar ou terminar com ponto ou hífen; ponto ou hífen deve ser seguido por letra(s) ou dígito(s); comprimento máximo é 64 caracteres.<br>Domínio é composto por uma ou mais partes separadas por ponto (.); cada parte pode conter letra (a-z), dígito (0-9) ou hífen (-); não pode iniciar ou terminar com hífen; comprimento máximo é 255 caracteres. |
| **Estado**     | A FAZER, FAZENDO, FEITO                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Nome**       | Texto com até 10 caracteres.<br>Caracter pode ser letra maiúscula (A-Z), letra minúscula (a-z) ou espaço em branco; espaço em branco é seguido por letra; primeiro caracter não pode ser espaço em branco; último caracter não pode ser espaço em branco.                                                                                                                                                                                                            |
| **Papel**      | DESENVOLVEDOR, MESTRE SCRUM, PROPRIETARIO DE PRODUTO                                                                                                                                                                                                                                                                                                                                                                                                                 |
| **Prioridade** | ALTA, MEDIA, BAIXA                                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| **Senha**      | 6 caracteres.<br>Caracter pode ser letra (a-z ou A-Z) ou dígito (0-9); letra não pode ser seguida por letra, dígito não pode ser seguido por dígito; existe pelo menos uma letra minúscula (a-z), uma letra maiúscula (A-Z) e um dígito (0-9).                                                                                                                                                                                                                       |
| **Tempo**      | 1 a 365                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
| **Texto**      | Texto com até 40 caracteres.<br>Caracter pode ser letra (a-z ou A-Z), dígito (0-9), vírgula, ponto ou espaço em branco; vírgula não pode ser seguida por vírgula ou ponto; ponto não pode ser seguido por vírgula ou ponto; espaço em branco é seguido por letra ou dígito; primeiro e último caracter não pode ser vírgula, ponto ou espaço em branco.                                                                                                              |

### 4. Relacionamentos entre as entidades

![[Pasted image 20260608004338.png]]