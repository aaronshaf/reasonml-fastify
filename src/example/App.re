open Fastify;
let app = createServer(~logger=true);
app->get("/", Foo.handler);
app->post("/", Bar.handler);
app->listen(3000, result =>
  switch (result) {
  | Ok(_address) => ()
  | Error(error) =>
    app->logError(error);
    Node.Process.exit(1);
  }
);