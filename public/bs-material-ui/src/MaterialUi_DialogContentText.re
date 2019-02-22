[@bs.deriving jsConverter]
type align = [
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "left"] `Left
  | [@bs.as "center"] `Center
  | [@bs.as "right"] `Right
  | [@bs.as "justify"] `Justify
];

[@bs.deriving jsConverter]
type color = [
  | [@bs.as "default"] `Default
  | [@bs.as "error"] `Error
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "primary"] `Primary
  | [@bs.as "secondary"] `Secondary
  | [@bs.as "textPrimary"] `TextPrimary
  | [@bs.as "textSecondary"] `TextSecondary
];

[@bs.deriving jsConverter]
type variant = [
  | [@bs.as "h1"] `H1
  | [@bs.as "h2"] `H2
  | [@bs.as "h3"] `H3
  | [@bs.as "h4"] `H4
  | [@bs.as "h5"] `H5
  | [@bs.as "h6"] `H6
  | [@bs.as "subtitle1"] `Subtitle1
  | [@bs.as "subtitle2"] `Subtitle2
  | [@bs.as "body1"] `Body1
  | [@bs.as "body2"] `Body2
  | [@bs.as "caption"] `Caption
  | [@bs.as "button"] `Button
  | [@bs.as "overline"] `Overline
  | [@bs.as "srOnly"] `SrOnly
  | [@bs.as "inherit"] `Inherit
  | [@bs.as "display4"] `Display4
  | [@bs.as "display3"] `Display3
  | [@bs.as "display2"] `Display2
  | [@bs.as "display1"] `Display1
  | [@bs.as "headline"] `Headline
  | [@bs.as "title"] `Title
  | [@bs.as "subheading"] `Subheading
];

module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makeProps:
  (
    ~align: string=?,
    ~className: string=?,
    ~color: string=?,
    ~gutterBottom: bool=?,
    ~headlineMapping: Js.t({..})=?,
    ~inline: bool=?,
    ~internalDeprecatedVariant: bool=?,
    ~noWrap: bool=?,
    ~paragraph: bool=?,
    ~theme: Js.t({..})=?,
    ~variant: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "DialogContentText";
let make =
    (
      ~align: option(align)=?,
      ~className: option(string)=?,
      ~color: option(color)=?,
      ~gutterBottom: option(bool)=?,
      ~headlineMapping: option(Js.t({..}))=?,
      ~inline: option(bool)=?,
      ~internalDeprecatedVariant: option(bool)=?,
      ~noWrap: option(bool)=?,
      ~paragraph: option(bool)=?,
      ~theme: option(Js.t({..}))=?,
      ~variant: option(variant)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~align=?align->(Belt.Option.map(v => alignToJs(v))),
        ~className?,
        ~color=?color->(Belt.Option.map(v => colorToJs(v))),
        ~gutterBottom?,
        ~headlineMapping?,
        ~inline?,
        ~internalDeprecatedVariant?,
        ~noWrap?,
        ~paragraph?,
        ~theme?,
        ~variant=?variant->(Belt.Option.map(v => variantToJs(v))),
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
