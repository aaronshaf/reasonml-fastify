open Fastify;
let handler = (_request, reply) => send(reply, "hi");
let plugin = (app: app, _options, next): plugin => {
  get(app, "/foo", handler);
  next();
};