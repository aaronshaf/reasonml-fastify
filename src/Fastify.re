type error;
type logger = {
  info: string => unit,
  error: error => unit,
};
type server = {logger};
type serverOptions;
type request;
type reply;
type handler = (request, reply) => unit;
type schema =
  | None
  | Some(string);
type options = {schema};
type next = unit => unit;
type plugin = (server, unit, next) => unit;
[@bs.send] external send: (reply, string) => unit = "";
[@bs.send] external register: (server, plugin) => unit = "";
[@bs.send] external get: (server, string, handler) => unit = "";
[@bs.send]
external __listen:
  (server, int, (Js.Nullable.t(error), string) => unit) => unit =
  "listen";
[@bs.module] external createServer: unit => server = "fastify";

let listen = (server: server, port: int, callback) =>
  server->__listen(port, (error, address) =>
    callback(Js.Nullable.toOption(error), address)
  );