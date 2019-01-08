open Fastify;

let handler = (_request, reply) => reply->send("Hello, world!");