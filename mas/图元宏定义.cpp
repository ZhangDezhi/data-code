enum CoreTypes {
/*0*/	ellipseClass, ///< ellipse class type.
		ellipseFClass,///< filled ellipse class type.
		circleClass,  ///< circle class type.
		circleFClass, ///< filled circle class type.
		arcTwoPointsClass,///< two-point arc class type.
		arcTwoPointsFClass, ///< filled two-point class type.
		arcThreePointsClass, ///< three-point arc class type.
		arcThreePointsFClass,///< filled three-point class type.
		closedSplineClass, ///< closed Spline class type.
/*9*/	coreClass, ///< core class type, the ancestor type.
 		displayClass, ///< display class type.
		dynMethodClass, ///< dynamic method class type.
		dynamicClass, ///< dynamic class type.
		templateClass, ///< template class.
		solidLineClass, ///< solid line class type.
		fontLibraryClass, ///< font library class type.
		freehandClass, ///< freehand class type.	
		groupClass, ///< group class type.
/*18*/	layerClass, ///< layer class type.
		libraryClass, ///< library class type.	
		lineClass, ///< line class type.
		multiLineClass, ///< folded line class type.
		listClass, ///< list class type. list is a core-type object manager class type.
		objListClass, ///< object list class type. list is a core-type object manager class type.
		polygonClass,	///< polygon class type.
		polygonFClass, ///<	filled polygon class type.
		primitiveClass, ///< primitive class type. this is the base class for most device.
/*27*/	queueClass,	///< queue structure class type.
		rectangleClass,	///< rectange class type.
		rectangleFClass, ///< filled rectangle class type.
		refClass,	///< ref class type.
		splineClass,	
		stackClass,
		textClass,	
		pieSliceClass,		
		pieSliceFClass,
/*36*/	tileClass,				viewClass,				closedSplineFClass,
/*39*/	iosButtonClass,			motifButtonClass,	
		powerDeviceClass=motifButtonClass+EXTEND_BASE, //begin Device is powerDeviceClass wind modify 2008.11.18 )展
/*42*/	breakerClass ,			switchClass ,			transformerClass ,
/*45*/	currentTransformerClass, voltageTransformerClass, generatorClass ,
/*48*/	busSectionClass ,		powerLineClass ,		capacitorClass ,
/*51*/	reactanceClass ,		loadClass ,				transformer1Class,
/*54*/	transformer2Class,		earthClass,				nonConstantLoadClass,
/*57*/	hydroGeneratorClass,	arresterClass,			arcCoilClass,		
		lightningRodClass=arresterClass+EXTEND_DEVICE, //end Device is lightningRodClass /wind modify 2008.11.18 )展

/*60*/	connectLineClass ,		scadaRealValueClass ,	connectPointClass, 
/*63*/	connectNodeClass,		scadaMeterClass,		scadaHistoryCurveClass,
/*66*/	powerDevLibClass,		imageClass,				transColorClass,
	      	
/*69*/	scadaMultiCurveClass,	scadaBarClass,			scadaRealCurveClass,
/*72*/	scadaIndicatorLampClass,pieChartClass,			termMeasureClass,
/*75*/	scadaListClass,			scadaGaugeClass,		subGraphClass,
/*78*/	loadFactorClass,		dynamicPointClass,		dynamicPointAClass,
        dynamicPointBClass,     dynamicPointCClass,     stationClass,
/*81*/	agcBarClass,			agcRealCurveClass,		agcRealValueClass,
/*84*/	agcToggleLineClass,		agcIndicatorLampClass,	agcParaCurveClass,

/*87*/	tableControlClass,		treeListControlClass,	symbolClass,
/*90*/	scadaMultiBarClass,		adapterStatusClass, 	contourLineAreaClass,
/*93*/	dynamicPickupPointClass,vqcAreaClass, dateControlClass,scadaPeriodCurveClass,
        selfControlClass, 
		polyGroupClass,		    polyGroupAClass,	    polyGroupBClass,
		polyGroupCClass,	    polyGroupDClass,	    polyGroupEClass,
		/* chuixj 2011-07-27*/

		basDeviceClass,  /*!< BAS 都含有"basDevice", 方便以后比较判断 */
		blower_basDeviceClass, /*!< 风机系统 */
		airvalve_basDeviceClass, /*!< 风阀系统 */
		aircond_basDeviceClass,  /*!< 空调系统 */
		fan_basDeviceClass,  /*!< 通风系统 */
		water_basDeviceClass,  /*!< 冷水系统 */
		drain_basDeviceClass,  /*!< 给排水系统 */
		elevator_basDeviceClass,  /*!< 电扶梯系统 */
		light_basDeviceClass,  /*!< 照明系统 */
		sensor_basDeviceClass, /*!< 传感器 */
		other_basDeviceClass,  /*!< 其他BAS设备 */
		basDeviceClassEnd, /*<! BAS END */

		/* added by chuixj 2011-09-19 STX */
		fasDeviceClass, /*!< FAS及其它图元 */
		fasvalve_fasDeviceClass, /*!< FAS */
		fassensor_fasDeviceClass, /*!< FAS */
		fasother_fasDeviceClass, /*!< FAS */

		afc_fasDeviceClass, /*!< AFC */
		pa_fasDeviceClass, /*!< PA */
		pis_fasDeviceClass, /*!< PIS */
		cctv_fasDeviceClass, /*!< CCTV */
		psd_fasDeviceClass, /*!< PSD图元　*/
		acs_fasDeviceClass, /*!< ACS图元　*/
		sig_fasDeviceClass, /*!< SIG图元　*/
		nms_fasDeviceClass, /*!< NMS图元　*/
		gwgx_fasDeviceClass, /*!< GX图元　*/
		ed_fasDeviceClass, /*!< ED图元　*/
		ups_fasDeviceClass, /*!< UPS图元　*/
		alm_fasDeviceClass, /*!< ALM图元　*/
		fg_fasDeviceClass, /*!< ALM图元　*/
		fasDeviceClassEnd, /*!< FAS END */
	
    	/* added by chuixj 2011-09-19 ETX */
        securityGroupClass,
        patrolGroupClass,
        elecFireGroupClass, //电气火灾 
        emergencyEvacuationClass,//应急疏散
    //MARK: addly01新增机柜检测    by:  zdz  on 2020-04-06  11:47:02
    cabinetDetectionClass,//机柜检测
    //MARK: addly01新增电能采集    by:  zdz  on 2020-04-06  11:47:02
    electricEnergyCollectionClass,
    //MARK: addly01新增SF6检测    by:  zdz  on 2020-04-06  11:47:02
    SF6TestClass,
    //MARK: addly01新增集中警告    by:  zdz  on 2020-04-06  11:47:02
    concentratedWarningClass,
    //MARK: addly01新增弱电智能化    by:  zdz  on 2020-04-06  11:47:02
    electronicIntelligentizedClass,
    //MARK: 增加专业:能源管理    by:  zdz  on 2020-06-10  10:37:26
    energyManagementClass,


        securityGroupClassEnd,
        CoreTypeCnt

};