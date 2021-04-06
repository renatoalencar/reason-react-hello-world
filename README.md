# ReasonML

Quero mostrar pra vocês hoje algo que eu venho estudando nos últimos dias,
e que tá bem ligado com a nossa stack. Então resolvi compartilhar e ver se
vocês animam alguma apresentação mais completa sobre o assunto.

## O que é Reason?

Reason é uma linguagem de programação funcional, construída a partir do
sistema de tipos extremamente poderoso do OCaml e com uma sintaxe feita
pra agradar quem vem de linguagens C-like com JavaScript, Java e C#.

Um hello world simples em Reason é quase igual ao JS:

```reason
Js.log("Hello world");
```

Ou como uma função

```reason
let hello = () => {
  Js.log("Hello world");
}

hello()
```

## Características que tornam Reason topzera

**Tipagem cabulosa**

O sistema de tipos é muito bom, tenta validar não só os tipos em si mas
todas as possibilidades possíveis. Se você tá fazendo um switch com pattern
matching o Reason te faz cobrir todas as possibilidades o que evita muitos bugs.

**Imutabilidade**

Além da tipagem, as estruturas de dados também são imutáveis. Você nunca altera
um valor diretamente sempre cria um novo, e isso é feito da mesma forma que no
JavaScript, **só que mais performático!**

**Pattern matching**

Pattern matching é uma feature muito legal de várias linguagens, mas que não
existe no Javascript. Ao invés de escrever um monte de ifs ou um switch case gigante
da pra fazer pattern matching, e o Reason valida se você está realmente cobrindo
todos os casos possíveis.

```reason
let greet = Person(string) | None;

let hello = (greeting) => {
  switch (greeting) {
    | Person(name) => Js.log("Hello " ++ name)
    | None => Js.log("Hello world")
  };
}

hello(Person("John"));
```

**Nomes de arquivo não importam**

Ao criar um arquivo `Greeting.re` por exemplo, você cria um namespace `Greeting`
global que pode ser acessado por qualquer arquivo, o que te força a ser mais específico
nos nomes e ajuda quando for necessário reorganizar uma quantidade muito grande de
arquivos em uma estrutura que faça mais sentido.

## Componentes React

Agora da pra juntar tudo isso, com as funcionalidades funcionais do React, mais
o sistema de tipagem incrível e criar componentes React absurdamente a prova de
balas:

```reason
// Greeting.re
type greet =
  | Person(string)
  | None;

[@react.component]
let make = (~greeting) =>
  <p>
    {React.string(
       "Hello "
       ++ (
         switch (greeting) {
         | Person(name) => name
         | None => ""
         }
       ),
     )}
  </p>;

```

```reason
// Index.re
switch (ReactDOM.querySelector("#root")) {
| Some(root) =>
  ReactDOM.render(<Greeting greeting={Greeting.Person("John")} />, root)
| None => ()
};
```
