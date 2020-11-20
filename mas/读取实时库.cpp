     //从实时库读取子系统
        Rsqlclient rsql;
        rsql.selectfrom( TC_PARAM_TAB );//表名
        rsql.selectattr( RDB_TC_OP_FLAG );
        rsql.selectattr( RDB_OP_HOST_NAME );
        rsql.where( RDB_NAME, DATATYPE_STRING, m_pInfo->name );
//        rsql.orderby( RDB_OP_HOST_NAME );
        rsql.select( "ems", "" );//用户名,密码
        int rcdCnt=rsql.getrcdcnt();
        if( rcdCnt>0 )
        {
            char* _hostname = rsql.get_string( 0, RDB_OP_HOST_NAME );
            int   _opflag =rsql.get_uintval(0,RDB_TC_OP_FLAG);
           // qDebug("  %s  -- %s   - %s  -- %d ",m_OpHost,m_hostName,_hostname,_opflag);
            strncpy( m_OpHost, _hostname, DESCRIBE_LEN-1);
            m_bTcOpF = (unsigned char)_opflag;

        }