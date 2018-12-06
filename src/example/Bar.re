open Fastify;
let stringifyParseError = Decode.ParseError.failureToDebugString;

let handler = (request, reply) =>
  switch (request.body->Thing.toRecord) {
  | Ok(thing) => reply->send(thing->Thing.toJs->Js.Json.stringify)
  | Error(error) => reply->send(stringifyParseError(error))
  };

let plugin = (app, _options, next) => {
  app->post("/bar", handler);
  next();
};