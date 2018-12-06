type error;
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
type plugin = (server, unit, next) => unit
and next = unit => unit;
[@bs.send] external send: (reply, string) => unit = "";
[@bs.send] external register: (server, plugin) => unit = "";
[@bs.send] external get: (server, string, handler) => unit = "";
/* type postOptions = {. "schema": Js.Json.t}; */

[@bs.send] external __logError: (fastifyLogger, error) => unit = "error";
let logError = (server: server, error: error) =>
  __logError(server->logGet, error);

[@bs.send] external __logInfo: (fastifyLogger, string) => unit = "info";
let logInfo = (server: server, message: string) =>
  __logInfo(server->logGet, message);

[@bs.module] external __createServer: serverOptions => server = "fastify";
let createServer = (~logger: bool) => {
  let options = serverOptions(~logger);
  __createServer(options);
};

[@bs.send]
external __listen:
  (server, int, string, (Js.Nullable.t(error), string) => unit) => unit =
  "listen";
let listen = (server: server, port: int, callback) =>
  server->__listen(port, "0.0.0.0", Utils.useResult(callback));

type postRequest = {body: Js.Json.t};
type postHandler = (postRequest, reply) => unit;

let prepareHandler = (handler: postHandler, _request, reply) => {
  let request = {body: [%raw "_request"]};
  handler(request, reply);
};

[@bs.send] external __post: (server, string, postHandler) => unit = "post";
let post = (server: server, path: string, handler: postHandler) =>
  /* let options: postOptions = {"schema": schema}; */
  __post(server, path, prepareHandler(handler));