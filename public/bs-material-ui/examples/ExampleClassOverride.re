let component = ReasonReact.statelessComponent("Example");

[%mui.withStyles
  "OverrideExample"({
    fontSize: ReactDOMRe.Style.make(~fontSize="30px", ()),
    bgColor:
      ReactDOMRe.Style.make(~backgroundColor=MaterialUi.Colors.Red.c300, ()),
  })
];

let make = _children => {
  ...component,
  render: _self =>
    <OverrideExample>
      ...{
           classes =>
             <MaterialUi.Button
               color=`Primary
               variant=`Contained
               classes=[
                 Root(classes.fontSize),
                 RaisedPrimary(classes.bgColor),
               ]>
               {ReasonReact.string("Example Button")}
             </MaterialUi.Button>
         }
    </OverrideExample>,
};