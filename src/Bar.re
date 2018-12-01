open Fastify;
let handler = (_request, reply) => reply->send("Bar");
let plugin = (app, _options, next) => {
  app->get("/bar", handler);
  next();
};