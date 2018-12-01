open Fastify;
let handler = (_request, reply) => reply->send("Baz");
let plugin = (app, _options, next) => {
  app->get("/baz", handler);
  next();
};