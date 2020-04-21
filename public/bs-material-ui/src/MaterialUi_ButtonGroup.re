module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "contained": option(option(string)),
    "disabled": option(option(string)),
    "fullWidth": option(option(string)),
    "vertical": option(option(string)),
    "grouped": option(option(string)),
    "groupedHorizontal": option(option(string)),
    "groupedVertical": option(option(string)),
    "groupedText": option(option(string)),
    "groupedTextHorizontal": option(option(string)),
    "groupedTextVertical": option(option(string)),
    "groupedTextPrimary": option(option(string)),
    "groupedTextSecondary": option(option(string)),
    "groupedOutlined": option(option(string)),
    "groupedOutlinedHorizontal": option(option(string)),
    "groupedOutlinedVertical": option(option(string)),
    "groupedOutlinedPrimary": option(option(string)),
    "groupedOutlinedSecondary": option(option(string)),
    "groupedContained": option(option(string)),
    "groupedContainedHorizontal": option(option(string)),
    "groupedContainedVertical": option(option(string)),
    "groupedContainedPrimary": option(option(string)),
    "groupedContainedSecondary": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~contained: string=?,
      ~disabled: string=?,
      ~fullWidth: string=?,
      ~vertical: string=?,
      ~grouped: string=?,
      ~groupedHorizontal: string=?,
      ~groupedVertical: string=?,
      ~groupedText: string=?,
      ~groupedTextHorizontal: string=?,
      ~groupedTextVertical: string=?,
      ~groupedTextPrimary: string=?,
      ~groupedTextSecondary: string=?,
      ~groupedOutlined: string=?,
      ~groupedOutlinedHorizontal: string=?,
      ~groupedOutlinedVertical: string=?,
      ~groupedOutlinedPrimary: string=?,
      ~groupedOutlinedSecondary: string=?,
      ~groupedContained: string=?,
      ~groupedContainedHorizontal: string=?,
      ~groupedContainedVertical: string=?,
      ~groupedContainedPrimary: string=?,
      ~groupedContainedSecondary: string=?,
      unit
    ) =>
    t;
};

type color = [ | `Default | `Inherit | `Primary | `Secondary];

module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

type orientation = [ | `Vertical | `Horizontal];

type size = [ | `Small | `Medium | `Large];

type variant = [ | `Text | `Outlined | `Contained];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "default"] `Default
                | [@bs.as "inherit"] `Inherit
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~component: option(Component.t)=?,
    ~disabled: option(bool)=?,
    ~disableFocusRipple: option(bool)=?,
    ~disableRipple: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~orientation: option(
                    [@bs.string] [
                      | [@bs.as "vertical"] `Vertical
                      | [@bs.as "horizontal"] `Horizontal
                    ],
                  )
                    =?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "small"] `Small
               | [@bs.as "medium"] `Medium
               | [@bs.as "large"] `Large
             ],
           )
             =?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "text"] `Text
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "contained"] `Contained
                ],
              )
                =?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "ButtonGroup";
