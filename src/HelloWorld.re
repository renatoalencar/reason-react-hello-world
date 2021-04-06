type greet =
  | Person(string)
  | None;

let hello = greeting => {
  Js.log(
    "Hello "
    ++ (
      switch (greeting) {
      | Person(name) => name
      | None => "world"
      }
    ),
  );
};
