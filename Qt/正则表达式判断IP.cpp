
//IP
QRegExp regExp("\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b");

//Port
QRegExp regExp("^([0-9]|[1-9]\\d|[1-9]\\d{2}|[1-9]\\d{3}|[1-5]\\d{4}|6[0-4]\\d{3}|65[0-4]\\d{2}|655[0-2]\\d|6553[0-5])$");

QMessageBox::critical(0 , "critical message" , "Do you want to process?", QMessageBox::Ok | QMessageBox::Default , QMessageBox::Cancel | QMessageBox::Escape , 	0 ); 

bool isIpAddr(const QString &ip){

    QRegExp rx2("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-5]|[01]?\\d\\d?)");

    if(rx2.exactMatch(ip))

    {

        return true;

    }

    return false;

}