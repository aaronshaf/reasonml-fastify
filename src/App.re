open Fastify;
let app = createServer();
app->get("/", Foo.handler);
app->register(Bar.plugin);
app->listen(3000, (error, address) =>
  switch (error) {
  | Some(error) =>
    app->logError(error);
    Js.log(error);
    Node.Process.exit(1);
  | None => app->logInfo("server listening on " ++ address)
  }
);