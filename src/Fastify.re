type server;
type logger;
type error;
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
[@bs.send] external logger: server => logger = "log";
[@bs.send] external __logError: (logger, error) => unit = "error";
[@bs.send] external __logInfo: (logger, string) => unit = "info";
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

let logError = (server: server, error: error) =>
  server->logger->__logError(error);

let logInfo = (server: server, message: string) =>
  server->logger->__logInfo(message);