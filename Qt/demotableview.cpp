//.h

static char* device_col_name[] = 
{
    "所属厂站", // "Substation name",  //厂站名称
    "Device name",			    //"设备名称"
    "Device attr",			    //"设备属性"
    "Inhibit scan",			    //"暂停扫描"
    "Inhibit alarm",			//"禁止报警"
    "Manual input",			    //"人工置数"
    "Realtime value",			//"实时值"
    "name",					    //"代码"
    "npoint",				    //"小数点个数"
};
#define device_col_num (sizeof(device_col_name)/sizeof(char*))



//.cpp
//初始化
	int i = 0;
	m_table->setNumRows(0);
	m_table->setNumCols(device_col_num);
	for(i=0;i<device_col_num;i++)
	{
		m_table->horizontalHeader()->setLabel(i,tr(device_col_name[i]));
		m_table->setColumnReadOnly(i,true);
	}
    m_table->setColumnWidth(SUBSTATION_NAME_COL, 80);
    m_table->setColumnWidth(DEV_NAME_COL, 220);
    m_table->setColumnWidth(SCAN_FLAG_COL, 80);
    m_table->setColumnWidth(ALARM_FLAG_COL, 80);
    m_table->setColumnWidth(INPUT_FLAG_COL, 80);
    m_table->setColumnWidth(REAL_VALUE_COL, 120);
    m_table->hideColumn(NAME_COL);
    m_table->hideColumn(NPOINT_COL);
    m_table->setColumnStretchable(DEV_ATTR_COL, TRUE);