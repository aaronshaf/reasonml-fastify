open Fastify;
let options = serverOptions(~logger=true);
let app = createServer(options);
app->get("/", Foo.handler);
app->register(Bar.plugin);
app->listen(3000, (error, _address) =>
  switch (error) {
  | Some(error) =>
    app->logError(error);
    Node.Process.exit(1);
  | None => () /* success */
  }
);