let rs = ReasonReact.string;
let component = ReasonReact.statelessComponent(__MODULE__);

let make = _ => {
  ...component,
  render: _ =>
    <>
      <div>
        <MaterialUi_Typography variant=`H6>
          "Icon Types:"
        </MaterialUi_Typography>
        <MaterialUi_Tooltip title={"Default"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Outlined"->rs}>
          <MaterialUi_Icons.SupervisedUserCircleOutlined />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Rounded"->rs}>
          <MaterialUi_Icons.SupervisedUserCircleRounded />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"TwoTone"->rs}>
          <MaterialUi_Icons.SupervisedUserCircleTwoTone />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Sharp"->rs}>
          <MaterialUi_Icons.SupervisedUserCircleSharp />
        </MaterialUi_Tooltip>
      </div>
      <hr />
      <div>
        <MaterialUi_Typography variant=`H6>
          "Icon Colors:"
        </MaterialUi_Typography>
        <MaterialUi_Tooltip title={"Primary"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle color=`Primary />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Secondary"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle color=`Secondary />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Action"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle color=`Action />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Error"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle color=`Error />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Disabled"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle color=`Disabled />
        </MaterialUi_Tooltip>
      </div>
      <hr />
      <div>
        <MaterialUi_Typography variant=`H6>
          "Icon Sizes:"
        </MaterialUi_Typography>
        <MaterialUi_Tooltip title={"Large"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle fontSize=`Large />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Default"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle fontSize=`Default />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Small"->rs}>
          <MaterialUi_Icons.SupervisedUserCircle fontSize=`Small />
        </MaterialUi_Tooltip>
      </div>
    </>,
};