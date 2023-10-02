# Sistema de Controle para Espaçonaves em Migração Interestelar

## Pré-requisitos

Certifique-se de que você tenha o Code::Blocks instalado em seu sistema. Se ainda não o tiver instalado, você pode baixá-lo e instalá-lo a partir do site oficial do Code::Blocks (https://www.codeblocks.org/).

## Passos para Execução

1. Abra o Code::Blocks em seu sistema.

2. No menu principal, clique em "File" (Arquivo) e selecione "Open" (Abrir).

3. Navegue até o diretório onde está localizado o arquivo "Projeto.cbp". O caminho completo deve ser algo como "Principal/Projeto/Projeto.cbp".

4. Selecione o arquivo "Projeto.cbp" e clique em "Open" (Abrir).

5. O projeto será carregado no Code::Blocks. Agora, você deve ver a estrutura do projeto no painel à esquerda.
   
6. Dentro do projeto existe um arquivo nomeado "naves.txt". É nele que você deve inserir as naves no sistema, obedecendo o seguinte formato: "id,prioridade,nomeDoPiloto,idadeDoPiloto,planetaDeOrigem,idDoPiloto"
Como por exemplo: 1,5,Adao,30,Terra,1 

7. Para compilar o código, vá até o menu "Build" (Compilar) e selecione "Build" (Compilar) ou use a tecla de atalho "F9". Isso irá compilar seu projeto.

8. Se o código compilar com sucesso, você pode executá-lo. Vá até o menu "Build" (Compilar) novamente e selecione "Run" (Executar) ou use a tecla de atalho "F10".

9.  Se em algum momento você encontrar erros ou desejar recompilar o código, vá até o menu "Build" (Compilar) e selecione "Rebuild" (Recompilar) para recompilar todo o projeto. Se desejar apenas compilar novamente, selecione "Build" (Compilar).

10. Após a execução bem-sucedida do código, você verá a saída no console do Code::Blocks.


### Obeservações

Algumas modificações foram feitas para que facilitasse para o usuário a utilização desse sistema de espaçonaves, entre elas estão:

1. O usuário só deve se preocupar poucos dados para criação de uma nave, a ideia é que se utilize apenas uma linha no arquivo "naves.txt". Dessa forma, nos preocupamos em deixar com que ele preencha os dados de idade, identificador, nome e planeta de origem apenas do piloto e não de todos os passageiros da nave. Porém, lembrando que cada nave ainda possui seu id e sua prioridade.
   
2. O número de passageiros e de recursos são gerados aleatoriamente, também para facilitar a criação das naves pelo usuário e já sabendo que teremos apenas 6 tipos de recursos distintos, de acordo com as especificações passadas em sala.
   
3. Todos os outros critérios das especificações do projeto foram seguidos, como por exemplo para cada espaçonave que entra na fila, deve-se atribuir uma nova prioridade com probabilidade de 10% e uma função que verifica se a prioridade é válida ou não.