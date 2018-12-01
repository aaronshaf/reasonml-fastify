open Fastify;
let app = createServer(~logger=true);
app->get("/", Foo.handler);
app->register(Bar.plugin);
app->listen(3000, result =>
  switch (result) {
  | ListenSuccess(_address) => () /* fastify already logs success */
  | ListenError(error) =>
    app->logError(error);
    Node.Process.exit(1);
  }
);