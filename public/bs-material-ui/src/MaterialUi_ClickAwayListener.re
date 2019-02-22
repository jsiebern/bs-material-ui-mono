[@bs.deriving jsConverter]
type mouseEvent = [
  | [@bs.as "onClick"] `OnClick
  | [@bs.as "onMouseDown"] `OnMouseDown
  | [@bs.as "onMouseUp"] `OnMouseUp
  | [@bs.as "false"] `False
];

[@bs.deriving jsConverter]
type touchEvent = [
  | [@bs.as "onTouchStart"] `OnTouchStart
  | [@bs.as "onTouchEnd"] `OnTouchEnd
  | [@bs.as "false"] `False
];
[@bs.obj]
external makeProps:
  (
    ~mouseEvent: string=?,
    ~onClickAway: ReactEvent.Mouse.t => unit,
    ~touchEvent: string=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "ClickAwayListener";
let make =
    (
      ~mouseEvent: option(mouseEvent)=?,
      ~onClickAway: ReactEvent.Mouse.t => unit,
      ~touchEvent: option(touchEvent)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~mouseEvent=?mouseEvent->(Belt.Option.map(v => mouseEventToJs(v))),
        ~onClickAway,
        ~touchEvent=?touchEvent->(Belt.Option.map(v => touchEventToJs(v))),
        (),
      ),
    children,
  );
