open Fastify;
let handler = (_request, reply) => reply->send("Bar.");
let plugin = (app: server, _options, next) => {
  app->get("/", handler);
  next();
};