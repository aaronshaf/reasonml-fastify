type app;
type request;
type reply;
type handler = (request, reply) => unit;
type schema =
  | None
  | Some(string);
type options = {schema};
type next = unit => unit;
type plugin = (app, unit, next) => unit;
[@bs.send] external send: (reply, string) => unit = "";
[@bs.send] external get: (app, string, handler) => unit = "";