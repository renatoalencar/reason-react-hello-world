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
