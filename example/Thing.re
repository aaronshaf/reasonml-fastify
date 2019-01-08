module D = Decode.AsResult.OfParseError;

type t = {
  foo: string,
  bar: string,
};

let make = (foo, bar) => {foo, bar};

let toRecord = jsObj =>
  D.Pipeline.(
    succeed(make)
    |> field("foo", D.string)
    |> field("bar", D.string)
    |> run(jsObj)
  );

let toJs = (thing: t) => {
  open Js.Dict;
  let dict = empty();
  set(dict, "foo", Js.Json.string(thing.foo));
  set(dict, "bar", Js.Json.string(thing.bar));
  Js.Json.object_(dict);
};