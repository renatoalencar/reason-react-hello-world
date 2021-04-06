[@react.component]
let make = () => {
  let name = "John";
  let greet = Greeting.Person(name);

  <div> <Greeting greeting=greet /> <Counter name /> </div>;
};
