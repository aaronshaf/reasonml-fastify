const fastify = require("fastify")({
  logger: true
});
const result = fastify.get("/", function(request, reply) {
  reply.send({ hello: "world" });
});
fastify.register(require("./ExamplePlugin.bs.js").plugin);
fastify.listen(3000, function(err, address) {
  if (err) {
    fastify.log.error(err);
    process.exit(1);
  }
  fastify.log.info(`server listening on ${address}`);
});
