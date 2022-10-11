 if(m_serialName.length()<1)
        return;

    if(m_pointName.length()<1)
        return;
    if(m_scaName.length()<1)
        return;

    uchar flag=(uchar)state;

    int ret;
    Rsqlclient rsqlcli;

    if(g_serialCtrlDlg && g_serialCtrlDlg->hasTCRight(m_scaName.local8Bit().data()))
    {
        rsqlcli.updatetable(RDB_SERIAL_CTRL_OBJ_TAB);
        rsqlcli.updateattr(RDB_USE_FLAG,DATATYPE_UCHAR,&flag);
        rsqlcli.where( RDB_SERIAL_NAME, DATATYPE_STRING,(char*)m_serialName.ascii() );
        rsqlcli.where( RDB_CTRL_OBJ, DATATYPE_STRING,(char*)m_pointName.ascii() );
        ret=rsqlcli.update("scada","df_scada");
        if(ret!=RDB_OK)
        {
            QMessageBox::warning( this, tr("error"), tr("Update Serial_Ctrl_Obj_Tab failed!") );
            return;
        }
    }

    rsqlcli.ClearSQLCommand();
    rsqlcli.selectfrom(RDB_SERIAL_CTRL_OBJ_TAB);
    rsqlcli.selectattr(RDB_USE_FLAG);
    rsqlcli.where( RDB_SERIAL_NAME, DATATYPE_STRING,(char*)m_serialName.ascii() );
    rsqlcli.where( RDB_CTRL_OBJ, DATATYPE_STRING,(char*)m_pointName.ascii() );

    ret=rsqlcli.select("ems","");
    if (ret!=RDB_OK)
    {
        QMessageBox::warning( this, tr("error"), tr("Read Serial_Ctrl_Obj_Tab failed!") );
        return;
    }

    int count	= rsqlcli.getrcdcnt();
    if(count<1)
    {
        QMessageBox::warning( this, tr("error"), tr("Read Serial_Ctrl_Obj_Tab failed!") );
        return;
    }

    uint8 useFlag =  (uint8)rsqlcli.get_intval(0,RDB_USE_FLAG);

    bool state2=(bool)useFlag;

    if(state2!=state)
    {
        setSelected(state2);
    }


/*{{{



*/