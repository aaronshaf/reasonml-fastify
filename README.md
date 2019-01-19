![Logo](https://raw.githubusercontent.com/aaronshaf/reasonml-fastify/master/Reasonfastify.png)

[Fastify](https://www.fastify.io/) bindings for [BuckleScript](https://github.com/bloomberg/bucklescript) in [ReasonML](https://reasonml.github.io/) 

![](https://img.shields.io/npm/v/fastify-with-reason.svg?style=plastic) ![](https://img.shields.io/github/license/aaronshaf/reasonml-fastify.svg?style=plastic) 

## Getting Started

Create a new project:

```Shell
bsb -init server -theme basic-reason
```

Install fastify-with-reason using npm:

```Shell
yarn add fastify-with-reason
```

Then add fastify-with-reason as a dependency to `bsconfig.json`


## Example Server

Create a Server.re inside src:

```Reason
open Fastify;

let app = createServer(~logger=true);

app->get("/", (_request, reply) => reply->send("Hello, world!"));

app->listen(3000, result =>
  switch (result) {
  | Ok(_address) => ()
  | Error(error) =>
    app->logError(error);
    Node.Process.exit(1);
  }
);
```

This server simply respond with a json "Hello, world!" on localhost:3000

```Shell
yarn build
node src/Server.bs.js
```
### A little Benchmark with Autocannon

On my iMac (2,3 GHz Intel Core i5 - 8 GB 2133 MHz DDR4)

![Benchmark](https://raw.githubusercontent.com/aaronshaf/reasonml-fastify/master/Benchmark.png)

Go to [Wiki](https://github.com/aaronshaf/reasonml-fastify/wiki) for documentation (coming soon)
