[@bs.deriving jsConverter]
type orientation = [
  | [@bs.as "horizontal"] `Horizontal
  | [@bs.as "vertical"] `Vertical
];

module Classes = {
  type classesType =
    | Root(string)
    | Horizontal(string)
    | Vertical(string)
    | AlternativeLabel(string)
    | Completed(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Horizontal(_) => "horizontal"
    | Vertical(_) => "vertical"
    | AlternativeLabel(_) => "alternativeLabel"
    | Completed(_) => "completed";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Horizontal(className)
                         | Vertical(className)
                         | AlternativeLabel(className)
                         | Completed(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~active: bool=?,
    ~alternativeLabel: bool=?,
    ~children: 'children=?,
    ~className: string=?,
    ~completed: bool=?,
    ~connector: React.element=?,
    ~disabled: bool=?,
    ~index: 'number_9=?,
    ~last: bool=?,
    ~orientation: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core"]
external reactComponent: React.component('a) = "Step";

[@react.component]
let make =
    (
      ~active: option(bool)=?,
      ~alternativeLabel: option(bool)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~completed: option(bool)=?,
      ~connector: option(React.element)=?,
      ~disabled: option(bool)=?,
      ~index: option([ | `Int(int) | `Float(float)])=?,
      ~last: option(bool)=?,
      ~orientation: option(orientation)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
    ) =>
  React.createElement(
    reactComponent,
    makePropsMui(
      ~active?,
      ~alternativeLabel?,
      ~children?,
      ~className?,
      ~completed?,
      ~connector?,
      ~disabled?,
      ~index=?
        index->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
      ~last?,
      ~orientation=?orientation->(Belt.Option.map(v => orientationToJs(v))),
      ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
      ~style?,
      (),
    ),
  );
