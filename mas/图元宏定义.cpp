#ifndef CORETYPE_H
#define CORETYPE_H

/** all Core types defined here. */
#ifdef DF8003S
#define EXTEND_BASE 20
#define EXTEND_DEVICE EXTEND_BASE + 20
#else
#define EXTEND_BASE 0
#define EXTEND_DEVICE 0
#endif
/*! \addtogroup CoreTypes 核心类
*** \{
*** \brief 所有可支持的图元类类型
*/
enum CoreTypes {
  /*0*/
  ellipseClass,         ///< 椭圆类类型。
  ellipseFClass,        ///< 实心椭圆类类型
  circleClass,          ///< circle class type.
  circleFClass,         ///< filled circle class type.
  arcTwoPointsClass,    ///< two-point arc class type.
  arcTwoPointsFClass,   ///< filled two-point class type.
  arcThreePointsClass,  ///< three-point arc class type.
  arcThreePointsFClass, ///< filled three-point class type.
  closedSplineClass,    ///< closed Spline class type.

  /*9*/
  coreClass,        ///< core class type, the ancestor type.
  displayClass,     ///< display class type.
  dynMethodClass,   ///< dynamic method class type.
  dynamicClass,     ///< dynamic class type.
  templateClass,    ///< template class.
  solidLineClass,   ///< solid line class type.
  fontLibraryClass, ///< font library class type.
  freehandClass,    ///< freehand class type.
  groupClass,       ///< group class type.

  /*18*/
  layerClass,     ///< layer class type.
  libraryClass,   ///< library class type.
  lineClass,      ///< line class type.
  multiLineClass, ///< folded line class type.
  listClass,      ///< 类类型列表。list是一个核心类型的对象管理器类类型。
  objListClass,   ///< 对象列表类类型。list是一个核心类型的对象管理器类类型。
  polygonClass,   ///< polygon class type.
  polygonFClass,  ///<	filled polygon class type.
  primitiveClass, ///< 原始的类类型。这是大多数设备的基类。

  /*27*/
  queueClass,      ///< 队列结构类类型。
  rectangleClass,  ///< rectange class type.
  rectangleFClass, ///< filled rectangle class type.
  refClass,        ///< ref class type.
  splineClass,
  stackClass,
  textClass,
  pieSliceClass,
  pieSliceFClass,

  /*36*/
  tileClass,
  viewClass,
  closedSplineFClass,

  /*39*/
  iosButtonClass,
  motifButtonClass,

  // ------------- begin Device is powerDeviceClass --------------------
  powerDeviceClass = motifButtonClass + EXTEND_BASE,

  /*42*/
  breakerClass,     //开关
  switchClass,      //刀闸
  transformerClass, //三卷变

  /*45*/
  currentTransformerClass, //电流互感器
  voltageTransformerClass, //电压互感器
  generatorClass,          //火电机组

  /*48*/
  busSectionClass, //<母线>
  powerLineClass,  //线路
  capacitorClass,  //<*电容>

  /*51*/
  reactanceClass,    //电抗
  loadClass,         //恒定负荷
  transformer1Class, //自藕变

  /*54*/
  transformer2Class,    //两卷变
  earthClass,           //接地
  nonConstantLoadClass, //非恒定负荷

  /*57*/
  hydroGeneratorClass,                               //水电机组
  arresterClass,                                     //避雷器
  arcCoilClass,                                      //消弧线圈
  lightningRodClass = arresterClass + EXTEND_DEVICE, //避雷针
  // ------------- end Device is powerDeviceClass --------------------

  /*60*/
  connectLineClass,
  scadaRealValueClass, // SCADA动态数据
  connectPointClass,

  /*63*/
  connectNodeClass,
  scadaMeterClass,        // SCADA表盘
  scadaHistoryCurveClass, // SCADA历史曲线

  /*66*/
  powerDevLibClass,
  imageClass,
  transColorClass,

  /*69*/
  scadaMultiCurveClass, // SCADA多曲线
  scadaBarClass,        // SCADA棒图
  scadaRealCurveClass,  // SCADA实时曲线

  /*72*/
  scadaIndicatorLampClass, // SCADA指示灯
  pieChartClass,           //饼图
  termMeasureClass,

  /*75*/
  scadaListClass,
  scadaGaugeClass, // SCADA刻度尺
  subGraphClass,

  /*78*/
  loadFactorClass,
  dynamicPointClass,  // SCADA动态点
  dynamicPointAClass, // SCADA动态点A
  dynamicPointBClass, // SCADA动态点B
  dynamicPointCClass, // SCADA动态点C
  stationClass,

  /*81*/
  agcBarClass,       // AGC棒图
  agcRealCurveClass, // AGC实时曲线
  agcRealValueClass, // AGC动态数据
  /*84*/
  agcToggleLineClass,
  agcIndicatorLampClass,
  agcParaCurveClass,

  /*87*/
  tableControlClass,
  treeListControlClass,
  symbolClass,

  /*90*/
  scadaMultiBarClass,
  adapterStatusClass,
  contourLineAreaClass,

  /*93*/
  dynamicPickupPointClass,
  vqcAreaClass,
  dateControlClass,
  scadaPeriodCurveClass,
  selfControlClass,
  polyGroupClass,
  polyGroupAClass,
  polyGroupBClass,
  polyGroupCClass,
  polyGroupDClass,
  polyGroupEClass,
  /* chuixj 2011-07-27*/

  basDeviceClass, /*!< BAS 都含有"basDevice", 方便以后比较判断 */
  blower_basDeviceClass,   //风机系统
  airvalve_basDeviceClass, //风阀系统
  aircond_basDeviceClass,  //空调系统
  fan_basDeviceClass,      //通风系统
  water_basDeviceClass,    //冷水系统
  drain_basDeviceClass,    //给排水系统
  elevator_basDeviceClass, //电扶梯系统
  light_basDeviceClass,    //照明系统
  sensor_basDeviceClass,   //传感器
  other_basDeviceClass,    //其他BAS设备
  basDeviceClassEnd,       // BAS END

  /* added by chuixj 2011-09-19 STX */
  fasDeviceClass,           /*!< FAS及其它图元 */
  fasvalve_fasDeviceClass,  /*!< FAS */
  fassensor_fasDeviceClass, /*!< FAS */
  fasother_fasDeviceClass,  /*!< FAS */

  afc_fasDeviceClass,  // AFC
  pa_fasDeviceClass,   // PA
  pis_fasDeviceClass,  // PIS
  cctv_fasDeviceClass, // CCTV
  psd_fasDeviceClass,  // PSD图元
  acs_fasDeviceClass,  // ACS图元
  sig_fasDeviceClass,  // SIG图元
  nms_fasDeviceClass,  // NMS图元
  gwgx_fasDeviceClass, // GX图元
  ed_fasDeviceClass,   // ED图元
  ups_fasDeviceClass,  // UPS图元
  alm_fasDeviceClass,  // ALM图元
  fg_fasDeviceClass,   // ALM图元
  fasDeviceClassEnd,   // FAS END

    /*MARK: 郑州14号线增加 by : qsj on 2019-9-8 */
  securityGroupClass, //安防
  patrolGroupClass,  //安检查机

  /*MARK: 同步洛阳01新增专业 by:  zdz  on 2020-04-06  11:47:02*/
  elecFireGroupClass,             //电气火灾
  emergencyEvacuationClass,       //应急疏散
  cabinetDetectionClass,          //机柜检测
  electricEnergyCollectionClass,  //电能采集
  SF6TestClass,                   // SF6检测
  concentratedWarningClass,       //集中警告
  electronicIntelligentizedClass, //弱电智能化
  energyManagementClass,          //能源管理
  securityGroupClassEnd,
  CoreTypeCnt

};
/*! \} */
#endif
