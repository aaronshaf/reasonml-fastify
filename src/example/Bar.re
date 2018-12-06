open Fastify;

let handler = (request, reply) =>
  switch (request.body->Thing.toRecord) {
  | Ok(thing) =>
    switch (Js.Json.stringifyAny(thing->Thing.toJs)) {
    | Some(thingJson) => reply->send(thingJson)
    | None => reply->send("Error")
    }
  | Error(error) =>
    reply->send(Decode.ParseError.failureToDebugString(error))
  };

let plugin = (app, _options, next) => {
  app->post("/bar", handler);
  next();
};