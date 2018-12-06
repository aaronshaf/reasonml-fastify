let useResult = (callback, error, data) => {
  let result =
    switch (Js.Nullable.toOption(error)) {
    | Some(error) => Belt.Result.Error(error)
    | None => Belt.Result.Ok(data)
    };
  callback(result);
};