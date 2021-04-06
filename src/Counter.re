[@react.component]
let make = (~name) => {
  let (count, setCount) = React.useState(() => 0);

  <div>
    <p>
      {React.string(
         name ++ " clicked " ++ Belt.Int.toString(count) ++ " times",
       )}
    </p>
    <button onClick={_ => setCount(_ => count + 1)}>
      {React.string("Click me")}
    </button>
  </div>;
};
