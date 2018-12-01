open Fastify;
let app = createServer();
app->get("/", Foo.handler);
app->register(Bar.plugin);
app->listen(3000, (error, address) =>
  switch (error) {
  | Some(error) =>
    app.logger.error(error);
    Node.Process.exit(1);
  | None => app.logger.info("server listening on " ++ address)
  }
);