type error;
type listenResponse =
  | ListenSuccess(string)
  | ListenError(error);
[@bs.deriving abstract]
type fastifyLogger = {
  info: string => unit,
  error: error => unit,
};
[@bs.deriving abstract]
type server = {log: fastifyLogger};
[@bs.deriving abstract]
type serverOptions = {logger: bool};
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
[@bs.send] external __logError: (fastifyLogger, error) => unit = "error";
[@bs.send] external __logInfo: (fastifyLogger, string) => unit = "info";
[@bs.send] external register: (server, plugin) => unit = "";
[@bs.send] external get: (server, string, handler) => unit = "";
[@bs.send]
external __listen:
  (server, int, (Js.Nullable.t(error), string) => unit) => unit =
  "listen";
[@bs.module] external __createServer: serverOptions => server = "fastify";

let logError = (server: server, error: error) =>
  __logError(server->logGet, error);

let logInfo = (server: server, message: string) =>
  __logInfo(server->logGet, message);

let createServer = (~logger: bool) => {
  let options = serverOptions(~logger);
  __createServer(options);
};

let listen = (server: server, port: int, callback) =>
  server->__listen(
    port,
    (error, address) => {
      let result =
        switch (Js.Nullable.toOption(error)) {
        | Some(error) => ListenError(error)
        | None => ListenSuccess(address)
        };
      callback(result);
    },
  );