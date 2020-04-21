type direction = [ | `Down | `Left | `Right | `Up];

module Timeout_shape = {
  type t = {
    .
    "appear": option(option(MaterialUi_Types.Number.t)),
    "enter": option(option(MaterialUi_Types.Number.t)),
    "exit": option(option(MaterialUi_Types.Number.t)),
  };
  [@bs.obj]
  external make:
    (
      ~appear: MaterialUi_Types.Number.t=?,
      ~enter: MaterialUi_Types.Number.t=?,
      ~exit: MaterialUi_Types.Number.t=?,
      unit
    ) =>
    t;
};

module Timeout: {
  type t;
  let int: int => t;
  let float: float => t;
  let shape: Timeout_shape.t => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let shape = (v: Timeout_shape.t) => Any(v);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~direction: option(
                  [@bs.string] [
                    | [@bs.as "down"] `Down
                    | [@bs.as "left"] `Left
                    | [@bs.as "right"] `Right
                    | [@bs.as "up"] `Up
                  ],
                )
                  =?,
    ~_in: option(bool)=?,
    ~onEnter: option(ReactEvent.Synthetic.t => unit)=?,
    ~onEntering: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExit: option(ReactEvent.Synthetic.t => unit)=?,
    ~onExited: option(ReactEvent.Synthetic.t => unit)=?,
    ~timeout: option(Timeout.t)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Slide";
